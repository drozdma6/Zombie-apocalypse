//
// Created by marek on 5/9/2021.
//
#pragma once

#include "CGame.h"
#include "CAction.h"
#include <vector>

class CAction;

/*
 * Abstract class for generators.
 * Generators are changing the game independently from user input.
 */
class CActionGenerator {
public:
    /**
     * Abstract method which creates vector of Actions, which are supposed to be executed in next iteration of the game.
     */
    virtual std::vector<CAction> GenerateNextActions(const CGame &game) = 0;
};