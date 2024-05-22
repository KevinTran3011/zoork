#pragma once

#include <memory>
#include <string>
#include "Room.h"
#include "Player.h"
#include "HiddenBossRoom.h"

class ZoorkEngine {
public:
    ZoorkEngine();

    void play();

private:
    void createRooms();
    void placeItems();
    void placeEnemies();
    void connectRooms();
    void handleAdditionalCommands(const std::string& command);
    void movePlayer(const std::string& direction);

    Player player;
    PlayerProxy* playerProxy;

    std::shared_ptr<Room> entrance;
    std::shared_ptr<Room> mainHallway;
    std::shared_ptr<Room> enemyRoom1;
    std::shared_ptr<Room> enemyRoom2;
    std::shared_ptr<Room> library;
    std::shared_ptr<Room> cathedral;
    std::shared_ptr<Room> throneRoom;
    std::shared_ptr<Room> arsenal;
    std::shared_ptr<Room> enemyRoom3;
    std::shared_ptr<Room> dungeon;
    std::shared_ptr<HiddenBossRoom> hiddenBossRoom;
};
