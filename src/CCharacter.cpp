//
//
// Created by marek on 5/31/2021.

#include "CCharacter.h"

size_t CCharacter::nextId = 0;

CCharacter::CCharacter() : id(CCharacter::nextId++) {}

CCharacter::CCharacter(CCoords pos, EDirection dir) : m_Position(pos), m_Direction(dir), id(CCharacter::nextId++) {}

CCharacter &CCharacter::Coord(CCoords newCoord) {
    m_Position = newCoord;
    return *this;
}

const CCoords &CCharacter::Coord() const {
    return m_Position;
}

EDirection CCharacter::Direction() const {
    return m_Direction;
}

void CCharacter::SetDirection(EDirection dir) {
    m_Direction = dir;
}

size_t CCharacter::GetId() const {
    return id;
}
