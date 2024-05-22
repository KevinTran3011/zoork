#ifndef PLAYERPROXY_H
#define PLAYERPROXY_H

#include "Player.h"

class PlayerProxy : public Player {
public:
    PlayerProxy(Player* realPlayer);
    int getLevel() const override;
    void attackEnemy(Enemy* enemy) override;

private:
    Player* realPlayer;
};

#endif // PLAYERPROXY_H
