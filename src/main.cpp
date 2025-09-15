#include <iostream>
#include "../include/Game.h"
#include "../include/Store.h"
#include <vector>

int main() {
    // Creează câteva jocuri
    Game g1("SuperPuzzle", "Puzzle", 29.99, 1.2);
    Game g2("FastRacer", "Racing", 49.99, 5.0);
    Game g3("SpaceArcade", "Arcade", 19.99, 0.8);

    // Creează magazinul
    std::vector<Game> initialGames = {g1, g2, g3};
    Store store(initialGames);

    // Listează toate jocurile
    std::cout << "All games:\n";
    for (const auto& game : store.listGames()) {
        game.printInfo();
        std::cout << "--------------------\n";
    }

    // Cumpara un joc
    store.buyGame("FastRacer");

    // Verifică cele mai cumpărate jocuri
    std::cout << "\nMost bought games:\n";
    auto topGames = store.getMostBoughtGames(2);
    for (const auto& game : topGames) {
        game.printInfo();
        std::cout << "--------------------\n";
    }

    // Listează jocuri după categorie
    std::cout << "\nPuzzle games:\n";
    auto puzzleGames = store.listGamesByCategory("Puzzle");
    for (const auto* gamePtr : puzzleGames) {
        gamePtr->printInfo();
        std::cout << "--------------------\n";
    }

    return 0;
}
