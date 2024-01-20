/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:06:51 by slippert          #+#    #+#             */
/*   Updated: 2024/01/20 14:39:38 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Data
{
  private:
	Data();
  public:
	std::string notify;
	Data(std::string _notify);
	Data(const Data &ref);
	Data &operator=(const Data &ref);
	~Data();
};
