#include <string.h>

#include <stdio.h>

#include <locale.h>

#include <stdbool.h>

#include <ctype.h>

typedef struct veiculo {

  int cod;

  char marca[20];

  char modelo[20];

  int ano;

  char placa[8];

}
veiculo;

veiculo veh[10];

int main() {

  setlocale(LC_ALL, "portuguese");

  int i = 0;

  int z = 0;

  int option;

  int ano_fab = 0;

  char modelo[20];

  veh[i].cod = 0;

  bool find = false;

  bool valid_placa = false;

  strcpy(veh[i].marca, "NULL");

  strcpy(veh[i].modelo, "NULL");

  strcpy(veh[i].placa, "NULL");

  do {

    printf("\n\nGestão de veículos");

    printf("\n1 - Cadastrar novo veículo");

    printf("\n2 - Listar todos veículos cadastrados");

    printf("\n3 - Listar veículos filtrando por modelo");

    printf("\n4 - Listar veículos filtrando por ano de fabricação");

    printf("\n5 - Listar veículos filtrando a partir de um ano de fabricação");

    printf("\n6 - Sair");

    printf("\n\nDigite qual opção deseja: ");
    scanf("%d", & option);

    switch (option) {

    case 1:
      if (veh[i].cod < 10) {
        veh[i].cod = i;
        printf("\nCadastrar %iº veículo", i + 1);

        printf("\n\nDigite a marca do veículo:");
        scanf("%s", veh[i].marca);

        printf("Digite o modelo do veículo:");
        scanf("%s", veh[i].modelo);

        printf("Digite o ano do veículo:");
        scanf("%d", & veh[i].ano);

        while (valid_placa == false) {
          printf("Digite a placa do veículo (no formato XXX-YYYY; onde X denota as letras e Y denota os números da placa): ");
          scanf("%8s", veh[i].placa);
          if (isalpha(veh[i].placa[0]) && isalpha(veh[i].placa[1]) && isalpha(veh[i].placa[2]) &&
            isdigit(veh[i].placa[4]) && isdigit(veh[i].placa[5]) && isdigit(veh[i].placa[6]) && isdigit(veh[i].placa[7])) {
            valid_placa = true;
          } else if (strlen(veh[i].placa) != 8 || veh[i].placa[3] != '-') {
            printf("Formato inválido. Tente novamente.\n");
          }
        }

        i = i + 1;
        valid_placa = false;
      } else {
        printf("Limite de veículos máximo atingido!");
      }
      break;

    case 2:

      for (int j = 0; j < i; j++) {
        for (int k = j + 1; k < i; k++) {
          if (veh[j].ano > veh[k].ano) {
            struct veiculo temp = veh[j];
            veh[j] = veh[k];
            veh[k] = temp;
          }
        }
      }

      printf("\n-------- Lista de veículos (ordenado por ano) --------");

      for (int x = 0; x < i; x++) {
        printf("\nVeículo: %i ", x + 1);

        printf("\nMarca: %s", veh[x].marca);

        printf("\nModelo: %s", veh[x].modelo);

        printf("\nAno: %d", veh[x].ano);

        printf("\nPlaca: %s", veh[x].placa);

        printf("\n");
      }
      break;

    case 3:

      printf("\nInforme o modelo do veículo: ");
      scanf("%s", modelo);

      for (int x = 0; x < i; x++) {
        if (strcmp(veh[x].modelo, modelo) == 0) {
          printf("\n-------- Modelo %s --------", modelo);
          printf("\nVeículo: %i ", x + 1);
          printf("\nMarca: %s", veh[x].marca);
          printf("\nModelo: %s", veh[x].modelo);
          printf("\nAno: %d", veh[x].ano);
          printf("\nPlaca: %s", veh[x].placa);
          printf("\n\n");
          find = true;
        }
      }

      if (!find) {
        printf("\nNenhum veículo do modelo '%s' foi encontrado! \n\n", modelo);
      }
      break;

    case 4:

      printf("\nInforme o ano de fabricação a ser pesquisado: ");
      scanf("%d", & ano_fab);

      for (int x = 0; x < i; x++) {
        if (veh[x].ano == ano_fab) {
          printf("\n-------- Ano %d --------", ano_fab);
          printf("\nVeículo: %i ", x + 1);
          printf("\nMarca: %s", veh[x].marca);
          printf("\nModelo: %s", veh[x].modelo);
          printf("\nAno: %d", veh[x].ano);
          printf("\nPlaca: %s", veh[x].placa);
          printf("\n\n");
          z++;
        }
      }

      if (z == 0) {

        printf("\nNenhum veículo com ano de fabricação '%d' foi encontrado!", ano_fab);
      } else {

        z = 0;
      }
      break;

    case 5:

      printf("\nInforme o ano de fabricação inicial a ser pesquisado: ");
      scanf("%d", & ano_fab);

      for (int x = 0; x < i; x++) {

        if (veh[x].ano >= ano_fab) {
          printf("\n-------- Ano %d --------", veh[x].ano);
          printf("\nVeículo: %i ", x + 1);
          printf("\nMarca: %s", veh[x].marca);
          printf("\nModelo: %s", veh[x].modelo);
          printf("\nAno: %d", veh[x].ano);
          printf("\nPlaca: %s", veh[x].placa);
          printf("\n\n");
          z++;
        }
      }

      if (z == 0) {
        printf("\nNenhum veículo com ano de fabricação '%d', ou superior, foi encontrado!", ano_fab);
      } else {
        z = 0;
      }
      break;

    case 6:
      return 0;

      break;

    default:

      printf("\nOpção inexistente!");

      break;
    }
  }

  while (option != 6);

  return 0;
}