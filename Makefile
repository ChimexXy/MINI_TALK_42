CC = cc
CFLAGS = -Wall -Wextra -Werror

CLIENT = ./mandatory/client.c ./mandatory/utils.c
SERVER = ./mandatory/server.c ./mandatory/utils.c
client = client
server = server

B_CLIENT = ./bonus/client_bonus.c ./bonus/utils_bonus.c
B_SERVER = ./bonus/server_bonus.c ./bonus/utils_bonus.c
client_bonus = client_bonus
server_bonus = server_bonus

all : $(server) $(client)

$(server): $(SERVER) 
					$(CC) $(CFLAGS) $(SERVER) -o $(server)
$(client): $(CLIENT)
					$(CC) $(CFLAGS) $(CLIENT) -o $(client)

bonus: $(server_bonus) $(client_bonus)

$(server_bonus): $(B_SERVER)
					$(CC) $(CFLAGS) $(B_SERVER) -o $(server_bonus)
$(client_bonus): $(B_CLIENT)
					$(CC) $(CFLAGS) $(B_CLIENT) -o $(client_bonus)

clean:
		rm -rf $(server) $(client) $(client_bonus) $(server_bonus)

fclean: clean

re: fclean all
