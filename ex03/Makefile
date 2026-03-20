# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvenkata <jvenkata@student.42belgium.be    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/22 13:46:58 by julian            #+#    #+#              #
#    Updated: 2026/03/16 15:19:07 by jvenkata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Intern
C = c++
CFLAGS = -Iinclude -Wall -Wextra -Werror -std=c++98
SRC = 	main.cpp Bureaucrat.cpp  AForm.cpp\
		ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp \
		Intern.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(C) $(OBJ) -o $@

%.o: %.cpp
	$(C) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re