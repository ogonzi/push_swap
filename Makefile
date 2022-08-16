# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 10:00:13 by ogonzale          #+#    #+#              #
#    Updated: 2022/08/16 11:03:36 by ogonzale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Standard

NAME 		:= push_swap
BNAME		:= push_swap_bonus
INC		 	:= inc/
LIBFT_DIR	:= lib/libft/
LIBFT		:= $(LIBFT_DIR)libft.a
HEADER 		= -I$(INC) -I$(LIBFT_DIR)$(INC)
SRC_DIR 	:= src/
OBJ_DIR 	:= obj/
CC 			:= cc
CFLAGS 		:= -Wall -Wextra -Werror -g3
FSANITIZE	:= -fsanitize=address -g3
RM 			:= rm -f
ECHO		:= echo -e
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
MAND_FILES	:= push_swap parse ft_atoi_mod utils

BONUS_DIR	:= bonus/
BONUS_FILES	:= 

SRC_FILES	= $(addprefix $(MAND_DIR), $(MAND_FILES))
SRC_BFILES	= $(addprefix $(BONUS_DIR), $(BONUS_FILES))

SRC 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

BSRC 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_BFILES)))
BOBJ 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_BFILES)))

###

OBJF := .cache_exists

all:	$(NAME)

$(NAME):	$(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) -MT $@ -MMD -MP $(CFLAGS) $(HEADER) -O3 -c $< -o $@

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

#bonus:	$(BNAME)

$(BNAME):	$(BOBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(BOBJ) $(LIBFT) -o $(BNAME)
	@echo "$(GREEN)$(BNAME) compiled!$(DEF_COLOR)"

rebonus: fclean bonus
	@echo "$(GREEN)Cleaned and rebuilt bonus.$(DEF_COLOR)"

norm:
	@clear
	@norminette $(SRC_DIR) $(INC) $(LIBFT_DIR) | grep -v Norme -B1 || true
	
.PHONY:	all clean fclean re norm bonus rebonus $(LIBFT)

-include $(OBJ:%.o=%.d) $(BOBJ:%.o=%.d)
