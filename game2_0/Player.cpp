#include "pch.h"
#include "Player.h"

Player::Player(const string& name, int level) :
    m_name(name), m_level(level), m_character(nullptr) {}

Player::~Player() {
    for (Item* item : m_inventory) {
        delete item;
    }
    if (m_character != nullptr) {
        delete m_character;
    }
}

string Player::getName() const {
    return m_name;
}

int Player::getLevel() const {
    return m_level;
}

vector<Item*> Player::getEquippedItems() const {
    return m_equippedItems;
}

vector<Item*> Player::getInventory() const {
    return m_inventory;
}

void Player::levelUp() {
    ++m_level;
}

void Player::addItem(Item* item) {
    m_inventory.push_back(item);
}

void Player::removeItem(Item* item) {
    m_inventory.erase(remove(m_inventory.begin(), m_inventory.end(), item), m_inventory.end());
}

void Player::equipItem(Item* item) {
    m_equippedItems.push_back(item);
}

void Player::unequipItem(Item* item) {
    m_equippedItems.erase(remove(m_equippedItems.begin(), m_equippedItems.end(), item), m_equippedItems.end());
}
