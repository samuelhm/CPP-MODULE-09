/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:54:23 by shurtado          #+#    #+#             */
/*   Updated: 2025/03/18 23:35:12 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

BitcoinExchange::BitcoinExchange()
{
		throw FileNotFoundException();
}

BitcoinExchange::BitcoinExchange(const std::string &filename)
{
	std::ifstream db("data.csv");
	std::ifstream file(filename.c_str());
	if (!file.is_open() || !db.is_open())
	{	if (file.is_open())
			file.close();
		if (db.is_open())
			db.close();
		throw FileNotFoundException();
	}

	std::string line;
	while (std::getline(db, line))
	{
		if (line == "date,exchange_rate")
			continue;
		size_t separator = line.find(',');
		std::string date = line.substr(0, separator);
		std::string valueStr = line.substr(separator + 1);
		std::istringstream iss(valueStr);
		double value;
		iss >> value;
		_db[date] = value;
	}
	processInputFile(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) { this->_db = other._db; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		this->_db = other._db;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::checkDate(const std::string &date, int numLine) const
{
	std::ostringstream oss;
	oss << numLine;
	std::string numLineStr = oss.str();
	if (date.empty())
		throw InvalidFormatException("Empty date field in line: " + numLineStr);
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		throw InvalidFormatException("Invalid date format => " + date + " in line: " + numLineStr);

	int year, month, day;
	char dash1, dash2;
	std::istringstream iss(date);

	if (!(iss >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-' || !iss.eof())
		throw InvalidFormatException("Invalid date format => " + date + " in line: " + numLineStr);
	if (year < 0)
		throw InvalidFormatException("Year cannot be negative => " + date + " in line: " + numLineStr);
	if (month < 1 || month > 12)
		throw InvalidFormatException("Invalid month in date => " + date + " in line: " + numLineStr);

	int maxDays;
	switch (month)
	{
		case 4: case 6: case 9: case 11:
			maxDays = 30;
			break;
		case 2:
			maxDays = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
			break;
		default:
			maxDays = 31;
	}
	if (day < 1 || day > maxDays)
		throw InvalidFormatException("Invalid day in date => " + date + " in line: " + numLineStr);
}

void BitcoinExchange::checkValue(const std::string &valueStr, int numLine) const
{
	std::ostringstream oss;
	oss << numLine;
	std::string numLineStr = oss.str();

	if (valueStr.empty())
	{
		throw InvalidValueException("Empty value field (line " + numLineStr + ")");
	}

	std::istringstream iss(valueStr);
	double value;
	if (!(iss >> value) || !iss.eof())
	{
		throw InvalidValueException("Invalid value format => " + valueStr + " (line " + numLineStr + ")");
	}

	if (value < 0)
	{
		throw InvalidValueException("not a positive number (line " + numLineStr + ")");
	}

	if (value > 1000)
	{
		throw InvalidValueException("too large a number (line " + numLineStr + ")");
	}
}


void BitcoinExchange::processInputFile(const std::string &inputFile) const
{
	std::ifstream file(inputFile.c_str());
	if (!file.is_open())
	{
		throw FileNotFoundException();
	}

	std::string line;
	int num_line = 0;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		num_line++;
		size_t separator = line.find('|');
		if (separator == std::string::npos)
		{
			std::cerr << "Error: bad input format => " << line << " (line " << num_line << ")" << std::endl;
			continue;
		}
		std::string date = line.substr(0, separator);
		std::string valueStr = line.substr(separator + 1);

		date.erase(0, date.find_first_not_of(" \t"));
		date.erase(date.find_last_not_of(" \t") + 1);
		valueStr.erase(0, valueStr.find_first_not_of(" \t"));
		valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

		try
		{
			checkDate(date, num_line);
			checkValue(valueStr, num_line);

			std::string closestDate = findClosestDate(date);
			double exchangeRate = _db.at(closestDate);

			std::istringstream iss(valueStr);
			double value;
			iss >> value;

			std::cout << date << " => " << value << " = " << (value * exchangeRate) << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

std::string BitcoinExchange::findClosestDate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it = _db.lower_bound(date);
	if (it == _db.begin() && it->first != date)
	{
		throw InvalidFormatException("No available exchange rate for date: " + date);
	}
	if (it->first != date)
		--it;

	return it->first;
}

const char *BitcoinExchange::FileNotFoundException::what() const throw() { return "Error: could not open file."; }

BitcoinExchange::InvalidFormatException::InvalidFormatException(const std::string &input) {	this->message = "Error: bad input => " + input; }
const char *BitcoinExchange::InvalidFormatException::what() const throw() { return this->message.c_str(); }

BitcoinExchange::InvalidValueException::InvalidValueException(const std::string &reason) { this->message = "Error: " + reason; }
const char *BitcoinExchange::InvalidValueException::what() const throw() { return this->message.c_str(); }
