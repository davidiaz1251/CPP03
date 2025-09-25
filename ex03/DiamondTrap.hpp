#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string name; // Same variable name as ClapTrap::name

public:
    // Constructors and destructor
    DiamondTrap();
    DiamondTrap(const std::string &name);
    DiamondTrap(const DiamondTrap &other);
    ~DiamondTrap();

    // Assignment operator
    DiamondTrap &operator=(const DiamondTrap &other);

    // Special ability
    void whoAmI();

    // Override attack to use ScavTrap's version
    using ScavTrap::attack;
};

#endif