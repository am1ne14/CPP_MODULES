#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    FragTrap aa("AA");
    aa.attack("target1");
    aa.highFivesGuys();

    FragTrap bb = aa;
    bb.attack("target2");

    FragTrap cc("CC");
    cc = aa;
    cc.attack("target3");

    ScavTrap dd("DD");
    dd.attack("target4");
    dd.guardGate();

    return 0;
}

