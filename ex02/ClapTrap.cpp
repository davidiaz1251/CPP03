#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " is constructed!" << std::endl;
}

// Parameterized constructor
ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " is constructed!" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name), hitPoints(other.hitPoints),
                                            energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
    std::cout << "ClapTrap " << name << " is copied!" << std::endl;
}

// Destructor
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " is destroyed!" << std::endl;
}

// Assignment operator
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
        std::cout << "ClapTrap " << name << " is assigned!" << std::endl;
    }
    return *this;
}

// Attack function
void ClapTrap::attack(const std::string &target)
{
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " cannot attack because it has no hit points left!" << std::endl;
        return;
    }
    if (energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " cannot attack because it has no energy points left!" << std::endl;
        return;
    }

    energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target
              << ", causing " << attackDamage << " points of damage!" << std::endl;
}

// Take damage function
void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " is already destroyed!" << std::endl;
        return;
    }

    if (amount >= hitPoints)
    {
        hitPoints = 0;
        std::cout << "ClapTrap " << name << " takes " << amount
                  << " points of damage and is destroyed!" << std::endl;
    }
    else
    {
        hitPoints -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount
                  << " points of damage! Hit points remaining: " << hitPoints << std::endl;
    }
}

// Be repaired function
void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " cannot be repaired because it's destroyed!" << std::endl;
        return;
    }
    if (energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " cannot be repaired because it has no energy points left!" << std::endl;
        return;
    }

    energyPoints--;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " is repaired for " << amount
              << " hit points! Current hit points: " << hitPoints << std::endl;
}

// Getters
std::string ClapTrap::getName() const
{
    return name;
}

unsigned int ClapTrap::getHitPoints() const
{
    return hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const
{
    return energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const
{
    return attackDamage;
}