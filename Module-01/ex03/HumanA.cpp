# include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
    std::cout << this->name 
        << " HumanA created" <<  std::endl;
}

HumanA::~HumanA()
{
    std::cout << this->name <<" HumanA destroyed" << std::endl;
}

void HumanA::setWeapon(Weapon &weapon)
{
    this->weapon = weapon;
}

void HumanA::attack()
{
    std::cout << this->name 
        << " attacks with their "
        << this->weapon.getType() <<  std::endl;
}
