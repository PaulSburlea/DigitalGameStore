//
// Created by G713 on 11.09.2025.
//

#pragma once
#include <vector>
#include "Game.h"

class Bundle {
private:
    std::string bundleName;
    std::vector<Game> bundleGames;
    double price;

public:
    // constructor
    explicit Bundle(std::string bundleName, std::vector<Game> bundleGames, double price);

    // destructor
    ~Bundle() = default;

    // getters
    [[nodiscard]] const std::string& getBundleName() const;
    [[nodiscard]] double getBundlePrice() const;
    [[nodiscard]] const std::vector<Game>& getGames() const;
    std::vector<Game>& getGames();

    // functions
    bool addGameToBundle(const Game& game);
    bool removeGameFromBundle(const std::string& gameName);
    void printBundleInfo() const;
};