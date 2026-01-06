#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap aa("aa");
    ClapTrap bb("bb");
    aa.attack("bb");
    aa.attack("bb");
    aa.takeDamage(3);
    aa.takeDamage(20);
    aa.beRepaired(5);
    ClapTrap cc("cc");
    for (int i = 0; i <= 10; i++)
        cc.attack("dd");
    return 0;
}