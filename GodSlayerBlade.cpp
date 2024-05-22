#include "GodSlayerBlade.h"

GodSlayerBlade::GodSlayerBlade(Item* weapon)
    : WeaponDecorator(weapon) {}

std::string GodSlayerBlade::getDescription() const {
    return weapon->getDescription() + " (GodSlayer Blade)";
}

int GodSlayerBlade::use() {
    return weapon->use() + 100; // Adds extra damage
}
