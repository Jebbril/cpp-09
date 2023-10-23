/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:47:48 by orakib            #+#    #+#             */
/*   Updated: 2023/10/23 13:17:18 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIT_EX_HPP

#define BIT_EX_HPP

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>

class	BitcoinExchange {
	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &obj);
		BitcoinExchange	&operator=(const BitcoinExchange &obj);
		~BitcoinExchange();
	public:
		static std::map<std::string, double>	_data;
		static int	retrieveData();
		static int	makeExchanges(std::string &arg);
};

#endif