#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <sstream>

int main()
{
    std::cout << "=== Testing DiamondTrap - The Ultimate Test! ===" << std::endl;


    std::cout << "\n--- DiamondTrap Constructor Test ---" << std::endl;
    DiamondTrap diamond1("DT-01");

    std::cout << "\n--- DiamondTrap Stats Test ---" << std::endl;
    std::cout << "DiamondTrap " << diamond1.getName() << " has:" << std::endl;
    std::cout << "- Hit Points: " << diamond1.getHitPoints() << " (should be 100 from FragTrap)" << std::endl;
    std::cout << "- Energy Points: " << diamond1.getEnergyPoints() << " (should be 50 from ScavTrap)" << std::endl;
    std::cout << "- Attack Damage: " << diamond1.getAttackDamage() << " (should be 30 from FragTrap)" << std::endl;


    std::cout << "\n--- DiamondTrap Attack Test ---" << std::endl;
    diamond1.attack("Boss");
    diamond1.attack("Minion");


    std::cout << "\n--- DiamondTrap Inherited Functions Test ---" << std::endl;
    diamond1.takeDamage(25);
    diamond1.beRepaired(10);


    std::cout << "\n--- DiamondTrap Special Abilities Test ---" << std::endl;
    diamond1.guardGate();
    diamond1.highFivesGuys();
    diamond1.whoAmI();


    std::cout << "\n--- DiamondTrap Copy Constructor Test ---" << std::endl;
    DiamondTrap diamond2(diamond1);
    diamond2.whoAmI();


    std::cout << "\n--- DiamondTrap Assignment Operator Test ---" << std::endl;
    DiamondTrap diamond3("DT-03");
    diamond3 = diamond1;
    diamond3.whoAmI();


    std::cout << "\n--- Diamond Problem Resolution Test ---" << std::endl;
    std::cout << "Testing that there's only ONE ClapTrap instance in DiamondTrap..." << std::endl;
    DiamondTrap diamond4("TestDiamond");
    diamond4.whoAmI();
    std::cout << "If you see only one ClapTrap construction message above, virtual inheritance works!" << std::endl;


    std::cout << "\n--- All Classes Comparison ---" << std::endl;
    std::cout << "ClapTrap:   HP=10,  EP=10,  AD=0   (base class)" << std::endl;
    std::cout << "ScavTrap:   HP=100, EP=50,  AD=20  (overrides attack)" << std::endl;
    std::cout << "FragTrap:   HP=100, EP=100, AD=30  (uses ClapTrap attack)" << std::endl;
    std::cout << "DiamondTrap:HP=100, EP=50,  AD=30  (uses ScavTrap attack)" << std::endl;


    std::cout << "\n--- DiamondTrap Energy Depletion Test ---" << std::endl;
    DiamondTrap energyTester("EnergyTester");
    for (int i = 0; i < 25; i++)
    {
        std::stringstream ss;
        ss << "Target" << i;
        energyTester.attack(ss.str());
    }
    for (int i = 0; i < 25; i++)
    {
        energyTester.beRepaired(1);
    }

    energyTester.attack("LastTarget");
    energyTester.beRepaired(1);

    energyTester.guardGate();
    energyTester.highFivesGuys();
    energyTester.whoAmI();

    std::cout << "\n--- All Destructors will be called now (reverse order) ---" << std::endl;
    return 0;
}