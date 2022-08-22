//
// Created by marek on 6/12/2021.
//

#pragma once

#include "CItem.h"

class CBomb : public CItem {
public:
    /**
     * Call CItem constructor, where itemName is defined as B and attributes is set to 1 => Each field with Bomb adds
     * just one bomb to player's inventory.
     */
    CBomb();

    /**
     * Constructor used for loading saved games, giving player specific number of bombs.
     * @param[in] bombs 
     */
    explicit CBomb(size_t bombs);

    /**
     * Kills all zombies, that are 2 or less fields away from current player's position.
     * @param[in,out] game 
     */
    void UseItem(CGame &game) override;
};