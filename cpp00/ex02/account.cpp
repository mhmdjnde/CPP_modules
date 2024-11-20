#include <iostream>
#include "Account.hpp"
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	std::cout << "Total Accounts: " << _nbAccounts << std::endl;
    std::cout << "Total Amount: " << _totalAmount << std::endl;
    std::cout << "Total Deposits: " << _totalNbDeposits << std::endl;
    std::cout << "Total Withdrawals: " << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;
	std::cout << deposit << "$ were added to your account" << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal > _amount)
	{
		std::cout << "Withdrawal refused" << std::endl;
		return (false);
	}
	_displayTimestamp();
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	std::cout << withdrawal << "$ were reduced from your account" << std::endl;
	return (true);
}

int		Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	std::cout << "your account index is: " << _accountIndex << std::endl;
	std::cout << "your account balance is: " << _amount << "$" << std::endl;
	std::cout << "you did " << _nbDeposits << " deposits" << std::endl;
	std::cout << "you did " << _nbWithdrawals << " withdrawals" << std::endl;
}

void Account::_displayTimestamp(void) {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    std::cout	<< "["
        	<< 1900 + ltm->tm_year
        	<< std::setw(2) << std::setfill('0') << 1 + ltm->tm_mon
        	<< std::setw(2) << std::setfill('0') << ltm->tm_mday
        	<< "_"
        	<< std::setw(2) << std::setfill('0') << ltm->tm_hour
        	<< std::setw(2) << std::setfill('0') << ltm->tm_min
        	<< std::setw(2) << std::setfill('0') << ltm->tm_sec
        	<< "] ";
}

Account::Account(int initial_deposit)
{
	if (initial_deposit < 0)
	{
		std::cout << "error creating account" << std::endl;
		return ;
	}
	_accountIndex  = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	if (initial_deposit > 0)
		_nbDeposits = 1;
	else
		_nbDeposits = 0;
	_amount = initial_deposit;
	_nbWithdrawals = 0;
}

Account::~Account(void) {
    _nbAccounts--;
    _displayTimestamp();
    std::cout << "Account closed: " << _accountIndex << std::endl;
}
