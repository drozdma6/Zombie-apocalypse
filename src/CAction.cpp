//
// Created by marek on 6/1/2021.
//

#include "CAction.h"

CAction::CAction(std::function<void(CGame &)> action) : m_Action(std::move(action)) {}

void CAction::Execute(CGame &game) {
    m_Action(game);
}


