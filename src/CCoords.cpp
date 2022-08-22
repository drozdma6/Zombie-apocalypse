//
// Created by marek on 5/31/2021.
//

#include "CCoords.h"
#include <stdexcept>

CCoords operator+(const CCoords &coord, EDirection direction) {
    switch (direction) {
        case EDirection::UP:
            return {coord.m_X, coord.m_Y - 1};
        case EDirection::DOWN:
            return {coord.m_X, coord.m_Y + 1};
        case EDirection::LEFT:
            return {coord.m_X - 1, coord.m_Y};
        case EDirection::RIGHT:
            return {coord.m_X + 1, coord.m_Y};
        default:
            throw std::logic_error("Unknown direction");
    }
}

bool operator==(const CCoords &first, const CCoords &second) {
    return ((first.m_X == second.m_X) && (first.m_Y == second.m_Y));
}

bool operator<(const CCoords &lhs, const CCoords &rhs) {
    if (lhs.m_Y < rhs.m_Y)
        return true;
    if (lhs.m_Y == rhs.m_Y && lhs.m_X < rhs.m_X)
        return true;
    return false;
}
