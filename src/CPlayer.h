//
// Created by marek on 5/4/2021.
//
#pragma once

#include "CCharacter.h"
#include "CInventory.h"
#include "SPlayerProperties.h"

#include <string>

class CInventory;

/*
 * Class represents user's character.
 */
class CPlayer : public CCharacter {
public:
    /**
     * Constructor creates with given properties, coords and direction. Allocates memory on heap for inventory.
     * @param[in] coords 
     * @param[in] dir 
     * @param[in] properties 
     */
    CPlayer(CCoords coords, EDirection dir, SPlayerProperties properties);

    /**
     * Loads all needed information to create player from file. Used, while loading previously saved game.
     * @param[in] file 
     */
    explicit CPlayer(std::ifstream &file);

    std::shared_ptr<CInventory> Inventory();

    CPlayer &MinusHealth();

    CPlayer &MinusPort();

    SPlayerProperties GetProperties() const;

    /**
     * Puts information about Player to file.
     * @param[out] file 
     */
    void Save(std::ofstream &file) const;

private:
    SPlayerProperties m_Properties;
    std::shared_ptr<CInventory> m_Inventory;
};

