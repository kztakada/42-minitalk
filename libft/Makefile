# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: katakada <katakada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/30 16:04:12 by katakada          #+#    #+#              #
#    Updated: 2024/12/02 00:10:52 by katakada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

PRINTF =	ft_printf/ft_printf.c \
			ft_printf/ft_dprintf.c \
			ft_printf/ft_vprintf.c \
			ft_printf/print_format_funcs.c \
			ft_printf/print_format_setters.c \
			ft_printf/print_format_validator_order.c \
			ft_printf/print_format_validator.c \
			ft_printf/print_format.c \
			ft_printf/print_invalid_format.c \
			ft_printf/print_invalid_order_case.c \
			ft_printf/print_invalid_order_case_printers.c \
			ft_printf/print_invalid_order_case_setters.c \
			ft_printf/printer_char.c \
			ft_printf/printer_hex.c \
			ft_printf/printer_hex_prefix.c \
			ft_printf/printer_int.c \
			ft_printf/printer_percent.c \
			ft_printf/printer_ptr.c \
			ft_printf/printer_str.c \
			ft_printf/printer_u_int.c \
			ft_printf/printer_util_loop_print.c \
			ft_printf/printer_util_nbr_and_str_print.c \
			ft_printf/printer_util_number_print.c \
			ft_printf/util_func_putnbr.c \
			ft_printf/util_print_conf_func.c \
			ft_printf/util_print_conf_hex.c \
			ft_printf/util_print_conf_int_func.c \
			ft_printf/util_print_conf_int.c \
			ft_printf/util_print_conf_others.c \
			ft_printf/util_print_conf_ptr.c \
			ft_printf/util_print_conf_u_int.c \
			ft_printf/util_validator_flag.c \
			ft_printf/util_validator_format.c 
LIBFT = 	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			get_next_line_bonus.c
SRCS = 		$(LIBFT) $(PRINTF)
BONUSSRCS = bonus/ft_lstadd_back.c \
			bonus/ft_lstadd_front.c \
			bonus/ft_lstclear.c \
			bonus/ft_lstdelone.c \
			bonus/ft_lstiter.c \
			bonus/ft_lstlast.c \
			bonus/ft_lstmap.c \
			bonus/ft_lstnew.c \
			bonus/ft_lstsize.c
INCS =		includes/

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INCS) 
ISBOUNS = 0

ifeq ($(ISBOUNS), 1)
	SRCS += $(BONUSSRCS)
endif

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus:
	$(MAKE) all ISBOUNS=1


clean:
	rm -f $(SRCS:.c=.o) $(BONUSSRCS:.c=.o)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re