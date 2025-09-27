#include "FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap()
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap " << name << " is constructed!" << std::endl;
}


FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap " << name << " is constructed!" << std::endl;
}


FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap " << name << " is copied!" << std::endl;
}


FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " is destroyed!" << std::endl;
}


FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        std::cout << "FragTrap " << name << " is assigned!" << std::endl;
    }
    return *this;
}


void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " requests positive high fives! ✋" << std::endl;
}