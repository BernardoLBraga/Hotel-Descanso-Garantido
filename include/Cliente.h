#ifndef CLIENTE_H
#define CLIENTE_H

#include "Definicoes.h"

class Cliente {
private:
    int codigo;
    char nome[MAX_NOME];
    char endereco[MAX_ENDERECO];
    char telefone[MAX_TELEFONE];
    int pontosFidelidade;

public:
    Cliente(int cod, const char* n, const char* end, const char* tel);
    Cliente() : codigo(0), pontosFidelidade(0) {}
    
    int obterCodigo() const { return codigo; }
    const char* obterNome() const { return nome; }
    const char* obterEndereco() const { return endereco; }
    const char* obterTelefone() const { return telefone; }
    
    int obterPontosFidelidade() const { return pontosFidelidade; }
    void adicionarPontos(int pontos) { pontosFidelidade += pontos; }
};

#endif