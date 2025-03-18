/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:54:31 by shurtado          #+#    #+#             */
/*   Updated: 2025/03/18 11:12:47 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _db;

		void	fillDatabase(const std::string &filename);
		void	checkCsv(const std::string &filename);
		void	checkDate(const std::string &date);
		void	checkValue(double value);
	public:
		BitcoinExchange();
		BitcoinExchange(const std::string &file);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange& operator=(const BitcoinExchange &other);
		~BitcoinExchange();
};

#endif


