#include "ClapTrap.hpp"
#include <sstream>

int main()
{
    std::cout << "=== Testing ClapTrap ===" << std::endl;

    // Test constructor
    std::cout << "\n--- Constructor Test ---" << std::endl;
    ClapTrap claptrap1("CT-01");
    ClapTrap claptrap2("CT-02");

    // Test attack
    std::cout << "\n--- Attack Test ---" << std::endl;
    claptrap1.attack("Enemy1");
    claptrap1.attack("Enemy2");

    // Test take damage
    std::cout << "\n--- Take Damage Test ---" << std::endl;
    claptrap2.takeDamage(5);
    claptrap2.takeDamage(3);
    claptrap2.takeDamage(10); // This should destroy it

    // Test repair
    std::cout << "\n--- Repair Test ---" << std::endl;
    claptrap1.beRepaired(5);
    claptrap1.beRepaired(3);

    // Test energy depletion
    std::cout << "\n--- Energy Depletion Test ---" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::stringstream ss;
        ss << "Target" << i;
        claptrap1.attack(ss.str());
    }
    // This should fail due to no energy
    claptrap1.attack("LastTarget");
    claptrap1.beRepaired(1);

    // Test destroyed claptrap
    std::cout << "\n--- Destroyed ClapTrap Test ---" << std::endl;
    claptrap2.attack("Someone");
    claptrap2.beRepaired(5);
    claptrap2.takeDamage(1);

    // Test copy constructor
    std::cout << "\n--- Copy Constructor Test ---" << std::endl;
    ClapTrap claptrap3("Original");
    claptrap3.takeDamage(2);
    ClapTrap claptrap4(claptrap3);

    // Test assignment operator
    std::cout << "\n--- Assignment Operator Test ---" << std::endl;
    ClapTrap claptrap5("ToBeAssigned");
    claptrap5 = claptrap3;

    std::cout << "\n--- Destructors will be called now ---" << std::endl;
    return 0;
}