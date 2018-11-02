#include "construction.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  vector<Prof> profs;
  vector<Escola> escolas;

  getProfsEscolas("entradaProj3TAG.txt", profs, escolas);
  vector<Adj> adj(escolas.length, pair<int, int>(-1, -1));

  vector<int> ans(profs.size(), -1);
  queue<int> auxiliarQueue;
}