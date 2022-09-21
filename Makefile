# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 10:00:13 by ogonzale          #+#    #+#              #
#    Updated: 2022/09/21 16:43:08 by ogonzale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Standard

NAME 		:= push_swap
BNAME		:= checker
INC		 	:= inc/
LIBFT_DIR	:= lib/libft/
LIBFT		:= $(LIBFT_DIR)libft.a
MAKEFILE	:= Makefile
HEADER 		= -I $(INC) -I $(LIBFT_DIR)$(INC)
SRC_DIR 	:= src/
OBJ_DIR 	:= obj/
CC 			:= cc
CFLAGS 		:= -Wall -Wextra -Werror
RM 			:= rm -f
UNAME		:= $(shell uname)

# Colors

DEF_COLOR 	:= \033[0;39m
GRAY 		:= \033[0;90m
RED 		:= \033[0;91m
GREEN 		:= \033[0;92m
YELLOW 		:= \033[0;93m
BLUE 		:= \033[0;94m
MAGENTA 	:= \033[0;95m
CYAN 		:= \033[0;96m
WHITE 		:= \033[0;97m

#Sources

MAND_DIR	:= mand/
MAND_FILES	:= push_swap parse ft_atoi_mod sort operations large_sort \
			   large_sort_2 utils utils_2

BONUS_DIR	:= bonus/
BONUS_FILES	:= checker_bonus parse_bonus ft_atoi_mod_bonus operations_bonus \
			   utils_bonus follow_instructions_bonus

SRC_FILES	= $(addprefix $(MAND_DIR), $(MAND_FILES))
SRC_BFILES	= $(addprefix $(BONUS_DIR), $(BONUS_FILES))

SRC 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

BSRC 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_BFILES)))
BOBJ 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_BFILES)))

###

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(MAKEFILE)
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) -MT $@ -MMD -MP $(CFLAGS) $(HEADER) -O3 -c $< -o $@

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) 
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"

$(OBJF):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)$(MAND_DIR)
	@mkdir -p $(OBJ_DIR)$(BONUS_DIR)
	@touch $(OBJF)

$(LIBFT):
	@make -sC $(LIBFT_DIR)

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -sC $(LIBFT_DIR)
	@echo "$(BLUE)Libft object and dependency files cleaned.$(DEF_COLOR)"
	@$(RM) $(OBJF)
	@echo "$(BLUE)Pipex object and dependency files cleaned.$(DEF_COLOR)"

fclean:	clean
	@$(RM) $(NAME)
	@$(RM) $(BNAME)
	@$(RM) libft.a
	@make fclean -C $(LIBFT_DIR)
	@rm -rf *.dSYM
	@find . -name ".DS_Store" -delete
	@echo "$(CYAN)Libft executable files cleaned.$(DEF_COLOR)"
	@echo "$(CYAN)$(NAME) executable and junk files cleaned.$(DEF_COLOR)"

re:	fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for $(NAME).$(DEF_COLOR)"

bonus:	$(LIBFT) $(BNAME)

$(BNAME):	$(BOBJ)
	@$(CC) $(CFLAGS) $(BOBJ) $(LIBFT) -o $(BNAME)
	@echo "$(GREEN)$(BNAME) compiled!$(DEF_COLOR)"

rebonus: fclean bonus
	@echo "$(GREEN)Cleaned and rebuilt bonus.$(DEF_COLOR)"

norm:
	@clear
	@norminette $(SRC_DIR) $(INC) $(LIBFT_DIR) | grep -v Norme -B1 || true
	
.PHONY:	all clean fclean re norm bonus rebonus $(LIBFT)

-include $(OBJ:%.o=%.d) $(BOBJ:%.o=%.d)
