// Projeto 3 de Teoria e Aplicação de Grafos, Turma A
// Prof.: Díbio
// Autores: Rafael Gonçalves de Paulo (17/0043959)
//          João Lucas Azevedo Yamin Rodrigues da Cunha (17/0013731)

#include "empEstavel.h"

using namespace std;

vector<int> getEmpEstavel(int numPares, vector<Prof> profs, vector<Escola> escolas) {

  int paresQfaltam = numPares;

  vector<int> ans(profs.size(), -1);
    deque<int> escAseremPreench;
    for(unsigned int i = 0; i < escolas.size(); i++) escAseremPreench.push_back(i);
    int vagaSendoOfertada[escolas.size()];
    memset(vagaSendoOfertada, 0, sizeof(vagaSendoOfertada));

    while(!escAseremPreench.empty() && paresQfaltam > 0){
        int escAtual = escAseremPreench[0],
        habVagaAtual = escolas[escAtual][vagaSendoOfertada[escAtual]],
        temp = -1, trank = 100;
        escAseremPreench.pop_front();
        for(auto prof: profs){
            int rank = -1;
            if (prof.escolas[0] == escAtual) rank = 0;
            if (prof.escolas[1] == escAtual) rank = 1;
            if (prof.escolas[2] == escAtual) rank = 2;
            if (prof.escolas[3] == escAtual) rank = 3;
            if (prof.escolas[4] == escAtual) rank = 4;
            if (rank == -1) continue;

            if (rank == -1) continue;                 // se o prof n quer essa escola, va para o próximo
            if (prof.hab < habVagaAtual)  continue;   // se o prof não tem habilitação para essa vaga
            if (ans[prof.ind] != -1) continue;        // se prof já foi alocado para alguma escola
            
            // se já tem um professor candidato que é melhor do que esse, vá para o próximo
            if (((temp != -1) and ((profs[temp].hab > prof.hab) or (trank < rank)))) continue;
            // se ainda não tem um professor alocado nessa vaga, considere essa vaga como alocada
            // e continue procurando por um professor melhor para substituir o atual nessa vaga
            if (temp == -1) paresQfaltam--;
            // se tinha um professor anteriormente alocado, que não é tão bom candidato para essa vaga
            // como o prof atual, desaloque o professor antigo
            else ans[temp] = -1;
            // se chegou aqui, o prof atual é melhor do que o temporario, coloque ele como melhor candidato
            // atual para a vaga, e aloque ele para a vaga
            ans[prof.ind] = escAtual, temp = prof.ind, trank = rank;
        }
        vagaSendoOfertada[escAtual]++;
        if ((int) escolas[escAtual].size() > vagaSendoOfertada[escAtual]) escAseremPreench.push_back(escAtual); // se numero atual de vagas escolas > a vaga atual preenchida, bota a escola na lista escAseremPreench
    }

    return ans;
}