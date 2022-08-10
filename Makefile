# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 19:48:42 by hrolle            #+#    #+#              #
#    Updated: 2022/08/10 11:36:36 by hrolle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ECHO = @echo
PRINT = @printf
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
INVERT = \033[7m
RESETTXT = \033[0m
BOLD = \033[1m

RM = rm -rf

SRC =	cmd/push.c				main/push_swap.c		utils/five_sort.c	utils/i_min_size.c		utils/monmax.c		utils/simple_push_chunk.c	utils/split_arg.c				\
		cmd/reverse_rotate.c	secure/exit_error.c		utils/ft_atoi.c		utils/int_ft_strlen.c	utils/monmin.c		utils/simple_sort.c			utils/strarray_to_nbrarray.c	\
		cmd/rotate.c			utils/arg_check.c		utils/ft_satoi.c	utils/max_size.c		utils/push_chunk.c	utils/sort_b.c				utils/tree_sort.c				\
		cmd/swap.c				utils/cmpt_arg_check.c	utils/i_max_size.c	utils/min_size.c		utils/set_stacks.c	utils/sorted_checker.c

OBJ = $(SRC:.c=.o)

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra

ifeq ($(DEBUG), debug)
	CFLAGS += -fsanitize=address -g3
endif

$(NAME) : $(OBJ)
	$(ECHO) "$(YELLOW)Compilation de push_swap...$(RESETTXT)"
	@$(CC) $(CFLAGS) -o $@ $^
	$(ECHO) "$(GREEN)$(BOLD)Compilation Terminée !!!$(RESETTXT)"

%.o : %.c
	$(PRINT) "$(YELLOW)Generation des objets...$(RESETTXT)\r"
	@$(CC) $(CFLAGS) -o $@ -c $<

bonus :
	@make -C Checker

all : $(NAME) bonus

clean :
	$(ECHO) "$(RED)Suppression des objets...$(RESETTXT)"
	@$(RM) $(OBJ)
	$(ECHO) "$(GREEN)$(BOLD)Terminé !$(RESETTXT)"

b_clean :
	@make clean -C Checker

all_clean : clean b_clean

fclean : clean
	$(ECHO) "$(RED)Suppression du checker...$(RESETTXT)"
	@$(RM) Checker/checker
	$(ECHO) "$(GREEN)$(BOLD)Terminé !$(RESETTXT)"
	$(ECHO) "$(RED)Suppression de push_swap...$(RESETTXT)"
	@$(RM) $(NAME)
	$(ECHO) "$(GREEN)$(BOLD)Terminé !$(RESETTXT)"

b_fclean :
	@make fclean -C Checker

all_fclean : fclean b_fclean

re : fclean $(NAME)

b_re :
	@make re -C Checker

all_re : re b_re

.PHONY: all re bonus clean fclean