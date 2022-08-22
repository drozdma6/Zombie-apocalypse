//
// Created by marek on 5/4/2021.
//
#pragma once

#include "CCoords.h"
#include "EDirection.h"

#include <memory>

/*
 * Class represents all characters that are present in current game.
 * Player and zombie inherit from this class.
 */
class CCharacter {
public:
    /**
     * Constructor, sets id to nextId + 1, so each character will keep unique id.
     */
    CCharacter();

    /**
     * Constructor, sets id to nextId + 1, so each character will keep unique id. Creates character on given coords with
     * given direction. 
     * @param[in] pos 
     * @param[in] dir 
     */
    CCharacter(CCoords pos, EDirection dir);

    /**
     * @return current position of character. 
     */
    const CCoords &Coord() const;

    /**
     * Sets character position to new Positon.
     * @param[in] newCoord 
     * @return reference to CCharacter
     */
    CCharacter &Coord(CCoords newCoord);

    EDirection Direction() const;

    /**
     * Set character direction to given direction.
     * @param[in] dir 
     */
    void SetDirection(EDirection dir);

    /**
     * @return characters unique id. 
     */
    size_t GetId() const;

protected:
    CCoords m_Position{};
    EDirection m_Direction;
    size_t id;
private:
    //for creating ids of next characters.
    static size_t nextId;
};


