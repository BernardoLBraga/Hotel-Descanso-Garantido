#include <iostream>
#include <limits>
#include "../include/SistemaHotel.h"

void exibirMenu() {
    std::cout << "\n--- MENU PRINCIPAL ---" << std::endl;
    std::cout << "1. Cadastrar Quarto" << std::endl;
    std::cout << "0. Sair e Salvar" << std::endl;
    std::cout << "Escolha uma opcao: ";
}

void processarCadastroQuarto(SistemaHotel& sistema) {
    int numero, capacidade;
    float valorDiaria;

    std::cout << "Numero do Quarto: ";
    std::cin >> numero;
    std::cout << "Capacidade de Hospedes: ";
    std::cin >> capacidade;
    std::cout << "Valor da Diaria: ";
    std::cin >> valorDiaria;

    int resultado = sistema.cadastrarQuarto(numero, capacidade, valorDiaria);

    if (resultado == SUCESSO) {
        std::cout << "Quarto cadastrado com sucesso!" << std::endl;
    } else if (resultado == ERRO_DUPLICIDADE) {
        std::cout << "ERRO: Numero de quarto ja cadastrado." << std::endl;
    } else if (resultado == ERRO_CAPACIDADE) {
        std::cout << "ERRO: Capacidade de hospedes deve ser positiva." << std::endl;
    } else if (resultado == ERRO_VALOR) {
        std::cout << "ERRO: Valor da diaria deve ser positivo." << std::endl;
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