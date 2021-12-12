# MANDATORY :
CLIENT		=	client

SERVER		=	server

SRC_CLI		=	srcs/client.c

SRC_SERV	=	srcs/server.c

OBJ_CLI		=	$(SRC_CLI:.c=.o)

OBJ_SERV	=	$(SRC_SERV:.c=.o)

# BONUS :
CLIENT_B	=	client_bonus

SERVER_B	=	server_bonus

SRC_CLI_B	=	bonus/client_bonus.c

SRC_SERV_B	=	bonus/server_bonus.c

OBJ_CLI_B	=	$(SRC_CLI_B:.c=.o)

OBJ_SERV_B	=	$(SRC_SERV_B:.c=.o)

# REST :
CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror


all:			$(CLIENT) $(SERVER)

$(CLIENT):		$(OBJ_CLI)
				make -C libft/
				$(CC) $(CFLAGS) -o $(CLIENT) $(OBJ_CLI) -Llibft -lft

$(SERVER):		$(OBJ_SERV)
				make -C libft/
				$(CC) $(CFLAGS) -o $(SERVER) $(OBJ_SERV) -Llibft -lft

bonus:			$(CLIENT_B) $(SERVER_B)

$(CLIENT_B):	$(OBJ_CLI_B)
				make -C libft/
				$(CC) $(CFLAGS) -o $(CLIENT_B) $(OBJ_CLI_B) -Llibft -lft

$(SERVER_B):	$(OBJ_SERV_B)
				make -C libft/
				$(CC) $(CFLAGS) -o $(SERVER_B) $(OBJ_SERV_B) -Llibft -lft

clean:
				make -C libft/ clean
				rm -rf $(OBJ_CLI) $(OBJ_SERV) $(OBJ_CLI_B) $(OBJ_SERV_B)

fclean:			clean
				make -C libft/ fclean
				rm -rf $(CLIENT) $(SERVER) $(CLIENT_B) $(SERVER_B)

re:				fclean all

.PHONY:			all clean fclean re
