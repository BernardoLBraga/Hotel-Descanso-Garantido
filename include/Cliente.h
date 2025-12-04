#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente {
private:
    int codigo;
    std::string nome;
    std::string endereco;
    std::string telefone;

public:
    Cliente(int cod, std::string nom, std::string end, std::string tel) : 
        codigo(cod), nome(nom), endereco(end), telefone(tel) {}
    
    Cliente() : codigo(0) {}
    
    int obterCodigo() const { return codigo; }
    std::string obterNome() const { return nome; }
    std::string obterTelefone() const { return telefone; }
};

#endif