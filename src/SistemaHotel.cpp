#include "../include/SistemaHotel.h"
#include <algorithm>
#include <iostream>

int SistemaHotel::cadastrarQuarto(int numero, int capacidade, float valorDiaria) {
    if (capacidade <= 0) {
        return ERRO_CAPACIDADE; 
    }

    if (valorDiaria <= 0.0) {
        return ERRO_VALOR;
    }

    auto it = std::find_if(quartos.begin(), quartos.end(), 
        [numero](const Quarto& q){
            return q.obterNumero() == numero;
        });

    if (it != quartos.end()) {
        return ERRO_DUPLICIDADE;
    }

    Quarto novoQuarto(numero, capacidade, valorDiaria);
    quartos.push_back(novoQuarto);
    
    return SUCESSO;
}