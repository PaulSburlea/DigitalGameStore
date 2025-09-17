#pragma once

#include <vector>
#include <string>

#include "Game.h"
#include "Store.h"

class User {
private:
    std::string username;
    double consoleStorage;
    std::vector<Game> boughtGames;

public:
    // constructor
    explicit User(std::string username);

    // destructor
    ~User() = default;


    // user methods
    bool buyGame(const std::string& gameName, Store& store);
    bool buyBundle(const std::string& bundleName, Store& store);
    bool installGame(const std::string& gameName);
    bool uninstallGame(const std::string& gameName);
    const std::vector<Game>& listPurchasedGames();
    std::vector<Game> listInstalledGames();

};
