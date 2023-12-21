#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "Item.h"

class Weapon : public Item {
private:
    int m_damage;

public:
    Weapon(const string&, int, int, int);
    virtual ~Weapon();

    int getDamage() const;
};

#endif
