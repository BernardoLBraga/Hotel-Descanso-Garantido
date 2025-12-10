#include "../include/SistemaHotel.h"
#include <ctime>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <cstdio> 
#include <cmath> 

#define ARQUIVO_CLIENTES "clientes.bin"
#define ARQUIVO_QUARTOS "quartos.bin"
#define ARQUIVO_FUNCIONARIOS "funcionarios.bin"
#define ARQUIVO_ESTADIAS "estadias.bin"

template <typename T>
int gravarColecao(const std::vector<T>& colecao, const std::string& nomeArquivo) {
    std::ofstream arquivo(nomeArquivo, std::ios::binary | std::ios::out);
    if (!arquivo.is_open()) {
        return ERRO_ESCRITA_ARQUIVO;
    }

    size_t tamanho = colecao.size();
    arquivo.write(reinterpret_cast<const char*>(&tamanho), sizeof(size_t));

    if (tamanho > 0) {
        arquivo.write(reinterpret_cast<const char*>(colecao.data()), tamanho * sizeof(T));
    }

    arquivo.close();
    return SUCESSO;
}

template <typename T>
int lerColecao(std::vector<T>& colecao, const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo, std::ios::binary | std::ios::in);
    if (!arquivo.is_open()) {
        colecao.clear();
        return ERRO_LEITURA_ARQUIVO;
    }

    size_t tamanho = 0;
    if (!arquivo.read(reinterpret_cast<char*>(&tamanho), sizeof(size_t))) {
        arquivo.close();
        colecao.clear();
        return SUCESSO;
    }

    if (tamanho > 0) {
        colecao.resize(tamanho);
        arquivo.read(reinterpret_cast<char*>(colecao.data()), tamanho * sizeof(T));
    } else {
        colecao.clear();
    }

    arquivo.close();
    return SUCESSO;
}

int calcularDiarias(const char* dataEntrada, const char* dataSaida) {
    int diaE, mesE, anoE;
    int diaS, mesS, anoS;

    if (std::sscanf(dataEntrada, "%d/%d/%d", &diaE, &mesE, &anoE) != 3) {
        return -1;
    }
    if (std::sscanf(dataSaida, "%d/%d/%d", &diaS, &mesS, &anoS) != 3) {
        return -1;
    }

    std::tm tEntrada = {};
    tEntrada.tm_mday = diaE;
    tEntrada.tm_mon = mesE - 1;
    tEntrada.tm_year = anoE - 1900;
    tEntrada.tm_hour = 12;

    std::tm tSaida = {};
    tSaida.tm_mday = diaS;
    tSaida.tm_mon = mesS - 1;
    tSaida.tm_year = anoS - 1900;
    tSaida.tm_hour = 12;

    std::time_t timeEntrada = std::mktime(&tEntrada);
    std::time_t timeSaida = std::mktime(&tSaida);

    if (timeSaida <= timeEntrada) {
        return 0;
    }

    double diferencaSegundos = std::difftime(timeSaida, timeEntrada);
    int numDiarias = static_cast<int>(std::round(diferencaSegundos / 86400.0));

    return numDiarias;
}

int SistemaHotel::cadastrarQuarto(int numero, int capacidade, float valorDiaria) {
    if (buscarQuartoPorNumero(numero) != nullptr) {
        return ERRO_DUPLICIDADE;
    }
    if (capacidade <= 0) {
        return ERRO_CAPACIDADE;
    }
    if (valorDiaria <= 0) {
        return ERRO_VALOR;
    }
    quartos.emplace_back(numero, capacidade, valorDiaria, "DESOCUPADO");
    return SUCESSO;
}

int SistemaHotel::cadastrarCliente(int codigo, const char* nome, const char* endereco, const char* telefone) {
    if (codigo <= 0 || buscarClientePorCodigo(codigo) != nullptr) {
        return ERRO_CODIGO;
    }
    if (std::strlen(nome) == 0 || std::strlen(endereco) == 0 || std::strlen(telefone) == 0) {
        return ERRO_CODIGO;
    }
    clientes.emplace_back(codigo, nome, endereco, telefone);
    return SUCESSO;
}

int SistemaHotel::cadastrarFuncionario(int codigo, const char* nome, const char* telefone, const char* cargo, float salario) {
    if (codigo <= 0) {
        return ERRO_CODIGO;
    }
    if (std::any_of(funcionarios.begin(), funcionarios.end(), [codigo](const Funcionario& f){ return f.obterCodigo() == codigo; })) {
        return ERRO_CODIGO; 
    }
    if (salario <= 0.0f) {
        return ERRO_SALARIO;
    }
    if (std::strlen(cargo) == 0) {
        return ERRO_CARGO;
    }
    if (std::strlen(nome) == 0 || std::strlen(telefone) == 0) {
        return ERRO_CODIGO;
    }
    funcionarios.emplace_back(codigo, nome, telefone, cargo, salario);
    return SUCESSO;
}

std::vector<Cliente> SistemaHotel::pesquisarCliente(int codigo, const char* nome) {
    std::vector<Cliente> resultados;
    if (codigo > 0) {
        Cliente* c = buscarClientePorCodigo(codigo);
        if (c != nullptr) {
            resultados.push_back(*c);
        }
    } else if (nome != nullptr && std::strlen(nome) > 0) {
        for (const auto& c : clientes) {
            if (c.obterNome() != nullptr && std::strstr(c.obterNome(), nome) != nullptr) {
                resultados.push_back(c);
            }
        }
    }
    return resultados;
}

std::vector<Funcionario> SistemaHotel::pesquisarFuncionario(int codigo, const char* nome) {
    std::vector<Funcionario> resultados;
    if (codigo > 0) {
        auto it = std::find_if(funcionarios.begin(), funcionarios.end(), [codigo](const Funcionario& f){ return f.obterCodigo() == codigo; });
        if (it != funcionarios.end()) {
            resultados.push_back(*it);
        }
    } else if (nome != nullptr && std::strlen(nome) > 0) {
        for (const auto& f : funcionarios) {
            if (f.obterNome() != nullptr && std::strstr(f.obterNome(), nome) != nullptr) {
                resultados.push_back(f);
            }
        }
    }
    return resultados;
}

Cliente* SistemaHotel::buscarClientePorCodigo(int codigo) {
    auto it = std::find_if(clientes.begin(), clientes.end(),
        [codigo](const Cliente& c){
            return c.obterCodigo() == codigo;
        });
    return (it != clientes.end()) ? &(*it) : nullptr;
}

Quarto* SistemaHotel::buscarQuartoPorNumero(int numero) {
    auto it = std::find_if(quartos.begin(), quartos.end(),
        [numero](const Quarto& q){
            return q.obterNumero() == numero;
        });
    return (it != quartos.end()) ? &(*it) : nullptr;
}

Estadia* SistemaHotel::buscarEstadiaPorCodigo(int codigo) {
    auto it = std::find_if(estadias.begin(), estadias.end(),
        [codigo](const Estadia& e){
            return e.obterCodigoEstadia() == codigo;
        });
    return (it != estadias.end()) ? &(*it) : nullptr;
}

int SistemaHotel::cadastrarEstadia(int codigoCliente, int numeroQuarto, const char* dataEntrada, const char* dataSaida) {
    Cliente* cliente = buscarClientePorCodigo(codigoCliente);
    if (cliente == nullptr) {
        return ERRO_CLIENTE_NAO_ENCONTRADO;
    }

    Quarto* quarto = buscarQuartoPorNumero(numeroQuarto);
    if (quarto == nullptr) {
        return ERRO_QUARTO_NAO_ENCONTRADO;
    }

    if (quarto->obterStatus() != nullptr && std::strcmp(quarto->obterStatus(), "OCUPADO") == 0) {
        return ERRO_QUARTO_OCUPADO;
    }

    int qtdDiarias = calcularDiarias(dataEntrada, dataSaida);

    if (qtdDiarias <= 0) {
        return ERRO_DATA_INVALIDA;
    }

    Estadia novaEstadia(proximoCodigoEstadia++, codigoCliente, numeroQuarto, dataEntrada, dataSaida, qtdDiarias);
    estadias.push_back(novaEstadia);

    quarto->definirStatus("OCUPADO");

    return SUCESSO;
}

int SistemaHotel::darBaixaEstadia(int codigoEstadia, float& valorTotalPago) {
    Estadia* estadia = buscarEstadiaPorCodigo(codigoEstadia);
    if (estadia == nullptr) {
        return ERRO_ESTADIA_NAO_ENCONTRADA;
    }

    Cliente* cliente = buscarClientePorCodigo(estadia->obterCodigoCliente());
    Quarto* quarto = buscarQuartoPorNumero(estadia->obterNumeroQuarto());

    if (quarto == nullptr) {
        return ERRO_QUARTO_NAO_ENCONTRADO;
    }

    if (quarto->obterStatus() == nullptr || std::strcmp(quarto->obterStatus(), "DESOCUPADO") == 0) {
        return ERRO_ESTADIA_JA_FINALIZADA;
    }

    int qtdDiarias = estadia->obterQtdDiarias();
    valorTotalPago = qtdDiarias * quarto->obterValorDiaria();

    if (cliente != nullptr) {
        int pontosGanhos = qtdDiarias * 10;
        cliente->adicionarPontos(pontosGanhos);
    }

    quarto->definirStatus("DESOCUPADO");

    return SUCESSO;
}

std::vector<Estadia> SistemaHotel::buscarEstadiasCliente(int codigo, const char* nome) {
    std::vector<Estadia> resultados;

    if (codigo > 0) {
        for (const auto& estadia : estadias) {
            if (estadia.obterCodigoCliente() == codigo) {
                resultados.push_back(estadia);
            }
        }
    } else if (nome != nullptr && std::strlen(nome) > 0) {
        for (const auto& cliente : clientes) {
            if (cliente.obterNome() != nullptr && std::strstr(cliente.obterNome(), nome) != nullptr) {
                for (const auto& estadia : estadias) {
                    if (estadia.obterCodigoCliente() == cliente.obterCodigo()) {
                        resultados.push_back(estadia);
                    }
                }
            }
        }
        std::sort(resultados.begin(), resultados.end(),
                      [](const Estadia& a, const Estadia& b) {
                          return a.obterCodigoEstadia() < b.obterCodigoEstadia();
                      });
    }

    return resultados;
}

int SistemaHotel::gravarDados() {
    int resultado;

    resultado = gravarColecao(clientes, ARQUIVO_CLIENTES);
    if (resultado != SUCESSO) return resultado;

    resultado = gravarColecao(quartos, ARQUIVO_QUARTOS);
    if (resultado != SUCESSO) return resultado;

    resultado = gravarColecao(funcionarios, ARQUIVO_FUNCIONARIOS);
    if (resultado != SUCESSO) return resultado;

    resultado = gravarColecao(estadias, ARQUIVO_ESTADIAS);
    if (resultado != SUCESSO) return resultado;

    return SUCESSO;
}

int SistemaHotel::lerDados() {
    lerColecao(clientes, ARQUIVO_CLIENTES);
    lerColecao(quartos, ARQUIVO_QUARTOS);
    lerColecao(funcionarios, ARQUIVO_FUNCIONARIOS);
    lerColecao(estadias, ARQUIVO_ESTADIAS);

    if (!estadias.empty()) {
        proximoCodigoEstadia = estadias.back().obterCodigoEstadia() + 1;
    } else {
        proximoCodigoEstadia = 1;
    }

    return SUCESSO;
}

int SistemaHotel::calcularDiarias(const char* dataEntrada, const char* dataSaida) {
    if (dataEntrada == nullptr || dataSaida == nullptr) {
        return -1;
    }
    return ::calcularDiarias(dataEntrada, dataSaida);
}