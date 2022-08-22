//
// Created by marek on 5/31/2021.
//

#include "CExecutor.h"
#include "SActions.h"

CExecutor::CExecutor(std::shared_ptr<CInterface> interface, CGame &game) : m_Interface(std::move(interface)),
                                                                           m_Game(game) {}


void CExecutor::Run() {
    while (m_Running) {
        //check collisions with zombies, kills zombie on player's position.
        if (m_Game.KillZombie(m_Game.GetPlayer().Coord())) {
            m_Game.GetPlayer().MinusHealth();
            m_Interface->ZombieAttack();
        }
        m_Interface->DrawGame(m_Game);
        if (m_Game.GetPlayer().GetProperties().m_Health == 0) {
            m_Interface->PlayerDied();
            break;
        }
        //clear actions from previous game iteration
        ClearActions();

        //add player-based actions
        AddActions();

        //add zombie movement to game actions
        for (const auto &zombie : m_Game.GetZombies()) {
            for (const auto &zombieMovement : zombie->GenerateNextActions(m_Game)) {
                m_Actions.push_back(zombieMovement);
            }
        }
        //add generator actions to game actions
        for (auto &m_Generator : m_Generators) {
            for (const auto &elem : m_Generator->GenerateNextActions(m_Game)) {
                m_Actions.push_back(elem);
            }
        }
        ExecuteStep();
    }
}

CExecutor &CExecutor::RegisterGenerator(const std::shared_ptr<CActionGenerator> &generator) {
    m_Generators.push_back(generator);
    return *this;
}

void CExecutor::Quit() {
    m_Running = false;
    if (m_Interface->PromptSave()) {
        m_Game.Save(m_Interface->PromptFileName());
    }
}

void CExecutor::AddActions() {
    switch (m_Interface->PromptGameInput()) {
        case EGameInputs::move_down:
            m_Game.GetPlayer().SetDirection(EDirection::DOWN);
            m_Actions.push_back(SActions::MovePlayer(EDirection::DOWN));
            break;
        case EGameInputs::move_up:
            m_Game.GetPlayer().SetDirection(EDirection::UP);
            m_Actions.push_back(SActions::MovePlayer(EDirection::UP));
            break;
        case EGameInputs::move_left:
            m_Game.GetPlayer().SetDirection(EDirection::LEFT);
            m_Actions.push_back(SActions::MovePlayer(EDirection::LEFT));
            break;
        case EGameInputs::move_right:
            m_Game.GetPlayer().SetDirection(EDirection::RIGHT);
            m_Actions.push_back(SActions::MovePlayer(EDirection::RIGHT));
            break;
        case EGameInputs::teleport:
            m_Actions.push_back(SActions::Teleport(m_Game.GetPlayer()));
            break;
        case EGameInputs::use_item:
            m_Actions.push_back(SActions::UseActiveItem(m_Game.GetPlayer()));
            break;
        case EGameInputs::switch_item:
            m_Actions.push_back(SActions::SwitchActiveItem());
            break;
        case EGameInputs::quit:
            Quit();
            break;
    }
    //checks if players is standing on some item.
    m_Actions.push_back(SActions::PickUp());
}

void CExecutor::ExecuteStep() {
    //runs all actions
    for (auto action : m_Actions) {
        action.Execute(m_Game);
    }
}

void CExecutor::ClearActions() {
    m_Actions.clear();
}




