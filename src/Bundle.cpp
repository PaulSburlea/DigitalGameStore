//
// Created by G713 on 11.09.2025.
//

#include "../include/Bundle.h"

#include <utility>
#include <vector>
#include <algorithm>

Bundle::Bundle(std::string bundleName, std::vector<Game> bundleGames, double price)
    : bundleName(std::move(bundleName)), bundleGames(std::move(bundleGames)), price(price) {}

// getters
const std::string &Bundle::getBundleName() const {
    return bundleName;
}
double Bundle::getBundlePrice() const {
    return price;
}
const std::vector<Game> &Bundle::getGames() const {
    return bundleGames;
}
std::vector<Game>& Bundle::getGames() {
    return bundleGames;
}


bool Bundle::addGameToBundle(const Game &game) {
    auto it = std::find_if(bundleGames.begin(), bundleGames.end(), [&game](const Game& g){return g.getName() == game.getName();});

    if (it == bundleGames.end()) {
        bundleGames.push_back(game);
        return true;
    }
    return false;
}

bool Bundle::removeGameFromBundle(const std::string &gameName) {
    const size_t oldSize = bundleGames.size();
    auto it = std::remove_if(bundleGames.begin(), bundleGames.end(), [&gameName](const Game& g){return g.getName() == gameName;});

    bundleGames.erase(it, bundleGames.end()) ;

    return bundleGames.size() != oldSize;
}

void Bundle::printBundleInfo() const {
    std::cout << "Bundle name: " << bundleName << std::endl;
    std::cout << "Games in bundle: " << std::endl;
    for (const auto& x : bundleGames) {
        std::cout << "- " << x.getName() << std::endl;
    }
    std::cout << "Bundle price: " << price << std::endl;
}

