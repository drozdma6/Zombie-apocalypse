//
// Created by marek on 5/4/2021.
//
#pragma once

#include <utility>
#include <vector>
#include <memory>

#include "CGame.h"
#include "CInterface.h"


/*
 * Class represents whole application, individual games are started inside application.
 */
class CApplication {
public:
    /**
     * Constructors adds interface to m_Interface.
     * @param[in] interface 
     */
    explicit CApplication(std::shared_ptr<CInterface> interface);

    /**
     * Creates CExecutor and register all generators to executor, and runs executor afterwards.  
     * @param[in] game 
     */
    void RunGameExecutor(CGame &game);

    /**
     * Based on input from m_Interface decides, whether to start new game, load previously saved game or quit application.
     */
    void ProcessPrompt();

    /**
     * Main application loop. Individual games run inside the application. More games can be loaded in one application run.
     */
    void Run();

    /**
     * Loads map from file, creates player on random coords, creates game.
     * First line of the file has to have map's Height and Width.
     */
    void NewGame();

    /**
     * Loads all information needed for game from file. Saved games must have (in this order):
     * MapHeight mapWidth
     * Map
     * Player's properties.
     * Player's coords and direction
     * Number of items in players inventory, active item
     * Score
     * Number of spawned zombies
     * Coords of each zombie
     * Number of spawned items
     * Information about each item
     */
    void LoadGame();

private:
    std::shared_ptr<CInterface> m_Interface;
    bool m_Running = true;
};

