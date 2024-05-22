#include "WeaponDecorator.h"

WeaponDecorator::WeaponDecorator(Item* weapon)
    : weapon(weapon) {}

std::string WeaponDecorator::getDescription() const {
    return weapon->getDescription();
}

int WeaponDecorator::use() {
    return weapon->use();
}
