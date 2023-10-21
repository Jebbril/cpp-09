/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:47:48 by orakib            #+#    #+#             */
/*   Updated: 2023/10/21 20:05:51 by orakib           ###   ########.fr       */
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
		static std::map<std::string, double>	_input;
		static int	retrieveData();
		static int	retrieveInput(std::string &arg);
		static int	parseInput();
		static int	outputValues();
};

#endif