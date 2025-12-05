# Hotel-Descanso-Garantido

## Desenvolvido por:
- Bernardo Leão Braga   

---

## Descrição
O sistema Hotel Descanso Garantido tem como objetivo automatizar os processos de gestão essenciais de um hotel, incluindo o cadastro e a consulta de clientes, funcionários e quartos, além do registro e controle das estadias.

---

## Especificação das Entidades e Operações

### 1. Cadastro de Clientes
```cpp
class Cliente {
  int codigo;        // Identificador único do cliente
  string nome;       // Nome completo
  string endereco;   // Endereço residencial
  string telefone;   // Contato telefônico
}

// Operações da classe Cliente
int cadastrarCliente(Cliente cliente);                     // Cadastra um novo cliente (retorna SUCESSO/ERRO_CODIGO).
vector<Cliente> listarClientes();                          // Lista todos os clientes cadastrados.
vector<Cliente> pesquisarCliente(int codigo, const string& nome); // Pesquisa por código (exato) ou nome (parcial).

```
### 2. Cadastro de Funcionários
```cpp
class Funcionario {
  int codigo;        // Identificador único do funcionário
  string nome;       // Nome completo
  string telefone;   // Contato telefônico
  string cargo;      // Ex: "Gerente", "Recepcionista"
  float salario;     // Salário base
}

// Operações da classe Funcionario
int cadastrarFuncionario(Funcionario funcionario);                // Cadastra novo funcionário (retorna SUCESSO/ERRO).
vector<Funcionario> listarFuncionarios();                         // Lista todos os funcionários cadastrados.
vector<Funcionario> pesquisarFuncionario(int codigo, const string& nome); // Pesquisa por código (exato) ou nome (parcial).

```
### 3. Cadastro de Quartos
```cpp
class Quarto {
  int numero;          // Identificador único do quarto
  int capacidade;      // Máximo de hóspedes
  float valorDiaria;   // Custo da diária
  string status;       // "DESOCUPADO" ou "OCUPADO"
}

// Operações da classe Quarto
int cadastrarQuarto(Quarto quarto);                // Cadastra um novo quarto (retorna SUCESSO/ERRO).
vector<Quarto> listarQuartos();                    // Lista todos os quartos cadastrados.
void definirStatus(int numero, const string& status); // Altera o status do quarto.

```

### Validações e Regras de Negócio Essenciais
Esta seção detalha as regras de negócio implementadas nas funções de cadastro (SistemaHotel.cpp), que garantem a integridade dos dados.

1. Garantia de Unicidade
Todas as funções de cadastro verificam a duplicidade do identificador único (código ou número):

Cliente: Não permite cadastro com codigo já existente.

Funcionário: Não permite cadastro com codigo já existente.

Quarto: Não permite cadastro com numero já existente.

2. Validações de Valores
As seguintes validações de valores de domínio foram implementadas (retornando códigos de erro específicos):

Quarto: capacidade deve ser positiva (> 0).

Quarto: valorDiaria deve ser positiva (> 0).

Funcionário: salario deve ser positivo (> 0).