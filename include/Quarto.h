#ifndef QUARTO_H
#define QUARTO_H

#include "Definicoes.h"

class Quarto {
private:
    int numero;
    int capacidade;
    float valorDiaria;
    char status[MAX_TELEFONE]; 

public:
    Quarto(int num, int cap, float val, const char* stat);
    Quarto() : numero(0), capacidade(0), valorDiaria(0.0f) {}
    
    int obterNumero() const { return numero; }
    int obterCapacidade() const { return capacidade; }
    float obterValorDiaria() const { return valorDiaria; }
    const char* obterStatus() const { return status; }
    
    void definirStatus(const char* novoStatus);
};

#endif