#include "ClapTrap.hpp"
#include <sstream>

int main()
{
    std::cout << "=== Testing ClapTrap ===" << std::endl;

    std::cout << "\n--- Constructor Test ---" << std::endl;
    ClapTrap claptrap1("CT-01");
    ClapTrap claptrap2("CT-02");

    std::cout << "\n--- Attack Test ---" << std::endl;
    claptrap1.attack("Enemy1");
    claptrap1.attack("Enemy2");

    std::cout << "\n--- Take Damage Test ---" << std::endl;
    claptrap2.takeDamage(5);
    claptrap2.takeDamage(3);
    claptrap2.takeDamage(10);

    std::cout << "\n--- Repair Test ---" << std::endl;
    claptrap1.beRepaired(5);
    claptrap1.beRepaired(3);

    std::cout << "\n--- Energy Depletion Test ---" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::stringstream ss;
        ss << "Target" << i;
        claptrap1.attack(ss.str());
    }
    claptrap1.attack("LastTarget");
    claptrap1.beRepaired(1);

    std::cout << "\n--- Destroyed ClapTrap Test ---" << std::endl;
    claptrap2.attack("Someone");
    claptrap2.beRepaired(5);
    claptrap2.takeDamage(1);

    std::cout << "\n--- Copy Constructor Test ---" << std::endl;
    ClapTrap claptrap3("Original");
    claptrap3.takeDamage(2);
    ClapTrap claptrap4(claptrap3);

    std::cout << "\n--- Assignment Operator Test ---" << std::endl;
    ClapTrap claptrap5("ToBeAssigned");
    claptrap5 = claptrap3;

    std::cout << "\n--- Destructors will be called now ---" << std::endl;
    return 0;
}
