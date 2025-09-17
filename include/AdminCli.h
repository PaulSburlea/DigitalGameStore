#pragma once
#include "Store.h"

class AdminCli {
private:
    Store& store;
    static void showMenu();
    void handleChoice(int choice) const;

public:
    explicit AdminCli(Store& s);
    void run() const;
};