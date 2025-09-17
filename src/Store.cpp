#include "Store.h"
#include "Game.h"

#include <algorithm>
#include <vector>
#include <fstream>
#include <nlohmann/json.hpp>

// "manual" constructor
Store::Store(const std::vector<Game> &games) : games(games){}


// function to add a new game
void Store::addGame(const Game &game) {
    games.push_back(game);
}

// function to delete a game
bool Store::removeGame(const std::string &name) {
    auto it = std::find_if(games.begin(), games.end(), [name](const Game& g){return g.getName() == name;});

    if (it != games.end()) {
        games.erase(it);
        return true;
    }
    return false;
}

// function to modify the price of a game
bool Store::modifyGame(const std::string &name, const double newPrice) {
    auto it = std::find_if(games.begin(), games.end(), [name](const Game& g){return g.getName() == name;});

    if (it != games.end()) {
        it->setPrice(newPrice);
        return true;
    }
    return false;
}

Game *Store::getGame(const std::string &name) {
    auto it = std::find_if(games.begin(), games.end(), [name](const Game& g){return g.getName() == name;});

    if (it != games.end()) {
        return &(*it);
    }
    return nullptr;
}

const std::vector<Game> &Store::listGames() const {
    return games;
}

std::vector<const Game*> Store::listGamesByCategory(const std::string &category) const {
    std::vector<const Game*> gamesByCategory;

    for (const auto& game : games) {
        if (game.getCategory() == category) {
            gamesByCategory.push_back(&game);
        }
    }
    return gamesByCategory;
}


std::vector<Game> Store::getMostBoughtGames(const size_t topCount) {
    std::sort(games.begin(), games.end(), [](const Game& a, const Game&b) {return a.getTimesBought() > b.getTimesBought();});

    std::vector<Game> mostBoughtGames;

    const size_t count = std::min(topCount, games.size());
    mostBoughtGames.reserve(count);
    for (auto i=0; i<count; i++) {
        mostBoughtGames.push_back(games[i]);
    }
    return mostBoughtGames;
}

bool Store::buyGame(const std::string &name) {
    auto it = std::find_if(games.begin(), games.end(), [name](const Game& g){return g.getName() == name;});

    if (it != games.end()) {
        it->purchase();
        return true;
    }
    return false;
}

// bundle functions
bool Store::addBundle(const Bundle &bundle) {
    auto it = std::find_if(bundles.begin(), bundles.end(), [&bundle](const Bundle& b) {return bundle.getBundleName() == b.getBundleName();});

    if (it == bundles.end()) {
        bundles.push_back(bundle);
        return true;
    }
    return false;
}

bool Store::removeBundle(const std::string &bundleName) {
    const size_t oldSize = bundles.size();
    auto it = std::remove_if(bundles.begin(), bundles.end(), [&bundleName](const Bundle& b){return b.getBundleName() == bundleName;});

    bundles.erase(it, bundles.end()) ;

    return bundles.size() != oldSize;
}

bool Store::buyBundle(const std::string &bundleName) {
    auto it = std::find_if(bundles.begin(), bundles.end(), [&bundleName](const Bundle& b){return b.getBundleName() == bundleName;});

    if (it == bundles.end()) {
        return false;
    }
    Bundle& bundle = *it;
    for (const auto& g : bundle.getGames()) {
        if (Game* gameInStore = getGame(g.getName())) {
            gameInStore->purchase();
        }
    }
    return true;
}

const std::vector<Bundle> &Store::listBundles() const {
    return bundles;
}

Game *Store::getGameByID(int ID) {
    auto it = std::find_if(games.begin(), games.end(),
        [ID](const Game& g){return g.getId() == ID;});

    if (it != games.end()) {
        return &(*it);
    }
    return nullptr;
}


// json handling
// save store to JSON
void Store::saveToJSON(const std::string& path) const {
    json j;
    j["games"] = games;
    j["bundles"] = bundles;

    std::ofstream file(path);
    file << j.dump(4);
}

void Store::loadFromJSON(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) return;

    json j;
    file >> j;

    games = j["games"].get<std::vector<Game>>();

    bundles.clear();
    for (const auto& bj : j["bundles"]) {
        bundles.push_back(Bundle::from_json_with_store(bj, games));
    }

    int maxGameID = 0;
    for (const auto& g : games) if (g.getId() > maxGameID) maxGameID = g.getId();
    Game::updateNextID(maxGameID + 1);

    int maxBundleID = 0;
    for (const auto& b : bundles) if (b.getId() > maxBundleID) maxBundleID = b.getId();
    Bundle::updateNextID(maxBundleID + 1);
}
