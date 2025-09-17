#pragma once

#include <Store.h>

#include <iostream>
#include <string>

class UserCli {
private:
    Store& store;
    static void showMenu();
    void handleChoice(int choice) const;

public:
    explicit UserCli(Store& s);
    void run() const;
};