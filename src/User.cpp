#include "User.h"
#include "Store.h"

#include <algorithm>
#include <utility>

User::User(std::string username) : username(std::move(username)), consoleStorage(512) {}


bool User::buyGame(const std::string& gameName, Store& store) {
    Game *g = store.getGame(gameName);

    if (!g)
        return false;

    if (store.buyGame(gameName)) {
        boughtGames.push_back(g);
        store.saveToJSON("data/store.json");
    }
    return true;
}

bool User::buyBundle(const std::string& bundleName, Store& store) {
    const auto it = std::find_if(store.listBundles().begin(), store.listBundles().end(), [&bundleName](const Bundle& b){return b.getBundleName() == bundleName;});

    if (it == store.listBundles().end()) {
        return false;
    }
    const Bundle& bundle = *it;

    for (const auto& gBundle : bundle.getGames()) {
        Game* g = store.getGame(gBundle.getName());
        if (g && store.buyGame(g->getName())) {
            boughtGames.push_back(g);
            store.saveToJSON("data/store.json");
        }
    }
    return true;
}

bool User::installGame(const std::string &gameName) {
    const auto it = std::find_if(boughtGames.begin(), boughtGames.end(),
        [&gameName](const Game* g){return g->getName() == gameName;});

    if (it == boughtGames.end())
        return false;

    Game* g = *it;
    if (g->getSizeGB() > consoleStorage)
        return false;

    g->setInstalled(true);
    consoleStorage -= g->getSizeGB();
    return true;

}

bool User::uninstallGame(const std::string &gameName) {
    const auto it = std::find_if(boughtGames.begin(), boughtGames.end(),
        [&gameName](const Game* g){return g->getName() == gameName;});

    if (it == boughtGames.end())
        return false;

    Game* g = *it;
    if (!g->isInstalled())
        return false;

    g->setInstalled(true);
    consoleStorage += g->getSizeGB();
    return true;
}

const std::vector<Game*>& User::listPurchasedGames() {
    return boughtGames;
}

std::vector<Game> User::listInstalledGames() const {
    std::vector<Game> installedGames;
    for ( auto* game : boughtGames) {
        if (game->isInstalled()) {
            installedGames.push_back(*game);
        }
    }
    return installedGames;
}
