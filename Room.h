#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "Enemy.h"
#include "Item.h"
#include "Passage.h"

class Room {
public:
    Room(const std::string& name, const std::string& description);

    void addEnemy(const std::shared_ptr<Enemy>& enemy);
    void addItem(const std::shared_ptr<Item>& item);
    void addPassage(const std::string& direction, const std::shared_ptr<Passage>& passage);
    void enter() const;
    std::string getName() const;
    std::shared_ptr<Passage> getPassage(const std::string& direction);

protected:
    std::string name;
    std::string description;
    std::vector<std::shared_ptr<Enemy>> enemies;
    std::vector<std::shared_ptr<Item>> items;
    std::map<std::string, std::shared_ptr<Passage>> passages;
};
