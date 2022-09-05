# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 10:38:02 by parnaldo          #+#    #+#              #
#    Updated: 2022/09/05 13:24:55 by parnaldo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = minitalk

CLIENT	= client
SERVER	= server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

# Libft #
LIBFT	=	./libs/libft/libft.a
LIBFT_DIR	=	./libs/libft

# ft_Printf #
PRINTF	= ./libs/ft_printf/libftprintf.a
PRINTF_DIR = ./libs/ft_printf

SRC_C = client.c
SRC_S = server.c
SRC_C_BONUS = client_bonus.c
SRC_S_BONUS = server_bonus.c

INC		= -I. -I$(LIBFT_DIR)

all:	$(CLIENT) $(SERVER)

$(NAME): all

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT): $(LIBFT)
	@$(CC) $(CFLAGS) $(SRC_C) $(LIBFT) $(PRINTF) $(INC) -o $(CLIENT)

$(SERVER): $(LIBFT)
	@$(CC) $(CFLAGS) $(SRC_S) $(LIBFT) $(PRINTF) $(INC) -o $(SERVER)

$(CLIENT_BONUS): $(LIBFT)
	@$(CC) $(CFLAGS) $(SRC_C_BONUS) $(LIBFT) $(PRINTF) $(INC) -o $(CLIENT_BONUS)

$(SERVER_BONUS): $(LIBFT)
	@$(CC) $(CFLAGS) $(SRC_S_BONUS) $(LIBFT) $(PRINTF) $(INC) -o $(SERVER_BONUS)


$(LIBFT):
		@$(MAKE) -C ./libs/libft

$(PRINTF):
		@$(MAKE) -C ./libs/ft_printf

clean:
		@$(MAKE) fclean -C $(LIBFT_DIR)
		@$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

fclean: clean
		@$(RM) $(CLIENT) $(SERVER) $(CLINT_BONUS) $(SERVER_BONUS)

re: fclean $(NAME)

.PHONY: all clean fclean re bonus
