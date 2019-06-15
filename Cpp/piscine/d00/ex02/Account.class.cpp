
// ************************************************************************** //
//                                                                            //
//                Account.class.cpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : t "Scienthou" behra <__@g__.com>                  //
//                                                                            //
// ************************************************************************** //

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

#include <string>
#include <iostream>
#include "Account.class.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) {
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void ) {
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:"
		<< Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits
		<< ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
	return ;
}

void Account::_displayTimestamp( void ) {
	std::time_t t = std::time(nullptr);
	char timeString[21];
	if (std::strftime(timeString, sizeof(timeString), "[%Y%m%d_%H%M%S] ", std::localtime(&t))) {
		std::cout << timeString;
	}
}

Account::Account(int initial_deposit) {
	this->_amount = initial_deposit;
	this->_accountIndex = Account::_nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" 
		<< initial_deposit << ";created" << std::endl; 
	Account::_nbAccounts++;	
	Account::_totalAmount += initial_deposit;
}

Account::~Account(void) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
		<< ";closed" << std::endl; 
}

void	Account::makeDeposit(int deposit) {
	Account::_displayTimestamp();
	if (deposit > 0) {
		std::cout << "index:" << this->_accountIndex << ";p_amount:"
			<< this->_amount << ";deposit:" << deposit << ";amount:";
		this->_amount += deposit;
		Account::_totalAmount += deposit;
		this->_nbDeposits++;
		Account::_totalNbDeposits++;
		std::cout << this->_amount << ";nb_deposits:" << Account::_nbDeposits
			<< std::endl;
	}
}

bool Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();
	if (withdrawal > this->_amount) {
		std::cout << "index:" << this->_accountIndex << ";p_amount:"
			<< this->_amount << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else {
		std::cout << "index:" << this->_accountIndex << ";p_amount:"
			<< this->_amount << ";withdrawal:" << withdrawal << ";amount:";
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		std::cout << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals
			<< std::endl;
		return (true);
	}
}

int	Account::checkAmount( void ) const {
	return (this->_amount);
}

void	Account::displayStatus( void ) const {

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
		<< ";deposits:" << this->_nbDeposits << ";withdrawals:"
		<< this->_nbWithdrawals << std::endl;
	return ;
}
