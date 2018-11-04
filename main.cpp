#include "construction.h"
#include "empEstavel.h"
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define NUM_PARES 69

using namespace std;

int main() {
  vector<Prof> profs;
  vector<Escola> escolas;

  getProfsEscolas("entradaProj3TAG.txt", profs, escolas);

  vector<int> emparEstavel = getEmpEstavel(NUM_PARES, profs, escolas);
  
  int profInd = 0;
  cout << "RESULTADO DO EMPARELHAMENTO:" << endl << "Nº do Professor \t Nº da Escola" << endl; 
  for (auto esc: emparEstavel) {
    profInd++;
    if (esc == -1) continue;  // se o professor não foi assinalado a nenhuma escola, continue
    cout << " Prof. " << profInd << " \t\t  Escola " << esc << endl;
  }
  
}