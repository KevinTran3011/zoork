#ifndef WEAPONDECORATOR_H
#define WEAPONDECORATOR_H

#include "Item.h"

class WeaponDecorator : public Item {
public:
    WeaponDecorator(Item* weapon);
    virtual std::string getDescription() const override;
    virtual int use() override;

protected:
    Item* weapon;
};

#endif // WEAPONDECORATOR_H
