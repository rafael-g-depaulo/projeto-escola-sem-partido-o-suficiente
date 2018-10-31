#include "construction.h"
#include <iostream>

using namespace std;

int main() {
  vector<Prof> profs;
  vector<Escola> escolas;

  getProfsEscolas("entradaProj3TAG.txt", profs, escolas);

  for (auto escola : escolas) {
    cout << "escola: " << escola[0] << ", " << escola[1] << endl;
  }
}