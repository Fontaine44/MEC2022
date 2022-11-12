#include "FrenchSinger.h"

std::string FrenchSinger::sing() const {
    return FRANCAIS_DE_FRANCE + Singer::sing();
}
