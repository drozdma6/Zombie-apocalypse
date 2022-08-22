//
// Created by marek on 5/9/2021.
//
#pragma once

#include "CZombie.h"
#include "CGame.h"
#include "CAction.h"

#include <vector>

/*
 * Class represents certain type of zombie, with specific movement.
 */
class CZombieWalker : public CZombie {
public:
    CZombieWalker(CCoords coords, EDirection dir);

    /**
     * Generate movement for all zombie walkers. Zombie walker moves to his directions until he hits wall/item, then
     * he changes his direction.
     * @param[in] game
     * @return vector of actions (zombie movement) which are supposed to be executed after next iteration of game.
     */
    std::vector<CAction> GenerateNextActions(const CGame &game) override;
};