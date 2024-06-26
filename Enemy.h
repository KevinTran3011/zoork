#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Enemy {
public:
    Enemy(const std::string& name, int health, int damage);
    const std::string& getName() const;
    int getHealth() const;
    int getDamage() const;
    void takeDamage(int amount);

private:
    std::string name;
    int health;
    int damage;
};

#endif // ENEMY_H
