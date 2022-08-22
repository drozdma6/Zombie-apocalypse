#pragma once

#include "EDirection.h"
#include "CCoords.h"
#include <cstddef>


/*
 * Class for working with random numbers.
 */
class SRandom {
public:
    SRandom() = delete;

    static void Init();

    static size_t RandomIdx(size_t limit = -1);

    /**
     * Gives random coords
     * @param width 
     * @param height 
     * @return random coords.
     */
    static CCoords RandomCoord(size_t width, size_t height);
};
