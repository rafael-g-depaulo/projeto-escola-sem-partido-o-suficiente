// Projeto 3 de Teoria e Aplicação de Grafos, Turma A
// Prof.: Díbio
// Autores: Rafael Gonçalves de Paulo (17/0043959)
//          João Lucas Azevedo Yamin Rodrigues da Cunha (17/0013731)
// construction.cpp: Arquivo de implementação das funções necessárias para construção do grafo

#include <string>
#include <vector>
#include <regex>
#include <fstream>
#include <iostream>
#include "construction.h"

using namespace std;

void getProfsEscolas(const string& fileName, vector<Prof>& profs, vector<Escola>& escolas) {

  fstream fileStream (fileName);
  string buffer;
  bool jumpFirstSchool = true;

  if (!fileStream.is_open())
    return;
  
  while (getline(fileStream, buffer)) {
    if (buffer.find("(P") != string::npos) {
      int ind, esc1, esc2, esc3, esc4, esc5, habilitacao;
    
      sscanf(buffer.c_str(), "(P%d, %d): (E%d, E%d, E%d, E%d, E%d)", 
        &ind, &habilitacao, &esc1, &esc2, &esc3, &esc4, &esc5);

      profs.push_back(Prof(ind-1, habilitacao, esc1, esc2, esc3, esc4, esc5));
    }
    // pule a primeira escola. da merda se n fizer isso
    else if (jumpFirstSchool && buffer.find("(E") != string::npos) {
      jumpFirstSchool = false;
    }
    else if (buffer.find("(E") != string::npos) {
      if (buffer.length() < 10) {
        int hab;
        sscanf(buffer.c_str(), "(E%*d):(%d)", &hab);
        Escola esc;
        esc.push_back(hab);
        escolas.push_back(esc);
      } else {
        int hab1, hab2;
        sscanf(buffer.c_str(), "(E%*d):(%d):(%d)", &hab1, &hab2);
        Escola esc;
        esc.push_back(hab1);
        esc.push_back(hab2);
        escolas.push_back(esc);
      }
    }
  }
}