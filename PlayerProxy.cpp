#include "PlayerProxy.h"

PlayerProxy::PlayerProxy(Player* realPlayer)
    : realPlayer(realPlayer) {}

int PlayerProxy::getLevel() const {
    return realPlayer->getLevel();
}

void PlayerProxy::attackEnemy(Enemy* enemy) {
    realPlayer->attackEnemy(enemy);
}
