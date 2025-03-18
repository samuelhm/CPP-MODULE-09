# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 10:55:42 by shurtado          #+#    #+#              #
#    Updated: 2025/03/18 21:59:19 by shurtado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	btc
CC			=	c++
CPPFLAGS	=	-std=c++98 -g -Wall -Werror -Wextra -MMD -MP -fsanitize=address -pedantic

SRC			=	src/main.cpp src/BitcoinExchange.cpp

OBJS		=	$(SRC:%.cpp=obj/%.o)
DEPS		=	$(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(INCLUDES) $(CPPFLAGS) -o $@ $(OBJS) $(LDFLAGS)

obj/%.o: %.cpp Makefile
	@mkdir -p $(dir $@)
	$(CC) $(INCLUDES) $(CPPFLAGS) -c $< -o $@


clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
