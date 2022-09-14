# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 10:38:02 by parnaldo          #+#    #+#              #
#    Updated: 2022/09/05 14:19:25 by parnaldo         ###   ########.fr        #
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

INC_LIBFT	= -I. -I$(LIBFT_DIR)
INC_PRINTF	= -I. -I$(PRINTF_DIR)

all:	$(CLIENT) $(SERVER)

$(NAME): all

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT): $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(SRC_C) $(LIBFT) $(INC_LIBFT) $(PRINTF) $(INC_PRINTF) -o $(CLIENT)

$(SERVER): $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(SRC_S) $(LIBFT) $(INC_LIBFT) $(PRINTF) $(INC_PRINTF) -o $(SERVER)

$(CLIENT_BONUS): $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(SRC_C_BONUS) $(LIBFT) $(INC_LIBFT) $(PRINTF) $(INC_PRINTF) -o $(CLIENT_BONUS)

$(SERVER_BONUS): $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(SRC_S_BONUS) $(LIBFT) $(INC_LIBFT) $(PRINTF) $(INC_PRINTF) -o $(SERVER_BONUS)


$(LIBFT):
		@$(MAKE) -C ./libs/libft

$(PRINTF):
		@$(MAKE) -C ./libs/ft_printf

clean:
		@$(MAKE) fclean -C $(LIBFT_DIR)
		@$(MAKE) fclean -C $(PRINTF_DIR)
		@$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

fclean: clean
		@$(RM) $(CLIENT) $(SERVER) $(CLINT_BONUS) $(SERVER_BONUS)

re: fclean $(NAME)

.PHONY: all clean fclean re bonus
