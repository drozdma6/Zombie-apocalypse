//
// Created by marek on 6/4/2021.
//

#include "CInventory.h"

void CInventory::AddItem(const std::shared_ptr<CItem> &item) {
    auto it = m_Items.find(item->GetName());
    if (m_Items.empty()) {
        m_ActiveItem = item;
    }
    if (it == m_Items.end()) {
        m_Items.insert(std::pair<char, std::shared_ptr<CItem>>(item->GetName(), item));
    } else {
        it->second->AddAmount(item->Amount());
    }
}

bool CInventory::EmptyItems() const {
    return m_Items.empty();
}

std::shared_ptr<CItem> CInventory::GetActiveItem() const {
    return m_ActiveItem;
}

void CInventory::DropItem(char name) {
    m_Items.erase(name);
    if (m_ActiveItem->GetName() == name) {
        if (EmptyItems()) {
            m_ActiveItem = nullptr;
        } else {
            m_ActiveItem = m_Items.begin()->second;
        }
    }
}

void CInventory::Save(std::ofstream &file) const {
    if (m_Items.empty()) {
        file << 0 << std::endl;
        return;
    }
    file << m_Items.size() << ' ' << m_ActiveItem->GetName() << std::endl;

    for (const auto &elem : m_Items) {
        elem.second->Save(file);
    }
}

std::map<char, std::shared_ptr<CItem>> CInventory::GetItems() const {
    return m_Items;
}

void CInventory::NextActiveItem() {
    if (m_ActiveItem == nullptr) {
        return;
    }
    auto it = m_Items.find(m_ActiveItem->GetName());
    it++;
    if (it == m_Items.end()) {
        it = m_Items.begin();
    }
    m_ActiveItem = it->second;
}

void CInventory::SetActiveItem(char itemName) {
    m_ActiveItem = m_Items[itemName];
}
