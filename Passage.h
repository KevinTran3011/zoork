#pragma once

#include "Room.h"
#include "Command.h"

class Passage {
public:
    Passage(const std::shared_ptr<Room>& destination);

    void enter();
    void setCommand(const std::shared_ptr<Command>& command);
    std::shared_ptr<Room> getDestination() const;

private:
    std::shared_ptr<Room> destination;
    std::shared_ptr<Command> command;
};
