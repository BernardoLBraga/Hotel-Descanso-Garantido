#include "../include/Funcionario.h"
#include <cstring>
#include <cstdio>

Funcionario::Funcionario(int cod, const char* n, const char* tel, const char* c, float sal) 
    : codigo(cod), salario(sal) {
    
    strncpy(nome, n, MAX_NOME - 1);
    nome[MAX_NOME - 1] = '\0';
    strncpy(telefone, tel, MAX_TELEFONE - 1);
    telefone[MAX_TELEFONE - 1] = '\0';
    strncpy(cargo, c, MAX_CARGO - 1);
    cargo[MAX_CARGO - 1] = '\0';
}