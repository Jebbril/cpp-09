/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:18:39 by orakib            #+#    #+#             */
/*   Updated: 2023/10/23 16:53:56 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP

#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

class	RPN {
	private:
		static std::string			input;
		static std::stack<double>	s;
		RPN();
		RPN(const RPN &obj);
		RPN	&operator=(const RPN &obj);
		~RPN();
	public:
		static int	parseInput(std::string &arg);
		static int	calculate();
};

#endif