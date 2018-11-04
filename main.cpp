#include "construction.h"
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define NUM_PARES 70

using namespace std;

int main() {
  vector<Prof> profs;
  vector<Escola> escolas;

  getProfsEscolas("entradaProj3TAG.txt", profs, escolas);
  vector<Adj> adj(escolas.size(), pair<int, int>(-1, -1));

  int paresQfaltam = NUM_PARES;

  vector<int> empEst(profs.size(), -1);   // variavel final do emparelhamento

  deque<int> escolasASeremVistas;
  // inserir as escolas no deque
  for (int i = 0; i < escolas.size(); i++)
    escolasASeremVistas.push_back(i);

  int vagaAtual[escolas.size()];  // a vaga atual que está sendo vista para essa escola
  for (int i = 0; i < escolas.size(); i++)
    vagaAtual[i] = 0;

  while(!escolasASeremVistas.empty() && paresQfaltam > 0) {
    int esc = escolasASeremVistas[0];
    int habEscAt = escolas[esc][vagaAtual[esc]]; // a hab necessaria para a vaga atual da escola atual
    int temp = -1;                               // professor mais adequado pra vaga dos mais visitados
    int tpref = 999999;                          // preferencia de temp pela escola esc

    escolasASeremVistas.pop_front();

    for (auto prof: profs) {
      // se o professor não quer essa escola, vá para o próximo
      if (find(prof.escolas.begin(), prof.escolas.end(), esc) != prof.escolas.end())
        continue;

      int rankPref = -1;  // a ordem da escola nas preferencias do professor
      for (auto escPreten : prof.escolas) {
        rankPref++;
        if (escPreten == esc) break;
      }

      if (temp != -1 && (profs[temp].hab > prof.hab || tpref < rankPref))
        continue;
      if (temp != -1)
        paresQfaltam--;
      else
        empEst[temp] = -1;

      empEst[prof.ind] = esc;
      temp = prof.ind;
      tpref = rankPref;
      // if (prof.ind == profs[1].ind)
      //   cout << "temp: " << temp << endl;
    }
    vagaAtual[esc]++;

    // se a escola não está preenchida, coloque ela de novo na fila
    if (escolas[esc].size() > vagaAtual[esc]) escolasASeremVistas.push_back(esc);
  }


  for (auto a : empEst) {
    cout << "par est: " << a << endl;
  }
  
}