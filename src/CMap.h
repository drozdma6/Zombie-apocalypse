//
// Created by marek on 5/4/2021.
//
#pragma once

#include "EField.h"
#include "CCoords.h"

#include <vector>
#include <fstream>

class CMap {
public:
    /**
     * Constructor used for loading map from previously saved game.
     * @param[in] file 
     */
    explicit CMap(std::ifstream &file);

    /**
     * Decides if given coords are inside map.
     * @param[in] coord 
     * @return true, if given coords are inside map, false otherwise.
     */
    bool isInside(const CCoords &coord) const;

    /**
     * Checks if EField on given coord is empty.
     * @param[in] coord 
     * @return true, coord is inside our map, and if the field is empty (there isn't wall or zombie spawn)
     */
    bool isEmpty(const CCoords &coord) const;

    /**
     * Gets field on given coords.
     * @param[in] coord 
     * @return field, which is on given coord.
     */
    EField Field(const CCoords &coord) const;

    size_t Height() const;

    size_t Width() const;

    /**
     * Finds all zombie spawns in our map.
     * @return vector, which contains coords of all zombie spawns
     */
    std::vector<CCoords> ZombieSpawns() const;

    /**
     * Access element on given index.
     * @param[in] index
     * @return vector of efield on position index in m_Map
     */
    std::vector<EField> operator[](size_t index);

    /**
     * Finds all empty fields in map.
     * @return coords of all empty fields.
     */
    std::vector<CCoords> EmptyFields() const;

    /**
     * Puts information about map to stream.
     * @param[out] file 
     */
    void Save(std::ofstream &file) const;


private:
    std::vector<std::vector<EField>> m_Map;
};

