/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:35:08 by orakib            #+#    #+#             */
/*   Updated: 2023/10/26 18:34:06 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av) {
	if (ac > 2) {
		if (!PmergeMe::parseInput(ac, av)) {
			std::cout << "Error." << std::endl;
			return (1);
		}
		
		std::cout << "Before : ";
		std::vector<int>::iterator it1 = PmergeMe::_valuesVec.begin();
		while (it1 != PmergeMe::_valuesVec.end()) {
			std::cout << *it1 << "  ";
			it1++;
		}
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

		clock_t start = clock();
		PmergeMe::fillSortPairsVec();
		PmergeMe::splitSortVec();
		clock_t end = clock();
		
		double vecTime = (end - start) / (double)CLOCKS_PER_SEC;
		
		std::cout << "After : ";
		it1 = PmergeMe::_firstVec.begin();
		while (it1 != PmergeMe::_firstVec.end()) {
			std::cout << *it1 << "  ";
			it1++;
		}
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

		start = clock();
		PmergeMe::fillSortPairsDeq();
		PmergeMe::splitSortDeq();
		end = clock();
		
		double deqTime = (end - start) / (double)CLOCKS_PER_SEC;
		
		std::cout << "Time to process a range of	" << PmergeMe::_valuesVec.size() << " elements with std::vector : " << std::fixed << vecTime << " us" << std::endl;
		std::cout << "Time to process a range of	" << PmergeMe::_valuesDeq.size() << " elements with std::deque : " << std::fixed << deqTime << " us" << std::endl;
		
	}
}