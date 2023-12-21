#include "pch.h"
#include "Item.h"

Item::Item(const string& name, int weight, int cost) :
	m_name(name), m_weight(weight), m_cost(cost) {}

Item::~Item() {}

string Item::getName() const {
	return m_name;
}

int Item::getWeight() const {
	return m_weight;
}

int Item::getCost() const {
	return m_cost;
}
