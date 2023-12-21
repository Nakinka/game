#include "pch.h"
#include "Level.h"

Level::Level(int size, int difficulty) :
    m_size(size), m_difficulty(difficulty) {}

Level::~Level() {
    for (Character* character : m_characters) {
        delete character;
    }
    for (Item* item : m_items) {
        delete item;
    }
}

int Level::getSize() const {
    return m_size;
}

int Level::getDifficulty() const {
    return m_difficulty;
}

int Level::getCharacterCount() const {
    return m_characters.size();
}

int Level::getItemCount() const {
    return m_items.size();
}


void Level::addCharacter(Character* character) {
    m_characters.push_back(character);
}

void Level::removeCharacter(Character* character) {
    m_characters.erase(remove(m_characters.begin(), m_characters.end(), character), m_characters.end());
}

void Level::addItem(Item* item) {
    m_items.push_back(item);
}

void Level::removeItem(Item* item) {
    m_items.erase(remove(m_items.begin(), m_items.end(), item), m_items.end());
}
