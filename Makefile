SRCS		=	server.c \
				client.c
				
OBJECTS		=	$(SRCS:.c=.o)
LIB_PATH	=	./libft

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

NAME		= server client

all: libft server client

libft:
	make -C libft

server: server.o
	$(CC) -o $@ $< -Llibft -lft

client: client.o libft
	$(CC) -o $@ $< -Llibft -lft

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	@/bin/rm -f $(OBJECTS)
	@make clean -C $(LIB_PATH)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(LIB_PATH)/*.a

re: fclean all

.PHONY: all clean fclean re libft
