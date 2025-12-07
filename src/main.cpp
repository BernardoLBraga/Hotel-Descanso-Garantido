#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include "../include/SistemaHotel.h"
#include "../include/Cliente.h"
#include "../include/Funcionario.h"
#include "../include/Quarto.h"
#include "../include/Estadia.h"

void processarCadastroQuarto(SistemaHotel& sistema);
void processarCadastroCliente(SistemaHotel& sistema);
void processarCadastroFuncionario(SistemaHotel& sistema); 
void processarPesquisaCliente(SistemaHotel& sistema);
void processarPesquisaFuncionario(SistemaHotel& sistema);
void processarCadastroEstadia(SistemaHotel& sistema);
void processarBaixaEstadia(SistemaHotel& sistema);
void processarEstadiasCliente(SistemaHotel& sistema);
void processarPontosFidelidade(SistemaHotel& sistema);


void exibirMenu() {
    std::cout << "\n--- MENU PRINCIPAL ---" << std::endl;
    std::cout << "1. Cadastrar Quarto" << std::endl;
    std::cout << "2. Cadastrar Cliente" << std::endl;
    std::cout << "3. Cadastrar Funcionario" << std::endl;
    std::cout << "4. Pesquisar Cliente" << std::endl;
    std::cout << "5. Pesquisar Funcionario" << std::endl;
    std::cout << "6. Cadastrar Estadia" << std::endl;
    std::cout << "7. Dar Baixa em Estadia" << std::endl;
    std::cout << "8. Estadias do Cliente" << std::endl;
    std::cout << "9. Pontos de Fidelidade" << std::endl;
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
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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

void processarCadastroCliente(SistemaHotel& sistema) {
    int codigo;
    std::string nome, endereco, telefone;

    std::cout << "Codigo do Cliente: ";
    std::cin >> codigo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Nome: ";
    std::getline(std::cin, nome);
    std::cout << "Endereco: ";
    std::getline(std::cin, endereco);
    std::cout << "Telefone: ";
    std::getline(std::cin, telefone);

    int resultado = sistema.cadastrarCliente(codigo, nome, endereco, telefone);

    if (resultado == SUCESSO) {
        std::cout << "Cliente cadastrado com sucesso!" << std::endl;
    } else if (resultado == ERRO_CODIGO) {
        std::cout << "ERRO: Codigo de cliente invalido ou ja cadastrado." << std::endl;
    }
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
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                      << " | Tel: " << c.obterTelefone() << " | End: " << c.obterEndereco() 
                      << " | Pontos: " << c.obterPontosFidelidade() << std::endl;
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
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

void processarCadastroEstadia(SistemaHotel& sistema) {
    int codCliente, numQuarto;
    std::string dataEntrada, dataSaida;

    std::cout << "Codigo do Cliente: ";
    std::cin >> codCliente;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Numero do Quarto: ";
    std::cin >> numQuarto;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Data de Entrada (DD/MM/AAAA): ";
    std::getline(std::cin, dataEntrada);
    std::cout << "Data de Saida (DD/MM/AAAA): ";
    std::getline(std::cin, dataSaida);

    int resultado = sistema.cadastrarEstadia(codCliente, numQuarto, dataEntrada, dataSaida);

    if (resultado == SUCESSO) {
        std::cout << "Estadia cadastrada com sucesso! Quarto agora ocupado." << std::endl;
    } else if (resultado == ERRO_CLIENTE_NAO_ENCONTRADO) {
        std::cout << "ERRO: Cliente nao encontrado. Cadastre o cliente primeiro." << std::endl;
    } else if (resultado == ERRO_QUARTO_NAO_ENCONTRADO) {
        std::cout << "ERRO: Quarto nao encontrado." << std::endl;
    } else if (resultado == ERRO_QUARTO_OCUPADO) {
        std::cout << "ERRO: O quarto ja esta ocupado." << std::endl;
    } else if (resultado == ERRO_DATA_INVALIDA) {
        std::cout << "ERRO: As datas de entrada/saida sao invalidas." << std::endl;
    }
}

void processarBaixaEstadia(SistemaHotel& sistema) {
    int codEstadia;
    float valorTotal = 0.0f;

    std::cout << "Codigo da Estadia para dar baixa: ";
    std::cin >> codEstadia;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int resultado = sistema.darBaixaEstadia(codEstadia, valorTotal);

    if (resultado == SUCESSO) {
        std::cout << "Baixa realizada com sucesso!" << std::endl;
        std::cout << "Valor total a ser pago: R$ " << valorTotal << std::endl;
        std::cout << "Quarto liberado." << std::endl;
    } else if (resultado == ERRO_ESTADIA_NAO_ENCONTRADA) {
        std::cout << "ERRO: Estadia com codigo " << codEstadia << " nao encontrada." << std::endl;
    } else if (resultado == ERRO_ESTADIA_JA_FINALIZADA) {
        std::cout << "ERRO: O quarto desta estadia ja esta desocupado (baixa ja realizada)." << std::endl;
    } else {
        std::cout << "ERRO desconhecido ao tentar dar baixa." << std::endl;
    }
}

void processarEstadiasCliente(SistemaHotel& sistema) {
    int codigo;
    std::string nome;

    std::cout << "Pesquisar estadias por (1) Codigo do Cliente ou (2) Nome do Cliente? ";
    int tipo_pesquisa;
    std::cin >> tipo_pesquisa;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (tipo_pesquisa == 1) {
        std::cout << "Digite o Codigo do Cliente: ";
        std::cin >> codigo;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        nome = "";
    } else if (tipo_pesquisa == 2) {
        codigo = 0;
        std::cout << "Digite o Nome do Cliente: ";
        std::getline(std::cin, nome);
    } else {
        std::cout << "Opcao invalida." << std::endl;
        return;
    }

    std::vector<Estadia> resultados = sistema.buscarEstadiasCliente(codigo, nome);
    
    if (resultados.empty()) {
        std::cout << "Nenhuma estadia encontrada para o cliente." << std::endl;
    } else {
        std::cout << "--- Estadias do Cliente ---" << std::endl;
        for (const auto& e : resultados) {
            std::cout << "Estadia #"<< e.obterCodigoEstadia() 
                      << " | Quarto: " << e.obterNumeroQuarto() 
                      << " | Entrada: " << e.obterDataEntrada() 
                      << " | Saida: " << e.obterDataSaida() 
                      << " | Diarias: " << e.obterQtdDiarias() << std::endl;
        }
    }
}

void processarPontosFidelidade(SistemaHotel& sistema) {
    int codigo;
    
    std::cout << "Digite o Codigo do Cliente para ver os Pontos de Fidelidade: ";
    std::cin >> codigo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Cliente* cliente = sistema.buscarClientePorCodigo(codigo);

    if (cliente == nullptr) {
        std::cout << "ERRO: Cliente com codigo " << codigo << " nao encontrado." << std::endl;
    } else {
        std::cout << "--- Pontos de Fidelidade ---" << std::endl;
        std::cout << "Cliente: " << cliente->obterNome() << std::endl;
        std::cout << "Total de Pontos: " << cliente->obterPontosFidelidade() << std::endl;
    }
}

int main() {
    SistemaHotel sistema;
    int opcao = 0;
    
    sistema.lerDados(); 
    
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
            case 6:
                processarCadastroEstadia(sistema);
                break;
            case 7:
                processarBaixaEstadia(sistema);
                break;
            case 8:
                processarEstadiasCliente(sistema);
                break;
            case 9:
                processarPontosFidelidade(sistema);
                break;
            case 0:
                std::cout << "Encerrando e salvando..." << std::endl;
                sistema.gravarDados();
                break;
            default:
                std::cout << "Opcao invalida. Tente novamente." << std::endl;
                break;
        }
        
    } while (opcao != 0);

    return 0;
}