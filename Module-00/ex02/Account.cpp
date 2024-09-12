#include "Account.hpp"
#include <iostream>
#include <ctime>


// initialize the static variables
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// constructor
Account::Account(int initial_deposit)
{

}

void	Account::_displayTimestamp(void)
{
    std::time_t t;
    struct tm   *date;

    t = std::time(NULL);
    date = std::localtime(&t);
}