//
// Created by marek on 5/31/2021.
//

#include "CItemGenerator.h"
#include "SActions.h"
#include "SRandom.h"
#include "CGun.h"
#include "CBomb.h"

using namespace std;

static constexpr size_t ITEM_SPAWN_PERCENTAGE = 70;

std::vector<CAction> CItemGenerator::GenerateNextActions(const CGame &game) {
    std::vector<CAction> actions;
    vector<CCoords> emptyFields = game.EmptyFields();
    CCoords position{};
    //Max 4 items can be spawned at some state of the game
    if (game.GetItems().size() >= 4) {
        return actions;
    }
    if (SRandom::RandomIdx(100) > ITEM_SPAWN_PERCENTAGE) {
        return actions;
    }

    //randomIdx can not divide by 0
    if (emptyFields.size() > 1) {
        position = emptyFields[SRandom::RandomIdx(emptyFields.size() - 1)];
    } else if (emptyFields.size() == 1) {
        position = emptyFields[0];
    }
    //actions.push_back(SActions::SpawnItem(std::make_shared<CGun>(), {2,0}));
    //50 percent to spawn bomb/gun
    if (SRandom::RandomIdx(100) >= 50) {
        actions.push_back(SActions::SpawnItem(std::make_shared<CBomb>(), position));
    } else {
        actions.push_back(SActions::SpawnItem(std::make_shared<CGun>(), position));
    }
    return actions;
}
