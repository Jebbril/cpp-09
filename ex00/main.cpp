/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:47:33 by orakib            #+#    #+#             */
/*   Updated: 2023/10/21 19:49:04 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av) {
	if (ac == 2) {
		(void)av;
		BitcoinExchange::retrieveData();
		// std::map<std::string, double>::iterator it = BitcoinExchange::_data.begin();
		// while (it != BitcoinExchange::_data.end()) {
		// 	std::cout << it->first << "  :  " << it->second << std::endl;
		// 	it++;
		// }
	}
}