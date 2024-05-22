#pragma once

#include "Command.h"
#include <iostream>

class NullCommand : public Command {
public:
    void execute() override {
        std::cout << "There is nothing to do here." << std::endl;
    }
};
