/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:01:17 by slippert          #+#    #+#             */
/*   Updated: 2024/01/29 13:13:52 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

bool is_sorted(std::vector<int> arr)
{
	for (size_t i = 0; i < arr.size() - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return (false);
	}
	return (true);
}

void display(std::vector<int> arr)
{
	for (size_t i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void insertion_rotate(std::vector<int> &arr, size_t until_index)
{
	int tmp = arr[until_index];
	for (size_t i = until_index; i > 0; i--)
		arr[i] = arr[i - 1];
	arr[0] = tmp;
}

void insertion(std::vector<int> &arr)
{
	size_t tmp_index = 0;
	while (!is_sorted(arr))
	{
		for (size_t i = tmp_index + 1; i < arr.size(); i++)
		{
			if (arr[i] < arr[tmp_index])
				insertion_rotate(arr, i);
		}
		if (++tmp_index == arr.size())
			tmp_index = 0;
	}
}

void merge(std::vector<int> &arr)
{
	std::vector<int> tmp_arr = arr;
}

int main(int argc, char **argv)
{
	std::vector<int> arr;
	for (int i = 1; i < argc; i++)
		arr.push_back(static_cast<int>(std::atoi(argv[i])));

	// MERGE SORT

	// INSERTION SORT
	display(arr);
	insertion(arr);
	display(arr);
	return (0);
}
