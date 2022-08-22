//
// Created by marek on 5/9/2021.
//
#pragma once

#include "CAction.h"
#include "CActionGenerator.h"
#include "CGame.h"

#include <vector>

/*
 * Class represents spawner for items.
 */
class CItemGenerator : public CActionGenerator {
public:
    /**
     * Generates spawnItem actions. There can only be 4 items spawned at the same time. Items are spawning based on 
     * given percentage.
     * @param[in] game 
     * @return vector of SpawnItems actions.
     */
    std::vector<CAction> GenerateNextActions(const CGame &game) override;
};
