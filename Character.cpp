#include "Character.h"
#include <iostream>

void Character::SetWeapon(std::unique_ptr<Weapon> weapon) {
    inventory.push_back(std::move(weapon));
}

void Character::SetActiveWeapon(int index) {
    if (index >= 0 && index < inventory.size()) {
        activeWeapon = inventory[index].get();
        std::cout << "Active weapon: " << index << ": " << inventory[index]->GetName() << std::endl;
    }
    else {
        std::cout << "Invalid input." << std::endl;
        activeWeapon = nullptr;
    }
}

void Character::RemoveWeapon(int index) {
    if (index >= 0 && index < inventory.size()) {

        std::string weaponName = inventory[index]->GetName();
        inventory.erase(inventory.begin() + index);

        if (activeWeapon && activeWeapon == inventory[index].get()) {
            activeWeapon = nullptr;
        }

        std::cout << "Weapon " << index << ": " << weaponName << " removed." << std::endl;
    }
    else {
        std::cout << "Invalid input." << std::endl;
    }
}


Weapon* Character::GetWeapon() const {
    return activeWeapon;
}

int Character::GetInventorySize()
{
    return inventory.size();
}

void Character::PrintInventory() const {
    
    std::cout << "Inventory:\n";

    for (size_t i = 0; i < inventory.size(); ++i) {
        std::cout << i << ": " << inventory[i]->GetName() << " (Damage: " << inventory[i]->GetDamage() << ")\n";
    }
}

std::string Character::WeaponTypeToString(WeaponType type) const
{
    switch (type) {
    case WeaponType::Melee:   return "Melee";
    case WeaponType::Pistol:  return "Pistol";
    case WeaponType::Rifle:   return "Rifle";
    case WeaponType::Shotgun: return "Shotgun";
    case WeaponType::Grenade: return "Grenade";
    default: return "Unknown";
    }
}


void Character::PrintActiveWeaponType() const {
    if (activeWeapon) {
        WeaponType type = activeWeapon->GetWeaponType();
        std::string name = WeaponTypeToString(type);
        std::cout << "Active weapon type: " << static_cast<int>(type) << ": " << name << std::endl;
    }
    else {
        std::cout << "No active weapon." << std::endl;
    }
}