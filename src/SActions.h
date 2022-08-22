//
// Created by marek on 5/9/2021.
//
#pragma once

#include "CAction.h"
#include "CGame.h"
#include "CPlayer.h"
#include "CZombie.h"
#include "CCoords.h"
#include "CItem.h"
#include "EDirection.h"

#include <memory>

/*
 * Class represents implementation of actions, which are executed after each game iteration.
 */
class SActions {
public:
    SActions() = delete;

    /**
     * Creates action which takes care of player's movement. Player can move to any field on map which is empty.
     * @param[in] dir 
     * @return action which, if possible, moves player in given direction
     */
    static CAction MovePlayer(EDirection dir);

    /**
     * Creates action which takes care of zombie's movement. Checks if zombie with given id was not killed in a meantime.
     * @param[in] zombieId 
     * @param[in] newPosition 
     * @return action which moves zombie to newPosition.
     */
    static CAction MoveZombie(size_t zombieId, CCoords newPosition);

    /**
     * Creates action which take care of spawning new zombies. Adds them to game.
     * @param[in] zombie 
     * @return action which spawns zombie (adds it to game).
     */
    static CAction ZombieSpawn(const std::shared_ptr<CZombie> &zombie);

    /**
     * Creates action which take care of spawning new items on map.
     * @param[in] item 
     * @param[in] position 
     * @return action which spawns items on given position.
     */
    static CAction SpawnItem(const std::shared_ptr<CItem> &item, CCoords position);

    /**
     * Creates action allowing player to pick up items from game.
     * @return action to pick up items.
     */
    static CAction PickUp();

    /**
     * Creates action which allows player to teleport to closest wall in player's direction.
     * @param[in] player 
     * @return action which teleports player.
     */
    static CAction Teleport(CPlayer &player);

    /**
     * Creates action for using active item from player's inventory.
     * @param[in] player 
     * @return action which uses active item.
     */
    static CAction UseActiveItem(CPlayer &player);

    /**
     * Creates action for switching active item to other item from player's inventory.
     * @return action which switches active item.
     */
    static CAction SwitchActiveItem();
};
