#define PRE_CQI_2023_DEBUG_FRENCHSINGER_H


#include "Singer.h"

#define FRANCAIS_DE_FRANCE "???"

class FrenchSinger : public Singer {
public:
    virtual std::string sing() const;
};