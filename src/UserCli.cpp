#include "UserCli.h"
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

UserCli::UserCli(Store &s) : store(s) {}

void UserCli::showMenu() {
    std::cout << "\n=== User Menu ===\n";
    std::cout << "1. List Games\n";
    std::cout << "2. List Bundles\n";
    std::cout << "3. Buy Game\n";
    std::cout << "4. Buy Bundle\n";
    std::cout << "5. List Most Bought Games\n";
    std::cout << "6. List Games by Category\n";
    std::cout << "0. Exit\n";
}

void UserCli::handleChoice(const int choice) const {
    switch (choice) {
        case 1:
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

        case 2:
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

        case 3: {
            const int gameID = readInt("Game ID to buy:");
            if (Game* g = store.getGameByID(gameID)) {
                store.buyGame(g->getName());
                std::cout << "You bought game: " << g->getName() << "\n";
            } else {
                std::cout << "Game not found.\n";
            }
            break;
        }

        case 4: {
            std::string name;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Bundle name to buy:";
            std::getline(std::cin, name);
            if (store.buyBundle(name)) {
                std::cout << "Bundle bought successfully!\n";
            } else {
                std::cout << "Bundle not found.\n";
            }
            break;
        }

        case 5: {
            const int topCount = readInt("Top how many games?");
            for (const auto& g : store.getMostBoughtGames(topCount)) {
                std::cout << g.getName() << " | Times Bought: " << g.getTimesBought() << "\n";
            }
            break;
        }

        case 6: {
            std::string category;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Category:";
            std::getline(std::cin, category);
            for (const auto& g : store.listGamesByCategory(category)) {
                std::cout << g->getName() << " | Price: " << g->getPrice() << "\n";
            }
            break;
        }

        case 0:
            std::cout << "Exiting user menu...\n";
            break;

        default:
            std::cout << "Invalid choice.\n";
            break;
    }
}

void UserCli::run() const {
    int choice;
    do {
        showMenu();
        choice = readInt("Choice:");
        handleChoice(choice);
    } while (choice != 0);
}
