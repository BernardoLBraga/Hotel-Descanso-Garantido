#include "../include/Cliente.h"
#include <cstring>
#include <cstdio>

Cliente::Cliente(int cod, const char* n, const char* end, const char* tel) : codigo(cod), pontosFidelidade(0) {
    strncpy(nome, n, MAX_NOME - 1);
    nome[MAX_NOME - 1] = '\0';
    strncpy(endereco, end, MAX_ENDERECO - 1);
    endereco[MAX_ENDERECO - 1] = '\0';
    strncpy(telefone, tel, MAX_TELEFONE - 1);
    telefone[MAX_TELEFONE - 1] = '\0';
}