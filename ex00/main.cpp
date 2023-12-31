/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:47:33 by orakib            #+#    #+#             */
/*   Updated: 2023/10/23 13:19:35 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av) {
	if (ac == 2) {
		std::string	arg = av[1];
		BitcoinExchange::retrieveData();
		BitcoinExchange::makeExchanges(arg);
	}
}