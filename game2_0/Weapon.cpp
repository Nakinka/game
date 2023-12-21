#include "pch.h"
#include "Weapon.h"

Weapon::Weapon(const string& name, int weight, int cost, int damage) :
	Item(name, weight, cost), m_damage(damage) {}

Weapon::~Weapon() {}

int Weapon::getDamage() const {
	return m_damage;
}
