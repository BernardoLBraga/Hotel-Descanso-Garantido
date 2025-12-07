#include "../include/Estadia.h"
#include <cstring>
#include <cstdio>

Estadia::Estadia(int codE, int codC, int numQ, const char* dE, const char* dS, int qtdD) 
    : codigoEstadia(codE), codigoCliente(codC), numeroQuarto(numQ), qtdDiarias(qtdD) {
    
    strncpy(dataEntrada, dE, MAX_DATA - 1);
    dataEntrada[MAX_DATA - 1] = '\0';
    strncpy(dataSaida, dS, MAX_DATA - 1);
    dataSaida[MAX_DATA - 1] = '\0';
}