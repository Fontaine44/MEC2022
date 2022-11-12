#include "Karaoke.h"

const Song *Karaoke::getNextSong() {
    if (!_requestedSongCount)
        return nullptr;

    const Song s = _requestedSongs[_requestedSongsHeadIndex];

    _requestedSongsHeadIndex = (_requestedSongsHeadIndex + 1);
    _requestedSongCount--;

    return &s;
}

bool Karaoke::specialRequest(Song *song) {
    if (_requestedSongCount == SONG_QUEUE_SIZE)
        return false;

    _requestedSongsTailIndex = (_requestedSongsTailIndex + 1) % SONG_QUEUE_SIZE;
    _requestedSongs[_requestedSongsTailIndex] = song;
    _requestedSongCount++;

    return true;
}

int Karaoke::getRequestedSongCount() const {
    return _requestedSongCount;
}
