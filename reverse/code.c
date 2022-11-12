//
// gcc -m32 code.c -o binary-test
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 64

#pragma weak check_credentials
int check_credentials(unsigned long matricule, char* password) {
    return 0;
}

#pragma weak get_flag
char* get_flag(unsigned long matricule, char* password) {
    return "flag-is-not-me";
}

void ask_credentials() {
    char* flag;
    unsigned long matricule;
    char password[BUFFER_SIZE];

    printf("Username: ");
    if(scanf("%lu", &matricule) != 1) {
        printf("Error\n");
        return;
    }

    printf("Password: ");
    if(scanf("%s", password) != 1) {
        printf("Error\n");
        return;
    }

    flag = get_flag(matricule, password);

    char msg[BUFFER_SIZE];
    snprintf(msg, BUFFER_SIZE, "Username: %lu\nPassword: %s\n", matricule, password);
    dprintf(1, msg);

    if(!check_credentials(matricule, password)) {
        dprintf(1, "Invalid credentials.\n");
        return;
    }

    snprintf(msg, BUFFER_SIZE, "Login successful, here's the flag: %s\n", flag);
    dprintf(1, msg);
}

#pragma weak main
int main() {
    ask_credentials();
    return 0;
}
