//
// Created by marek on 5/4/2021.
//
#pragma once

#include "CActionGenerator.h"
#include "CCharacter.h"


class CZombie : public CCharacter, public CActionGenerator {
protected:
    CZombie(CCoords coord, EDirection dir);
};
