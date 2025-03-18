/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:45:49 by shurtado          #+#    #+#             */
/*   Updated: 2025/03/18 23:48:27 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RPN_H__
#define __RPN_H__

#include <stack>
#include <string>

class RPN
{
	private:
		std::stack<int> stack;

	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		int evaluate(const std::string &expression);
};

#endif // __RPN_H__
