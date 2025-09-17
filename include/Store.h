#pragma once

#include "Game.h"
#include "Bundle.h"

#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

class Store {
private:
    std::vector<Game> games;
    std::vector<Bundle> bundles;

public:
    // "manual" constructor
    explicit Store(const std::vector<Game>& games);

    explicit Store() = default;

    // destructor
    ~Store() = default;

    // crud
    void addGame(const Game& game);
    bool removeGame(const std::string& name);
    bool modifyGame(const std::string& name, double newPrice);

    // data access
    Game* getGame(const std::string& name);
    const std::vector<Game>& listGames() const ;
    std::vector<const Game*> listGamesByCategory(const std::string& category) const;
    std::vector<Game> getMostBoughtGames(size_t topCount);
    Game* getGameByID(int ID);

    //action
    bool buyGame(const std::string& name);

    // bundle functions
    bool addBundle(const Bundle& bundle);
    bool removeBundle(const std::string& bundleName);
    const std::vector<Bundle>& listBundles() const;
    bool buyBundle(const std::string& bundleName);

    // json handling
    void saveToJSON(const std::string& path) const;
    void loadFromJSON(const std::string& path);

};