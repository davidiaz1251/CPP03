#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() : ClapTrap()
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << name << " is constructed!" << std::endl;
}

// Parameterized constructor
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << name << " is constructed!" << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap " << name << " is copied!" << std::endl;
}

// Destructor
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " is destroyed!" << std::endl;
}

// Assignment operator
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        std::cout << "ScavTrap " << name << " is assigned!" << std::endl;
    }
    return *this;
}

// Override attack function
void ScavTrap::attack(const std::string &target)
{
    if (hitPoints == 0)
    {
        std::cout << "ScavTrap " << name << " cannot attack because it has no hit points left!" << std::endl;
        return;
    }
    if (energyPoints == 0)
    {
        std::cout << "ScavTrap " << name << " cannot attack because it has no energy points left!" << std::endl;
        return;
    }

    energyPoints--;
    std::cout << "ScavTrap " << name << " attacks " << target
              << ", causing " << attackDamage << " points of damage!" << std::endl;
}

// Special ability
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode!" << std::endl;
}