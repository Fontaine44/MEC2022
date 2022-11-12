#include "Singer.h"

void Singer::setProposedSong(Song* proposedSong) {
    _proposedSong = proposedSong;
}

bool Singer::omgItsMySooooong(const Song *song) const {
    return _proposedSong == song;
}

std::string Singer::sing() const {
    return _proposedSong ? _proposedSong->sing() : NO_SONG_MESSAGE;
}
