#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente {
private:
    int codigo;
    std::string nome;
    std::string endereco;
    std::string telefone;
    int pontosFidelidade;

public:
    Cliente(int cod, std::string n, std::string end, std::string tel) : 
        codigo(cod), nome(n), endereco(end), telefone(tel), pontosFidelidade(0) {}
    
    Cliente() : codigo(0), pontosFidelidade(0) {}
    
    int obterCodigo() const { return codigo; }
    std::string obterNome() const { return nome; }
    std::string obterEndereco() const { return endereco; }
    std::string obterTelefone() const { return telefone; }
    
    int obterPontosFidelidade() const { return pontosFidelidade; }
    void adicionarPontos(int pontos) { pontosFidelidade += pontos; } // NOVO MÉTODO
};

#endif