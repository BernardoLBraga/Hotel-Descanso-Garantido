#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Definicoes.h"

class Funcionario {
private:
    int codigo;
    char nome[MAX_NOME];
    char telefone[MAX_TELEFONE];
    char cargo[MAX_CARGO];
    float salario;

public:
    Funcionario(int cod, const char* n, const char* tel, const char* c, float sal);
    Funcionario() : codigo(0), salario(0.0f) {}
    
    int obterCodigo() const { return codigo; }
    const char* obterNome() const { return nome; }
    const char* obterTelefone() const { return telefone; }
    const char* obterCargo() const { return cargo; }
    float obterSalario() const { return salario; }
};

#endif