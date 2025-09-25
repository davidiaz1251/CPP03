#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    // Constructors and destructor
    FragTrap();
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &other);
    ~FragTrap();

    // Assignment operator
    FragTrap &operator=(const FragTrap &other);

    // Special ability
    void highFivesGuys(void);
};

#endif