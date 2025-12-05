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