NAME = push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c utils.c utils2.c opRotate.c opSwap.c opPush.c opReverserotate.c opSort.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
