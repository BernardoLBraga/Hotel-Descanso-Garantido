#include "../include/SistemaHotel.h"
#include <algorithm>
#include <iostream>
#include <string>

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

int SistemaHotel::cadastrarCliente(int codigo, std::string nome, std::string endereco, std::string telefone) {
    if (codigo <= 0) {
        return ERRO_CODIGO;
    }

    auto it = std::find_if(clientes.begin(), clientes.end(), 
        [codigo](const Cliente& c){
            return c.obterCodigo() == codigo;
        });

    if (it != clientes.end()) {
        return ERRO_CODIGO;
    }

    Cliente novoCliente(codigo, nome, endereco, telefone);
    clientes.push_back(novoCliente);
    
    return SUCESSO;
}

int SistemaHotel::cadastrarFuncionario(int codigo, std::string nome, std::string telefone, std::string cargo, float salario) {
    if (codigo <= 0) {
        return ERRO_CODIGO;
    }
    
    if (salario <= 0.0) {
        return ERRO_SALARIO;
    }
    
    if (cargo.empty()) {
        return ERRO_CARGO;
    }

    auto it = std::find_if(funcionarios.begin(), funcionarios.end(), 
        [codigo](const Funcionario& f){
            return f.obterCodigo() == codigo;
        });

    if (it != funcionarios.end()) {
        return ERRO_CODIGO;
    }

    Funcionario novoFuncionario(codigo, nome, telefone, cargo, salario);
    funcionarios.push_back(novoFuncionario);
    
    return SUCESSO;
}