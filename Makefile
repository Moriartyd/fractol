# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 16:09:49 by cpollich          #+#    #+#              #
#    Updated: 2019/11/01 19:14:07 by cpollich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

F = -Wall -Wextra -Werror

INC_DIR	=	./inc/
SRC_DIR	=	./src/
SRC_LST	=	errors.c hook_init.c initializating.c main.c	\
			f_mandelbrot.c f_bshp.c draw.c changes.c f_julia.c

OBJ_DIR	=	./obj/
OBJS	=	$(addprefix $(OBJ_DIR),$(SRC_LST:%.c=%.o))

LIBFT_DIR	=	./libft/
LIBFT		=	$(LIBFT_DIR)libft.a
LIBFT_HEAD	=	$(LIBFT_DIR)inc/

MLX_DIR		=	./minilibx_macos/
MLX_HEAD	=	$(MLX_DIR)
MLX			= 	$(MLX_DIR)libmlx.a

LIBRARIES	=	-lmlx -lm -lft -L$(LIBFT_DIR) -L$(MLX_DIR) -framework OpenGL -framework AppKit
INCLUDES	=	-I$(LIBFT_HEAD) -I$(MLX_HEAD) -I$(INC_DIR)

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJ_DIR) $(OBJS)
	@gcc $F -g $(LIBRARIES) $(INCLUDES) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)
	@gcc -c -g $F $< $(INCLUDES) -o $@

$(MLX):
	@make -C $(MLX_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@rm -Rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re:	fclean all

norme:
	@norminette $(LIBFT_DIR) $(INC_DIR) $(SRC_DIR)

.PHONY: all clean fclean re norme
