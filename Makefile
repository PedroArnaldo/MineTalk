# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 10:38:02 by parnaldo          #+#    #+#              #
#    Updated: 2022/08/17 12:02:25 by parnaldo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = minitalk

CLIENT	= client
SERVER	= server

# Libft #
LIBFT	=	./libs/libft/libft.a
LIBFT_DIR	=	./libs/libft

# ft_Printf #
PRINTF	= ./libs/ft_printf/libftprintf.a
PRINTF_DIR = ./libs/ft_printf

SRC_C = client.c
SRC_S = server.c
INC		= -I. -I$(LIBFT_DIR)

all:	$(CLIENT) $(SERVER)

$(NAME): all

$(CLIENT): $(LIBFT)
	@$(CC) $(CFLAGS) $(SRC_C) $(LIBFT) $(PRINTF) $(INC) -o $(CLIENT)

$(SERVER): $(LIBFT)
	@$(CC) $(CFLAGS) $(SRC_S) $(LIBFT) $(PRINTF) $(INC) -o $(SERVER)

$(LIBFT):
		@$(MAKE) -C ./libs/libft

$(PRINTF):
		@$(MAKE) -C ./libs/ft_printf

clean:
		@$(MAKE) fclean -C $(LIBFT_DIR)
		@$(RM) $(CLIENT) $(SERVER)

fclean: clean
		@$(RM) $(CLIENT) $(SERVER)

re: fclean $(NAME)

.PHONY: all clean fclean re
