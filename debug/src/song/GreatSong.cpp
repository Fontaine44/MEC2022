#include "GreatSong.h"

GreatSong::GreatSong(const std::string &name, const std::string &lyrics) : Song(name, lyrics) {}

std::string GreatSong::sing() const {
    std::string shoutedLyrics(_lyrics);

    return shoutedLyrics;
}
