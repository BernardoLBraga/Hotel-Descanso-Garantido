#ifndef ESTADIA_H
#define ESTADIA_H

#include "Definicoes.h"

class Estadia {
private:
    int codigoEstadia;
    int codigoCliente;
    int numeroQuarto;
    char dataEntrada[MAX_DATA];
    char dataSaida[MAX_DATA];
    int qtdDiarias;

public:
    Estadia(int codE, int codC, int numQ, const char* dE, const char* dS, int qtdD);
    Estadia() : codigoEstadia(0), codigoCliente(0), numeroQuarto(0), qtdDiarias(0) {}
    
    int obterCodigoEstadia() const { return codigoEstadia; }
    int obterCodigoCliente() const { return codigoCliente; }
    int obterNumeroQuarto() const { return numeroQuarto; }
    int obterQtdDiarias() const { return qtdDiarias; }
    const char* obterDataEntrada() const { return dataEntrada; }
    const char* obterDataSaida() const { return dataSaida; }
};

#endif