#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Weapon.h"

class Character {
public:
    void SetWeapon(std::unique_ptr<Weapon> weapon); 

    Weapon* GetWeapon() const;

    int GetInventorySize();
    
    void PrintInventory() const;

    std::string WeaponTypeToString(WeaponType type) const;

    void PrintActiveWeaponType() const;

    void SetActiveWeapon(int index);

    void RemoveWeapon(int index);

private:
    std::vector<std::unique_ptr<Weapon>> inventory;
    Weapon* activeWeapon = nullptr;  
};