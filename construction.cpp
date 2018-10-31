// Projeto 1 de Teoria e Aplicação de Grafos, Turma A
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

// // profSize: retorna o tamanho que o vetor de professores deve ter
// size_t profSize (fstream& fileStream) {

// 	string buffer;
// 	size_t size = 0;

// 	if (fileStream.is_open()) {
// 		while (getline (fileStream, buffer)) {
// 			if (buffer.find("(P") != string::npos)
// 				size++;
// 			else if (buffer.find("(E") != string::npos)
// 				break;
// 		}
// 	}
// 	else {
// 		throw "Erro ao ler o arquivo!";
// 	}
// 	return size;
// }

// // escSize: retorna o tamanho que o vetor de escolas deve ter
// size_t escSize (fstream& fileStream) {

// 	string buffer;
// 	size_t size = 0;

// 	if (fileStream.is_open()) {
// 		while (getline (fileStream, buffer)) {
// 			if (buffer.find("(E") != string::npos)
// 				size++;
// 		}
// 	}
// 	else {
// 		throw "Erro ao ler o arquivo!";
// 	}
// 	return size;
// }

void getProfsEscolas(const string& fileName, vector<Prof>& profs, vector<Escola>& escolas) {

  fstream fileStream (fileName);
  string buffer;

  if (!fileStream.is_open())
    return;
  
  while (getline(fileStream, buffer)) {
    if (buffer.find("(P") != string::npos) {
      int esc1, esc2, esc3, esc4, esc5, habilitacao;
    
      sscanf(buffer.c_str(), "(P%*d, %d): (E%d, E%d, E%d, E%d, E%d)", 
        &habilitacao, &esc1, &esc2, &esc3, &esc4, &esc5);

      profs.push_back(Prof(habilitacao, esc1, esc2, esc3, esc4, esc5));
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