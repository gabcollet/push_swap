# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/17 19:56:08 by gcollet           #+#    #+#              #
#    Updated: 2021/09/13 10:10:48 by gcollet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG	= push_swap

SRCS 	= srcs/main.c srcs/dbl_list_lib.c srcs/utils.c\
			srcs/operations.c srcs/radix.c srcs/selection.c
OBJS 	= ${SRCS:.c=.o}

HEADER	= -Iinclude/ -Ilibft

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

.c.o:		
					@gcc ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all:	${OBJS}
					@printf "\033c"
					@echo "\n\033[33m    COMPILING [*......]"
					@sleep 0.5
					@printf "\033c"
					@echo "\n\033[33m    COMPILING [****...]"
					@make re -C ./libft
					@$(CC) ${OBJS} -L libft -l ft -o ${PROG}
					@printf "\033c"
					@echo "\n\033[33m    COMPILING [*******]"
					@echo "\n\033[32m\033[1mPush_Swap Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n\033[0m"

clean:
					@make clean -C ./libft
					@rm -f ${OBJS} ${OBJS_B}

fclean: 	clean
					@make fclean -C ./libft
					@rm -f ${PROG}

re:			fclean all

party:
					@printf "\033c"
					@echo "\n\033[35m♪┏(・o･)┛♪"
					@sleep 1
					@printf "\033c"
					@echo "\033[1;33m♪┗(・o･)┓♪"
					@sleep 1
					@printf "\033c"
					@echo "\n\033[36m♪┏(・o･)┛♪"
					@sleep 1
					@printf "\033c"
					@echo "\033[34m♪┗(・o･)┓♪\n"

.PHONY: all clean fclean re bonus party