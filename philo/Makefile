# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/27 17:44:27 by dlanotte          #+#    #+#              #
#    Updated: 2022/01/21 00:26:40 by dlanotte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOR_OFF	= "\033[0m"       # Text Reset
RED			= "\033[0;31m"    # Red
YELLOW		= "\033[0;33m"    # Yellow


NAME = Philo

CC = gcc

CFLAGS = #-Werror -Wextra -Wall

DFLAGS = -g -Werror -Wextra -Wall 

MAIN = main.c

OTHER = other/functions01.c

SRCS = src/utils01.c

SRC = $(SRCS) $(MAIN) $(OTHER)

OBJ := ${SRC:.c=.o}

%.o: %.c
	@printf "\033[0;31mGenerating minishell objects... %-33.33s\r" $@
	@ $(CC) $(CFLAGS) -g -c $< -o $@ 

all: $(NAME)

title:
	@ echo $(RED)"    ____  __    _ __                       __                  "$(COLOR_OFF)
	@ echo $(RED)"   / __ \/ /_  (_) /___  _________  ____  / /_  ___  __________"$(COLOR_OFF)
	@ echo $(RED)"  / /_/ / __ \/ / / __ \/ ___/ __ \/ __ \/ __ \/ _ \/ ___/ ___/"$(COLOR_OFF)
	@ echo $(RED)" / ____/ / / / / / /_/ (__  ) /_/ / /_/ / / / /  __/ /  (__  ) "$(COLOR_OFF)
	@ echo $(RED)"/_/   /_/ /_/_/_/\____/____/\____/ .___/_/ /_/\___/_/  /____/  "$(COLOR_OFF)
	@ echo $(RED)"                                /_/                            "$(COLOR_OFF)
	@ echo $(YELLOW)"                     a bad project                          "$(COLOR_OFF)

$(NAME): $(OBJ)
	@ $(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@ make title

debug: $(OBJ)
	@ $(CC) $(DFLAGS) $(SRC) -o $(NAME)
	@ make title

clean:   
	@ rm -f ${OBJ}
	@ echo $(YELLOW)"⚒ clean completed."$(COLOR_OFF)

fclean: clean
	@ rm -f $(NAME)
	@ rm -f ${OBJ}
	@ rm -dir -f *.dSYM
	@ rm -f *.out
	@ find . -name ".DS_Store" -delete
	@ echo $(RED)"⚒ fclean completed."$(COLOR_OFF)

re: fclean all

PHONY: 	all clean fclean re 