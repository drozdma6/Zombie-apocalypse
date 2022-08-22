//
// Created by marek on 5/5/2021.
//
#pragma once

#include "CItem.h"

#include <memory>
#include <map>

class CItem;

class CInventory {
public:
    /**
     * Add item to inventory and set active item, if there wasn't any item in inventory before. If given item is already
     * in inventory, add it's attributes, to owned item.
     * @param[in] item 
     */
    void AddItem(const std::shared_ptr<CItem> &item);

    /**
     * Checks if m_items is empty
     * @return true, if m_items is empty
     */
    bool EmptyItems() const;

    /**
     * Drops item, sets new activeItem, if dropping current active item.
     * @param name 
     */
    void DropItem(char name);

    /**
     * Save information about player's inventory to file.
     * @param[out] file 
     */
    void Save(std::ofstream &file) const;

    /**
     * If there is any other item in inventory, set some of them as active.
     */
    void NextActiveItem();

    std::map<char, std::shared_ptr<CItem>> GetItems() const;

    std::shared_ptr<CItem> GetActiveItem() const;

    /**
     * Set item with given item name from m_Items as active item.
     * @param[in] itemName 
     */
    void SetActiveItem(char itemName);

private:
    std::map<char, std::shared_ptr<CItem>> m_Items;
    std::shared_ptr<CItem> m_ActiveItem;
};