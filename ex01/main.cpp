/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:18:35 by orakib            #+#    #+#             */
/*   Updated: 2023/10/23 16:59:46 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av) {
	if (ac == 2) {
		std::string	arg = av[1];
		if (RPN::parseInput(arg) || RPN::calculate()) {
			std::cerr << "Error" << std::endl;
			return (1);
		}
		return (0);
	}
	return (1);
}