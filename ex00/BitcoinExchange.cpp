/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:47:42 by orakib            #+#    #+#             */
/*   Updated: 2023/10/23 13:46:37 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::string, double>	BitcoinExchange::_data;

BitcoinExchange::BitcoinExchange() {

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) {
	(void)obj;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &obj) {
	(void)obj;
	return (*this);
}
BitcoinExchange::~BitcoinExchange() {
	
}

int	BitcoinExchange::retrieveData() {
	std::ifstream	dataFile;
	std::string		dataLine;
	double			value;

	dataFile.open("data.csv");
	if (!dataFile.is_open()) {
		std::cerr << "Cannot open the data file" << std::endl;
		return (1);
	}
	std::getline(dataFile, dataLine);
	while (std::getline(dataFile, dataLine)) {
		std::stringstream(dataLine.substr(11)) >> value;
		_data[dataLine.substr(0, 10)] = value;
	}
	
	return (0);
}

int	parseKey(std::string key) {
	if (key[4] != '-' || key[7] != '-') {
		std::cerr << "Error: bad date format" << std::endl;
		return (1);
	}
	std::string	yearstr = key.substr(0, 4);
	std::string	monthstr = key.substr(5, 2);
	std::string	daystr = key.substr(8, 2);
	std::string	digits = "0123456789";
	
	if (yearstr.find_first_not_of(digits) != std::string::npos
		|| monthstr.find_first_not_of(digits) != std::string::npos
		|| daystr.find_first_not_of(digits) != std::string::npos) {
		std::cerr << "Error: date contains characters other than digits" << std::endl;
		return (1);
	}
	int	year;
	int	month;
	int	day;

	std::stringstream(yearstr) >> year;
	std::stringstream(monthstr) >> month;
	std::stringstream(daystr) >> day;
	if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31
		|| key == "2009-01-01") {
		std::cerr << "Error: invalid date" << std::endl;
		return (1);
	}
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30) {
			std::cerr << "Error: invalid date" << std::endl;
			return (1);
		}
	}
	if (month == 2) {
		if (year % 4 == 0 && (year % 100 || year % 400 == 0)) {
			if (day > 29) {
				std::cerr << "Error: invalid date" << std::endl;
				return (1);
			}
		}
		else {
			if (day > 28) {
				std::cerr << "Error: invalid date" << std::endl;
				return (1);
			}
		}
	}
	
	return (0);
}

int	parseValue(std::string valuestr) {
	size_t	i = -1;
	size_t	dot_count = 0;
	std::string	digits = "0123456789.";
	double	value;
	
	if (valuestr[0] == '-') {
		std::cerr << "Error: not a positive number." << std::endl;
		return (1);
	}
	if (valuestr.find_first_not_of(digits) != std::string::npos) {
		std::cerr << "Error: value contains characters other than digits" << std::endl;
		return (1);
	}
	while (valuestr[++i])
		if (valuestr[i] == '.')
			dot_count++;
	if (dot_count > 1) {
		std::cerr << "Error: invalid value" << std::endl;
		return (1);
	}
	std::stringstream(valuestr) >> value;
	if (value > 1000) {
		std::cerr << "Error: too large a number." << std::endl;
		return (1);
	}
	return (0);
}

int	BitcoinExchange::makeExchanges(std::string &arg) {
	std::ifstream	inputFile;
	std::string		inputLine;
	std::string		key;
	std::string		valuestr;
	double			value;
	int				i = 0;
	
	inputFile.open(arg);
	if (!inputFile.is_open()) {
		std::cerr << "Error: Cannot open the input file" << std::endl;
		return (1);
	}
	while (std::getline(inputFile, inputLine)) {
		if (i == 0 && inputLine == "date | value"){
			i++;
			continue;
		}
		if (inputLine.size() < 14 || inputLine.find(" | ") == std::string::npos) {
			std::cerr << "Error: bad input => " << inputLine << std::endl;
			continue;
		}
		key = inputLine.substr(0, 10);
		valuestr = inputLine.substr(13, inputLine.size() - 13);

		if (parseKey(key))
			continue;
		if (parseValue(valuestr))
			continue;
		std::stringstream(valuestr) >> value;
		std::map<std::string, double>::iterator	it = _data.lower_bound(key);
		if (it->first > key)
			it--;
		std::cout << key << " => " << value << " = " << value * it->second << std::endl;
		i++;
	}
	
	return (0);
}
