#include "Game.h"

#include <utility>
#include <iostream>

int Game::nextID = 1;

// constructor games from json
Game::Game(std::string name, std::string category, const double price, const double sizeGB) :
ID(nextID++),
name(std::move(name)),
category(std::move(category)),
price(price),
sizeGB(sizeGB) {}

// constructor for new games
Game::Game(const int ID, std::string name, std::string category, const double price, const double sizeGB) :
ID(ID),
name(std::move(name)),
category(std::move(category)),
price(price),
sizeGB(sizeGB) {}


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
int Game::getId() const {
    return ID;
}

std::string Game::getName() const {
    return name;
}
int Game::getNextID() {
    return nextID;
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
void Game::setID(const int newID) {
    ID = newID;
}

void Game::updateNextID(const int newValue) {
    nextID = newValue;
}

void Game::setPrice(const double price) {
    this->price = price;
}

void Game::setInstalled(const bool installed) {
    this->installed = installed;
}

void Game::setTimesBought(const int times) {
    timesBought = times;
}
