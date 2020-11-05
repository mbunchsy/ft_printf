# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mramos-j <mramos-j@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/06 13:38:35 by gcachon-          #+#    #+#              #
#    Updated: 2020/10/13 21:52:33 by mramos-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra -I.
SRC_PF =  ft_printf.c  ft_parse.c ft_init.c ft_compute.c ft_printnums.c  \
		ft_utils.c ft_printnumspos.c ft_printnumsneg.c ft_printchar.c \
		ft_printnumsu.c ft_printhexa.c ft_printpointer.c ft_asterisk.c \
		printfmain.c
        
SRC_LFT = ft_atoi.c ft_bzero.c ft_isdigit.c ft_toupper.c ft_putchar_fd.c \
        ft_putstr_fd.c ft_strlen.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
        ft_isascii.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c \
        ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putendl_fd.c \
        ft_putnbr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c \
        ft_strlcat.c ft_strlcpy.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
        ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c  \
		ft_putchar.c 
OBJ_SRC = $(SRC_PF:.c=.o)
OBJ_LFT = $(SRC_LFT:.c=.o)
LIBFT_PATH = libft
SRC_PATH = srcs
INCLUDES_PATH = includes
LFT = $(addprefix $(LIBFT_PATH)/, $(OBJ_LFT))
SRC = $(addprefix $(SRC_PATH)/, $(OBJ_SRC))
INCLUDE_PF = ft_printf.h
INCLUDE_LFT = libft.h
PF_LIB = $(addprefix $(INCLUDES_PATH)/, $(INCLUDE_PF))
LFT_LIB = $(addprefix $(LIBFT_PATH)/, $(INCLUDE_LFT))

all: $(NAME)
$(NAME): $(SRC) $(LFT) $(PF_LIB) $(LFT_LIB)
	ar rc $(NAME) $(SRC) $(LFT)
%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<
debug:
	gcc $(CFLAGS) -g $(SRC) $(LFT)

clean:
	rm -f $(SRC) $(LFT)

fclean: clean
	rm -f $(NAME)

re: fclean all