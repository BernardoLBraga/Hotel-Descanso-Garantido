#ifndef SISTEMAHOTEL_H
#define SISTEMAHOTEL_H

#include <vector>
#include "Quarto.h"

#define SUCESSO 0
#define ERRO_DUPLICIDADE 1
#define ERRO_CAPACIDADE 2
#define ERRO_VALOR 3

class SistemaHotel {
private:
    std::vector<Quarto> quartos;
    
public:
    int cadastrarQuarto(int numero, int capacidade, float valorDiaria);
    
    std::vector<Quarto>& obterQuartos() { return quartos; }
    void limparQuartos() { quartos.clear(); }
};

#endif