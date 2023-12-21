#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>

class Character;
class Item;

using namespace std;

class Player {
private:
    string m_name;
    int m_level;
    Character* m_character;
    vector<Item*> m_inventory;
    vector<Item*> m_equippedItems;

public:
    Player(const string&, int);
    virtual ~Player();

    string getName() const;
    int getLevel() const;
    vector<Item*> getEquippedItems() const;
    vector<Item*> getInventory() const;

    void levelUp();
    void addItem(Item*);
    void removeItem(Item*);
    void equipItem(Item*);
    void unequipItem(Item*);
};

#endif
