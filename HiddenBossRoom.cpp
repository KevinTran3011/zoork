#include "HiddenBossRoom.h"
#include <iostream>

HiddenBossRoom::HiddenBossRoom(const std::string& description, Room* fallbackRoom)
    : Room(description), fallbackRoom(fallbackRoom) {}

void HiddenBossRoom::enter(Player* player) {
    if (player->getLevel() < 5) {
        std::cout << "You are not strong enough to face the hidden boss!" << std::endl;
        player->setCurrentRoom(fallbackRoom);
    } else {
        std::cout << "Prepare to face the hidden boss!" << std::endl;
        // Battle logic here
    }
}
