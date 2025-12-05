#ifndef SISTEMAHOTEL_H
#define SISTEMAHOTEL_H

#include <vector>
#include "Quarto.h"
#include "Cliente.h"
#include "Funcionario.h"

#define SUCESSO 0
#define ERRO_DUPLICIDADE 1
#define ERRO_CAPACIDADE 2
#define ERRO_VALOR 3
#define ERRO_CODIGO 4
#define ERRO_SALARIO 5 
#define ERRO_CARGO 6

class SistemaHotel {
private:
    std::vector<Quarto> quartos;
    std::vector<Cliente> clientes;
    std::vector<Funcionario> funcionarios;
    
public:
    int cadastrarQuarto(int numero, int capacidade, float valorDiaria);
    int cadastrarCliente(int codigo, std::string nome, std::string endereco, std::string telefone);
    int cadastrarFuncionario(int codigo, std::string nome, std::string telefone, std::string cargo, float salario);
    
    std::vector<Quarto>& obterQuartos() { return quartos; }
    void limparQuartos() { quartos.clear(); }
    
    std::vector<Cliente>& obterClientes() { return clientes; }
    void limparClientes() { clientes.clear(); }

    std::vector<Funcionario>& obterFuncionarios() { return funcionarios; }
    void limparFuncionarios() { funcionarios.clear(); }
};

#endif