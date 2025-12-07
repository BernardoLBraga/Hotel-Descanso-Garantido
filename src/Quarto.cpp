#include "../include/Quarto.h"
#include <cstring>
#include <cstdio>

Quarto::Quarto(int num, int cap, float val, const char* stat) 
    : numero(num), capacidade(cap), valorDiaria(val) {
    
    strncpy(status, stat, MAX_TELEFONE - 1);
    status[MAX_TELEFONE - 1] = '\0';
}

void Quarto::definirStatus(const char* novoStatus) {
    strncpy(status, novoStatus, MAX_TELEFONE - 1);
    status[MAX_TELEFONE - 1] = '\0';
}