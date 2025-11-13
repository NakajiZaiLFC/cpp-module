#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	_nbAccounts++;
	_totalAmount += initial_deposit;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";created" << std::endl;
}

Account::~Account(void)
{
	_nbAccounts--;
	_totalAmount -= this->_amount;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";closed" << std::endl;
}

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}
int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts()
			  << ";total:" << Account::getTotalAmount()
			  << ";deposits:" << Account::getNbDeposits()
			  << ";withdrawals:" << Account::getNbWithdrawals()
			  << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";p_amount:" << this->_amount - deposit;
	std::cout << ";deposit:" << deposit
			  << ";amount:" << this->_amount
			  << ";nb_deposits:" << this->_nbDeposits
			  << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";p_amount:" << this->_amount;
	if (withdrawal > this->_amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	else
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		_nbWithdrawals++;

		std::cout << ";withdrawal:" << withdrawal
				  << ";amount:" << this->_amount
				  << ";nb_withdrawals:" << this->_nbWithdrawals
				  << std::endl;
		return true;
	}
}

int Account::checkAmount(void) const
{
	return _amount;
}

void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";deposits:" << this->_nbDeposits
			  << ";withdrawals:" << this->_nbWithdrawals
			  << std::endl;
}

void Account::_displayTimestamp(void)
{
    std::time_t rawtime;
    std::time(&rawtime);

    std::tm *timeinfo;
    timeinfo = std::localtime(&rawtime);
    
    char buffer[18];

    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", timeinfo);

    std::cout << buffer << " ";
}