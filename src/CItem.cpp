//
// Created by marek on 6/12/2021.
//

#include "CItem.h"

CItem::CItem(char name, size_t amount) : m_Name(name), m_Amount(amount) {}

char CItem::GetName() const {
    return m_Name;
}

size_t CItem::Amount() const {
    return m_Amount;
}

void CItem::AddAmount(size_t count) {
    m_Amount += count;
}

void CItem::Save(std::ofstream &file) const {
    file << m_Name << ' ' << m_Amount << std::endl;
}




