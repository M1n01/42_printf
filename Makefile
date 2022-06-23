NAME = libftprintf.a

CC = cc
INCDIR = -I./include
CFLAGS = -Wall -Wextra -Werror $(INCDIR)

MANDATORY = ft_printf.c process_ascii.c process_ptr.c ft_putchar.c ft_putnbr.c

SRCS = $(addprefix srcs/,$(MANDATORY))

OBJS = $(SRCS:%.c=%.o)

$(NAME): $(OBJS)
		ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
		$(RM) $(OBJS) $(B_OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

norm:
		@norminette -R CheckForbiddenSourceHeader $(SRCS)
		@norminette -R CheckDefine include/*.h

.PHONY: all clean fclean re norm
