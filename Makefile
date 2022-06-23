NAME = libftprintf.a

CC = cc
INCDIR = -I./include -I./libft/include
CFLAGS = -Wall -Wextra -Werror $(INCDIR)
LFLAGS = 

MANDATORY = ft_printf.c process_ascii.c process_ptr.c process_int.c process_hex.c
BONUS = 

SRCS = $(addprefix srcs/,$(MANDATORY))
B_SRCS = $(addprefix srcs/bonuses/,$(BONUS))

OBJS = $(SRCS:%.c=%.o)
B_OBJS = $(B_SRCS:%.c=%.o)

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

norm:
		@norminette -R CheckForbiddenSourceHeader $(SRCS)
		@norminette -R CheckDefine include/*.h

.PHONY: all clean fclean re bonus norm
