#ifndef SISTEMAHOTEL_H
#define SISTEMAHOTEL_H

#include <vector>
#include <string>
#include "Quarto.h"
#include "Cliente.h"
#include "Funcionario.h"
#include "Estadia.h"

#define SUCESSO 0
#define ERRO_DUPLICIDADE 1
#define ERRO_CAPACIDADE 2
#define ERRO_VALOR 3
#define ERRO_CODIGO 4
#define ERRO_SALARIO 5 
#define ERRO_CARGO 6
#define ERRO_CLIENTE_NAO_ENCONTRADO 7
#define ERRO_QUARTO_NAO_ENCONTRADO 8
#define ERRO_QUARTO_OCUPADO 9
#define ERRO_DATA_INVALIDA 10

class SistemaHotel {
private:
    std::vector<Quarto> quartos;
    std::vector<Cliente> clientes;
    std::vector<Funcionario> funcionarios;
    std::vector<Estadia> estadias;
    int proximoCodigoEstadia = 1;

public:
    int cadastrarQuarto(int numero, int capacidade, float valorDiaria);
    int cadastrarCliente(int codigo, std::string nome, std::string endereco, std::string telefone);
    int cadastrarFuncionario(int codigo, std::string nome, std::string telefone, std::string cargo, float salario);
    
    std::vector<Cliente> pesquisarCliente(int codigo, const std::string& nome);
    std::vector<Funcionario> pesquisarFuncionario(int codigo, const std::string& nome);
    
    int cadastrarEstadia(int codigoCliente, int numeroQuarto, const std::string& dataEntrada, const std::string& dataSaida);
    
    int calcularDiarias(const std::string& dataEntrada, const std::string& dataSaida); 
    
    Cliente* buscarClientePorCodigo(int codigo);
    Quarto* buscarQuartoPorNumero(int numero);
    
    std::vector<Quarto>& obterQuartos() { return quartos; }
    void limparQuartos() { quartos.clear(); }
    
    std::vector<Cliente>& obterClientes() { return clientes; }
    void limparClientes() { clientes.clear(); }

    std::vector<Funcionario>& obterFuncionarios() { return funcionarios; }
    void limparFuncionarios() { funcionarios.clear(); }

    std::vector<Estadia>& obterEstadias() { return estadias; }
    void limparEstadias() { estadias.clear(); }
};

#endif