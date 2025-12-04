#ifndef QUARTO_H
#define QUARTO_H

#include <string>

class Quarto {
private:
    int numero;
    int capacidade;
    float valorDiaria;
    std::string status;

public:
    Quarto(int num, int cap, float valor) : 
        numero(num), capacidade(cap), valorDiaria(valor), status("DESOCUPADO") {}
    
    Quarto() : numero(0), capacidade(0), valorDiaria(0.0), status("INDEFINIDO") {}
    
    int obterNumero() const { return numero; }
    int obterCapacidade() const { return capacidade; }
    float obterValorDiaria() const { return valorDiaria; }
    std::string obterStatus() const { return status; }

    void definirStatus(const std::string& novoStatus) { status = novoStatus; }
};

#endif