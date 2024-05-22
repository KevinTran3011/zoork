#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Item.h"
#include "Room.h"
#include "PlayerObserver.h"

class Enemy; // Forward declaration

class Player {
public:
    Player(const std::string& name);
    const std::string& getName() const;
    int getHealth() const;
    int getLevel() const;
    void addObserver(PlayerObserver* observer);
    void removeObserver(PlayerObserver* observer);
    void addItem(Item* item);
    void useItem(Item* item);
    void attackEnemy(Enemy* enemy);
    void setCurrentRoom(Room* room);
    Room* getCurrentRoom() const;
    void gainXP(int amount);
    void takeDamage(int amount);

private:
    void notifyObservers();
    std::string name;
    int health;
    int level;
    int xp;
    std::vector<Item*> inventory;
    Room* currentRoom;
    std::vector<PlayerObserver*> observers;
};

#endif // PLAYER_H
