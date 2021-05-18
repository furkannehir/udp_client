targets: client server

client:
	$(CC) -o clientMain client.c clientMain.c

server:
	$(CC) -o server server.c


clean:
	rm -f clientMain server