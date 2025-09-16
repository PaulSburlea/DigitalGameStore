//
// Created by G713 on 11.09.2025.
//
#include <utility>

#include "../include/Game.h"

Game::Game(std::string name, std::string category, const double price, const double sizeGB) :
name(std::move(name)), category(std::move(category)), price(price), sizeGB(sizeGB), purchased(false), installed(false), timesBought(0){}

void Game::purchase() {
    purchased = true;
    increaseTimesBought();
}

void Game::increaseTimesBought() {
    ++timesBought;
}

void Game::printInfo() const {
    std::cout << "Name: " << name << std::endl
    << "Category: " << category << std::endl
    << "Price: " << price << std::endl
    << "Size: " << sizeGB << std::endl
    << "Purchased: " << purchased << std::endl
    << "Installed: " << installed << std::endl
    << "Times bought: " << timesBought << std::endl;
}
// getters
std::string Game::getName() const {
    return name;
}
std::string Game::getCategory() const {
    return category;
}
double Game::getPrice() const {
    return price;
}
double Game::getSizeGB() const {
    return sizeGB;
}
int Game::getTimesBought() const {
    return timesBought;
}

bool Game::isPurchased() const {
    return purchased;
}
bool Game::isInstalled() const {
    return installed;
}


// setters
void Game::setPrice(const double price) {
    this->price = price;
}
void Game::setInstalled(const bool installed) {
    this->installed = installed;
}
