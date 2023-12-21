#include "pch.h"
#include "Character.h"
#include "Item.h"

Character::Character(const string& name, int health, int strength, int agility) : m_name(name), m_health(health), m_strength(strength), m_agility(agility) {}

Character::~Character() {}

string Character::getName() const {
	return m_name;
}

int Character::getHealth() const {
	return m_health;
}

int Character::getStrength() const {
	return m_strength;
}

int Character::getAgility() const {
	return m_agility;
}

void Character::takeDamage(int damage) {
	m_health -= damage;
	if (m_health < 0) {
		m_health = 0;
	}
}

void Character::heal(int amount) {
	m_health += amount;
}

void Character::attack(Character* target) {
	target->takeDamage(m_strength);
}

void Character::useItem(Item* item) {
	takeDamage(item->getCost());
}
