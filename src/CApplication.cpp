//
// Created by marek on 5/31/2021.
//

#include "CApplication.h"
#include "CExecutor.h"
#include "SRandom.h"
#include "CZombieSpawnGenerator.h"
#include "CItemGenerator.h"
#include "CGun.h"
#include "CBomb.h"
#include "CZombieWalker.h"

#include <iostream>
#include <string>

using namespace std;

CApplication::CApplication(std::shared_ptr<CInterface> interface) : m_Interface(std::move(interface)) {}

void CApplication::ProcessPrompt() {
    EApplicationInputs command = m_Interface->PromptApplicationInput();
    if (command == EApplicationInputs::newGame) {
        NewGame();
    } else if (command == EApplicationInputs::load) {
        LoadGame();
    } else if (command == EApplicationInputs::quit) {
        //Ends application
        m_Running = false;
    }
}

void CApplication::RunGameExecutor(CGame &game) {
    CExecutor executor{m_Interface, game};
    //register generators to executor
    executor.RegisterGenerator(make_shared<CZombieSpawnGenerator>())
            .RegisterGenerator(make_shared<CItemGenerator>())
            .Run();
}

void CApplication::Run() {
    //main application loop
    while (m_Running) {
        ProcessPrompt();
    }
}

void CApplication::NewGame() {
    //Loads map from file
    string path = "examples/maps/map" + to_string(m_Interface->PromptMap()) + ".txt";
    ifstream file(path);
    if (!file.is_open() || !file) {
        throw runtime_error("Unable to open file with map.");
    }
    CMap map(file);
    //Creating player on random empty field on map
    auto emptyFields = map.EmptyFields();
    CCoords coord{};
    if (emptyFields.empty()) {
        throw runtime_error("Cannot create a player, there isn't an empty field on map.");
    } else if (emptyFields.size() == 1) {
        coord = emptyFields[0];
    } else {
        coord = emptyFields[SRandom::RandomIdx(emptyFields.size() - 1)];
    }
    CPlayer player(coord, EDirection::RIGHT, m_Interface->PromptPlayerProperties());
    //Creating Game
    //While creating new game initial score is set to zero
    CGame game(map, player, 0);
    RunGameExecutor(game);
}

void CApplication::LoadGame() {
    //Loads whole game from file
    ifstream file(m_Interface->PromptFileName());
    if (!file.is_open() || !file) {
        throw runtime_error("Unable to open file with map.");
    }
    CMap map(file);
    CPlayer player(file);
    size_t score;
    file >> score;
    if (file.get() != '\n') {
        throw runtime_error("Unexpected problem with map loading.");
    }
    CGame game(map, player, score);

    size_t zombiesCount, itemsCount;
    char itemName;
    CCoords coords{};

    file >> zombiesCount;
    if (file.get() != '\n') {
        throw runtime_error("Unexpected problem with map loading.");
    }
    //add zombies to game
    for (size_t i = 0; i < zombiesCount; i++) {
        file >> coords.m_X >> coords.m_Y;
        if (file.get() != '\n') {
            throw runtime_error("Unexpected problem with map loading.");
        }
        game.AddZombie(make_shared<CZombieWalker>(coords, EDirection::UP));
    }
    //add spawned items to game
    file >> itemsCount;
    if (file.get() != '\n') {
        throw runtime_error("Unexpected problem with map loading.");
    }
    for (size_t i = 0; i < itemsCount; i++) {
        file >> itemName >> coords.m_X >> coords.m_Y;
        if (file.get() != '\n') {
            throw runtime_error("Unexpected problem with map loading.");
        }
        if (itemName == 'G') {
            game.AddItem(coords, std::make_shared<CGun>());
        } else if (itemName == 'B') {
            game.AddItem(coords, std::make_shared<CBomb>());
        }
    }
    RunGameExecutor(game);
}
