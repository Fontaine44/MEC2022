#ifndef PRE_CQI_2023_DEBUG_SONG_H
#define PRE_CQI_2023_DEBUG_SONG_H

#include <string>
#include <vector>

class Song {
public:
    virtual std::string sing() const = 0;

    Song(const std::string &name, const std::string &lyrics);

    friend bool operator==(const Song &s1, const Song &s2);

protected:
    const std::string& _name;
    const std::string _lyrics;
};


#endif //PRE_CQI_2023_DEBUG_SONG_H
