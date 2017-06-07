CC = g++


all:
	$(CC) *.cpp -pthread -o proxy
