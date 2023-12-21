#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

using namespace std;

class Item;

class Character {
private:
    string m_name;
    int m_health;
    int m_strength;
    int m_agility;

public:
    Character(const string&, int, int, int);
    virtual ~Character();

    string getName() const;
    int getHealth() const;
    int getStrength() const;
    int getAgility() const;

    void takeDamage(int);
    void heal(int);
    void attack(Character*);
    void useItem(Item*);
};
#endif
