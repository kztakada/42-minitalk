# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: katakada <katakada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/01 23:05:17 by katakada          #+#    #+#              #
#    Updated: 2024/12/11 20:21:33 by katakada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -I $(INCS) 

LIBFT_DIR		=	libft/
LIBFT			=	$(LIBFT_DIR)libft.a
INCS			=	includes/

OBJS_PATH		=	objs/
SRCS_PATH		=	src/

NAME			=	minitalk

SERVER			=	server
SERVER_OBJ		=	$(OBJS_PATH)server_bonus.o

CLIENT			=	client
CLIENT_OBJ		=	$(OBJS_PATH)client_bonus.o

UTILS_OBJ		=	$(OBJS_PATH)utils.o


$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJ) $(LIBFT) $(UTILS_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(UTILS_OBJ) $(LIBFT) -o $(SERVER)

$(CLIENT): $(CLIENT_OBJ) $(LIBFT) $(UTILS_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(UTILS_OBJ) $(LIBFT) -o $(CLIENT)

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I $(INCS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

all:	$(NAME)

bonus:	all

clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJS_PATH)

fclean:
	make fclean -C $(LIBFT_DIR)
	rm -rf $(OBJS_PATH)
	rm -f $(SERVER) $(CLIENT)

re:		fclean all

.PHONY:	$(NAME) all bonus clean fclean re
