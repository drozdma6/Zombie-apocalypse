//
// Created by marek on 5/9/2021.
//
#pragma once

#include "CAction.h"
#include "CActionGenerator.h"
#include "CGame.h"

#include <vector>

/*
 * Class represents generator for spawning zombies from ZombieSpawns.
 */
class CZombieSpawnGenerator : public CActionGenerator {
public:
    /**
     * Creates actions which spawns zombies from zombie spawns.
     * @param[in] game 
     * @return vector of actions (zombie spawns) which are supposed to be executed after next iteration of game. 
     */
    std::vector<CAction> GenerateNextActions(const CGame &game) override;
};
