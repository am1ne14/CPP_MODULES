#include "ScavTrap.hpp"

int main()
{
    ScavTrap aa("AA");
    aa.attack("target1");
    aa.guardGate();
    ScavTrap bb = aa;
    bb.attack("target2");
    ScavTrap cc("CC");
    cc = aa;
    cc.attack("target3");
    return 0;
}

