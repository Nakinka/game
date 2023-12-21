#include "pch.h"
#include "Enemy.h"

Enemy::Enemy(const string& name, int health, int strength, int agility, int experience) :
	Character(name, health, strength, agility), m_experience(experience) {}

Enemy::~Enemy() {}

int Enemy::getExperience() const
{
	return m_experience;
}

void Enemy::dropLoot() const {
	cout << "Enemy " << getName() << " dropped some loot!" << endl;
}