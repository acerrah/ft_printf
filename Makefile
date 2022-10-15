SRC = 		ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c\
			ft_strlen.c \
			ft_bzero.c \
			ft_memset.c \
			ft_memcpy.c \
			ft_calloc.c \
			ft_strmapi.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_itoa.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memmove.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_substr.c \
			ft_strtrim.c \
			ft_split.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_striteri.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

SRCS = ${addprefix ./libft/,${SRC}} \
			src/ft_printf.c \
			src/ft_printf2.c \
			src/ft_resetstruct.c \
			src/check_arg.c \
			src/convert_to_hexa.c

OBJS = ${SRCS:.c=.o}
SRCSB = ${addprefix ./libft/,${SRC}} \
		srcb/ft_check_arg.c \
		srcb/ft_flag_check.c \
		srcb/ft_flag_check2.c \
		srcb/ft_printf_bonus.c \
		srcb/ft_len.c \
		srcb/ft_print.c \
		srcb/ft_reset.c \
		srcb/ft_print_hex.c \
		srcb/ft_print_dec.c \
		srcb/ft_convert_to_hexa.c \
		srcb/ft_print_hexp.c \
		srcb/ft_print_unsigned.c
OBJS_B = ${SRCSB:.c=.o}
NAME = libftprintf.a
NAME_B = libftprintfb.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf
LIBC = ar -rcs

all: ${NAME}

bonus: fclean ${NAME_B}

${NAME}: ${OBJS}
	@${LIBC} ${NAME} ${OBJS}
	@echo "<3 :3 uWu <3 :3"

${NAME_B} : ${OBJS_B}
	@${LIBC} ${NAME_B} ${OBJS_B}
	@echo "<3 :3 uWu <3 :3"

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	@${RM} ${OBJS} ${OBJS_B}

fclean: clean
	@${RM} ${NAME} ${bonus}

re: fclean all

.PHONY: all bonus clean fclean re .c.o