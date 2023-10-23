/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:18:37 by orakib            #+#    #+#             */
/*   Updated: 2023/10/23 17:06:13 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::string			RPN::input;
std::stack<double>	RPN::s;

RPN::RPN() {

}

RPN::RPN(const RPN &obj) {
	(void)obj;
}

RPN	&RPN::operator=(const RPN &obj) {
	(void)obj;
	return (*this);
}
RPN::~RPN() {
	
}

int	RPN::parseInput(std::string &arg) {
	std::string	dig_op = "0123456789 +-*/";
	size_t	i = -1;
	
	if (arg.empty() || arg.find_first_not_of(dig_op) != std::string::npos)
		return (1);
	while (arg[++i]) {
		if (arg[i] == ' ')
			continue;
		if (arg[i] > '0' && arg[i] < '9' && arg[i + 1] && arg[i + 1] != ' ')
			return (1);
		else if ((arg[i] == '+' || arg[i] == '-' || arg[i] == '*' || arg[i] == '/')
				&& arg[i + 1] && arg[i + 1] != ' ')
			return (1);
	}
	input = arg;
	return (0);
}

int	RPN::calculate() {
	size_t	i = -1;
	double	f_param;
	double	s_param;

	while (input[++i]) {
		if (input[i] == ' ')
			continue;
		if (input[i] >= '0' && input[i] <= '9')
			s.push(input[i] - 48);
		else if (input[i] == '+' || input[i] == '-'
			|| input[i] == '*' || input[i] == '/') {
			if (s.size() < 2)
				return (1);
			f_param = s.top();
			s.pop();
			s_param = s.top();
			s.pop();
			switch (input[i])
			{
			case '+':
				s.push(s_param + f_param);
				break;
			case '-':
				s.push(s_param - f_param);
				break;
			case '*':
				s.push(s_param * f_param);
				break;
			case '/':
				if (f_param == 0)
					return (1);
				s.push(s_param / f_param);
				break;
			
			default:
				break;
			}
		}
	}
	if (s.size() > 1)
		return (1);
	std::cout << s.top() << std::endl;
	
	return (0);
}