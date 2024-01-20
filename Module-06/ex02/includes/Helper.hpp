/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Helper.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:00:58 by slippert          #+#    #+#             */
/*   Updated: 2024/01/20 15:23:02 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

class Base;


class Helper
{
	private:
	public:
		Helper();
		Helper(const Helper &ref);
		Helper &operator=(const Helper &ref);
		~Helper();
		Base * generate(void);
		void identify(Base* p);
		void identify(Base& p);
};
