#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), name("Default")
{


    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 30;
    std::cout << "DiamondTrap " << name << " is constructed!" << std::endl;
}


DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{


    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 30;
    std::cout << "DiamondTrap " << name << " is constructed!" << std::endl;
}


DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name)
{
    std::cout << "DiamondTrap " << name << " is copied!" << std::endl;
}


DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << name << " is destroyed!" << std::endl;
}


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


void DiamondTrap::whoAmI()
{
    std::cout << "I am DiamondTrap " << this->name
              << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}