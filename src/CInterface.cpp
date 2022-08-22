//
// Created by marek on 5/31/2021.
//

#include "CInterface.h"

#include <limits>
#include <string>
#include <vector>

using namespace std;

//highest number of points user can divide into health and ports
constexpr static size_t MAX_PROPERTIES_POINTS = 10;

CInterface::CInterface(std::istream &in, std::ostream &out) : m_In(in), m_Out(out) {}


void CInterface::ClearInput() {
    //clears input stream
    m_In.clear();
    m_In.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

EApplicationInputs CInterface::PromptApplicationInput() {
    string command;
    m_Out << "Welcome to Zombie Apocalypse, do you want to start a new game or load previous? [new, load, quit]"
          << endl;
    if (!(m_In >> command)) {
        throw runtime_error("Wrong application command.");
    }
    ClearInput();
    if (command == "new") return EApplicationInputs::newGame;
    else if (command == "load") return EApplicationInputs::load;
    else if (command == "quit") return EApplicationInputs::quit;
    else {
        throw runtime_error("Wrong application command.");
    }
}

EGameInputs CInterface::PromptGameInput() {
    char input;
    m_In >> input;
    ClearInput();
    switch (input) {
        case 'w':
            return EGameInputs::move_up;
        case 's':
            return EGameInputs::move_down;
        case 'a':
            return EGameInputs::move_left;
        case 'd':
            return EGameInputs::move_right;
        case 'f':
            return EGameInputs::use_item;
        case 'p':
            return EGameInputs::teleport;
        case 'q':
            return EGameInputs::quit;
        case 'e':
            return EGameInputs::switch_item;
        default:
            throw runtime_error("Wrong game command.");
    }
}

void CInterface::DrawGame(const CGame &game) {
    //print first line
    m_Out << "+";
    for (size_t i = 0; i < game.GetMap().Width(); i++) {
        m_Out << "-";
    }
    m_Out << "+" << endl;

    vector<vector<char>> buffer(game.GetMap().Height(), vector<char>(game.GetMap().Width()));
    //Inserting information about current game to buffer.
    //Map
    for (size_t i = 0; i < game.GetMap().Height(); i++) {
        for (size_t j = 0; j < game.GetMap().Width(); j++) {
            buffer[i][j] = (char) game.GetMap()[i][j];
        }
    }

    //Zombies
    for (auto const &elem : game.GetZombies()) {
        buffer[elem->Coord().m_Y][elem->Coord().m_X] = 'Z';
    }

    //Items
    for (auto const &item : game.GetItems()) {
        buffer[item.first.m_Y][item.first.m_X] = item.second->GetName();
    }

    //Player
    char player;
    EDirection playerDir = game.GetPlayer().Direction();
    switch (playerDir) {
        case EDirection::LEFT:
            player = '<';
            break;
        case EDirection::RIGHT:
            player = '>';
            break;
        case EDirection::UP:
            player = '^';
            break;
        case EDirection::DOWN:
            player = 'v';
            break;
    }
    //add player to buffer
    buffer[game.GetPlayer().Coord().m_Y][game.GetPlayer().Coord().m_X] = player;

    //print buffer
    for (const auto &line : buffer) {
        m_Out << "|";
        for (char field : line) {
            m_Out << field;
        }
        m_Out << "|" << endl;
    }
    //print last line
    m_Out << "+";
    for (size_t i = 0; i < game.GetMap().Width(); i++) {
        m_Out << "-";
    }
    m_Out << "+" << endl;

    //print score
    m_Out << "Score: " << game.GetScore() << endl;

    m_Out << "Health: " << game.GetPlayer().GetProperties().m_Health << " Ports: "
          << game.GetPlayer().GetProperties().m_Ports << endl;

    //print player's inventory and his active item
    for (const auto &elem : game.GetPlayer().Inventory()->GetItems()) {
        m_Out << elem.first << ' ' << elem.second->Amount();
        if (game.GetPlayer().Inventory()->GetActiveItem()->GetName() == elem.first) {
            m_Out << "<--";
        }
        m_Out << endl;
    }
}


SPlayerProperties CInterface::PromptPlayerProperties() {
    SPlayerProperties properties;
    m_Out << "Player properties. (name health port)" << endl << "You can divide only " << MAX_PROPERTIES_POINTS
          << " points between health and ports." << endl;
    if (!(m_In >> properties.m_Name >> properties.m_Health >> properties.m_Ports)) {
        throw runtime_error("Failed to load player's properties.");
    }
    if (properties.m_Health + properties.m_Ports > 10) {
        throw runtime_error("Given maximum of points to be divided into Health and Ports was exceeded.");
    }
    ClearInput();
    return properties;
}

void CInterface::ZombieAttack() {
    m_Out << "Zombie attacked!!!" << endl;
}

std::string CInterface::PromptFileName() {
    string fileName;
    m_Out << "File name: " << endl;
    if (!getline(m_In, fileName)) {
        throw runtime_error("Unexpected error during input of map filename.");
    }
    return fileName;
}

bool CInterface::PromptSave() {
    string str;
    m_Out << "Do you want to save game? [yes, no]" << endl;
    m_In >> str;
    ClearInput();
    if (str == "yes" || str == "y")
        return true;
    else if (str == "no" || str == "n")
        return false;
    else {
        throw runtime_error("Wrong input for saving file.");
    }

}

void CInterface::PlayerDied() {
    m_Out << "ZOMBIES WON, you died." << endl;
}

std::size_t CInterface::PromptMap() {
    size_t map;
    m_Out << "Choose map: (number between 1-5)" << endl;
    if (!(m_In >> map) || map > 5 || map < 1) {
        throw runtime_error("Wrong number for loading map.");
    }
    ClearInput();
    return map;
}
