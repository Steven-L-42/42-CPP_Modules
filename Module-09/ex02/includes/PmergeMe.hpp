/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:02:05 by slippert          #+#    #+#             */
/*   Updated: 2024/02/02 12:12:46 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
#include <queue>

#define blue "\033[1;34m"
#define red "\033[1;31m"
#define green "\033[1;32m"
#define reset "\033[0m"

class PmergeMe
{
private:
	const static int MIN_CHUNK_SIZE = 5;
	std::vector<int> insertionVec;
	PmergeMe(const PmergeMe &ref);
	PmergeMe &operator=(const PmergeMe &ref);
	bool is_sorted();
	void startSort(int startIdx, int endIdx);
	void display();
	void insertionRotate(size_t until_index);
	void insertion(int startIdx, int endIdx);
	void merge(int startIdx, int midIdx, int endIdx);
	class InvalidInputException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class SortedNumbersException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

public:
	PmergeMe();
	~PmergeMe();
	void FordJohnson(int _size, char **_argv);
};
