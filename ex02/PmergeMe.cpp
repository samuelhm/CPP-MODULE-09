/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:58:27 by shurtado          #+#    #+#             */
/*   Updated: 2025/03/20 11:59:22 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other) {
		// Copiar los atributos necesarios
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

