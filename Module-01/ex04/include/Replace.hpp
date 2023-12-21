/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 08:19:55 by slippert          #+#    #+#             */
/*   Updated: 2023/12/12 14:34:24 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __REPLACE_H__
#define __REPLACE_H__

#include <iostream>
#include <fstream>
#include <string>

class Replace
{
	private:
	std::string filename;
	std::string s1;
	std::string s2;

	public:
	Replace(char **argv);
	~Replace();
	int initReplace();
	void startReplace(std::ifstream &inputFile, std::ofstream &outputFile);
};

#endif
