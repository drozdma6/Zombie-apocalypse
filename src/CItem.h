//
// Created by marek on 5/9/2021.
//

#pragma once

#include "CGame.h"
#include <memory>

class CGame;

/*
 * Abstract class representing all items.
 * Class CGun inherit from this class.
 */
class CItem {
public:
    CItem(char name, size_t amount);

    virtual void UseItem(CGame &game) = 0;

    size_t Amount() const;

    void AddAmount(size_t count);

    /**
     * Saves information about item to file.
     * @param[out] file 
     */
    void Save(std::ofstream &file) const;

    char GetName() const;

protected:
    char m_Name{}; //name of item
    size_t m_Amount; //ammo in gun or number of bombs
};
