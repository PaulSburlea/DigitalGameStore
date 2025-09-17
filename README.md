# Digital Game Store

![C++](https://img.shields.io/badge/language-C%2B%2B-blue)
![CMake](https://img.shields.io/badge/build-CMake-orange)

## Overview
Digital Game Store is a simulation of a digital console game store. The application allows managing games and bundles, as well as interacting with the store by browsing, purchasing, and managing games and bundles.

## Features Implemented

### Game
- `Game.h` / `Game.cpp`
- Encapsulates game details: `name`, `category`, `price`, `sizeGB`, purchase status, installation status, and times bought.
- Provides getters, setters, and functions for purchasing, installing/uninstalling, and displaying game information.

### Bundle
- `Bundle.h` / `Bundle.cpp`
- Encapsulates a collection of games sold as a package.
- Each bundle has `id`, `bundleName`, `games`, and `price`.
- Supports adding/removing games in a bundle, printing bundle info, and JSON serialization/deserialization with reference to the store games.

### Store
- `Store.h` / `Store.cpp`
- Manages all `Game` and `Bundle` objects.
- Supports CRUD operations on games and bundles: add, remove, modify games; add, remove, buy bundles.
- Provides data access: get game by name or ID, list all games, list games by category, retrieve most bought games.
- Handles purchases and updates times bought automatically.

### CLI Interfaces
- `AdminCli.h` / `AdminCli.cpp`: Admin menu for managing games and bundles.
- `UserCli.h` / `UserCli.cpp`: User menu for browsing, buying games/bundles, listing most bought games, listing games by category.

### JSON Persistence
- Store can be saved/loaded in JSON format.
- All game and bundle data is serialized.
- Next IDs for games and bundles are updated automatically.

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

## How to Build and Run
1. Clone the repository:   
   ```bash
   git clone https://github.com/yourusername/GameStore.git
   ```
2. Navigate to the project folder and create a build directory:
   ```bash
   cd GameStore
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
   ./GameStore
   ```

## Usage
- Launch the application.
- Choose either Admin or User interface from the menu.
- Admin can add/remove games and bundles, modify game prices, and list all items.
- User can browse games and bundles, buy games or bundles, list most bought games, and filter games by category.