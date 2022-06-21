# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 10:00:13 by ogonzale          #+#    #+#              #
#    Updated: 2022/06/21 09:31:14 by ogonzale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Standard

NAME 		:= fdf
BNAME		:= fdf_bonus
INC		 	:= inc/
LIBFT_DIR	:= lib/libft/
LIBFT		:= $(LIBFT_DIR)libft.a
HEADER 		= -I$(INC) -I$(LIBFT_DIR)$(INC) -I$(MINILIBX_DIR)
SRC_DIR 	:= src/
OBJ_DIR 	:= obj/
CC 			:= cc
CFLAGS 		:= -Wall -Wextra -Werror -g
FSANITIZE	:= -fsanitize=address -g3
RM 			:= rm -f
ECHO		:= echo -e
UNAME		:= $(shell uname)
MINILIBX_DIR:= lib/mlx_$(UNAME)
MINILIBX	:= $(MINILIBX_DIR)libmlx.a
MINILIBXCC	= -I mlx -L$(MINILIBX_DIR) -lmlx
LINUX_MLX	:= -lXext -lX11 -lm -lz
OPENGL		:= -framework OpenGL -framework AppKit

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

FDF_DIR		:= fdf/
MAND_FILES	:= fdf ft_utils_1 ft_utils_2 parse_map graphics scale_coord_1 \
			   scale_coord_2 line_1 line_2 colors hooks
BONUS_DIR	:= bonus/
BONUS_FILES	:=

SRC_FILES	= $(addprefix $(FDF_DIR), $(MAND_FILES))
SRC_BFILES	= $(addprefix $(BONUS_DIR), $(BONUS_FILES))

SRC 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

BSRC 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_BFILES)))
BOBJ 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_BFILES)))

###

OBJF := .cache_exists

all:	$(NAME)

$(NAME):	$(LIBFT) $(MINILIBX) $(OBJ)
ifeq ($(UNAME),Linux)
	@$(CC) $(CFLAGS) $(OBJ) $(HEADER) $(LIBFT) $(MINILIBXCC) $(LINUX_MLX) -o $(NAME)
else
	@$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ) $(HEADER) $(LIBFT) $(MINILIBXCC) $(OPENGL) -o $(NAME)
endif
	@echo "$(GREEN)FDF compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) -MT $@ -MMD -MP $(CFLAGS) $(HEADER) -O3 -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)$(FDF_DIR)
	@mkdir -p $(OBJ_DIR)$(BONUS_DIR)
	@touch $(OBJF)

$(LIBFT):
	@make -sC $(LIBFT_DIR)

$(MINILIBX):
	@make -sC $(MINILIBX_DIR)
	@echo "$(GREEN)Minilibx compiled!$(DEF_COLOR)"

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -sC $(LIBFT_DIR)
	@echo "$(BLUE)Libft object and dependency files cleaned.$(DEF_COLOR)"
	@make clean -sC $(MINILIBX_DIR)
	@echo "$(BLUE)Minilibx object files cleaned.$(DEF_COLOR)"
	@$(RM) $(OBJF)
	@echo "$(BLUE)FDF object and dependency files cleaned.$(DEF_COLOR)"

fclean:	clean
	@$(RM) $(NAME)
	@$(RM) $(BNAME)
	@$(RM) libft.a
	@make fclean -C $(LIBFT_DIR)
	@rm -rf *.dSYM
	@find . -name ".DS_Store" -delete
	@echo "$(CYAN)Libft executable files cleaned.$(DEF_COLOR)"
	@echo "$(CYAN)FDF executable and junk files cleaned.$(DEF_COLOR)"

re:	fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for FDF.$(DEF_COLOR)"

norm:
	@clear
	@norminette $(SRC_DIR) $(INC) $(LIBFT) | grep -v Norme -B1 || true

.PHONY:	all clean fclean re norm $(LIBFT) $(MINILIBX)

-include $(OBJ:%.o=%.d)
