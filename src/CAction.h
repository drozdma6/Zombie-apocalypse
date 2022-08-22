//
// Created by marek on 5/8/2021.
//

#pragma once

#include "CGame.h"

#include <memory>
#include <functional>

class CGame;

/*
 * Class represents commands/actions which are executed after each iteration of the game
 */
class CAction {
public:
    /**
     * Constructor adds action (which is some lambda function) to m_Action.
     * @param[in]action
     */
    explicit CAction(std::function<void(CGame &)> action);

    /**
     * Executes m_Action, makes changes to current stage of the game.
     * @param[in,out] game
     */
    void Execute(CGame &game);

private:
    std::function<void(CGame &)> m_Action;
};

