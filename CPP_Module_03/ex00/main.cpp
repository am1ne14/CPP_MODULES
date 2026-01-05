#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap aa("aa");
    ClapTrap bb("bb");

    std::cout << "\n--- Attacks ---\n";
    aa.attack("bb");
    aa.attack("bb");

    std::cout << "\n--- Damage ---\n";
    aa.takeDamage(3);
    aa.takeDamage(20);

    std::cout << "\n--- Repair ---\n";
    aa.beRepaired(5);

    std::cout << "\n--- Energy Drain ---\n";
    ClapTrap cc("cc");
    for (int i = 0; i < 11; i++)
        cc.attack("dd");

    std::cout << "\n--- End ---\n";
    return 0;
}

