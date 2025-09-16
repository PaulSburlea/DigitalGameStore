//
// Created by G713 on 11.09.2025.
//

#pragma once
#include <vector>
#include "Game.h"
#include "Bundle.h"

class Store {
private:
    std::vector<Game> games;
    std::vector<Bundle> bundles;

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
    [[nodiscard]] std::vector<const Game*> listGamesByCategory(const std::string& category) const;
    std::vector<Game> getMostBoughtGames(size_t topCount);

    //action
    bool buyGame(const std::string& name);

    // bundle functions
    bool addBundle(const Bundle& bundle);
    bool removeBundle(const std::string& bundleName);
    [[nodiscard]] const std::vector<Bundle>& listBundles() const;
    bool buyBundle(const std::string& bundleName);

};