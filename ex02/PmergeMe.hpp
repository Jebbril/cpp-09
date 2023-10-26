/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:35:07 by orakib            #+#    #+#             */
/*   Updated: 2023/10/26 18:16:52 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP

#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

class	PmergeMe {
	private:
		static std::vector<std::pair<int, int> > _pairsVec;
		static std::vector<int>	_secondVec;
		
		static std::deque<std::pair<int, int> > _pairsDeq;
		static std::deque<int>	_secondDeq;
		
		static int	_struggler;
		
		PmergeMe();
		PmergeMe(const PmergeMe &obj);
		PmergeMe	&operator=(const PmergeMe &obj);
		~PmergeMe();
		
	public:
		static std::vector<int>	_valuesVec;
		static std::vector<int>	_firstVec;
		
		static std::deque<int>	_firstDeq;
		static std::deque<int>	_valuesDeq;
		
		static bool	parseInput(size_t ac, char **av);
		static void	fillSortPairsVec();
		static void	fillSortPairsDeq();
		static void	splitSortVec();
		static void	splitSortDeq();
};

#endif