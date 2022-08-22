//
// Created by marek on 5/8/2021.
//
#pragma once

#include "CGame.h"
#include "CActionGenerator.h"
#include "CInterface.h"
#include "CAction.h"

#include <memory>
#include <vector>

/*
 * Class executes current game.
 */
class CExecutor {
public:
    /**
     * Constructor adds interface to m_Interface and game to m_Game.
     * @param[in] interface 
     * @param[in] game 
     */
    CExecutor(std::shared_ptr<CInterface> interface, CGame &game);

    /**
     * Main game loop, each iteration consists of:
     * Checks whether player's health is equal to zero,
     * Waits for input from CInterface,
     * Adds player-based actions to m_Actions,
     * Runs all generators, if they have actions add them m_Actions,
     * Executes all actions.
     */
    void Run();

    /**
     * Adds generators to m_Generators.
     * @param[in] generator 
     * @return reference to CExecutor.
     */
    CExecutor &RegisterGenerator(const std::shared_ptr<CActionGenerator> &generator);

    /**
     * Ends game loop.
     */
    void Quit();

    /**
     * Adds all user-based actions to game.
     */
    void AddActions();

    /**
     * Executes all actions from m_Actions.
     */
    void ExecuteStep();

    /**
     * Clears m_Actions.
     */
    void ClearActions();

private:
    std::vector<std::shared_ptr<CActionGenerator>> m_Generators;
    std::shared_ptr<CInterface> m_Interface;
    std::vector<CAction> m_Actions;
    CGame &m_Game;
    bool m_Running = true;
};
