# Digital Game Store

![C++](https://img.shields.io/badge/language-C%2B%2B-blue)
![CMake](https://img.shields.io/badge/build-CMake-orange)

## Overview
Digital Game Store is a simulation of a digital console game store. The application allows managing games and bundles, as well as interacting with the store by browsing, purchasing, installing, and uninstalling games.

## Current Progress
The following components are currently implemented:

### Game
- `Game.h` / `Game.cpp`
- Encapsulates game details: name, category, price, size, purchase status, installation status, and number of times bought.
- Provides getters, setters, and functions for purchasing, installing, uninstalling, and displaying game info.

### Store
- `Store.h` / `Store.cpp`
- Manages a collection of `Game` objects.
- Supports CRUD operations: add, remove, modify games.
- Provides data access: get game by name, list all games, list games by category, retrieve most bought games.
- Implements purchase functionality (updates purchase status and times bought).

## Project Structure
```
GameStore/
├── cmake-build-debug/
├── include/
│   ├── Bundle.h
│   ├── Cli.h
│   ├── Game.h
│   ├── Store.h
│   └── User.h
├── scripts/
│   └── seed_data.py
├── src/
│   ├── Bundle.cpp
│   ├── Cli.cpp
│   ├── Game.cpp
│   ├── main.cpp
│   ├── Store.cpp
│   └── User.cpp
└── CMakeLists.txt
```

## Next Steps
- Implement `Bundle` and `User` classes.
- Complete CLI interaction (`Cli.cpp` / `Cli.h`) for browsing, buying, installing/uninstalling games, and viewing bundles.
- Add bundle management in the store.
- Add usage examples and screenshots to this README.

## How to Build and Run
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/GameStore.git
   ```
2. Navigate to the project folder and create a build directory:
   ```bash
   mkdir build && cd build
   ```
3. Generate the build system with CMake:
   ```bash
   cmake ..
   ```
4. Build the project:
   ```bash
   cmake --build .
   ```
5. Run the executable:
   ```bash
   ./DigitalGameStore
   ```