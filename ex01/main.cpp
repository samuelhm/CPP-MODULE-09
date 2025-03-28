/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:29:27 by shurtado          #+#    #+#             */
/*   Updated: 2025/03/20 11:38:24 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "use: " << argv[0] << " \"expression\"\n";
	}
	try
	{
		RPN rpn;
		std::cout << rpn.evaluate(argv[1]) << "\n";
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

}
