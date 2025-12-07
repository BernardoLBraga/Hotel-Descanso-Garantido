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
  int codigo;  // Identificador único do cliente
  string nome;  // Nome completo
  string endereco;  // Endereço residencial
  string telefone;  // Contato telefônico
  int pontosFidelidade;  // Pontos acumulados no programa de fidelidade
}

// Operações da classe Cliente
int cadastrarCliente(Cliente cliente);  // Cadastra um novo cliente (retorna SUCESSO/ERRO_CODIGO).
vector<Cliente> pesquisarCliente(int codigo, const string& nome);  // Pesquisa por código (exato) ou nome (parcial).

```
### 2. Cadastro de Funcionários
```cpp
class Funcionario {
  int codigo;  // Identificador único do funcionário
  string nome;  // Nome completo
  string telefone;  // Contato telefônico
  string cargo;  // Ex: "Gerente", "Recepcionista"
  float salario;  // Salário base
}

// Operações da classe Funcionario
int cadastrarFuncionario(Funcionario funcionario);  // Cadastra novo funcionário (retorna SUCESSO/ERRO).
vector<Funcionario> listarFuncionarios();  // Lista todos os funcionários cadastrados.
vector<Funcionario> pesquisarFuncionario(int codigo, const string& nome);  // Pesquisa por código (exato) ou nome (parcial).

```
### 3. Cadastro de Quartos
```cpp
class Quarto {
  int numero;  // Identificador único do quarto
  int capacidade;  // Máximo de hóspedes
  float valorDiaria;  // Custo da diária
  string status;  // "DESOCUPADO" ou "OCUPADO"
}

// Operações da classe Quarto
int cadastrarQuarto(Quarto quarto);  // Cadastra um novo quarto (retorna SUCESSO/ERRO).
vector<Quarto> listarQuartos();  // Lista todos os quartos cadastrados.
void definirStatus(int numero, const string& status);  // Altera o status do quarto.

```
### 4. Cadastro de Estadia
```cpp
class Estadia {
  int codigoEstadia;  // Identificador único da estadia
  int codigoCliente;  // Código do Cliente
  int numeroQuarto;  // Número do Quarto
  string dataEntrada;  // Data de Check-in (DD/MM/AAAA)
  string dataSaida;  // Data de Check-out (DD/MM/AAAA)
  int qtdDiarias;  // Quantidade de diárias calculada
}

// Operações da classe Estadia (Implementadas em SistemaHotel)
int cadastrarEstadia(int codCliente, int numQuarto, const string& dEntrada, const string& dSaida); // Realiza o Check-in e ocupa o quarto.
int darBaixaEstadia(int codigoEstadia, float& valorTotalPago); // Realiza o Check-out, calcula valor, adiciona pontos e desocupa o quarto.
vector<Estadia> buscarEstadiasCliente(int codigo, const string& nome); // Busca histórico de estadias por código ou nome do cliente.

```
### Validações e Regras de Negócio Essenciais
Esta seção detalha as regras de negócio implementadas nas funções de cadastro (SistemaHotel.cpp), que garantem a integridade dos dados.

1. Garantia de Unicidade
Todas as funções de cadastro verificam a duplicidade do identificador único (código ou número):

- Cliente: Não permite cadastro com codigo já existente.

- Funcionário: Não permite cadastro com codigo já existente.

- Quarto: Não permite cadastro com numero já existente.

2. Validações de Valores
As seguintes validações de valores de domínio foram implementadas (retornando códigos de erro específicos):

- Quarto: capacidade deve ser positiva (> 0).

- Quarto: valorDiaria deve ser positiva (> 0).

- Funcionário: salario deve ser positivo (> 0).

3. Persistência de Dados
O sistema garante a persistência de dados em arquivos binários de acesso direto.

- Leitura: Todas as coleções (clientes, quartos, funcionarios, estadias) são carregadas dos arquivos .bin no início da execução (main).

- Escrita: Os dados são salvos nos arquivos .bin sempre que o usuário seleciona a opção Sair (0) no menu principal.

4. Regra de Fidelidade
- Ao realizar a baixa de uma estadia com sucesso, o cliente associado acumula 10 pontos de fidelidade por cada diária paga.

5. Controle de Ocupação e Baixa
- Check-in: Só é permitido se o quarto estiver com status "DESOCUPADO". Após o cadastro da estadia, o status é alterado para "OCUPADO".

- Check-out: Realiza o cálculo do valor total (qtdDiarias * valorDiaria), adiciona pontos de fidelidade e altera o status do quarto para "DESOCUPADO".