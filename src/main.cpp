#include "../include/Game.h"
#include "../include/Bundle.h"
#include "../include/Store.h"

#include <iostream>
#include <vector>

int main() {
    // ===== 1️⃣ Creează jocuri =====
    Game g1("CyberAdventure", "Action", 59.99, 25.0);
    Game g2("FarmFun", "Simulation", 29.99, 5.0);
    Game g3("PuzzleMaster", "Puzzle", 19.99, 2.0);
    Game g4("SpaceRacer", "Racing", 49.99, 15.0);

    std::cout << "Created 4 games.\n";

    // ===== 2️⃣ Creează bundle =====
    std::vector<Game> bundleGames = {g1, g3};
    Bundle b1("Starter Pack", bundleGames, 69.99);
    b1.addGameToBundle(g2); // adaugă g2 în bundle
    std::cout << "Created bundle: " << b1.getBundleName() << " with " << b1.getGames().size() << " games.\n";

    // ===== 3️⃣ Creează magazin și adaugă jocuri și bundle =====
    std::vector<Game> storeGames = {g1, g2, g3, g4};
    Store myStore(storeGames);
    myStore.addBundle(b1);
    std::cout << "Store created with 4 games and 1 bundle.\n";

    // ===== 4️⃣ Listare jocuri =====
    std::cout << "\n=== Games in Store ===\n";
    for (const auto& game : myStore.listGames()) {
        std::cout << game.getName() << " - " << game.getCategory() << " - $" << game.getPrice() << "\n";
    }

    // ===== 5️⃣ Listare bundle-uri =====
    std::cout << "\n=== Bundles in Store ===\n";
    for (const auto& bundle : myStore.listBundles()) {
        bundle.printBundleInfo();
    }

    // ===== 6️⃣ Cumpără un joc individual =====
    std::cout << "\nBuying game: FarmFun\n";
    if (myStore.buyGame("FarmFun")) std::cout << "✅ Game purchased!\n";
    else std::cout << "❌ Game not found!\n";

    // ===== 7️⃣ Modifică prețul unui joc =====
    std::cout << "\nModifying price of SpaceRacer to $39.99\n";
    if (myStore.modifyGame("SpaceRacer", 39.99)) std::cout << "✅ Price updated!\n";
    else std::cout << "❌ Game not found!\n";

    // ===== 8️⃣ Cumpără bundle =====
    std::cout << "\nBuying bundle: Starter Pack\n";
    if (myStore.buyBundle("Starter Pack")) std::cout << "✅ Bundle purchased!\n";
    else std::cout << "❌ Bundle not found!\n";

    // ===== 9️⃣ Ștergere joc =====
    std::cout << "\nRemoving game: PuzzleMaster\n";
    if (myStore.removeGame("PuzzleMaster")) std::cout << "✅ Game removed!\n";
    else std::cout << "❌ Game not found!\n";

    // ===== 🔟 Ștergere bundle =====
    std::cout << "\nRemoving bundle: Starter Pack\n";
    if (myStore.removeBundle("Starter Pack")) std::cout << "✅ Bundle removed!\n";
    else std::cout << "❌ Bundle not found!\n";

    // ===== 1️⃣1️⃣ Verificare finală stoc =====
    std::cout << "\n=== Final Games in Store ===\n";
    for (const auto& game : myStore.listGames()) {
        std::cout << game.getName() << " - Purchased: " << (game.isPurchased() ? "Yes" : "No")
                  << " - Times Bought: " << game.getTimesBought()
                  << " - Price: $" << game.getPrice() << "\n";
    }

    std::cout << "\n=== Final Bundles in Store ===\n";
    for (const auto& bundle : myStore.listBundles()) {
        bundle.printBundleInfo();
    }

    return 0;
}