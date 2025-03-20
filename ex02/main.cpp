/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:12:21 by shurtado          #+#    #+#             */
/*   Updated: 2025/03/20 13:56:50 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>

int stringToInt(const std::string &s)
{
	std::stringstream ss(s);
	int number;
	ss >> number;
	return number;
}

bool isValidNumber(const std::string &s)
{
	for (size_t i = 0; i < s.length(); ++i)
	{
		if (!isdigit(s[i]))
			return false;
	}
	return !s.empty();
}

void runTests()
{
	std::vector<std::vector<int> > testCases;
	std::vector<int> case1; case1.push_back(5); case1.push_back(3); case1.push_back(9); case1.push_back(1); case1.push_back(7);
	testCases.push_back(case1);

	std::vector<int> case2; case2.push_back(10); case2.push_back(20); case2.push_back(30); case2.push_back(40); case2.push_back(50);
	testCases.push_back(case2);

	std::vector<int> case3; case3.push_back(50); case3.push_back(40); case3.push_back(30); case3.push_back(20); case3.push_back(10);
	testCases.push_back(case3);

	std::vector<int> case4; case4.push_back(1);
	testCases.push_back(case4);

	std::vector<int> case5; case5.push_back(5); case5.push_back(5); case5.push_back(5); case5.push_back(5); case5.push_back(5);
	testCases.push_back(case5);

	std::vector<int> case6; case6.push_back(1000); case6.push_back(1); case6.push_back(500); case6.push_back(250);
	case6.push_back(750); case6.push_back(125); case6.push_back(875); case6.push_back(62);
	testCases.push_back(case6);

	std::vector<int> case7;
	testCases.push_back(case7);

	for (size_t i = 0; i < testCases.size(); ++i)
	{
		std::cout << "\n===== Running Test Case " << i + 1 << " =====" << std::endl;
		if (testCases[i].empty())
		{
			std::cout << "Error: Empty input is not allowed." << std::endl;
			continue;
		}
		PmergeMe sorter(testCases[i]);
		sorter.sortVector();
		sorter.sortDeque();
		sorter.printResults(testCases[i]);
	}
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "Error: No numbers provided." << std::endl;
		return 1;
	}
	std::vector<int> numbers;
	for (int i = 1; i < argc; ++i)
	{
		if (!isValidNumber(argv[i]))
		{
			std::cout << "Error: Invalid input '" << argv[i] << "'." << std::endl;
			return 1;
		}
		numbers.push_back(stringToInt(argv[i]));
	}
	PmergeMe sorter(numbers);
	sorter.sortVector();
	sorter.sortDeque();
	sorter.printResults(numbers);

	runTests();

	return 0;
}
