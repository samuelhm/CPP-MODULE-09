/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:58:27 by shurtado          #+#    #+#             */
/*   Updated: 2025/03/20 13:55:51 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<int> data) : vec(data), deq(data.begin(), data.end()), timeVec(0), timeDeq(0) {}

PmergeMe::PmergeMe(const PmergeMe &other) : vec(other.vec), deq(other.deq), timeVec(other.timeVec), timeDeq(other.timeDeq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->deq = other.deq;
		this->vec = other.vec;
		this->timeDeq = other.timeDeq;
		this->timeVec = other.timeVec;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::mergeInsertionSortVector(std::vector<int> &arr)
{
	if (arr.size() <= 1)
		return;

	std::vector<int> mainSeq;
	std::vector<int> pending;

	for (size_t i = 0; i + 1 < arr.size(); i += 2)
	{
		if (arr[i] > arr[i + 1])
			std::swap(arr[i], arr[i + 1]);
		mainSeq.push_back(arr[i + 1]);
		pending.push_back(arr[i]);
	}
	if (arr.size() % 2 != 0)
		pending.push_back(arr.back());
	std::sort(mainSeq.begin(), mainSeq.end());
	for (size_t i = 0; i < pending.size(); ++i)
		binaryInsert(mainSeq, pending[i]);
	arr = mainSeq;
}

void PmergeMe::mergeInsertionSortDeque(std::deque<int> &arr)
{
	if (arr.size() <= 1)
		return;

	std::deque<int> mainSeq;
	std::deque<int> pending;

	for (size_t i = 0; i + 1 < arr.size(); i += 2)
	{
		if (arr[i] > arr[i + 1])
			std::swap(arr[i], arr[i + 1]);

		mainSeq.push_back(arr[i + 1]);
		pending.push_back(arr[i]);
	}
	if (arr.size() % 2 != 0)
		pending.push_back(arr.back());
	std::sort(mainSeq.begin(), mainSeq.end());
	for (size_t i = 0; i < pending.size(); ++i)
		binaryInsert(mainSeq, pending[i]);
	arr = mainSeq;
}

void PmergeMe::sortVector()
{
	clock_t start = clock();
	mergeInsertionSortVector(vec);
	clock_t end = clock();
	timeVec = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
}

void PmergeMe::sortDeque()
{
	clock_t start = clock();
	mergeInsertionSortDeque(deq);
	clock_t end = clock();
	timeDeq = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
}

void PmergeMe::printResults(std::vector<int> unordered) const
{
	std::cout << "Before: ";
	for (size_t i = 0; i < unordered.size(); ++i)
		std::cout << unordered[i] << " ";
	std::cout << std::endl;

	std::cout << "After: ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << timeDeq << " us" << std::endl;
}

void PmergeMe::binaryInsert(std::deque<int> &arr, int value)
{
	std::deque<int>::iterator pos = std::lower_bound(arr.begin(), arr.end(), value);
	arr.insert(pos, value);
}


void PmergeMe::binaryInsert(std::vector<int> &arr, int value)
{
	std::vector<int>::iterator pos = std::lower_bound(arr.begin(), arr.end(), value);
	arr.insert(pos, value);
}
