#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include "../include/SistemaHotel.h"
#include "../include/Cliente.h"
#include "../include/Funcionario.h"

void processarCadastroQuarto(SistemaHotel& sistema);
void processarCadastroCliente(SistemaHotel& sistema);
void processarCadastroFuncionario(SistemaHotel& sistema); 

void processarPesquisaCliente(SistemaHotel& sistema);
void processarPesquisaFuncionario(SistemaHotel& sistema);

void exibirMenu() {
    std::cout << "\n--- MENU PRINCIPAL ---" << std::endl;
    std::cout << "1. Cadastrar Quarto" << std::endl;
    std::cout << "2. Cadastrar Cliente" << std::endl;
    std::cout << "3. Cadastrar Funcionario" << std::endl;
    std::cout << "4. Pesquisar Cliente" << std::endl;   
    std::cout << "5. Pesquisar Funcionario" << std::endl;
    std::cout << "0. Sair e Salvar" << std::endl;
    std::cout << "Escolha uma opcao: ";
}

void processarCadastroFuncionario(SistemaHotel& sistema) {
    int codigo;
    float salario;
    std::string nome, telefone, cargo;

    std::cout << "Codigo do Funcionario: ";
    std::cin >> codigo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Nome: ";
    std::getline(std::cin, nome);
    std::cout << "Telefone: ";
    std::getline(std::cin, telefone);
    std::cout << "Cargo: ";
    std::getline(std::cin, cargo);
    std::cout << "Salario: ";
    std::cin >> salario;

    int resultado = sistema.cadastrarFuncionario(codigo, nome, telefone, cargo, salario);

    if (resultado == SUCESSO) {
        std::cout << "Funcionario cadastrado com sucesso!" << std::endl;
    } else if (resultado == ERRO_CODIGO) {
        std::cout << "ERRO: Codigo de funcionario invalido ou ja cadastrado." << std::endl;
    } else if (resultado == ERRO_SALARIO) {
        std::cout << "ERRO: Salario deve ser positivo." << std::endl;
    } else if (resultado == ERRO_CARGO) {
        std::cout << "ERRO: Cargo nao pode ser vazio." << std::endl;
    }
}

void processarPesquisaCliente(SistemaHotel& sistema) {
    int codigo;
    std::string nome;

    std::cout << "Pesquisar por (1) Codigo ou (2) Nome? ";
    int tipo_pesquisa;
    std::cin >> tipo_pesquisa;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (tipo_pesquisa == 1) {
        std::cout << "Digite o Codigo: ";
        std::cin >> codigo;
        nome = "";
    } else if (tipo_pesquisa == 2) {
        codigo = 0;
        std::cout << "Digite o Nome: ";
        std::getline(std::cin, nome);
    } else {
        std::cout << "Opcao invalida." << std::endl;
        return;
    }

    std::vector<Cliente> resultados = sistema.pesquisarCliente(codigo, nome);

    if (resultados.empty()) {
        std::cout << "Nenhum cliente encontrado." << std::endl;
    } else {
        std::cout << "--- Resultados da Pesquisa ---" << std::endl;
        for (const auto& c : resultados) {
            std::cout << "Cod: " << c.obterCodigo() << " | Nome: " << c.obterNome() 
                      << " | Tel: " << c.obterTelefone() << " | End: " << c.obterEndereco() << std::endl;
        }
    }
}

void processarPesquisaFuncionario(SistemaHotel& sistema) {
    int codigo;
    std::string nome;

    std::cout << "Pesquisar por (1) Codigo ou (2) Nome? ";
    int tipo_pesquisa;
    std::cin >> tipo_pesquisa;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (tipo_pesquisa == 1) {
        std::cout << "Digite o Codigo: ";
        std::cin >> codigo;
        nome = "";
    } else if (tipo_pesquisa == 2) {
        codigo = 0;
        std::cout << "Digite o Nome: ";
        std::getline(std::cin, nome);
    } else {
        std::cout << "Opcao invalida." << std::endl;
        return;
    }

    std::vector<Funcionario> resultados = sistema.pesquisarFuncionario(codigo, nome);

    if (resultados.empty()) {
        std::cout << "Nenhum funcionario encontrado." << std::endl;
    } else {
        std::cout << "--- Resultados da Pesquisa ---" << std::endl;
        for (const auto& f : resultados) {
            std::cout << "Cod: " << f.obterCodigo() << " | Nome: " << f.obterNome() 
                      << " | Tel: " << f.obterTelefone() << " | Cargo: " << f.obterCargo() 
                      << " | Salario: " << f.obterSalario() << std::endl;
        }
    }
}

int main() {
    SistemaHotel sistema;
    int opcao = 0;
    
    do {
        exibirMenu();
        if (!(std::cin >> opcao)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            opcao = -1; 
            std::cout << "Opcao invalida. Tente novamente." << std::endl;
            continue;
        }

        switch (opcao) {
            case 1:
                processarCadastroQuarto(sistema);
                break;
            case 2:
                processarCadastroCliente(sistema);
                break;
            case 3:
                processarCadastroFuncionario(sistema);
                break;
            case 4:
                processarPesquisaCliente(sistema);  
                break;
            case 5:
                processarPesquisaFuncionario(sistema);
                break;
            case 0:
                std::cout << "Encerrando e salvando..." << std::endl;
                break;
            default:
                std::cout << "Opcao invalida. Tente novamente." << std::endl;
                break;
        }
        
    } while (opcao != 0);

    return 0;
}