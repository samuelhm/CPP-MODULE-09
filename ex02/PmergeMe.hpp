/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:58:34 by shurtado          #+#    #+#             */
/*   Updated: 2025/03/20 13:55:32 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>

class PmergeMe
{
	private:
		std::vector<int> vec;
		std::deque<int> deq;
		double timeVec;
		double timeDeq;

		void mergeInsertionSortVector(std::vector<int> &arr);
		void mergeInsertionSortDeque(std::deque<int> &arr);
		void binaryInsert(std::vector<int> &arr, int value);
		void binaryInsert(std::deque<int> &arr, int value);
	public:
		PmergeMe();
		PmergeMe(std::vector<int> data);
		PmergeMe(const PmergeMe &other);
		PmergeMe& operator=(const PmergeMe &other);
		~PmergeMe();

		void sortVector();
		void sortDeque();
		void printResults(std::vector<int>) const;
};

#endif
