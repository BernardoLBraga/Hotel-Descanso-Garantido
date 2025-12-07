#include "../include/SistemaHotel.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<Cliente> SistemaHotel::pesquisarCliente(int codigo, const std::string& nome) {
    std::vector<Cliente> resultados;
    
    if (codigo > 0) {
        auto it = std::find_if(clientes.begin(), clientes.end(), 
            [codigo](const Cliente& c){
                return c.obterCodigo() == codigo;
            });
        
        if (it != clientes.end()) {
            resultados.push_back(*it);
            return resultados;
        }
    }
    
    if (!nome.empty()) {
        for (const auto& cliente : clientes) {
            if (cliente.obterNome().find(nome) != std::string::npos) {
                resultados.push_back(cliente);
            }
        }
    }

    return resultados;
}

std::vector<Funcionario> SistemaHotel::pesquisarFuncionario(int codigo, const std::string& nome) {
    std::vector<Funcionario> resultados;
    
    if (codigo > 0) {
        auto it = std::find_if(funcionarios.begin(), funcionarios.end(), 
            [codigo](const Funcionario& f){
                return f.obterCodigo() == codigo;
            });
        
        if (it != funcionarios.end()) {
            resultados.push_back(*it);
            return resultados;
        }
    }
    
    if (!nome.empty()) {
        for (const auto& funcionario : funcionarios) {
            if (funcionario.obterNome().find(nome) != std::string::npos) {
                resultados.push_back(funcionario);
            }
        }
    }

    return resultados;
}

Cliente* SistemaHotel::buscarClientePorCodigo(int codigo) {
    auto it = std::find_if(clientes.begin(), clientes.end(), 
        [codigo](const Cliente& c){
            return c.obterCodigo() == codigo;
        });
    return (it != clientes.end()) ? &(*it) : nullptr;
}

Quarto* SistemaHotel::buscarQuartoPorNumero(int numero) {
    auto it = std::find_if(quartos.begin(), quartos.end(), 
        [numero](const Quarto& q){
            return q.obterNumero() == numero;
        });
    return (it != quartos.end()) ? &(*it) : nullptr;
}

int SistemaHotel::calcularDiarias(const std::string& dataEntrada, const std::string& dataSaida) {
    if (dataEntrada.empty() || dataSaida.empty()) {
        return 0;
    }
    return 5;
}

int SistemaHotel::cadastrarEstadia(int codigoCliente, int numeroQuarto, const std::string& dataEntrada, const std::string& dataSaida) {
    Cliente* cliente = buscarClientePorCodigo(codigoCliente);
    if (cliente == nullptr) {
        return ERRO_CLIENTE_NAO_ENCONTRADO;
    }

    Quarto* quarto = buscarQuartoPorNumero(numeroQuarto);
    if (quarto == nullptr) {
        return ERRO_QUARTO_NAO_ENCONTRADO;
    }
    
    if (quarto->obterStatus() == "OCUPADO") {
        return ERRO_QUARTO_OCUPADO;
    }
    
    int qtdDiarias = calcularDiarias(dataEntrada, dataSaida);
    if (qtdDiarias <= 0) {
        return ERRO_DATA_INVALIDA;
    }

    Estadia novaEstadia(proximoCodigoEstadia++, codigoCliente, numeroQuarto, dataEntrada, dataSaida, qtdDiarias);
    estadias.push_back(novaEstadia);
    
    quarto->definirStatus("OCUPADO");
    
    return SUCESSO;
}