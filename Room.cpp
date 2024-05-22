#include "Room.h"
#include "NullPassage.h"
#include <iostream>

Room::Room(const std::string& name, const std::string& description)
    : name(name), description(description) {}

void Room::addEnemy(const std::shared_ptr<Enemy>& enemy) {
    enemies.push_back(enemy);
}

void Room::addItem(const std::shared_ptr<Item>& item) {
    items.push_back(item);
}

void Room::addPassage(const std::string& direction, const std::shared_ptr<Passage>& passage) {
    passages[direction] = passage;
}

void Room::enter() const {
    std::cout << "You enter the " << name << ". " << description << std::endl;
    for (const auto& enemy : enemies) {
        std::cout << "There is a " << enemy->getName() << " here." << std::endl;
    }
    for (const auto& item : items) {
        std::cout << "You see a " << item->getName() << " here." << std::endl;
    }
}

std::string Room::getName() const {
    return name;
}

std::shared_ptr<Passage> Room::getPassage(const std::string& direction) {
    auto it = passages.find(direction);
    if (it != passages.end()) {
        return it->second;
    }
    return std::make_shared<NullPassage>();
}
