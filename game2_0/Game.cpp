#include "pch.h"
#include "Game.h"
#include "Player.h"

Game::Game(const string& name, const string& genre)
    : m_name(name), m_genre(genre), m_environment(nullptr) {}

Game::~Game() {
    for (Player* player : m_players) {
        delete player;
    }
    m_players.clear();

    for (Level* level : m_levels) {
        delete level;
    }
    m_levels.clear();

    if (m_environment != nullptr) {
        delete m_environment;
    }
    m_environment = nullptr;
}

void Game::addPlayer(Player* player) {
    m_players.push_back(player);
}


int Game::getPlayerCount() const {
    return m_players.size();
}


string Game::getName() const {
    return m_name;
}

string Game::getGenre() const {
    return m_genre;
}

void Game::start() {
    cout << "Game started!" << endl;
}

void Game::pause() {
    cout << "Paused" << endl;
}

void Game::resume() {
    cout << "Game resumed!" << endl;
}

void Game::end() {
    cout << "Game over!" << endl;
}
