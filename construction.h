// Projeto 1 de Teoria e Aplicação de Grafos, Turma A
// Prof.: Díbio
// Autores: Rafael Gonçalves de Paulo (17/0043959)
//          João Lucas Azevedo Yamin Rodrigues da Cunha (17/0013731)
// construction.h: Declaração de funções necessárias para a montagem do grafo

#include <string>
#include <vector>
#include <pair>
#include <fstream>
#include "prof.cpp"

using namespace std;

typedef vector<int> Escola;
typedef Pair<int, int> Adj;

void getProfsEscolas(const string& fileName, vector<Prof>& profs, vector<Escola>& escola);