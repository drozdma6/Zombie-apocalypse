//
// Created by marek on 5/31/2021.
//

#include "CPlayer.h"
#include "CGun.h"
#include "CBomb.h"

#include <stdexcept>

using namespace std;

CPlayer::CPlayer(CCoords coords, EDirection dir, SPlayerProperties properties) :
        CCharacter(coords, dir),
        m_Properties(std::move(properties)) {
    m_Inventory = std::make_shared<CInventory>();
}

CPlayer::CPlayer(std::ifstream &file) : CCharacter() {
    size_t dir, itemsCount, attributes;
    char itemName, activeItem;
    //read properties
    file >> m_Properties.m_Name >> m_Properties.m_Health >> m_Properties.m_Ports;
    if (file.get() != '\n') {
        throw runtime_error("Unexpected problem with loading player's properties.");
    }
    //read position, direction
    file >> m_Position.m_X >> m_Position.m_Y >> dir;
    m_Direction = static_cast<EDirection> (dir);

    if (file.get() != '\n') {
        throw runtime_error("Unexpected problem while loading player and his inventory.");
    }
    //allocate memory for inventory
    m_Inventory = std::make_shared<CInventory>();
    //get active item
    file >> itemsCount;
    if (itemsCount > 0) {
        file >> activeItem;
    }
    if (file.get() != '\n') {
        throw runtime_error("Unexpected problem while loading player and his inventory.");
    }
    //fill inventory
    for (size_t i = 0; i < itemsCount; ++i) {
        file >> itemName >> attributes;
        if (file.get() != '\n') {
            throw runtime_error("Unexpected problem while loading player and his inventory.");
        }
        if (itemName == 'G') {
            m_Inventory->AddItem(make_shared<CGun>(attributes));
        } else if (itemName == 'B') {
            m_Inventory->AddItem(make_shared<CBomb>(attributes));
        }
    }
    if (itemsCount > 0) {
        m_Inventory->SetActiveItem(activeItem);
    }
}

CPlayer &CPlayer::MinusHealth() {
    m_Properties.m_Health--;
    return *this;
}

SPlayerProperties CPlayer::GetProperties() const {
    return m_Properties;
}

std::shared_ptr<CInventory> CPlayer::Inventory() {
    return m_Inventory;
}

CPlayer &CPlayer::MinusPort() {
    m_Properties.m_Ports--;
    return *this;
}

void CPlayer::Save(std::ofstream &file) const {
    file << m_Properties.m_Name << ' ' << m_Properties.m_Health << ' ' << m_Properties.m_Ports << std::endl;
    file << m_Position.m_X << ' ' << m_Position.m_Y << ' ' << static_cast<int>(m_Direction) << std::endl;
    m_Inventory->Save(file);
}





