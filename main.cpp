#include "construction.h"
#include <iostream>
#include <queue>
#include <vector>

#define NUM_PARES 70

using namespace std;

int main() {
  vector<Prof> profs;
  vector<Escola> escolas;

  getProfsEscolas("entradaProj3TAG.txt", profs, escolas);
  vector<Adj> adj(escolas.length, pair<int, int>(-1, -1));

  int paresQfaltam = NUM_PARES;
  int controle[escolas.size()];
  for (int i = 0; i < controle.size(); i++)
    controle[i] = 0;

  // aaaaaaaaaaaaaa
  vector<int> ans(profs.size(), -1);
  queue<int> auxiliarQueue;
  for (int ind = 0; ind < escolas.size(); ind++)
    auxiliarQueue.push_back(ind);

  while (!auxiliarQueue.empty() && paresQfaltam > 0) {
    int escAtual = auxiliarQueue.front();
    int x = escolas[escAtual][controle[escAtual]];
    int temp = -1;
    int tRank = 100;
    auxiliarQueue.pop_front();

    for (int i : adj)

  }
}