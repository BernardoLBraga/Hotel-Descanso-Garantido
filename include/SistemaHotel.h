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
#define ERRO_ESTADIA_NAO_ENCONTRADA 11
#define ERRO_ESTADIA_JA_FINALIZADA 12
#define ERRO_LEITURA_ARQUIVO 13
#define ERRO_ESCRITA_ARQUIVO 14

class SistemaHotel {
private:
    std::vector<Quarto> quartos;
    std::vector<Cliente> clientes;
    std::vector<Funcionario> funcionarios;
    std::vector<Estadia> estadias;
    int proximoCodigoEstadia = 1;

public:
    int cadastrarQuarto(int numero, int capacidade, float valorDiaria);
    int cadastrarCliente(int codigo, const char* nome, const char* endereco, const char* telefone);
    int cadastrarFuncionario(int codigo, const char* nome, const char* telefone, const char* cargo, float salario);
    
    std::vector<Cliente> pesquisarCliente(int codigo, const char* nome);
    std::vector<Funcionario> pesquisarFuncionario(int codigo, const char* nome);
    
    int cadastrarEstadia(int codigoCliente, int numeroQuarto, const char* dataEntrada, const char* dataSaida);
    int darBaixaEstadia(int codigoEstadia, float& valorTotalPago);
    
    std::vector<Estadia> buscarEstadiasCliente(int codigo, const char* nome);

    int gravarDados();
    int lerDados();

    int calcularDiarias(const char* dataEntrada, const char* dataSaida); 
    
    Cliente* buscarClientePorCodigo(int codigo);
    Quarto* buscarQuartoPorNumero(int numero);
    Estadia* buscarEstadiaPorCodigo(int codigo);

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