//
// Created by marek on 5/31/2021.
//

#include "CZombieWalker.h"
#include "SActions.h"
#include "SRandom.h"

using namespace std;

CZombieWalker::CZombieWalker(CCoords coords, EDirection dir) : CZombie(coords, dir) {}

std::vector<CAction> CZombieWalker::GenerateNextActions(const CGame &game) {
    vector<CAction> actions;
    CCoords newPosition = m_Position;

    if (m_Position + m_Direction == game.GetPlayer().Coord() || game.isEmpty(m_Position + m_Direction)) {
        newPosition = m_Position + m_Direction;
    } else {
        //change zombie direction
        m_Direction = static_cast<EDirection>((static_cast<size_t>(m_Direction) + 1) % DIRECTIONS);
    }

    actions.push_back(SActions::MoveZombie(this->id, newPosition));
    return actions;
}
