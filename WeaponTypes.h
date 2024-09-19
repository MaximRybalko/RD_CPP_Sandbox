#pragma once

#include "Weapon.h"

class Melee : public Weapon {
public:
    Melee() : Weapon(WeaponType::Melee) {}

    float GetDamage() const override {
        return 10.0f;
    }

    std::string GetName() const override {
        return "Melee Weapon";
    }
};

class Pistol : public Weapon {
public:
    Pistol() : Weapon(WeaponType::Pistol) {} 

    float GetDamage() const override {
        return 25.0f;
    }

    std::string GetName() const override {
        return "Pistol";
    }
};

class Rifle : public Weapon {
public:
    Rifle() : Weapon(WeaponType::Rifle) {}

    float GetDamage() const override {
        return 50.0f;
    }

    std::string GetName() const override {
        return "Rifle";
    }
};

class Shotgun : public Weapon {
public:
    Shotgun() : Weapon(WeaponType::Shotgun) {}

    float GetDamage() const override {
        return 500.0f;
    }

    std::string GetName() const override {
        return "Shotgun";
    }
};

class Grenade : public Weapon {
public:
    Grenade() : Weapon(WeaponType::Grenade) {}

    float GetDamage() const override {
        return 200.0f;
    }

    std::string GetName() const override {
        return "Granade";
    }
};