#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string& name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << this->name << " constructed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
    std::cout << "ClapTrap " << name << " copy constructed." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destroyed." << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " cannot attack (no hit points left)." << std::endl;
        return;
    }
    if (energyPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " cannot attack (no energy points left)." << std::endl;
        return;
    }

    energyPoints--;
    std::cout << "ClapTrap " << name
              << " attacks " << target
              << ", causing " << attackDamage
              << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    hitPoints -= amount;
    if (hitPoints < 0)
        hitPoints = 0;

    std::cout << "ClapTrap " << name
              << " takes " << amount
              << " points of damage! (HP: " << hitPoints << ")" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " cannot be repaired (no hit points left)." << std::endl;
        return;
    }
    if (energyPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " cannot be repaired (no energy points left)." << std::endl;
        return;
    }

    energyPoints--;
    hitPoints += amount;

    std::cout << "ClapTrap " << name
              << " repairs itself for " << amount
              << " hit points! (HP: " << hitPoints << ")" << std::endl;
}

