#include "pch.h"
#include "Armor.h"

Armor::Armor(const string& name, int weight, int cost, int defense) :
	Item(name, weight, cost), m_defense(defense) {}

Armor::~Armor() {}

int Armor::getDefense() const {
	return m_defense;
}
