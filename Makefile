# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 16:50:54 by afaugero          #+#    #+#              #
#    Updated: 2025/02/25 18:56:50 by afaugero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS= pipex_bonus
LIBFT_DIR= libft/
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -L ./libft -lft


SRC = 		mandatory/pipex \
			mandatory/exec/exec_cmds \
			mandatory/exec/helpers/exec_cmds_helpers \
			mandatory/parse/parse \
			mandatory/parse/cmds/parse_cmds \
			mandatory/parse/cmds/helpers/path \
			mandatory/parse/cmds/helpers/quotes \
			mandatory/parse/cmds/helpers/split_helpers \
			mandatory/parse/cmds/helpers/split_quotes \
			mandatory/parse/file/parse_infile \
			mandatory/parse/file/parse_outfile \
			mandatory/utils/clean_up \

SRC_BONUS =	bonus/pipex_bonus \
			bonus/exec/exec_cmds_bonus \
			bonus/exec/helpers/exec_cmds_errors_bonus \
			bonus/exec/helpers/exec_cmds_helpers_bonus \
			bonus/parse/parse_bonus \
			bonus/parse/cmds/parse_cmds_bonus \
			bonus/parse/cmds/helpers/path_bonus \
			bonus/parse/cmds/helpers/quotes_bonus \
			bonus/parse/cmds/helpers/split_helpers_bonus \
			bonus/parse/cmds/helpers/split_quotes_bonus \
			bonus/parse/file/parse_infile_bonus \
			bonus/parse/file/parse_outfile_bonus \
			bonus/parse/here_doc/parse_here_doc_bonus \
			bonus/utils/clean_up_bonus \

SRCS = $(addsuffix .c, ${SRC})
SRCS_BONUS = $(addsuffix .c, $(SRC_BONUS))

OBJECTS = $(SRCS:.c=.o)
OBJECTS_BONUS = $(SRCS_BONUS:.c=.o)

all: ${NAME}

%.o: %.c
	${CC} $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	make -C ${LIBFT_DIR} all
	${CC} ${CFLAGS} ${OBJECTS} -o ${NAME} ${INCLUDES}

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJECTS_BONUS)
	make -C $(LIBFT_DIR) all
	$(CC) $(CFLAGS) $(OBJECTS_BONUS) -o $(NAME_BONUS) $(INCLUDES)

clean:
	make -C ${LIBFT_DIR} clean
	rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	rm -f ${LIBFT_DIR}/libft.a
	rm -f $(NAME) $(NAME_BONUS)

re:	fclean all

.PHONY: all clean fclean re
