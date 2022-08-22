//
// Created by marek on 5/4/2021.
//
#pragma once

#include <cstddef>

//variable is used for turning zombies
constexpr const size_t DIRECTIONS = 4;

/**
 * Direction for characters.
 */
enum class EDirection : size_t {
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3,
};
