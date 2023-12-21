#ifndef ARMOR_HPP
#define ARMOR_HPP

#include "Item.h"

class Armor : public Item {
private:
    int m_defense;

public:
    Armor(const string&, int, int, int);
    virtual ~Armor();

    int getDefense() const;
};
#endif