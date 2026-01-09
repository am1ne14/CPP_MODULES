#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
    : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap Default constructed!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) 
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
    std::cout << "ClapTrap " << name << " copied!" << std::endl;
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
    std::cout << "ClapTrap " << name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        --energyPoints;
        std::cout << "ClapTrap " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!" 
                  << std::endl;
    }
    else
        std::cout << "ClapTrap " << name << " can't attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints > amount)
        hitPoints -= amount;
    else
        hitPoints = 0;
    std::cout << "ClapTrap " << name << " took " << amount << " damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        --energyPoints;
        hitPoints += amount;
        std::cout << "ClapTrap " << name << " repaired " << amount << " hit points!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << name << " can't be repaired!" << std::endl;
}

