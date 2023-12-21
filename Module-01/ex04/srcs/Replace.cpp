/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 08:19:52 by slippert          #+#    #+#             */
/*   Updated: 2023/12/12 14:34:16 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Replace.hpp"

Replace::Replace(char **argv)
{
	this->filename = argv[0];
	this->s1 = argv[1];
	this->s2 = argv[2];
}

Replace::~Replace() {}

int Replace::initReplace()
{
	std::ifstream inputFile(this->filename);
	if (!inputFile.is_open())
	{
		std::cerr << "Error: opening the file!" << std::endl;
		return (1);
	}
	std::ofstream outputFile(this->filename + ".replace");
	if (!outputFile.is_open())
	{
		std::cerr << "Error: creating the file!" << std::endl;
		return (1);
	}
	startReplace(inputFile, outputFile);
	return (0);
}

void Replace::startReplace(std::ifstream &inputFile, std::ofstream &outputFile)
{
	std::string line;
	while (std::getline(inputFile, line))
	{
		std::string replace;
		replace = line;
		size_t foundPos;
		while ((foundPos = replace.find(this->s1)) != std::string::npos)
		{
			replace.erase(foundPos, this->s1.length());
			replace.insert(foundPos, this->s2);
		}
		outputFile << replace;
		if (!inputFile.eof())
			outputFile << std::endl;
	}
	inputFile.close();
	outputFile.close();
}
