# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 10:38:02 by parnaldo          #+#    #+#              #
#    Updated: 2022/08/16 13:17:44 by parnaldo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I.

NAME = minitalk

CLIENT	= client
SERVER	= server

# Libft #
LIBFT	=	./libft/libft.a
LIBFT_DIR	=	./libft

SRC_C = client.c
SRC_S = server.c
INC		= -I. -I$(LIBFT_DIR)

all:	$(CLIENT) $(SERVER)

$(NAME): all

$(CLIENT): $(LIBFT)
	@$(CC) $(CFLAGS) $(SRC_C) $(LIBFT) $(INC) -o $(CLIENT)

$(SERVER): $(LIBFT)
	@$(CC) $(CFLAGS) $(SRC_S) $(LIBFT) $(INC) -o $(SERVER)

$(LIBFT):
		@$(MAKE) -C ./libft

clean:
		@$(MAKE) fclean -C $(LIBFT_DIR)
		$(RM) $(CLIENT) $(SERVER)

fclean:
		$(RM) $(CLIENT) $(SERVER)

re: fclean $(NAME)

.PHONY: all clean fclean re
