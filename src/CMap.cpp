//
// Created by marek on 5/31/2021.
//

#include "CMap.h"

#include <stdexcept>

using namespace std;

CMap::CMap(std::ifstream &file) {
    size_t Height, Width;
    //load height and width of map
    if (!(file >> Height >> Width) || file.get() != '\n') {
        throw runtime_error("Unable to read dimension of map.");
    }
    vector<vector<EField>> vectorMap;
    //fill vectorMap
    for (size_t j = 0; j < Height; ++j) {
        vector<EField> tmp;
        for (size_t i = 0; i < Width; ++i) {
            char pos = file.get();
            switch (pos) {
                case ' ':
                    tmp.push_back(EField::EMPTY);
                    continue;
                case '#':
                    tmp.push_back(EField::WALL);
                    continue;
                case '+':
                    tmp.push_back(EField::ZOMBIE_SPAWN);
                    continue;
                default:
                    throw runtime_error("Unreadable character in file.");
            }
        }
        if (file.get() != '\n') {
            throw runtime_error("Unexpected problem with map loading.");
        }
        vectorMap.push_back(tmp);
    }
    m_Map = vectorMap;
}

bool CMap::isInside(const CCoords &coord) const {
    if (m_Map.empty() || coord.m_Y >= m_Map.size() || coord.m_X >= m_Map[0].size())
        return false;
    return true;
}

EField CMap::Field(const CCoords &coord) const {
    return m_Map[coord.m_Y][coord.m_X];
}

size_t CMap::Height() const {
    return m_Map.size();
}

size_t CMap::Width() const {
    if (m_Map.empty())
        return 0;
    return m_Map[0].size();
}

bool CMap::isEmpty(const CCoords &coord) const {
    if (!isInside(coord) || Field(coord) != EField::EMPTY)
        return false;
    return true;
}


std::vector<CCoords> CMap::ZombieSpawns() const {
    std::vector<CCoords> zombieSpawns;
    //find all '+' in map
    for (size_t i = 0; i < Height(); ++i) {
        for (size_t j = 0; j < Width(); ++j) {
            if (Field({j, i}) == EField::ZOMBIE_SPAWN)
                zombieSpawns.push_back({j, i});
        }
    }
    return zombieSpawns;
}

std::vector<EField> CMap::operator[](size_t index) {
    return m_Map[index];
}

void CMap::Save(std::ofstream &file) const {
    file << Height() << ' ' << Width() << std::endl;

    for (size_t i = 0; i < Height(); i++) {
        for (size_t j = 0; j < Width(); j++) {
            file << static_cast<char>(m_Map[i][j]);
        }
        file << std::endl;
    }
}

std::vector<CCoords> CMap::EmptyFields() const {
    std::vector<CCoords> emptyFields;
    for (size_t i = 0; i < Height(); ++i) {
        for (size_t j = 0; j < Width(); ++j) {
            if (isEmpty({j, i})) {
                emptyFields.push_back({j, i});
            }
        }
    }
    return emptyFields;
}
