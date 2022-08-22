//
// Created by marek on 5/4/2021.
//
#pragma once

#include "CItem.h"
#include "CGame.h"

#include <memory>

class CGun : public CItem {
public:
    /**
     * Constructor calls CItem constructor with item name G and amount equal to 3 -> Each gun field on map adds 3
     * ammunition to gun.
     */
    CGun();

    /**
     * Constructor calls CItem constructor with item name G and amount equal to given ammo. Used for loading previously
     * saved games.
     * @param ammo
     */
    explicit CGun(size_t ammo);

    /**
     * Shoots from the gun, in player's current direction. If bullet hits zombie before it hits a wall, it kills a zombie.
     * @param[in] game 
     */
    void UseItem(CGame &game) override;
};
