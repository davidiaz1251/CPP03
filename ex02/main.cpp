#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <sstream>

int main()
{
    std::cout << "=== Testing ClapTrap ===" << std::endl;


    std::cout << "\n--- ClapTrap Constructor Test ---" << std::endl;
    ClapTrap claptrap1("CT-01");
    claptrap1.attack("Enemy1");

    std::cout << "\n=== Testing ScavTrap ===" << std::endl;


    std::cout << "\n--- ScavTrap Constructor Test ---" << std::endl;
    ScavTrap scavtrap1("ST-01");

    std::cout << "ScavTrap " << scavtrap1.getName() << " stats: HP=" << scavtrap1.getHitPoints()
              << ", EP=" << scavtrap1.getEnergyPoints() << ", AD=" << scavtrap1.getAttackDamage() << std::endl;

    scavtrap1.attack("Bandit");
    scavtrap1.guardGate();

    std::cout << "\n=== Testing FragTrap ===" << std::endl;


    std::cout << "\n--- FragTrap Constructor Test ---" << std::endl;
    FragTrap fragtrap1("FT-01");

    std::cout << "\n--- FragTrap Stats Test ---" << std::endl;
    std::cout << "FragTrap " << fragtrap1.getName() << " has:" << std::endl;
    std::cout << "- Hit Points: " << fragtrap1.getHitPoints() << std::endl;
    std::cout << "- Energy Points: " << fragtrap1.getEnergyPoints() << std::endl;
    std::cout << "- Attack Damage: " << fragtrap1.getAttackDamage() << std::endl;


    std::cout << "\n--- FragTrap Attack Test ---" << std::endl;
    fragtrap1.attack("Psycho");
    fragtrap1.attack("Skag");


    std::cout << "\n--- FragTrap Inherited Functions Test ---" << std::endl;
    fragtrap1.takeDamage(40);
    fragtrap1.beRepaired(20);


    std::cout << "\n--- FragTrap Special Ability Test ---" << std::endl;
    fragtrap1.highFivesGuys();


    std::cout << "\n--- FragTrap Copy Constructor Test ---" << std::endl;
    FragTrap fragtrap2(fragtrap1);

    std::cout << "\n--- FragTrap Assignment Operator Test ---" << std::endl;
    FragTrap fragtrap3("FT-03");
    fragtrap3 = fragtrap1;


    std::cout << "\n--- Class Comparison Test ---" << std::endl;
    std::cout << "ClapTrap: HP=10, EP=10, AD=0" << std::endl;
    std::cout << "ScavTrap: HP=100, EP=50, AD=20 (overrides attack)" << std::endl;
    std::cout << "FragTrap: HP=100, EP=100, AD=30 (uses ClapTrap attack)" << std::endl;


    std::cout << "\n--- FragTrap Energy Test ---" << std::endl;
    FragTrap energyTester("EnergyTester");
    for (int i = 0; i < 50; i++)
    {
        std::stringstream ss;
        ss << "Target" << i;
        energyTester.attack(ss.str());
    }
    for (int i = 0; i < 50; i++)
    {
        energyTester.beRepaired(1);
    }

    energyTester.attack("LastTarget");
    energyTester.beRepaired(1);
    energyTester.highFivesGuys();

    std::cout << "\n--- Destructors will be called now (reverse order) ---" << std::endl;
    return 0;
}