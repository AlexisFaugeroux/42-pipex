# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaugero <afaugerou@42.fr>                    +#+  +:+       +#+      #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 14:40:40 by afaugero          #+#    #+#              #
#    Updated: 2025/01/23 14:50:04 by afaugero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
INCLUDES = includes

CHECK = check
PRINT = print
PRINTF = printf
STRING = string
CONVERT = convert
MEM = mem
ITERATIVE = iterative
LINKED_LIST = linked_list
FILE = file

SRC = ${CHECK}/ft_isalpha \
		${CHECK}/ft_isdigit \
		${CHECK}/ft_isalnum \
		${CHECK}/ft_isascii \
		${CHECK}/ft_isprint \
		${PRINT}/ft_putchar_fd \
		${PRINT}/ft_putstr_fd \
		${PRINT}/ft_putendl_fd \
		${PRINT}/ft_putnbr_fd \
		${PRINT}/${PRINTF}/printf \
		${PRINT}/${PRINTF}/parsers \
		${PRINT}/${PRINTF}/parse_hex \
		${STRING}/ft_strlen \
		${STRING}/ft_toupper \
		${STRING}/ft_tolower \
		${STRING}/ft_strcmp \
		${STRING}/ft_strncmp \
		${STRING}/ft_strlcpy \
		${STRING}/ft_strlcat \
		${STRING}/ft_strchr \
		${STRING}/ft_strrchr \
		${STRING}/ft_strdup \
		${STRING}/ft_strndup \
		${STRING}/ft_substr \
		${STRING}/ft_strjoin \
		${STRING}/ft_strtrim \
		${STRING}/ft_strnstr \
		${STRING}/ft_strmapi \
		${STRING}/ft_split \
		${STRING}/ft_striteri \
		${CONVERT}/ft_atoi \
		${CONVERT}/ft_atol \
		${CONVERT}/ft_itoa \
		${CONVERT}/ft_uitoa \
		${CONVERT}/ft_itoa_base \
		${MEM}/ft_bzero \
		${MEM}/ft_calloc \
		${MEM}/ft_memchr \
		${MEM}/ft_memcmp \
		${MEM}/ft_memcpy \
		${MEM}/ft_memmove \
		${MEM}/ft_memset \
		${MEM}/ft_memswap \
		${ITERATIVE}/ft_foreach \
		${ITERATIVE}/ft_map \
		${ITERATIVE}/ft_any \
		${ITERATIVE}/ft_every \
		${ITERATIVE}/ft_count_if \
		${ITERATIVE}/ft_is_sort \
		${ITERATIVE}/ft_sort \
		${LINKED_LIST}/ft_lstadd_front \
		${LINKED_LIST}/ft_lstadd_back \
		${LINKED_LIST}/ft_lstat \
		${LINKED_LIST}/ft_lstclear \
		${LINKED_LIST}/ft_lstdelone \
		${LINKED_LIST}/ft_lstfind \
		${LINKED_LIST}/ft_lstforeach \
		${LINKED_LIST}/ft_lstforeach_if \
		${LINKED_LIST}/ft_lstlast \
		${LINKED_LIST}/ft_lstmap \
		${LINKED_LIST}/ft_lstmerge \
		${LINKED_LIST}/ft_lstnew \
		${LINKED_LIST}/ft_lstremove_if \
		${LINKED_LIST}/ft_lstreverse \
		${LINKED_LIST}/ft_lstsize \
		${LINKED_LIST}/ft_lstsort \
		${FILE}/get_next_line \

SRCS = $(addsuffix .c, ${SRC})

OBJECTS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	${CC} $(CFLAGS) -c $< -o $@ -I ${INCLUDES}

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

all: $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re

