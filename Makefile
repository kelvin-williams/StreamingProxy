CC = g++


all:
	$(CC) Main.cpp -pthread -o proxy -std=gnu++11
