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
    std::string getName() const;
    std::string getCategory() const;
    double getPrice() const;
    double getSizeGB() const;
    int getTimesBought() const;
    bool isPurchased() const;
    bool isInstalled() const;

    // setters
    void setPrice(double price);

    // functions
    void purchase();
    bool install (double availableMemory);
    void uninstall();
    void increaseTimesBought();
    void printInfo() const;


};
