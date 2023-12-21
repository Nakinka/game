#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Character.h"

class Enemy : public Character {
private:
    int m_experience;

public:
    Enemy(const string&, int, int, int, int);
    virtual ~Enemy();
    int getExperience() const;

    void dropLoot() const;

};
#endif


