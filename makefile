################################################################
# pra cada modulo(.cpp), fazer assim:
# 
# nomeDoModulo.o: nomeDoModulo.cpp [e outras dependencias .o, se tiver]
# 	$(CC) $(CFLAGS) nomeDoModulo.cpp
# 
# depois, adicione "nomeDoModulo.o" em "MODULES", do lado dos outros .o's
#

# Compilador:
CC = g++

# Flags:
CFLAGS = -c -g -Wall -std=c++11 -Wsign-compare

# modulos
MODULES = construction.o prof.o empEstavel.o

# Compila o executavel a partir dos .o's
executavel: $(MODULES) main.o
	$(CC) main.o $(MODULES) -fPIC -o main

# modulo principal, o programa em si
main.o: main.cpp $(MODULES)
	$(CC) $(CFLAGS) main.cpp
	
# modulo de leitura de arquivo e criação do grafo
construction.o: construction.cpp
	$(CC) $(CFLAGS) construction.cpp

# modulo da classe de professor
prof.o: prof.cpp
	$(CC) $(CFLAGS) prof.cpp

# modulo que retorna o emparelhamento estavel
empEstavel.o: empEstavel.cpp
	$(CC) $(CFLAGS) empEstavel.cpp