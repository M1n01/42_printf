NAME = libft.a

CC = cc
INCDIR = -I include
CFLAGS = -Wall -Wextra -Werror $(INCDIR)
LFLAGS = 

LIBFT = ft_isspace.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_strlen.c

SRCS = $(addprefix srcs/,$(LIBFT))

OBJS = $(SRCS:%.c=%.o)

$(NAME): $(OBJS)
		ar -rc $(NAME) $(OBJS)

all: $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

norm:
		@norminette -R CheckForbiddenSourceHeader $(SRCS)
		@norminette -R CheckDefine include/*.h

.PHONY: all clean fclean re bonus norm
