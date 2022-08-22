//
// Created by marek on 5/31/2021.
//

#include "CGame.h"

#include <iostream>
#include <cstring>


using namespace std;


CGame::CGame(CMap &map, CPlayer &player, size_t score) : m_Map(map), m_Player(player), m_Score(score) {}

CMap &CGame::GetMap() const {
    return m_Map;
}

CPlayer &CGame::GetPlayer() const {
    return m_Player;
}

void CGame::AddZombie(const shared_ptr<CZombie> &zombie) {
    m_Zombies.push_back(zombie);
}

std::vector<CCoords> CGame::EmptyFields(const CCoords &coord) const {
    std::vector<CCoords> vec;
    if (isEmpty(coord + EDirection::LEFT))
        vec.push_back(coord + EDirection::LEFT);
    if (isEmpty(coord + EDirection::RIGHT))
        vec.push_back(coord + EDirection::RIGHT);
    if (isEmpty(coord + EDirection::UP))
        vec.push_back(coord + EDirection::UP);
    if (isEmpty(coord + EDirection::DOWN))
        vec.push_back(coord + EDirection::DOWN);
    return vec;
}

vector<shared_ptr<CZombie>> CGame::GetZombies() const {
    return m_Zombies;
}

bool CGame::KillZombie(CCoords coords) {
    for (size_t i = 0; i < m_Zombies.size(); ++i) {
        if (m_Zombies[i]->Coord() == coords) {
            m_Zombies.erase(i + m_Zombies.begin());
            m_Score++;
            return true;
        }
    }
    return false;

}

void CGame::AddItem(CCoords coords, const shared_ptr<CItem> &item) {
    m_Items.insert(pair<CCoords, shared_ptr<CItem>>(coords, item));
}

vector<CCoords> CGame::EmptyFields() const {
    vector<CCoords> emptyFields;
    //loop through all fields on map, checks whether they are empty
    for (size_t i = 0; i < m_Map.Height(); ++i) {
        for (size_t j = 0; j < m_Map.Width(); ++j) {
            if (isEmpty({j, i})) {
                emptyFields.push_back({j, i});
            }
        }
    }
    return emptyFields;
}

map<CCoords, shared_ptr<CItem>> CGame::GetItems() const {
    return m_Items;
}

bool CGame::isEmpty(CCoords coords) const {
    //on given coord isn't player/zombie/item/wall
    if (!m_Map.isEmpty(coords) || m_Items.count(coords) == 1 || m_Player.Coord() == coords) {
        return false;
    }
    for (const auto &zombie : m_Zombies) {
        if (zombie->Coord() == coords)
            return false;
    }
    return true;
}

void CGame::RemoveItem(CCoords coords) {
    m_Items.erase(coords);
}

void CGame::Save(std::string fileName) const {
    ofstream file;
    file.open(&fileName[0], ios::out);
    if (!file) {
        throw runtime_error("Failed to create file");
    }
    //insert information about map to file
    m_Map.Save(file);

    //insert information about player to file
    m_Player.Save(file);

    //insert current score to file
    file << m_Score << std::endl;

    //insert information about all zombies to file
    file << m_Zombies.size() << std::endl;
    for (const auto &zombie : m_Zombies) {
        file << zombie->Coord().m_X << ' ' << zombie->Coord().m_Y << std::endl;
    }
    //insert information about all spawned items
    file << m_Items.size() << std::endl;
    for (const auto &item : m_Items) {
        file << item.second->GetName() << ' ' << item.first.m_X << ' ' << item.first.m_Y << std::endl;
    }
    file.close();
}

size_t CGame::GetScore() const {
    return m_Score;
}
