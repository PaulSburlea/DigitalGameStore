#pragma once

#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

class Game {
private:
    int ID = 0;
    static int nextID;
    std::string name = "";
    std::string category = "";
    double price = 0.0;
    double sizeGB = 0.0;

    // not in constructor
    bool purchased = false;
    bool installed = false;
    int timesBought = 0;

public:
    // constructor games from json
    Game(std::string  name, std::string  category, double price, double sizeGB);

    // constructor new games
    Game(int ID, std::string name, std::string category, double price, double sizeGB);

    // default constructor
    Game() = default;

    // destructor
    ~Game() = default;

    // getters
    [[nodiscard]] int getId() const;
    static int getNextID();
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] std::string getCategory() const;
    [[nodiscard]] double getPrice() const;
    [[nodiscard]] double getSizeGB() const;
    [[nodiscard]] int getTimesBought() const;
    [[nodiscard]] bool isPurchased() const;
    [[nodiscard]] bool isInstalled() const;

    // setters
    void setID(int newID);
    static void updateNextID(int newValue);
    void setPrice(double price);
    void setInstalled(bool installed);
    void setTimesBought(int times);

    // functions
    void purchase();
    void increaseTimesBought();
    void printInfo() const;


};

template <>
struct nlohmann::adl_serializer<Game> {
    static void to_json(json& j, const Game& g) {
        j = json{
            {"id", g.getId()},
            {"name", g.getName()},
            {"category", g.getCategory()},
            {"price", g.getPrice()},
            {"sizeGB", g.getSizeGB()},
            {"timesBought", g.getTimesBought()}
        };
    }

    static void from_json(const json& j, Game& g) {
        g = Game(
            j.at("id").get<int>(),
            j.at("name").get<std::string>(),
            j.at("category").get<std::string>(),
            j.at("price").get<double>(),
            j.at("sizeGB").get<double>()
        );
        g.setTimesBought(j.value("timesBought", 0));
    }
};
