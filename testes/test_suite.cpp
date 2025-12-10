#include <iostream>
#include <cstring>
#include "../include/SistemaHotel.h" 
#include "../include/Cliente.h"
#include "../include/Quarto.h"
#include "munit.h" 

#define SUCESSO 0
#define ERRO_DUPLICIDADE 1
#define ERRO_CODIGO 4

MunitResult test_cliente_cadastrar_sucesso(const MunitParameter params[], void* data) {
    SistemaHotel sistema;
    int resultado = sistema.cadastrarCliente(10, "Novo Cliente", "Rua A", "999999999");
    munit_assert_int(resultado, == , SUCESSO);
    return MUNIT_OK;
}

MunitResult test_cliente_cadastrar_duplicidade(const MunitParameter params[], void* data) {
    SistemaHotel sistema;
    sistema.cadastrarCliente(11, "Cliente Base", "Rua B", "888888888");
    int resultado = sistema.cadastrarCliente(11, "Cliente Duplicado", "Rua C", "777777777");
    munit_assert_int(resultado, == , ERRO_CODIGO);
    return MUNIT_OK;
}

MunitResult test_quarto_cadastrar_sucesso(const MunitParameter params[], void* data) {
    SistemaHotel sistema;
    int resultado = sistema.cadastrarQuarto(101, 2, 100.0f);
    munit_assert_int(resultado, == , SUCESSO);
    return MUNIT_OK;
}

MunitResult test_quarto_cadastrar_duplicidade(const MunitParameter params[], void* data) {
    SistemaHotel sistema;
    sistema.cadastrarQuarto(102, 2, 150.0f);
    int resultado = sistema.cadastrarQuarto(102, 4, 250.0f); 
    munit_assert_int(resultado, == , ERRO_DUPLICIDADE); 
    return MUNIT_OK;
}

MunitResult test_estadia_cadastrar_sucesso(const MunitParameter params[], void* data) {
    SistemaHotel sistema;
    sistema.cadastrarQuarto(201, 2, 100.0f);
    sistema.cadastrarCliente(200, "Cliente Estadia", "Rua Z", "9999-0000"); 
    int resultado = sistema.cadastrarEstadia(200, 201, "01/12/2025", "03/12/2025");
    munit_assert_int(resultado, == , SUCESSO);
    return MUNIT_OK;
}

MunitResult test_baixa_estadia_com_fidelidade(const MunitParameter params[], void* data) {
    SistemaHotel sistema;
    float valorTotal = 0.0f;
    const float DIARIA = 100.0f;
    const int DIAS = 5;
    const int PONTOS_ESPERADOS = DIAS * 10;
    
    sistema.cadastrarQuarto(301, 2, DIARIA); 
    sistema.cadastrarCliente(300, "Cliente Fidelidade", "Rua F", "9999-8888"); 
    sistema.cadastrarEstadia(300, 301, "01/12/2025", "06/12/2025");
    
    int resultado = sistema.darBaixaEstadia(1, valorTotal);

    munit_assert_int(resultado, == , SUCESSO);
    munit_assert_float(valorTotal, == , DIARIA * DIAS);

    Cliente* cliente = sistema.buscarClientePorCodigo(300);
    munit_assert_ptr(cliente, != , NULL); 
    munit_assert_int(cliente->obterPontosFidelidade(), == , PONTOS_ESPERADOS);
    
    Quarto* quarto = sistema.buscarQuartoPorNumero(301); 
    munit_assert_string_equal(quarto->obterStatus(), "DESOCUPADO");
    
    return MUNIT_OK;
}

MunitTest hotel_tests[] = {
    {(char*) "cliente/cadastrar/sucesso", test_cliente_cadastrar_sucesso, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*) "cliente/cadastrar/duplicidade", test_cliente_cadastrar_duplicidade, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*) "quarto/cadastrar/sucesso", test_quarto_cadastrar_sucesso, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*) "quarto/cadastrar/duplicidade", test_quarto_cadastrar_duplicidade, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*) "estadia/cadastrar/sucesso", test_estadia_cadastrar_sucesso, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*) "estadia/baixa/fidelidade", test_baixa_estadia_com_fidelidade, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL } 
};

MunitSuite hotel_suite = {
    (char*) "HotelDescansoGarantido/", 
    hotel_tests,                      
    NULL,                             
    1,                                
    MUNIT_SUITE_OPTION_NONE           
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc)]) {
    return munit_suite_main(&hotel_suite, (void*) "Suíte Principal de Testes", argc, argv);
}