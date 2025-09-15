//
// Created by G713 on 11.09.2025.
//

#pragma once
#include <vector>
#include "Game.h"

class Store {
private:
    std::vector<Game> games;

public:
    // constructor
    explicit Store(const std::vector<Game>& games);

    // destructor
    ~Store() = default;

    // crud
    void addGame(const Game& game);
    bool removeGame(const std::string& name);
    bool modifyGame(const std::string& name, double newPrice);

    // data access
    Game* getGame(const std::string& name);
    const std::vector<Game>& listGames();
    std::vector<const Game*> listGamesByCategory(const std::string& category) const;
    std::vector<Game> getMostBoughtGames(size_t topCount);

    //action
    bool buyGame(const std::string& name);

};