#ifndef GODSLAYERBLADE_H
#define GODSLAYERBLADE_H

#include "WeaponDecorator.h"

class GodSlayerBlade : public WeaponDecorator {
public:
    GodSlayerBlade(Item* weapon);
    std::string getDescription() const override;
    int use() override;
};

#endif // GODSLAYERBLADE_H
