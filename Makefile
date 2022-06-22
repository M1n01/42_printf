NAME = libftprintf.a

CC = cc
INCDIR = -I./include -I./libft/include
CFLAGS = -Wall -Wextra -Werror $(INCDIR)
LFLAGS = 

MANDATORY = ft_printf.c process_ascii.c process_ptr.c process_int.c process_hex.c
BONUS = 
TEST = ft_putstr.c ft_putchar.c ft_atoi.c ft_isspace.c ft_isdigit.c ft_strchr.c ft_strlen.c

SRCS = $(addprefix srcs/,$(MANDATORY))
B_SRCS = $(addprefix srcs/bonuses/,$(BONUS))
T_SRCS = $(addprefix libft/srcs/,$(TEST))

OBJS = $(SRCS:%.c=%.o)
B_OBJS = $(B_SRCS:%.c=%.o)
T_OBJS = $(T_SRCS:%.c=%.o)

ifdef WITH_BONUS
	OBJS += $(B_OBJS)
endif


$(NAME): $(OBJS)
		$(MAKE) -C ./libft
		cp libft/libft.a $(NAME)
		ar -rcs $(NAME) $(OBJS)

all: $(NAME)

bonus:
		@make all WITH_BONUS=1

clean:
		$(RM) $(OBJS) $(B_OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

test:
		$(CC) -Wno-format $(INCDIR) $(SRCS) $(T_SRCS)

printf:
		$(CC) -Wno-format $(INCDIR) $(SRCS) $(T_SRCS) -D TEST -o printf

ft_printf:
		$(CC) -Wno-format $(INCDIR) $(SRCS) $(T_SRCS) -D TEST -D FT_PRINTF -o ft_printf

norm:
		@norminette -R CheckForbiddenSourceHeader $(SRCS)
		@norminette -R CheckDefine include/*.h

.PHONY: all clean fclean re bonus norm
