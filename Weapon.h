#pragma once

#include <iostream>
#include <string>

enum class WeaponType {
    Melee = 0,
    Pistol,
    Rifle,
    Shotgun,
    Grenade,
};

class Weapon {
public:
    virtual float GetDamage() const = 0;
    virtual std::string GetName() const = 0;
    WeaponType GetWeaponType() const { return Type; }

    virtual ~Weapon() = default;

protected:
    Weapon(WeaponType Type) : Type(Type) {}

private:
    WeaponType Type;
};