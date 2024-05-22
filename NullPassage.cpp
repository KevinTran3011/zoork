#include "NullPassage.h"
#include "NullCommand.h"

NullPassage::NullPassage() : Passage(nullptr) {
    setCommand(std::make_shared<NullCommand>());
}
