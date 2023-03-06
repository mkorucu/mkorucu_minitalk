CC=gcc
CFLAGS=-Wall -Wextra -Werror
LIB = sources/sourcesminitalk.a
CLIENT = client
SERVER = server
OBJSERVER = $(SRCSERVER:.c=.o)
OBJCLIENT = $(SRCCLIENT:.c=.o)

all: $(LIB) $(SERVER) $(CLIENT)

$(LIB):
	@make -C ./sources

$(SERVER): $(OBJSERVER)
	@$(CC) $(CFLAGS) -o $(SERVER) server.c $(LIB)
	
$(CLIENT): $(OBJCLIENT)
	@$(CC) $(CFLAGS) -o $(CLIENT) client.c $(LIB)
clean:
	@rm -rf $(OBJSERVER) $(OBJCLIENT)

fclean: clean
	@make fclean -C ./sources
	@rm -rf $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
