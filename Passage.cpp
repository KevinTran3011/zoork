#include "Passage.h"
#include "NullCommand.h"

Passage::Passage(const std::shared_ptr<Room>& destination)
    : destination(destination), command(std::make_shared<NullCommand>()) {}

void Passage::enter() {
    command->execute();
    destination->enter();
}

void Passage::setCommand(const std::shared_ptr<Command>& command) {
    this->command = command;
}

std::shared_ptr<Room> Passage::getDestination() const {
    return destination;
}
