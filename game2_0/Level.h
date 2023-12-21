#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <vector>

class Character;
class Item;

using namespace std;

class Level {
private:
    int m_size;
    int m_difficulty;
    vector<Character*> m_characters;
    vector<Item*> m_items;

public:
    Level(int, int);
    virtual ~Level();

    int getSize() const;
    int getDifficulty() const;

    int getCharacterCount() const;
    int getItemCount() const;

    void addCharacter(Character*);
    void removeCharacter(Character*);
    void addItem(Item*);
    void removeItem(Item*);
};

#endif
