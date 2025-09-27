#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <sstream>

int main()
{
    std::cout << "=== Testing ClapTrap ===" << std::endl;


    std::cout << "\n--- ClapTrap Constructor Test ---" << std::endl;
    ClapTrap claptrap1("CT-01");


    std::cout << "\n--- ClapTrap Attack Test ---" << std::endl;
    claptrap1.attack("Enemy1");

    std::cout << "\n=== Testing ScavTrap ===" << std::endl;


    std::cout << "\n--- ScavTrap Constructor Test ---" << std::endl;
    ScavTrap scavtrap1("ST-01");

    std::cout << "\n--- ScavTrap Stats Test ---" << std::endl;
    std::cout << "ScavTrap " << scavtrap1.getName() << " has:" << std::endl;
    std::cout << "- Hit Points: " << scavtrap1.getHitPoints() << std::endl;
    std::cout << "- Energy Points: " << scavtrap1.getEnergyPoints() << std::endl;
    std::cout << "- Attack Damage: " << scavtrap1.getAttackDamage() << std::endl;


    std::cout << "\n--- ScavTrap Attack Test ---" << std::endl;
    scavtrap1.attack("Bandit");
    scavtrap1.attack("Raider");


    std::cout << "\n--- ScavTrap Inherited Functions Test ---" << std::endl;
    scavtrap1.takeDamage(30);
    scavtrap1.beRepaired(15);


    std::cout << "\n--- ScavTrap Special Ability Test ---" << std::endl;
    scavtrap1.guardGate();


    std::cout << "\n--- ScavTrap Copy Constructor Test ---" << std::endl;
    ScavTrap scavtrap2(scavtrap1);

    std::cout << "\n--- ScavTrap Assignment Operator Test ---" << std::endl;
    ScavTrap scavtrap3("ST-03");
    scavtrap3 = scavtrap1;


    std::cout << "\n--- ScavTrap Energy Depletion Test ---" << std::endl;
    ScavTrap scavtrap4("EnergyTester");
    for (int i = 0; i < 25; i++)
    {
        std::stringstream ss;
        ss << "Target" << i;
        scavtrap4.attack(ss.str());
    }
    for (int i = 0; i < 25; i++)
    {
        scavtrap4.beRepaired(1);
    }

    scavtrap4.attack("LastTarget");
    scavtrap4.beRepaired(1);

    std::cout << "\n--- Destructors will be called now (reverse order) ---" << std::endl;
    return 0;
}