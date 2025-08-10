# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: weijian <weijian@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/09 10:17:01 by weijian           #+#    #+#              #
#    Updated: 2025/08/10 13:34:01 by weijian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -O0 -I${INCL_DIR}

INCL_DIR = includes/
INCL = rush.h numbers.h
INCL := $(addprefix ${INCL_DIR},${INCL}) 

SRCS_DIR = srcs/
SRCS = main.c get_number.c load_dict.c translate.c tokenize.c write_num.c
SRCS := $(addprefix ${SRCS_DIR},${SRCS})

UTILS_DIR = utils/
UTILS = chars.c dictionary.c list.c strings.c substr.c write.c
UTILS := $(addprefix ${UTILS_DIR},${UTILS})
SRCS += ${UTILS}

ALL_SUB_DIR = ${SRCS_DIR} ${UTILS_DIR}

OBJS_DIR = objs/
OBJS_SUB_DIR = $(addprefix ${OBJS_DIR}, ${ALL_SUB_DIR})
OBJS := $(addprefix ${OBJS_DIR}, ${SRCS:%.c=%.o})

# --- RULES
all: ${NAME}

${NAME}: ${OBJS} ${INCL}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

${OBJS}: ${OBJS_DIR}%.o: %.c ${INCL} | ${OBJS_SUB_DIR}
	@${CC} ${CFLAGS} -c $< -o $@

# --- SUBDIR

${OBJS_SUB_DIR}: %:
	mkdir -p $@

# --- CLEANUP

clean:
	rm -rf ${OBJS_DIR}

fclean: clean
	rm -f ${NAME}

re: fclean all

# --- PHONY

.PHONY: all clean fclean re