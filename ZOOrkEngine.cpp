#include "ZoorkEngine.h"
#include "Item.h"
#include "Enemy.h"
#include "Boss.h"
#include "GodslayerBlade.h"
#include <iostream>

ZoorkEngine::ZoorkEngine()
    : playerProxy(new PlayerProxy(&player)) {
    createRooms();
    placeItems();
    placeEnemies();
    connectRooms();
}

void ZoorkEngine::createRooms() {
    entrance = std::make_shared<Room>("Entrance", "The entrance of the dungeon.");
    mainHallway = std::make_shared<Room>("Main Hallway", "A grand hallway with passages in all directions.");
    enemyRoom1 = std::make_shared<Room>("Enemy Room 1", "A room filled with enemies.");
    enemyRoom2 = std::make_shared<Room>("Enemy Room 2", "Another room filled with enemies.");
    library = std::make_shared<Room>("Library", "A room filled with ancient books.");
    cathedral = std::make_shared<Room>("Cathedral", "A grand cathedral.");
    throneRoom = std::make_shared<Room>("Throne Room", "The final room where the boss awaits.");
    arsenal = std::make_shared<Room>("Arsenal", "A room filled with weapons.");
    enemyRoom3 = std::make_shared<Room>("Enemy Room 3", "A room filled with enemies.");
    dungeon = std::make_shared<Room>("Dungeon", "A dark and damp dungeon.");
    hiddenBossRoom = std::make_shared<HiddenBossRoom>("Hidden Boss Room", "A secret room where a powerful boss resides.");
    hiddenBossRoom->setPlayerProxy(playerProxy);
}

void ZoorkEngine::placeItems() {
    entrance->addItem(std::make_shared<Item>("Sword", "A basic sword."));
    arsenal->addItem(std::make_shared<Item>("Shield", "A sturdy shield."));
}

void ZoorkEngine::placeEnemies() {
    enemyRoom1->addEnemy(std::make_shared<Enemy>("Goblin", "A small green goblin.", 20, 5));
    enemyRoom2->addEnemy(std::make_shared<Enemy>("Orc", "A large and strong orc.", 40, 10));
    enemyRoom3->addEnemy(std::make_shared<Enemy>("Skeleton", "A reanimated skeleton.", 30, 7));
    hiddenBossRoom->addEnemy(std::make_shared<Boss>("Hidden Boss", "A powerful and mysterious figure.", 100, 20));
}

void ZoorkEngine::connectRooms() {
    entrance->addPassage("forward", std::make_shared<Passage>(mainHallway));
    mainHallway->addPassage("left", std::make_shared<Passage>(enemyRoom1));
    mainHallway->addPassage("right", std::make_shared<Passage>(arsenal));
    mainHallway->addPassage("forward", std::make_shared<Passage>(enemyRoom2));
    enemyRoom2->addPassage("forward", std::make_shared<Passage>(dungeon));
    dungeon->addPassage("down", std::make_shared<Passage>(hiddenBossRoom));
    dungeon->addPassage("left", std::make_shared<Passage>(enemyRoom3));
    enemyRoom3->addPassage("forward", std::make_shared<Passage>(mainHallway)); // To create a loop if teleported back
}

void ZoorkEngine::play() {
    std::string command;
    player.setCurrentRoom(entrance.get());

    while (true) {
        player.getCurrentRoom()->enter();
        std::cout << "What would you like to do?" << std::endl;
        std::getline(std::cin, command);

        if (command == "quit") {
            break;
        }

        handleAdditionalCommands(command);
    }
}

void ZoorkEngine::handleAdditionalCommands(const std::string& command) {
    if (command == "attack") {
        auto currentRoom = player.getCurrentRoom();
        if (!currentRoom->getEnemies().empty()) {
            player.attackEnemy(currentRoom->getEnemies().front().get());
        } else {
            std::cout << "There are no enemies here to attack." << std::endl;
        }
    } else if (command == "look") {
        player.getCurrentRoom()->enter();
    } else if (command.find("go ") == 0) {
        std::string direction = command.substr(3);
        movePlayer(direction);
    } else if (command.find("take ") == 0) {
        std::string itemName = command.substr(5);
        auto currentRoom = player.getCurrentRoom();
        if (currentRoom->hasItem(itemName)) {
            player.addItem(currentRoom->takeItem(itemName));
            std::cout << "You take the " << itemName << "." << std::endl;
        } else {
            std::cout << "There is no " << itemName << " here." << std::endl;
        }
    } else if (command.find("use ") == 0) {
        std::string itemName = command.substr(4);
        player.useItem(itemName);
    } else {
        std::cout << "I don't understand that command." << std::endl;
    }
}

void ZoorkEngine::movePlayer(const std::string& direction) {
    auto currentRoom = player.getCurrentRoom();
    auto passage = currentRoom->getPassage(direction);
    passage->enter();
    if (passage->getDestination()) {
        player.setCurrentRoom(passage->getDestination().get());
    }
}
