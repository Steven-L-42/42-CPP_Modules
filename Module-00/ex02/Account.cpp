/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:25:43 by slippert          #+#    #+#             */
/*   Updated: 2023/12/08 13:17:59 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include "Account.hpp"
#include <chrono>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	std::cout
		<< "index:" << _nbAccounts
		<< ";amount:" << initial_deposit
		<< ";created"
	<< std::endl;

	_totalAmount += initial_deposit;
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
}

Account::~Account(void)
{
	_nbAccounts--;
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed"
	<< std::endl;
}

void Account::_displayTimestamp()
{
	std::time_t now = std::time(nullptr);
	std::tm *tm = std::localtime(&now);
	char buffer[16];
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", tm);
	std::cout << "[" << buffer << "] ";
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout
		<< "accounts:" << getNbAccounts()
		<< ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals()
	<< std::endl;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals
	<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	++_nbDeposits;
	int temp = _amount + deposit;
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";deposit:" << deposit
		<< ";amount:" << temp
		<< ";nb_deposits:" << _nbDeposits
	<< std::endl;

	_amount = temp;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	int temp = checkAmount() - withdrawal;
	if (temp < 0)
	{
		std::cout
			<< "index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";withdrawal:refused"
		<< std::endl;
		return (false);
	}
	std::cout
		<< "index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";withdrawal:" << withdrawal
		<< ";amount:" << temp
		<< ";nb_withdrawals:" << ++_nbWithdrawals
	<< std::endl;

	_amount = temp;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return (true);
}

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

int	Account::checkAmount(void) const
{
	return (_amount);
}
