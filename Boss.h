#ifndef BOSS_H
#define BOSS_H

#include "Enemy.h"

class Boss : public Enemy {
public:
    Boss(const std::string& name, int health, int damage, const std::string& specialAttack);
    const std::string& getSpecialAttack() const;
    void useSpecial();

private:
    std::string specialAttack;
};

#endif // BOSS_H
