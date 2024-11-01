
#include "Harl.hpp"

Harl::Harl()
{
    
}

Harl::~Harl()
{
    
}

void Harl::complain(std::string level)
{
    std::string levelArr[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "OTHERS"};
    void (Harl::*choiceOfComplain[5])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::others};

    for (int i = 0; i < 5; i++)
    {
        if (level == levelArr[i] || i == 4)
        {
            (this->*choiceOfComplain[i])();
            return;
        }
    }

}

void Harl::debug(void)
{
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl;

}

void Harl::info(void)
{
    std::cout << "[INFO]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[WARNING]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager.\n" << std::endl;
}

void Harl::others(void)
{
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
