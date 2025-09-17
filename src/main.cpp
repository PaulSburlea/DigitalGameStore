#include "Store.h"
#include "AdminCli.h"
#include "UserCli.h"
#include <iostream>

int main() {
    Store store;
    store.loadFromJSON("data/store.json");

    while (true) {
        int choice;
        std::cout << "Please choose an option\n";
        std::cout << "1. Admin\n2. User\n0. Exit\n";
        std::cout << "Choice:";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                AdminCli admin(store);
                admin.run();
                break;
            }
            case 2: {
                UserCli user(store);
                user.run();
                break;
            }
            case 0:
                store.saveToJSON("data/store.json");
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid option.\n";
                std::cout << "Press Enter to continue...";
                std::cin.get();
                break;
        }

        store.saveToJSON("data/store.json");
    }
}
