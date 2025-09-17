#include "AdminCli.h"
#include <iostream>
#include <string>
#include <limits>

// Helper functions for safe input
static int readInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input, please enter an integer.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

double readDouble(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input, please enter a number.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

AdminCli::AdminCli(Store &s) : store(s) {}

void AdminCli::showMenu() {
    std::cout << "\n=== Admin Menu ===\n";
    std::cout << "1. Add Game\n";
    std::cout << "2. Remove Game\n";
    std::cout << "3. Modify Game Price\n";
    std::cout << "4. Add Bundle\n";
    std::cout << "5. Remove Bundle\n";
    std::cout << "6. List Games\n";
    std::cout << "7. List Bundles\n";
    std::cout << "0. Exit\n";
}

void AdminCli::handleChoice(const int choice) const {
    switch (choice) {
        case 1: {
            std::string name, category;
            std::cout << "Game name:";
            std::getline(std::cin, name);
            std::cout << "Category:";
            std::getline(std::cin, category);
            const double price = readDouble("Price:");
            const double size = readDouble("Size (GB):");
            store.addGame(Game(name, category, price, size));
            std::cout << "Game \"" << name << "\" added!\n";
            break;
        }
        case 2: {
            std::string name;
            std::cout << "Game name:";
            std::getline(std::cin, name);
            if (store.removeGame(name)) {
                std::cout << "Game \"" << name << "\" removed!\n";
            } else {
                std::cout << "Game not found.\n";
            }
            break;
        }
        case 3: {
            std::string name;
            std::cout << "Game name:";
            std::getline(std::cin, name);
            double price = readDouble("New price:");
            if (store.modifyGame(name, price)) {
                std::cout << "Price updated for \"" << name << "\".\n";
            } else {
                std::cout << "Game not found.\n";
            }
            break;
        }
        case 4: {
            std::string bundleName;
            std::cout << "Bundle name:";
            std::getline(std::cin, bundleName);
            double bundlePrice = readDouble("Bundle price:");
            int gameCount = readInt("Number of games in bundle:");

            std::vector<Game> bundleGames;
            for (int i = 0; i < gameCount; i++) {
                int gameID = readInt("Game ID #" + std::to_string(i + 1) + ":");
                if (Game* g = store.getGameByID(gameID)) {
                    bundleGames.push_back(*g);
                } else {
                    std::cout << "No game with ID " << gameID << ", skipping.\n";
                }
            }

            store.addBundle(Bundle(bundleName, bundleGames, bundlePrice));
            std::cout << "Bundle added successfully!\n";
            break;
        }
        case 5: {
            std::string bundleName;
            std::cout << "Bundle name:";
            std::getline(std::cin, bundleName);
            if (store.removeBundle(bundleName)) {
                std::cout << "Bundle \"" << bundleName << "\" removed!\n";
            } else {
                std::cout << "Bundle not found.\n";
            }
            break;
        }
        case 6: {
            for (const auto& g : store.listGames()) {
                std::cout << "ID: " << g.getId()
                          << " | Name: " << g.getName()
                          << " | Category: " << g.getCategory()
                          << " | Price: " << g.getPrice()
                          << " | Size: " << g.getSizeGB()
                          << " | Times Bought: " << g.getTimesBought()
                          << "\n";
            }
            break;
        }
        case 7: {
            for (const auto& b : store.listBundles()) {
                std::cout << "Bundle ID: " << b.getId()
                          << " | Name: " << b.getBundleName()
                          << " | Price: " << b.getBundlePrice()
                          << " | Games: ";
                for (const auto& g : b.getGames()) {
                    std::cout << g.getId() << "(" << g.getName() << ") ";
                }
                std::cout << "\n";
            }
            break;
        }
        case 0:
            std::cout << "Exiting admin menu...\n";
            break;
        default:
            std::cout << "Invalid choice!\n";
            break;
    }
}

void AdminCli::run() const {
    int choice;
    do {
        showMenu();
        choice = readInt("Choice:");
        handleChoice(choice);
    } while (choice != 0);
}
