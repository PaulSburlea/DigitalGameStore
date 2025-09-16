//
// Created by G713 on 11.09.2025.
//

#pragma once
#include <string>
#include <cstddef>
#include <iostream>

class Game {
private:
    std::string name;
    std::string category;
    double price;
    double sizeGB;
    bool purchased;
    bool installed;
    int timesBought;

public:
    // constructor
    Game(std::string  name, std::string  category, double price, double sizeGB);

    // destructor
    ~Game() = default;

    // getters
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] std::string getCategory() const;
    [[nodiscard]] double getPrice() const;
    [[nodiscard]] double getSizeGB() const;
    [[nodiscard]] int getTimesBought() const;
    [[nodiscard]] bool isPurchased() const;
    [[nodiscard]] bool isInstalled() const;

    // setters
    void setPrice(double price);

    // functions
    void purchase();
    bool install (double availableMemory);
    void uninstall();
    void increaseTimesBought();
    void printInfo() const;


};
