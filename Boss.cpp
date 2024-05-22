#include "Boss.h"
#include <iostream>

Boss::Boss(const std::string& name, int health, int damage, const std::string& specialAttack)
    : Enemy(name, health, damage), specialAttack(specialAttack) {}

const std::string& Boss::getSpecialAttack() const {
    return specialAttack;
}

void Boss::useSpecial() {
    std::cout << "Boss uses special attack: " << specialAttack << std::endl;
}
