#include "Character.h"
#include "WeaponTypes.h"
#include <iostream>

// Функція для додавання зброї
void AddWeaponMenu(Character& character) {
    int input;
    while (true) {
        std::cout << "Select weapon:\n[1] Melee\n[2] Pistol\n[3] Rifle\n[4] Shotgun\n[5] Grenade\n[6] Exit to Menu\n";
        std::cin >> input;

        switch (input) {
        case 1:
            character.SetWeapon(std::make_unique<Melee>());
            break;
        case 2:
            character.SetWeapon(std::make_unique<Pistol>());
            break;
        case 3:
            character.SetWeapon(std::make_unique<Rifle>());
            break;
        case 4:
            character.SetWeapon(std::make_unique<Shotgun>());
            break;
        case 5:
            character.SetWeapon(std::make_unique<Grenade>());
            break;
        case 6:
            return;
        default:
            std::cout << "Invalid input.\n";
            break;
        }
    }
}

void RemoveWeaponMenu(Character& character) {
    int input;
    std::cout << "Select weapon to remove (0-" << character.GetInventorySize() - 1 << "):\n";
    std::cin >> input;
    character.RemoveWeapon(input);
}

void SetActiveWeaponMenu(Character& character) {
    int input;
    std::cout << "Select weapon to set active (0-" << character.GetInventorySize() - 1 << "):\n";
    std::cin >> input;
    character.SetActiveWeapon(input);
}

void MainMenu(Character& character) {
    int input;
    while (true) {
        std::cout << "\n[1] Add Weapon\n[2] Remove Weapon\n[3] Set Active Weapon\n[4] Print Inventory\n[5] Print Active Weapon Type\n[6] Exit Game\n";
        std::cin >> input;

        switch (input) {
        case 1:
            AddWeaponMenu(character);
            break;
        case 2:
            RemoveWeaponMenu(character);
            break;
        case 3:
            SetActiveWeaponMenu(character);
            break;
        case 4:
            character.PrintInventory();
            break;
        case 5:
            character.PrintActiveWeaponType();
            break;
        case 6:
            std::cout << "Exiting game...\n";
            return;
        default:
            std::cout << "Invalid input. Please try again.\n";
            break;
        }
    }
}

int main() {
    Character character;

    character.SetWeapon(std::make_unique<Melee>());
    character.SetWeapon(std::make_unique<Pistol>());
    character.SetWeapon(std::make_unique<Rifle>());

    character.PrintInventory();
    character.PrintActiveWeaponType();

    MainMenu(character);

    return 0;
}