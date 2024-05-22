#ifndef HIDDENBOSSROOM_H
#define HIDDENBOSSROOM_H

#include "Room.h"
#include "Player.h"

class HiddenBossRoom : public Room {
public:
    HiddenBossRoom(const std::string& description, Room* fallbackRoom);
    void enter(Player* player) override;

private:
    Room* fallbackRoom;
};

#endif // HIDDENBOSSROOM_H
