/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:02:05 by slippert          #+#    #+#             */
/*   Updated: 2024/02/05 12:58:44 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>

#define blue "\033[1;34m"
#define red "\033[1;31m"
#define green "\033[1;32m"
#define white "\033[1;37m"
#define reset "\033[0m"

class PmergeMe
{
private:
	const static int MIN_CHUNK_SIZE = 5;
	std::vector<int> conVector;
	std::deque<int> conDeque;
	PmergeMe(const PmergeMe &ref);
	PmergeMe &operator=(const PmergeMe &ref);
	template <class T>
	void templateSort(T &container, double &duration, int _size, char **_argv);
	template <class T>
	void startSort(T &container, int startIdx, int endIdx);
	template <class T>
	void display(T container);
	template <class T>
	void displayTime(T container, std::string containerType, double duration);
	template <class T>
	void insertion(T &container, int startIdx, int endIdx);
	template <class T>
	void merge(T &container, int startIdx, int midIdx, int endIdx);
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

template <class T>
void PmergeMe::displayTime(T container, std::string containerType, double duration)
{
	std::cout.precision(0);

	std::cout << white << "Time to process a range of "
			  << blue << container.size() << " elements "
			  << white << "with " << blue << containerType
			  << white << " : " << blue << std::fixed << duration << " μs"
			  << std::endl;
}

template <class T>
void PmergeMe::display(T container)
{
	typedef typename T::iterator iteratorType;
	for (iteratorType it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

/*
 * The "merge" function merges two sorted subarrays within the given container.
 * It assumes that the subarrays [startIndex, midIndex] and [midIndex + 1, endIndex]
 * are already sorted. The merging is performed in a way that maintains the sorted order.
 *
 * @param container - The container holding the elements to be merged.
 * @param startIndex - The start index of the first subarray to be merged.
 * @param midIndex - The end index of the first subarray, also the start index of the second subarray.
 * @param endIndex - The end index of the second subarray to be merged.
 */
template <class T>
void PmergeMe::merge(T &container, int startIndex, int midIndex, int endIndex)
{
	int leftSize = midIndex - startIndex + 1;
	int rightSize = endIndex - midIndex;

	T leftCon(container.begin() + startIndex, container.begin() + startIndex + leftSize);
	T rightCon(container.begin() + midIndex + 1, container.begin() + midIndex + 1 + rightSize);

	int leftIndex = 0;
	int rightIndex = 0;

	for (int i = startIndex; i <= endIndex; i++)
	{
		if (rightIndex == rightSize)
			container[i] = leftCon[leftIndex], leftIndex++;
		else if (leftIndex == leftSize)
			container[i] = rightCon[rightIndex], rightIndex++;
		else if (rightCon[rightIndex] > leftCon[leftIndex])
			container[i] = leftCon[leftIndex], leftIndex++;
		else
			container[i] = rightCon[rightIndex], rightIndex++;
	}
}

template <class T>
void PmergeMe::insertion(T &container, int startIndex, int endIndex)
{
	for (int i = startIndex; i < endIndex; i++)
	{
		int currentVal = container[i + 1];
		int j = i + 1;
		while (j > startIndex && container[j - 1] > currentVal)
			container[j] = container[j - 1], j--;
		container[j] = currentVal;
	}
}

/*
 * The "startSort" function implements the recursive approach for the Mergesort algorithm.
 * It sorts a subrange of a container from index "startIndex" to "endIndex".
 * If the range is large enough, it is divided into two parts, each recursively sorted.
 * Then, the sorted parts are merged using the "merge" function.
 * If the range is small enough, the insertion sort algorithm "insertion" is used instead.
 *
 * @param container - The container holding the elements to be sorted.
 * @param startIndex - The start index of the range to be sorted.
 * @param endIndex - The end index of the range to be sorted.
 */
template <class T>
void PmergeMe::startSort(T &container, int startIndex, int endIndex)
{
	if (endIndex - startIndex > MIN_CHUNK_SIZE)
	{
		int minIndex = (startIndex + endIndex) / 2;
		startSort(container, startIndex, minIndex);
		startSort(container, minIndex + 1, endIndex);
		merge(container, startIndex, minIndex, endIndex);
	}
	else
		insertion(container, startIndex, endIndex);
}

template <class T>
void PmergeMe::templateSort(T &container, double &duration, int _size, char **_argv)
{
	std::clock_t start_time = std::clock();

	for (int i = 1; i < _size; i++)
		container.push_back(static_cast<int>(std::atoi(_argv[i])));

	startSort(container, 0, container.size() - 1);

	std::clock_t stop_time = std::clock();
	duration = std::difftime(stop_time, start_time);
}