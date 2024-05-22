#include "Player.h"
#include "Enemy.h"
#include <algorithm>
#include <iostream>

Player::Player(const std::string& name)
    : name(name), health(100), level(1), xp(0), currentRoom(nullptr) {}

const std::string& Player::getName() const {
    return name;
}

int Player::getHealth() const {
    return health;
}

int Player::getLevel() const {
    return level;
}

void Player::addObserver(PlayerObserver* observer) {
    observers.push_back(observer);
}

void Player::removeObserver(PlayerObserver* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Player::addItem(Item* item) {
    inventory.push_back(item);
}

void Player::useItem(Item* item) {
    // Implementation for using an item
}

void Player::attackEnemy(Enemy* enemy) {
    if (!inventory.empty()) {
        auto weapon = dynamic_cast<Weapon*>(inventory.front()); // Use the first weapon
        if (weapon) {
            enemy->takeDamage(weapon->use());
            if (enemy->getHealth() <= 0) {
                gainXP(5);
            }
        }
    } else {
        enemy->takeDamage(10); // Default attack damage
        if (enemy->getHealth() <= 0) {
            gainXP(5);
        }
    }
}

void Player::setCurrentRoom(Room* room) {
    currentRoom = room;
}

Room* Player::getCurrentRoom() const {
    return currentRoom;
}

void Player::gainXP(int amount) {
    xp += amount;
    if (xp >= 10) {
        xp = 0;
        level++;
        notifyObservers();
    }
}

void Player::takeDamage(int amount) {
    health -= amount;
    if (health < 0) {
        health = 0;
    }
}

void Player::notifyObservers() {
    for (auto* observer : observers) {
        observer->update();
    }
}
