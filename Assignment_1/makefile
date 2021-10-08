all:	server.c client.c
	gcc server.c -o sever_test client.c -o client_test
server:	server.c
	gcc server.c -o server_test
client:	client.c
	gcc client.c -o client_test
clean:
	rm client_test server_test
	