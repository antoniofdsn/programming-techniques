#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <locale.h>

#define MAX_INPUT 100
#define BLOCO_CLIENTES 10
#define MAX_NOME 30

typedef struct {
  char nome[MAX_NOME];
  int ano_nascimento;
  float montante_compras;
}
Cliente;

void incluir_cliente(Cliente ** clientes, int * n_clientes);
int buscar_cliente(Cliente * clientes, int n_clientes, char * nome);
void remover_cliente(Cliente ** clientes, int * n_clientes);
void atualizar_montante_compras(Cliente * clientes, int n_clientes);
void exibir_montante_compras_cliente(Cliente * clientes, int n_clientes);
void zerar_montantes_compras(Cliente * clientes, int n_clientes);
void exibir_todos_clientes(Cliente * clientes, int n_clientes);
int cliente_melhor_comprador(Cliente * clientes, int n_clientes);

int main() {

  setlocale(LC_ALL, "portuguese");

  Cliente * clientes = NULL;
  int n_clientes = 0;
  int opcao;

  while (1) {
    printf("\n-------- Escolha uma opção --------\n");
    printf("1- Incluir cliente\n");
    printf("2- Remover cliente\n");
    printf("3- Atualizar montante de compras\n");
    printf("4- Exibir montante de compras de um cliente\n");
    printf("5- Zerar montantes de compras de todos os clientes\n");
    printf("6- Exibir todos os clientes\n");
    printf("7- Exibir o cliente com o maior montante de compras\n");
    printf("8- Sair\n");
    printf("Opção: ");
    scanf("%d", & opcao);

    switch (opcao) {
    case 1:
      incluir_cliente( & clientes, & n_clientes);
      break;
    case 2:
      remover_cliente( & clientes, & n_clientes);
      break;
    case 3:
      atualizar_montante_compras(clientes, n_clientes);
      break;
    case 4:
      exibir_montante_compras_cliente(clientes, n_clientes);
      break;
    case 5:
      zerar_montantes_compras(clientes, n_clientes);
      break;
    case 6:
      exibir_todos_clientes(clientes, n_clientes);
      break;
    case 7:
      printf("\n-------- Cliente melhor comprador --------\n");
      printf("Nome: %s\n", clientes[cliente_melhor_comprador(clientes, n_clientes)].nome);
      printf("Ano de nascimento: %d\n", clientes[cliente_melhor_comprador(clientes, n_clientes)].ano_nascimento);
      printf("Montante de compras: %.2f\n", clientes[cliente_melhor_comprador(clientes, n_clientes)].montante_compras);
      break;
    case 8:
      printf("Saindo...\n");
      free(clientes);
      exit(0);
    default:
      printf("Opção inválida. Tente novamente.\n");
      break;
    }
  }

  return 0;
}

void incluir_cliente(Cliente ** clientes, int * n_clientes) {
  if ( * n_clientes % BLOCO_CLIENTES == 0) {
    // É preciso realocar a memória
    * clientes = (Cliente * ) realloc( * clientes, ( * n_clientes + BLOCO_CLIENTES) * sizeof(Cliente));
    if ( * clientes == NULL) {
      printf("Erro ao alocar memória.\n");
      exit(1);
    }
  }

  Cliente novo_cliente;

  printf("Digite o nome do cliente (máximo de %d caracteres): ", MAX_NOME);
  scanf("%s", novo_cliente.nome);
  while (strlen(novo_cliente.nome) > MAX_NOME - 1) {
    printf("Nome muito longo. Digite novamente: ");
    scanf("%s", novo_cliente.nome);
  }

  printf("Digite o ano de nascimento do cliente: ");
  scanf("%d", & novo_cliente.ano_nascimento);
  while (novo_cliente.ano_nascimento < 1900 || novo_cliente.ano_nascimento > 2023) {
    printf("Ano de nascimento inválido. Digite novamente: ");
    scanf("%d", & novo_cliente.ano_nascimento);
  }

  printf("Digite o montante de compras do cliente: ");
  scanf("%f", & novo_cliente.montante_compras);
  while (novo_cliente.montante_compras < 0) {
    printf("Montante de compras inválido. Digite novamente: ");
    scanf("%f", & novo_cliente.montante_compras);
  }

  ( * clientes)[ * n_clientes] = novo_cliente;
  ( * n_clientes) ++;

  printf("\n\nCliente incluído com sucesso.\n");
}

int buscar_cliente(Cliente * clientes, int n_clientes, char * nome) {
  if (n_clientes == 0) {
    return -1;
  }

  int i;
  for (i = 0; i < n_clientes; i++) {
    if (strcmp(clientes[i].nome, nome) == 0) {
      return i;
    }
  }
  return -1;
}

void remover_cliente(Cliente ** clientes, int * n_clientes) {
  char nome[MAX_NOME];
  int posicao_cliente;

  printf("Digite o nome do cliente a ser removido: ");
  scanf("%s", nome);

  posicao_cliente = buscar_cliente( * clientes, * n_clientes, nome);
  if (posicao_cliente == -1) {
    printf("Cliente não encontrado\n");
    return;
  }

  ( * clientes)[posicao_cliente] = ( * clientes)[( * n_clientes) - 1];
  ( * n_clientes) --;
}

void atualizar_montante_compras(Cliente * clientes, int n_clientes) {
  char nome[MAX_NOME];
  int posicao_cliente;
  float montante_compras;
  char input[MAX_INPUT];
  char * endptr;

  printf("Digite o nome do cliente: ");
  scanf("%s", nome);
  getchar();

  posicao_cliente = buscar_cliente(clientes, n_clientes, nome);
  if (posicao_cliente == -1) {
    printf("Cliente não encontrado\n");
    return;
  }

  while (1) {
    printf("Digite o novo montante de compras do cliente: ");
    fgets(input, MAX_INPUT, stdin);
    if (strspn(input, "0123456789.") != strlen(input) - 1) {
      printf("Valor inválido. Tente novamente.\n");
      continue;
    }
    montante_compras = strtof(input, & endptr);
    if (endptr == input || * endptr != '\n') {
      printf("Valor inválido. Tente novamente.\n");
    } else {
      break;
    }
  }

  clientes[posicao_cliente].montante_compras = montante_compras;
}

void exibir_montante_compras_cliente(Cliente * clientes, int n_clientes) {
  char nome[MAX_NOME];
  int posicao_cliente;

  if (n_clientes == 0) {
    printf("Nenhum cliente cadastrado.\n");
    return;
  }

  printf("Digite o nome do cliente: ");
  scanf("%s", nome);

  posicao_cliente = buscar_cliente(clientes, n_clientes, nome);
  if (posicao_cliente == -1) {
    printf("Nome do cliente não encontrado\n");
    return;
  }

  printf("Montante de compras do cliente %s é: %.2f\n", nome, clientes[posicao_cliente].montante_compras);
}

void zerar_montantes_compras(Cliente * clientes, int n_clientes) {
  if (clientes == NULL) {
    printf("Lista de clientes vazia\n");
    return;
  }

  int i;
  for (i = 0; i < n_clientes; i++) {
    clientes[i].montante_compras = 0;
  }
}

void exibir_todos_clientes(Cliente * clientes, int n_clientes) {
  if (clientes == NULL) {
    printf("Lista de clientes vazia\n");
    return;
  }

  if (n_clientes == 0) {
    printf("Lista de clientes vazia\n");
    return;
  }

  int i;
  printf("\n-------- Lista de clientes --------\n");
  for (i = 0; i < n_clientes; i++) {
    printf("\n-------- Cliente %d --------\n", i+1);
    printf("Nome: %s\n", clientes[i].nome);
    printf("Ano de nascimento: %d\n", clientes[i].ano_nascimento);
    printf("Montante de compras: %.2f\n", clientes[i].montante_compras);
  }
}

int cliente_melhor_comprador(Cliente * clientes, int n_clientes) {
  int i;
  int indice_melhor_comprador = 0;
  float maior_montante = clientes[0].montante_compras;

  for (i = 1; i < n_clientes; i++) {
    if (clientes[i].montante_compras > maior_montante) {
      indice_melhor_comprador = i;
      maior_montante = clientes[i].montante_compras;
    }
  }

  return indice_melhor_comprador;
}