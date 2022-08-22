//
// Created by marek on 5/8/2021.
//
#pragma once

/*
 * Class represents all game inputs from user.
 */
enum class EGameInputs : char {
    move_left = 'a',
    move_right = 'd',
    move_up = 'w',
    move_down = 's',
    teleport = 'k',
    quit = 'q',
    use_item = 'f',
    switch_item = 'e'
};
