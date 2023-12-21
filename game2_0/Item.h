#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

using namespace std;

using namespace std;

class Item {
private:
    string m_name;
    int m_weight;
    int m_cost;

public:
    Item(const string&, int, int);
    virtual ~Item();

    string getName() const;
    int getWeight() const;
    int getCost() const;
};
#endif
