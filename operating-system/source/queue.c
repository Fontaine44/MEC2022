#include <assert.h>
#include <stdlib.h>

#include "log.h"
#include "queue.h"

queue_t* queue_create(size_t size) {
    queue_t* queue = calloc(sizeof(*queue), 1);
    if (queue == NULL) {
        LOG_ERROR_ERRNO("calloc");
        goto fail_exit;
    }

    queue->size = size;
    queue->used = 0;

    errno = pthread_mutex_init(&queue->mutex, NULL);
    if (errno != 0) {
        LOG_ERROR_ERRNO("pthread_mutex_init");
        goto fail_free_queue;
    }

    errno = pthread_cond_init(&queue->modified_item_pushed, NULL);
    if (errno != 0) {
        LOG_ERROR_ERRNO("pthread_cond_init");
        goto fail_destroy_mutex;
    }

    errno = pthread_cond_init(&queue->modified_item_poped, NULL);
    if (errno != 0) {
        LOG_ERROR_ERRNO("pthread_cond_init");
        goto fail_destroy_cond;
    }

    return queue;

fail_destroy_cond:
    pthread_cond_destroy(&queue->modified_item_pushed);
fail_destroy_mutex:
    pthread_mutex_destroy(&queue->mutex);
fail_free_queue:
    free(queue);
fail_exit:
    return NULL;
}

void queue_destroy(queue_t* queue) {
    pthread_mutex_destroy(&queue->mutex);
    pthread_cond_destroy(&queue->modified_item_pushed);
    pthread_cond_destroy(&queue->modified_item_poped);

    while (queue->head != NULL) {
        queue_node_t* head = queue->head;
        queue->head        = head->prev;
        free(head);
    }

    free(queue);
}

int queue_push(queue_t* queue, void* ptr) {
    queue_node_t* node = malloc(sizeof(*node));
    if (node == NULL) {
        LOG_ERROR_ERRNO("malloc");
        goto fail_exit;
    }

    errno = pthread_mutex_lock(&queue->mutex);
    if (errno != 0) {
        LOG_ERROR_ERRNO("pthread_mutex_lock");
        goto fail_free_node;
    }

    while (queue->used == queue->size) {
        errno = pthread_cond_wait(&queue->modified_item_poped, &queue->mutex);
        if (errno != 0) {
            LOG_ERROR_ERRNO("pthread_cond_wait");
            goto fail_unlock_mutex;
        }
    }

    node->value = ptr;
    node->prev  = NULL;

    if (queue->tail != NULL) {
        queue->tail->prev = node;
    }

    queue->tail = node;

    if (queue->used++ == 0) {
        queue->head = node;
    }

    errno = pthread_mutex_unlock(&queue->mutex);
    if (errno != 0) {
        LOG_ERROR_ERRNO("pthread_mutex_lock");
        goto fail_exit;
    }

    errno = pthread_cond_signal(&queue->modified_item_pushed);
    if (errno != 0) {
        LOG_ERROR_ERRNO("pthread_cond_signal");
        goto fail_exit;
    }

    return 0;

fail_unlock_mutex:
    pthread_mutex_unlock(&queue->mutex);
fail_free_node:
    free(node);
fail_exit:
    return -1;
}

void* queue_pop(queue_t* queue) {
    errno = pthread_mutex_lock(&queue->mutex);
    if (errno != 0) {
        LOG_ERROR_ERRNO("pthread_mutex_lock");
        goto fail_exit;
    }

    while (queue->used == 0) {
        errno = pthread_cond_wait(&queue->modified_item_pushed, &queue->mutex);
        if (errno != 0) {
            LOG_ERROR_ERRNO("pthread_cond_wait");
            goto fail_unlock_mutex;
        }
    }

    queue_node_t* head = queue->head;
    queue->head        = head->prev;

    void* value = head->value;
    free(head);

    if (--queue->used == 0) {
        queue->tail = NULL;
        queue->head = NULL;
    }

    errno = pthread_mutex_unlock(&queue->mutex);
    if (errno != 0) {
        LOG_ERROR_ERRNO("pthread_mutex_lock");
        goto fail_exit;
    }

    errno = pthread_cond_signal(&queue->modified_item_poped);
    if (errno != 0) {
        LOG_ERROR_ERRNO("pthread_cond_signal");
        goto fail_exit;
    }

    return value;

fail_unlock_mutex:
    pthread_mutex_unlock(&queue->mutex);
fail_exit:
    return NULL;
}