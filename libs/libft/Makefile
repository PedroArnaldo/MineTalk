#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 10:15:55 by parnaldo          #+#    #+#              #
#    Updated: 2022/06/18 18:14:51 by parnaldo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= cc
RM	= rm -f
CFLAGS	= -Wall -Wextra -Werror -I.

NAME	= libft.a

SRCS	=	ft_isalpha.c \
			ft_isprint.c \
			ft_memcpy.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_bzero.c \
			ft_isascii.c \
			ft_memchr.c \
			ft_memmove.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_isalnum.c \
			ft_isdigit.c \
			ft_memcmp.c \
			ft_memset.c \
			ft_strlcpy.c \
			ft_strnstr.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_atoi.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putstr_fd.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strmapi.c \
			ft_itoa.c \
			ft_putnbr_fd.c \
			ft_striteri.c \
			ft_split.c


OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)

clean: 
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean re
