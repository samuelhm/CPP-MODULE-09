/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:54:31 by shurtado          #+#    #+#             */
/*   Updated: 2025/03/18 23:01:10 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <exception>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_db;
		void	checkDate(const std::string &date, int numLine) const;
		void	checkValue(const std::string &valueStr, int numLine) const;

	public:
		BitcoinExchange();
		BitcoinExchange(const std::string &file);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange& operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void processInputFile(const std::string &inputFile) const;
		std::string findClosestDate(const std::string &date) const;

		class FileNotFoundException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class InvalidFormatException : public std::exception
		{
			private:
				std::string message;
			public:
				InvalidFormatException(const std::string &input);
				const char *what() const throw();
				virtual ~InvalidFormatException() throw() {}
		};

		class InvalidValueException : public std::exception
		{
			private:
				std::string message;
			public:
				InvalidValueException(const std::string &reason);
				const char *what() const throw();
				virtual ~InvalidValueException() throw() {}
		};

};

#endif
