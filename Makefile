# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 10:00:13 by ogonzale          #+#    #+#              #
#    Updated: 2022/06/09 19:06:36 by ogonzale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Standard

NAME 		:= fdf
BNAME		:= fdf_bonus
INC		 	:= inc/
LIBFT 		:= lib/libft/
MINILIBX 	:= lib/mlx/
HEADER 		= -I$(INC) -I$(LIBFT)$(INC) -I$(MINILIBX)
SRC_DIR 	:= src/
OBJ_DIR 	:= obj/
CC 			:= cc
CFLAGS 		:= -Wall -Wextra -Werror -g
FSANITIZE	:= -fsanitize=address -g3
RM 			:= rm -f
ECHO		:= echo -e
MINILIBXCC	= -I mlx -L$(MINILIBX) -lmlx -lXext -lX11 -lm -lz
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
MAND_FILES	:= fdf ft_utils parse_map graphics scale_coord
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

$(NAME):	$(OBJ)
	@make -C $(LIBFT)
	@cp $(LIBFT)libft.a .
	@echo "$(GREEN)Libft compiled!$(DEF_COLOR)"
	@make -s -C $(MINILIBX)
	@echo "$(GREEN)Minilibx compiled!$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ) $(HEADER) libft.a $(MINILIBXCC) -o $(NAME)
	@echo "$(GREEN)FDF compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) -MT $@ -MMD -MP $(CFLAGS) $(HEADER) -O3 -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)$(FDF_DIR)
	@mkdir -p $(OBJ_DIR)$(BONUS_DIR)
	@touch $(OBJF)

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -C $(LIBFT)
	@echo "$(BLUE)Libft object and dependency files cleaned.$(DEF_COLOR)"
	@make clean -C $(MINILIBX)
	@echo "$(BLUE)Minilibx object files cleaned.$(DEF_COLOR)"
	@$(RM) $(OBJF)
	@echo "$(BLUE)FDF object and dependency files cleaned.$(DEF_COLOR)"

fclean:	clean
	@$(RM) $(NAME)
	@$(RM) $(BNAME)
	@$(RM) libft.a
	@make fclean -C $(LIBFT)
	@rm -rf *.dSYM
	@find . -name ".DS_Store" -delete
	@echo "$(CYAN)Libft executable files cleaned.$(DEF_COLOR)"
	@echo "$(CYAN)FDF executable and junk files cleaned.$(DEF_COLOR)"

re:	fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for FDF.$(DEF_COLOR)"

norm:
	@clear
	@norminette $(SRC_DIR) $(INC) $(LIBFT) | grep -v Norme -B1 || true

.PHONY:	all clean fclean re norm

-include $(OBJ:%.o=%.d)
