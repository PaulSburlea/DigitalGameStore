#pragma once

#include "Game.h"

#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

class Bundle {
private:
    int id = 0;
    static int nextID;
    std::string bundleName = "";
    std::vector<Game> bundleGames;
    double price = 0.0;

public:
    // constructor for bundles from json
    explicit Bundle(std::string bundleName, std::vector<Game> bundleGames, double price);

    // constructor for new bundle
    Bundle(int id, std::string bundleName, std::vector<Game> bundleGames, double price);

    // default constructor
    Bundle() = default;

    // destructor
    ~Bundle() = default;

    // getters
    [[nodiscard]] int getId() const;
    [[nodiscard]] const std::string& getBundleName() const;
    [[nodiscard]] double getBundlePrice() const;
    [[nodiscard]] const std::vector<Game>& getGames() const;
    std::vector<Game>& getGames();

    static void updateNextID(int newNextID);

    // setters
    void setId(int newId);

    // functions
    bool addGameToBundle(const Game& game);
    bool removeGameFromBundle(const std::string& gameName);
    void printBundleInfo() const;

    ////
    static Bundle from_json_with_store(const json& j, const std::vector<Game>& allGames);
};


template <>
struct nlohmann::adl_serializer<Bundle> {
    static void to_json(json& j, const Bundle& b) {
        std::vector<std::string> gameNames;
        for (const auto& g : b.getGames()) {
            gameNames.push_back(g.getName());
        }

        j = json{
                    {"id", b.getId()},
                    {"bundleName", b.getBundleName()},
                    {"price", b.getBundlePrice()},
                    {"games", gameNames}
        };
    }
};
