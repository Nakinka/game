#include "pch.h"
#include "NPC.h"

NPC::NPC(const string& name, int health, int strength, int agility, const string& dialogue) :
	Character(name, health, strength, agility), m_dialogue(dialogue) {}

NPC::~NPC() {}

void NPC::talk() {
	cout << "NPC says: " << m_dialogue << endl;
}

void NPC::trade() {
	cout << "NPC " << getName() << " offers a trade!" << endl;
}
