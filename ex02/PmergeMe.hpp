/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:35:07 by orakib            #+#    #+#             */
/*   Updated: 2023/10/23 18:32:33 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP

#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

class	PmergeMe {
	private:
		static std::vector<int>	_valuesVec;
		static std::vector<std::pair<int, int>> _pairsVec;
		static std::vector<int>	_firstVec;
		static std::vector<int>	_secondVec;
		
		static std::deque<int>	_valuesDeq;
		static std::deque<std::pair<int, int>> _pairsDeq;
		static std::deque<int>	_firstDeq;
		static std::deque<int>	_secondDeq;
		
		PmergeMe();
		PmergeMe(const PmergeMe &obj);
		PmergeMe	&operator=(const PmergeMe &obj);
		~PmergeMe();
		
	public:
		
};

#endif