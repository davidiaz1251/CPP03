#include "DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), name("Default")
{
    // Set attributes according to subject:
    // Hit points (FragTrap), Energy points (ScavTrap), Attack damage (FragTrap)
    this->hitPoints = 100;   // FragTrap value
    this->energyPoints = 50; // ScavTrap value
    this->attackDamage = 30; // FragTrap value
    std::cout << "DiamondTrap " << name << " is constructed!" << std::endl;
}

// Parameterized constructor
DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
    // Set attributes according to subject:
    // Hit points (FragTrap), Energy points (ScavTrap), Attack damage (FragTrap)
    this->hitPoints = 100;   // FragTrap value
    this->energyPoints = 50; // ScavTrap value
    this->attackDamage = 30; // FragTrap value
    std::cout << "DiamondTrap " << name << " is constructed!" << std::endl;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name)
{
    std::cout << "DiamondTrap " << name << " is copied!" << std::endl;
}

// Destructor
DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << name << " is destroyed!" << std::endl;
}

// Assignment operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        this->name = other.name;
        std::cout << "DiamondTrap " << name << " is assigned!" << std::endl;
    }
    return *this;
}

// Special ability
void DiamondTrap::whoAmI()
{
    std::cout << "I am DiamondTrap " << this->name
              << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}