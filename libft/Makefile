NAME	=	libft.a

SRCS	=	ft_atoi.c		\
			ft_error.c		\
			ft_putchar_fd.c	\
			ft_putstr_fd.c	\
			ft_strlen.c		\
			ft_printf/ft_hex.c		\
			ft_printf/ft_nums.c		\
			ft_printf/ft_printf.c	\
			ft_printf/ft_strs.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

AR		=	ar rc

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

all:		$(NAME)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		clean fclean all re
