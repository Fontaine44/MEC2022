#ifndef PRE_CQI_2023_DEBUG_GREATSONG_H
#define PRE_CQI_2023_DEBUG_GREATSONG_H


#include "Song.h"

class GreatSong : Song {
public:
    GreatSong(const std::string &name, const std::string &lyrics);

    std::string sing() const override;
};


#endif //PRE_CQI_2023_DEBUG_GREATSONG_H
