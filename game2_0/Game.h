#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>

class Player;
class Level;
class Environment;

using namespace std;

class Game {
private:
    string m_name;
    string m_genre;
    vector<Player*> m_players;
    vector<Level*> m_levels;
    Environment* m_environment;

public:
    Game(const string&, const string&);
    virtual ~Game();

    void addPlayer(Player*);

    int getPlayerCount() const;
    string getName() const;
    string getGenre() const;

    void start();
    void pause();
    void resume();
    void end();
};

#endif
