
CC=g++
FLAGS=-std=c++20 -Wall -Wextra -Werror -fmodules-ts

main: math.o main.o
	$(CC) $(FLAGS) math.o main.o -o main

math.o: math.cpp
	$(CC) $(FLAGS) -c math.cpp

main.o: math.o main.cpp
	$(CC) $(FLAGS) -c main.cpp

clean:
	rm -rf *.o main gcm.cache
