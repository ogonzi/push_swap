# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 10:00:13 by ogonzale          #+#    #+#              #
#    Updated: 2022/06/15 11:08:36 by ogonzale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Standard

NAME := libft.a
INCLUDE := inc/
HEADER = -I$(INCLUDE)
SRC_DIR := src/
OBJ_DIR := obj/
CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f
AR := ar -rcs

# Colors

DEF_COLOR := \033[0;39m
GRAY := \033[0;90m
RED := \033[0;91m
GREEN := \033[0;92m
YELLOW := \033[0;93m
BLUE := \033[0;94m
MAGENTA := \033[0;95m
CYAN := \033[0;96m
WHITE := \033[0;97m

#Sources

FTIS_DIR := ft_is/
FTIS := ft_is_in_set ft_isalpha ft_isdigit ft_isprint ft_isupper ft_isalnum \
	   ft_isascii ft_islower ft_isspace

FTMEM_DIR := ft_mem/
FTMEM := ft_bzero ft_memccpy ft_memcmp ft_memmove ft_realloc ft_calloc \
		ft_memchr ft_memcpy ft_memset

FTTO_DIR := ft_to/
FTTO := ft_atoi ft_atoi_base ft_itoa ft_tolower ft_toupper

FTSTR_DIR := ft_str/
FTSTR := ft_split ft_strcat ft_strchr ft_strdup ft_striteri ft_strjoin \
		ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp ft_strnstr \
		ft_strrchr ft_strtrim ft_substr

FTMATH_DIR := ft_math/
FTMATH := ft_abs_value ft_numsize ft_pow

FTLST_DIR := ft_lst/
FTLST := ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone ft_lstiter \
		ft_lstlast ft_lstmap ft_lstnew ft_lstsize

FTPUT_DIR := ft_put/
FTPUT := ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd

GNL_DIR := gnl/
GNL := get_next_line get_next_line_utils

PRINTF_DIR := ft_printf/
PRINTF := ft_printf ft_utils ft_put ft_print_base10 ft_print_chars ft_print_hex

SRC_FILES+=$(addprefix $(FTIS_DIR), $(FTIS))
SRC_FILES+=$(addprefix $(FTMEM_DIR), $(FTMEM))
SRC_FILES+=$(addprefix $(FTTO_DIR), $(FTTO))
SRC_FILES+=$(addprefix $(FTSTR_DIR), $(FTSTR))
SRC_FILES+=$(addprefix $(FTMATH_DIR), $(FTMATH))
SRC_FILES+=$(addprefix $(FTLST_DIR), $(FTLST))
SRC_FILES+=$(addprefix $(FTPUT_DIR), $(FTPUT))
SRC_FILES+=$(addprefix $(GNL_DIR), $(GNL))
SRC_FILES+=$(addprefix $(PRINTF_DIR), $(PRINTF))

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

###

OBJF := .cache_exists

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "$(GREEN)Libft compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) -MT $@ -MMD -MP $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)$(FTIS_DIR)
	@mkdir -p $(OBJ_DIR)$(FTMEM_DIR)
	@mkdir -p $(OBJ_DIR)$(FTPUT_DIR)
	@mkdir -p $(OBJ_DIR)$(FTTO_DIR)
	@mkdir -p $(OBJ_DIR)$(FTSTR_DIR)
	@mkdir -p $(OBJ_DIR)$(FTMATH_DIR)
	@mkdir -p $(OBJ_DIR)$(FTLST_DIR)
	@mkdir -p $(OBJ_DIR)$(GNL_DIR)
	@mkdir -p $(OBJ_DIR)$(PRINTF_DIR)
	@touch $(OBJF)

clean:
	@$(RM) -r $(OBJ_DIR)
	@$(RM) $(OBJF)
	@echo "$(BLUE)Libft object files cleaned.$(DEF_COLOR)"

fclean:	clean
	@$(RM) $(NAME)
	@echo "$(CYAN)Libft executable files cleaned.$(DEF_COLOR)"

re:	fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for libft.$(DEF_COLOR)"

.PHONY:	all clean fclean re norm

-include $(OBJ:%.o=%.d)
