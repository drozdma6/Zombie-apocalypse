//
// Created by marek on 5/4/2021.
//
#pragma once

#include "SPlayerProperties.h"
#include "EApplicationInputs.h"
#include "EGameInputs.h"
#include "CGame.h"

#include <iostream>
#include <string>

/*
 * Class represents communication with user.
 */
class CInterface {
public:
    CInterface(std::istream &in, std::ostream &out);

    /**
     * Asks user for input. (new game, load game, quit application)
     * @return enum EApplicationInputs, based on user's input.
     */
    EApplicationInputs PromptApplicationInput();

    /**
     * Clear m_In.
     */
    void ClearInput();

    /**
     * Draw game to m_Out, functions is called after each game iteration.
     * @param[in] game 
     */
    void DrawGame(const CGame &game);

    /**
     * Asks user for player's name, health, number of ports. Ports plus health can not exceed 10 points.
     * @return struct which contains all given information.
     */
    SPlayerProperties PromptPlayerProperties();

    /**
     * Game commands, which controls player's character, or quits current game.
     * @return enum value based on user's input.
     */
    EGameInputs PromptGameInput();

    /**
     * Prints information about current zombie attack.
     */
    void ZombieAttack();

    /**
     * Ask user, how to name file used for saving the game.
     * @return fileName.
     */
    std::string PromptFileName();

    /**
     * Ask user, which map he wants load for new game. It has to be number between 1 and 5.
     * @return user's choice of a map.
     */
    std::size_t PromptMap();

    /**
     * Ask user, if he wants to save current state of the game.
     * @return true, if user types yes.
     */
    bool PromptSave();

    void PlayerDied();

private:
    std::istream &m_In;
    std::ostream &m_Out;
};


