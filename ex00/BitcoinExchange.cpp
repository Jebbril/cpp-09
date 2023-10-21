/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:47:42 by orakib            #+#    #+#             */
/*   Updated: 2023/10/21 20:26:21 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::string, double>	BitcoinExchange::_data;
std::map<std::string, double>	BitcoinExchange::_input;

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
		_data[dataLine.substr(0, 9)] = value;
	}
	
	return (0);
}

int	BitcoinExchange::retrieveInput(std::string &arg) {
	std::ifstream	inputFile;
	std::string		inputLine;
	double			value;
	int				i = 0;
	
	inputFile.open(arg);
	if (!inputFile.is_open()) {
		std::cerr << "Cannot open the input file" << std::endl;
		return (1);
	}
	while (std::getline(inputFile, inputLine)) {
		if (i == 0 && inputLine == "date | value")
			continue;
		
		i++;
	}
	return (0);
}

int	BitcoinExchange::parseInput() {
	return (0);
}

int	BitcoinExchange::outputValues() {
	return (0);
}