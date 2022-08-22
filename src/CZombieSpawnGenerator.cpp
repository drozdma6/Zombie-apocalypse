//
// Created by marek on 5/31/2021.
//

#include "CZombieSpawnGenerator.h"
#include "SActions.h"
#include "SRandom.h"
#include "CZombieWalker.h"

using namespace std;

static constexpr size_t ZOMBIE_SPAWN_PERCENTAGE = 100;


std::vector<CAction> CZombieSpawnGenerator::GenerateNextActions(const CGame &game) {
    std::vector<CAction> zombieSpawn;

    if (SRandom::RandomIdx(100) > ZOMBIE_SPAWN_PERCENTAGE) {
        return zombieSpawn;
    }
    vector<CCoords> zombieSpawns = game.GetMap().ZombieSpawns();
    //generate spawn actions from all zombie spawns on map
    for (CCoords coord : zombieSpawns) {
        vector<CCoords> emptyFields = game.EmptyFields(coord);
        if (emptyFields.empty()) {
            continue;
        }
        auto zombie = make_shared<CZombieWalker>(emptyFields[0], EDirection::RIGHT);
        zombieSpawn.push_back(SActions::ZombieSpawn(zombie));
    }
    return zombieSpawn;
}
