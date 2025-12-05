#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>

class Funcionario {
private:
    int codigo;
    std::string nome;
    std::string telefone;
    std::string cargo;
    float salario;

public:
    Funcionario(int cod, std::string nom, std::string tel, std::string car, float sal) : 
        codigo(cod), nome(nom), telefone(tel), cargo(car), salario(sal) {}
    
    Funcionario() : codigo(0), salario(0.0) {}
    
    int obterCodigo() const { return codigo; }
    std::string obterNome() const { return nome; }
    float obterSalario() const { return salario; }
};

#endif