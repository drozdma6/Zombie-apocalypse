//
// Created by marek on 6/1/2021.
//

#include "SRandom.h"

#include <cstdlib>
#include <ctime>

using namespace std;

void SRandom::Init() {
#ifndef DEBUG
    srand(time(nullptr)); // NOLINT(cert-msc51-cpp)
#else
    srand( 0 );
#endif
}

size_t SRandom::RandomIdx(size_t limit) {
    return static_cast<size_t> (rand()) % limit;
}

CCoords SRandom::RandomCoord(size_t width, size_t height) {
    return {RandomIdx(width), RandomIdx(height)};
}

