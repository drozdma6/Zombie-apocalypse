//
// Created by marek on 5/4/2021.
//
#pragma once

#include "CMap.h"
#include "CItem.h"
#include "CZombie.h"
#include "CPlayer.h"

#include <vector>
#include <map>
#include <memory>

class CItem;

class CPlayer;

class CZombie;

/*
 * Class represents current game.
 */
class CGame {
public:
    /**
     * Constructor creates game, with given player, map and score.
     * @param[in] map 
     * @param[in] player 
     * @param[in] score 
     */
    CGame(CMap &map, CPlayer &player, size_t score);

    /**
     * Adds zombie to m_Zombies.
     * @param[in] zombie 
     */
    void AddZombie(const std::shared_ptr<CZombie> &zombie);

    /**
     * Removes item on certain coords.
     * @param coords 
     */
    void RemoveItem(CCoords coords);

    /**
     * Find all emptyFields in all direction from certain coord. (Fields which are empty, and without zombie or item)
     * @param[in] coord 
     * @return vector of all empty coords from coord.
     */
    std::vector<CCoords> EmptyFields(const CCoords &coord) const;

    /**
     * Finds all empty fields.
     * @return vector of all empty fields.
     */
    std::vector<CCoords> EmptyFields() const;

    /**
     * Checks if there is zombie on coords, if there is, kills him.
     * @param[in] coords 
     * @return true, if zombie was killed (erase from m_Zombies).
     */
    bool KillZombie(CCoords coords);

    /**
     * Adds item to m_Items.
     * @param[in] coords 
     * @param[in] item 
     */
    void AddItem(CCoords coords, const std::shared_ptr<CItem> &item);

    /**
     * Checks if coords are empty.
     * @param[in] coords 
     * @return true, coords are empty (there arent any zombies, player, items and the field is empty)
     */
    bool isEmpty(CCoords coords) const;

    /**
     * Saves current state of the game to file with given filename.
     * @param[in] fileName 
     */
    void Save(std::string fileName) const;

    CPlayer &GetPlayer() const;

    CMap &GetMap() const;

    std::map<CCoords, std::shared_ptr<CItem>> GetItems() const;

    std::vector<std::shared_ptr<CZombie>> GetZombies() const;

    size_t GetScore() const;

private:
    CMap &m_Map;
    std::map<CCoords, std::shared_ptr<CItem>> m_Items;
    std::vector<std::shared_ptr<CZombie>> m_Zombies;
    CPlayer &m_Player;
    size_t m_Score = 0;
};
