#ifndef NPC_HPP
#define NPC_HPP

#include "Character.h"

class NPC : public Character {
private:
    string m_dialogue;

public:
    NPC(const string&, int, int, int, const string&);
    virtual ~NPC();

    void talk();
    void trade();

};

#endif
