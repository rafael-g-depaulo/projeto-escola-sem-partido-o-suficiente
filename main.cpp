#include "construction.h"
#include <iostream>

using namespace std;

int main() {
  vector<Prof> profs;
  vector<Escola> escolas;

  getProfsEscolas("entradaProj3TAG.txt", profs, escolas);
  vector<Adj> adj(escolas.length, pair<int, int>(-1, -1));

  for (auto prof : profs) {
    // escola #1 do prof
    auto esc1 = escolas[prof.escolas[0]];

    // se escola #1 tem vaga principal
    if (get<0>adj[esc1] == -1) {
      // se a escola aceita o prof
      if (esc1[0] <= prof.hab)
        // adj.
    }
    // se a escola #1 tem vaga secundária
    else if ((esc1.size() == 2 && get<1>adj[esc1] == -1)) {

    }
  }
}