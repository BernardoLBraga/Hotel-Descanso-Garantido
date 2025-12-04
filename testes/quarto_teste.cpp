#include <stdio.h>
#include "../include/munit.h"
#include "../include/SistemaHotel.h" 

SistemaHotel sistemaTeste;

static void* configurar_teste_quarto(const MunitParameter params[], void* user_data) {
    sistemaTeste.limparQuartos();
    return (void*)0; 
}

static MunitResult testar_cadastro_sucesso(const MunitParameter params[], void* fixture) {
    int resultado = sistemaTeste.cadastrarQuarto(101, 2, 150.00f);
    munit_assert_int(resultado, == , SUCESSO);
    munit_assert_size(sistemaTeste.obterQuartos().size(), == , 1);
    return MUNIT_OK;
}

static MunitResult testar_cadastro_duplicado(const MunitParameter params[], void* fixture) {
    sistemaTeste.cadastrarQuarto(202, 3, 200.00f);
    int resultado = sistemaTeste.cadastrarQuarto(202, 3, 200.00f);
    munit_assert_int(resultado, == , ERRO_DUPLICIDADE);
    munit_assert_size(sistemaTeste.obterQuartos().size(), == , 1);
    return MUNIT_OK;
}

static MunitResult testar_capacidade_invalida(const MunitParameter params[], void* fixture) {
    int resultado_zero = sistemaTeste.cadastrarQuarto(301, 0, 150.00f);
    munit_assert_int(resultado_zero, == , ERRO_CAPACIDADE);
    int resultado_negativo = sistemaTeste.cadastrarQuarto(302, -1, 150.00f);
    munit_assert_int(resultado_negativo, == , ERRO_CAPACIDADE);
    munit_assert_size(sistemaTeste.obterQuartos().size(), == , 0);
    return MUNIT_OK;
}

static MunitResult testar_valor_diaria_invalido(const MunitParameter params[], void* fixture) {
    int resultado_zero = sistemaTeste.cadastrarQuarto(401, 2, 0.0f);
    munit_assert_int(resultado_zero, == , ERRO_VALOR);
    int resultado_negativo = sistemaTeste.cadastrarQuarto(402, 2, -10.0f);
    munit_assert_int(resultado_negativo, == , ERRO_VALOR);
    munit_assert_size(sistemaTeste.obterQuartos().size(), == , 0);
    return MUNIT_OK;
}

static MunitTest testes_quarto[] = {
    { "/sucesso", testar_cadastro_sucesso, configurar_teste_quarto, MUNIT_TEST_OPTION_NONE, NULL },
    { "/duplicado", testar_cadastro_duplicado, configurar_teste_quarto, MUNIT_TEST_OPTION_NONE, NULL },
    { "/capacidade-invalida", testar_capacidade_invalida, configurar_teste_quarto, MUNIT_TEST_OPTION_NONE, NULL },
    { "/valor-invalido", testar_valor_diaria_invalido, configurar_teste_quarto, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite suite_quarto = {
    "/quarto", 
    testes_quarto, 
    NULL, 
    1, 
    MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
    return munit_suite_main(&suite_quarto, NULL, argc, argv);
}