#ifndef ESTADIA_H
#define ESTADIA_H

#include <string>

class Estadia {
private:
    int codigoEstadia;
    int codigoCliente;
    int numeroQuarto;
    std::string dataEntrada;
    std::string dataSaida;
    int qtdDiarias;

public:
    Estadia(int codE, int codC, int numQ, std::string dE, std::string dS, int qtdD) : 
        codigoEstadia(codE), codigoCliente(codC), numeroQuarto(numQ), 
        dataEntrada(dE), dataSaida(dS), qtdDiarias(qtdD) {}
    
    Estadia() : codigoEstadia(0), codigoCliente(0), numeroQuarto(0), qtdDiarias(0) {}
    
    int obterCodigoEstadia() const { return codigoEstadia; }
    int obterCodigoCliente() const { return codigoCliente; }
    int obterNumeroQuarto() const { return numeroQuarto; }
    int obterQtdDiarias() const { return qtdDiarias; }
    std::string obterDataEntrada() const { return dataEntrada; }
    std::string obterDataSaida() const { return dataSaida; }
};

#endif