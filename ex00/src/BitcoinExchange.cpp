/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:54:23 by shurtado          #+#    #+#             */
/*   Updated: 2025/03/18 12:01:02 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"
#include <iostream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &file)
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	// Constructor de copia
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
	// Operador de asignación
	if (this != &other)
	{
		// Copiar los atributos necesarios
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	// Destructor
}


