#ifndef SISTEMAHOTEL_H
#define SISTEMAHOTEL_H

#include <vector>
#include "Quarto.h"
#include "Cliente.h"

#define SUCESSO 0
#define ERRO_DUPLICIDADE 1
#define ERRO_CAPACIDADE 2
#define ERRO_VALOR 3
#define ERRO_CODIGO 4

class SistemaHotel {
private:
    std::vector<Quarto> quartos;
    std::vector<Cliente> clientes;
    
public:
    int cadastrarQuarto(int numero, int capacidade, float valorDiaria);
    int cadastrarCliente(int codigo, std::string nome, std::string endereco, std::string telefone);
    
    std::vector<Quarto>& obterQuartos() { return quartos; }
    void limparQuartos() { quartos.clear(); }
    
    std::vector<Cliente>& obterClientes() { return clientes; }
    void limparClientes() { clientes.clear(); }
};

#endif