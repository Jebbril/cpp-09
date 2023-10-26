/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:35:04 by orakib            #+#    #+#             */
/*   Updated: 2023/10/26 18:19:35 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int>	PmergeMe::_valuesVec;
std::vector<std::pair<int, int> > PmergeMe::_pairsVec;
std::vector<int>	PmergeMe::_firstVec;
std::vector<int>	PmergeMe::_secondVec;

std::deque<int>	PmergeMe::_valuesDeq;
std::deque<std::pair<int, int> > PmergeMe::_pairsDeq;
std::deque<int>	PmergeMe::_firstDeq;
std::deque<int>	PmergeMe::_secondDeq;

int	PmergeMe::_struggler = -1;

PmergeMe::PmergeMe() {

}

PmergeMe::PmergeMe(const PmergeMe &obj) {
	(void)obj;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &obj) {
	(void)obj;
	return (*this);
}
PmergeMe::~PmergeMe() {
	
}

bool	isPosInt(std::string str, int *n) {
	std::string	digits = "0123456789";
	long		number;

	if (str.find_first_not_of(digits) != std::string::npos)
		return (false);
	std::stringstream(str) >> number;
	if (number > INT_MAX)
		return (false);
	*n = number;
	return (true);
}

bool	PmergeMe::parseInput(size_t ac, char **av) {
	int	number;
	
	for (size_t i = 1; i < ac; i++)
	{
		std::string	str = av[i];
		if (str.empty() || !isPosInt(str, &number))
			return (false);
		
		_valuesVec.push_back(number);
		_valuesDeq.push_back(number);
	}

	return (true);
}

void	sortPairsVec(std::vector<std::pair<int, int> > &vec, size_t size) {
	if (size == 1)
		return ;
	size_t	count = 0;
	size_t	i = -1;
	while (++i < size - 1) {
		if (vec[i].first > vec[i + 1].first) {
			std::swap(vec[i], vec[i + 1]);
			count++;
		}
	}
	if (count == 0)
		return ;
	sortPairsVec(vec, size - 1);
}

void	PmergeMe::fillSortPairsVec() {
	if (_valuesVec.size() < 2)
		return ;
	
	std::vector<int>::iterator	it = _valuesVec.begin();
	while (it != _valuesVec.end()) {
		if (it + 1 == _valuesVec.end()) {
			_struggler = *it;
			break;
		}
		else {
			_pairsVec.push_back(std::make_pair(*it, *(it + 1)));
		}
		it++;
		it++;
	}
	std::vector<std::pair<int, int> >::iterator it1 = _pairsVec.begin();
	while (it1 != _pairsVec.end()) {
		if (it1->first < it1->second)
			std::swap(it1->first, it1->second);
		it1++;
	}
	
	sortPairsVec(_pairsVec, _pairsVec.size());
}

void	sortPairsDeq(std::deque<std::pair<int, int> > &deq, size_t size) {
	if (size == 1)
		return ;
	size_t	count = 0;
	size_t	i = -1;
	while (++i < size - 1) {
		if (deq[i].first > deq[i + 1].first) {
			std::swap(deq[i], deq[i + 1]);
			count++;
		}
	}
	if (count == 0)
		return ;
	sortPairsDeq(deq, size - 1);
}


void	PmergeMe::fillSortPairsDeq() {
	if (_valuesDeq.size() < 2)
		return ;
	
	std::deque<int>::iterator	it = _valuesDeq.begin();
	while (it != _valuesDeq.end()) {
		if (it + 1 == _valuesDeq.end()) {
			_struggler = *it;
			break;
		}
		else {
			_pairsDeq.push_back(std::make_pair(*it, *(it + 1)));
		}
		it++;
		it++;
	}
	
	std::deque<std::pair<int, int> >::iterator it1 = _pairsDeq.begin();
	while (it1 != _pairsDeq.end()) {
		if (it1->first < it1->second)
			std::swap(it1->first, it1->second);
		it1++;
	}
	
	sortPairsDeq(_pairsDeq, _pairsDeq.size());	
}

void	fillJacobVec(size_t size, std::vector<size_t> &comb) {
	size_t	n0 = 1;
	size_t	n1 = 1;
	size_t	n = n1 + n0 * 2;
	size_t	i;
	
	while (n < size) {
		n = n1 + n0 * 2;
		i = n;
		while (i > n1)
			comb.push_back(i--);
		n0 = n1;
		n1 = n;
	}
	i = n;
	while (i > n1)
		comb.push_back(i--);
}

void	binaryInsertVec(std::vector<int> &_firstVec, int value) {
	std::vector<int>::iterator it = std::lower_bound(_firstVec.begin(), _firstVec.end(), value);
	_firstVec.insert(it, value);
	// size_t	left = 0;
	// size_t	right = _firstVec.size() - 1;
	// size_t	mid;
	
	// while (left <= right) {
	// 	mid = left + (right - left) / 2;
	// 	if (_firstVec[mid] == value) {
	// 		_firstVec.insert(_firstVec.begin() + mid, value);
	// 		return ;
	// 	}
	// 	else if (mid >= _firstVec.size())
	// 		return ;
	// 	else if (_firstVec[mid] < value)
	// 		left = mid + 1;
	// 	else
	// 		right = mid - 1;
	// }
	// 	std::cout << "test" << std::endl;
	// _firstVec.insert(_firstVec.begin() + left, value);
}

void	PmergeMe::splitSortVec() {
	std::vector<std::pair<int, int> >::iterator it = _pairsVec.begin();
	while (it != _pairsVec.end()) {
		_firstVec.push_back(it->first);
		_secondVec.push_back(it->second);
		it++;
	}
	_firstVec.insert(_firstVec.begin(), _secondVec[0]);
	
	std::vector<size_t>	jacobComb;
	fillJacobVec(_secondVec.size(), jacobComb);
	
	size_t	i = -1;
	size_t	index;
	
	while (++i < jacobComb.size()) {
		if (jacobComb[i] > _secondVec.size())
			continue;
		index = jacobComb[i] - 1;
		binaryInsertVec(_firstVec, _secondVec[index]);
	}
	if (_struggler != -1)
		binaryInsertVec(_firstVec, _struggler);
}

void	fillJacobDeq(size_t size, std::deque<size_t> &comb) {
	size_t	n0 = 1;
	size_t	n1 = 1;
	size_t	n = n1 + n0 * 2;
	size_t	i;
	
	while (n < size) {
		n = n1 + n0 * 2;
		i = n;
		while (i > n1)
			comb.push_back(i--);
		n0 = n1;
		n1 = n;
	}
	i = n;
	while (i > n1)
		comb.push_back(i--);
}

void	binaryInsertDeq(std::deque<int> &_firstDeq, int value) {
	std::deque<int>::iterator it = std::lower_bound(_firstDeq.begin(), _firstDeq.end(), value);
	_firstDeq.insert(it, value);
}

void	PmergeMe::splitSortDeq() {
	std::deque<std::pair<int, int> >::iterator it = _pairsDeq.begin();
	while (it != _pairsDeq.end()) {
		_firstDeq.push_back(it->first);
		_secondDeq.push_back(it->second);
		it++;
	}
	_firstDeq.insert(_firstDeq.begin(), _secondDeq[0]);

	std::deque<size_t>	jacobComb;
	fillJacobDeq(_secondDeq.size(), jacobComb);
	
	size_t	i = -1;
	size_t	index;
	
	while (++i < jacobComb.size()) {
		if (jacobComb[i] > _secondVec.size())
			continue;
		index = jacobComb[i] - 1;
		binaryInsertDeq(_firstDeq, _secondDeq[index]);
	}
	if (_struggler != -1)
		binaryInsertDeq(_firstDeq, _struggler);
}
