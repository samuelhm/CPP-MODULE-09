/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:47:25 by shurtado          #+#    #+#             */
/*   Updated: 2025/03/18 23:50:22 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <sstream>
#include "RPN.hpp"

int RPN::evaluate(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (isdigit(token[0]))
			stack.push(token[0] - '0');
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (stack.size() < 2)
				throw std::runtime_error("Error: Expresión inválida.");

			int b = stack.top(); stack.pop();
			int a = stack.top(); stack.pop();

			if (token == "+") stack.push(a + b);
			else if (token == "-") stack.push(a - b);
			else if (token == "*") stack.push(a * b);
			else if (token == "/")
			{
				if (b == 0) throw std::runtime_error("Error: División por cero.");
				stack.push(a / b);
			}
		}
		else
		{
			throw std::runtime_error("Error: Token inválido.");
		}
	}

	if (stack.size() != 1)
		throw std::runtime_error("Error: Expresión inválida.");

	return stack.top();
}
