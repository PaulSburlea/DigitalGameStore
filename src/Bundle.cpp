#include "Bundle.h"

#include <utility>
#include <vector>
#include <algorithm>
#include <iostream>

int Bundle::nextID = 1;

// constructor for bundles from json
Bundle::Bundle(std::string bundleName, std::vector<Game> bundleGames, const double price) :
id(nextID++),
bundleName(std::move(bundleName)),
bundleGames(std::move(bundleGames)),
price(price) {}

// constructor for new bundle
Bundle::Bundle(const int id, std::string bundleName, std::vector<Game> bundleGames, double price) :
id(id),
bundleName(std::move(bundleName)),
bundleGames(std::move(bundleGames)),
price(price) {
    if (id >= nextID) {
        nextID = id + 1;
    }
}


// getters
int Bundle::getId() const {
    return id;
}
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

void Bundle::updateNextID(const int newNextID) {
    if (newNextID > nextID) {
        nextID = newNextID;
    }
}

// setters
void Bundle::setId(const int newId) {
    id = newId;
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
    std::cout << "Bundle ID: " << id << std::endl;
    std::cout << "Bundle name: " << bundleName << std::endl;
    std::cout << "Games in bundle: " << std::endl;
    for (const auto& x : bundleGames) {
        std::cout << "- " << x.getName() << std::endl;
    }
    std::cout << "Bundle price: " << price << std::endl;
}

////
Bundle Bundle::from_json_with_store(const json& j, const std::vector<Game>& allGames) {
    std::vector<Game> gamesInBundle;

    for (const auto& name : j.at("games").get<std::vector<std::string>>()) {
        auto it = std::find_if(allGames.begin(), allGames.end(),
                               [&name](const Game& g){ return g.getName() == name; });
        if (it != allGames.end()) {
            gamesInBundle.push_back(*it);
        } else {
            std::cerr << "Warning: game " << name << " not found in store!\n";
        }
    }

    return Bundle(
        j.at("id").get<int>(),
        j.at("bundleName").get<std::string>(),
        gamesInBundle,
        j.at("price").get<double>()
    );
}
