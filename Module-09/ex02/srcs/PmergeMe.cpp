/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:23:57 by slippert          #+#    #+#             */
/*   Updated: 2024/02/02 12:46:55 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

const char *PmergeMe::InvalidInputException::what() const throw()
{
	static std::string msg = red + std::string("Error: your input contains invalid characters!\n") + blue + std::string("(Allowed: only positive Numbers)") + reset;
	return (msg.c_str());
}

const char *PmergeMe::SortedNumbersException::what() const throw()
{
	static std::string msg = red + std::string("Error: your input is already sorted!") + reset;
	return (msg.c_str());
}

bool PmergeMe::is_sorted()
{
	for (size_t i = 0; i < insertionVec.size() - 1; i++)
	{
		if (insertionVec[i] > insertionVec[i + 1])
			return (false);
	}
	return (true);
}

void PmergeMe::display()
{
	for (size_t i = 0; i < insertionVec.size(); i++)
		std::cout << insertionVec[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::insertionRotate(size_t until_index)
{
	int tmp = insertionVec[until_index];
	for (size_t i = until_index; i > 0; i--)
		insertionVec[i] = insertionVec[i - 1];
	insertionVec[0] = tmp;
}

void PmergeMe::insertion(int startIndex, int endIndex)
{
	for (int i = startIndex; i < endIndex; i++)
	{
		int currentVal = insertionVec[i + 1];
		int j = i + 1;
		while (j > startIndex && insertionVec[j - 1] > currentVal)
			insertionVec[j] = insertionVec[j - 1], j--;
		insertionVec[j] = currentVal;
	}
}

void PmergeMe::merge(int startIndex, int midIndex, int endIndex)
{
	int leftSize = midIndex - startIndex + 1;
	int rightSize = endIndex - midIndex;

	std::vector<int> leftVec(insertionVec.begin() + startIndex, insertionVec.begin() + startIndex + leftSize);
	std::vector<int> rightVec(insertionVec.begin() + midIndex + 1, insertionVec.begin() + midIndex + 1 + rightSize);

	int leftIndex = 0;
	int rightIndex = 0;
	std::queue<int> mergeQueue;
	for (int i = startIndex; i <= endIndex; i++)
	{
		if (rightIndex == rightSize)
			mergeQueue.push(leftVec[leftIndex]), leftIndex++;
		else if (leftIndex == leftSize)
			mergeQueue.push(rightVec[rightIndex]), rightIndex++;
		else if (rightVec[rightIndex] > leftVec[leftIndex])
			mergeQueue.push(leftVec[leftIndex]), leftIndex++;
		else
			mergeQueue.push(rightVec[rightIndex]), rightIndex++;
	}
	for (int i = startIndex; i <= endIndex; i++)
		insertionVec[i] = mergeQueue.front(), mergeQueue.pop();
}

void PmergeMe::startSort(int startIndex, int endIndex)
{
	if (endIndex - startIndex > MIN_CHUNK_SIZE)
	{
		int minIndex = (startIndex + endIndex) / 2;
		startSort(startIndex, minIndex);
		startSort(minIndex + 1, endIndex);
		merge(startIndex, minIndex, endIndex);
	}
	else
		insertion(startIndex, endIndex);
}

void PmergeMe::FordJohnson(int _size, char **_argv)
{

	for (int i = 1; i < _size; i++)
	{
		int nbr = static_cast<int>(std::atoi(_argv[i]));
		if (nbr <= 0)
			throw(InvalidInputException());
		insertionVec.push_back(nbr);
	}

	std::cout << blue << "Before:\t" << green;
	display();

	if (is_sorted())
		throw(SortedNumbersException());
	startSort(0, insertionVec.size() - 1);

	std::cout << blue << "After:\t" << green;
	display();
}
