//
// Created by marek on 5/4/2021.
//
#pragma once

#include "EDirection.h"

struct CCoords {
    size_t m_X;
    size_t m_Y;

    /**
     * @param[in] coord 
     * @param[in] direction 
     * @return coords of next field in asked direction
     */
    friend CCoords operator+(const CCoords &coord, EDirection direction);

    /**
     * Compares two coords
     * @param[in] lhs 
     * @param[in] rhs 
     * @return true if lhs is higher than rhs, or if lhs is to the left from rhs.
     */
    friend bool operator<(const CCoords &lhs, const CCoords &rhs);

    /**
     * Decides if two coords are equal.
     * @param[in] first 
     * @param[in] second 
     * @return true if both m_X and m_Y are equal, else false.
     */
    friend bool operator==(const CCoords &first, const CCoords &second);
};
