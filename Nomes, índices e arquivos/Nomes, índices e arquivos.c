/*
Crie um programa em C que:
Leia o arquivo com 1299 nomes disponíveis no item Material;
Desordene o arquivo;
Defina um índice para cada nome;
Defina uma struct para armazenar cada par nome/índice;
Salve, usando as structs, os pares nome/índice em disco.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura para armazenar nome
typedef struct {
  char nome[256];
} Nome;

// Função para trocar dois elementos de um array
void swap(Nome *a, Nome *b) {
  Nome temp = *a;
  *a = *b;
  *b = temp;
}

// Função para embaralhar os elementos de um array
void embaralhar(Nome *nomes, int tamanho) {
  srand(time(NULL));
  for (int i = 0; i < tamanho - 1; i++) {
    int j = rand() % (tamanho - i) + i;
    swap(&nomes[i], &nomes[j]);
  }
}

int main() {
  // Definir o número de nomes
  int numero_nomes = 1299;

  // Alocar memória para o array de structs
  Nome *nomes = malloc(sizeof(Nome) * numero_nomes);

  // Abrir o arquivo com os nomes
  FILE *arquivo_nomes = fopen("nomesOrdenados.txt", "r");
  if (arquivo_nomes == NULL) {
    printf("Erro ao abrir o arquivo nomesOrdenados.txt\n");
    return 1;
  }

  // Ler os nomes para o array
  for (int i = 0; i < numero_nomes; i++) {
    fscanf(arquivo_nomes, "%s", nomes[i].nome);
  }

  // Fechar o arquivo
  fclose(arquivo_nomes);

  // Embaralhar os nomes
  embaralhar(nomes, numero_nomes);

  // Abrir um novo arquivo para salvar os nomes
  FILE *arquivo_saida = fopen("nomesDesordenados.txt", "w");
  if (arquivo_saida == NULL) {
    printf("Erro ao abrir o arquivo nomesDesordenados.txt\n");
    return 1;
  }

  // Escrever os nomes no arquivo
  for (int i = 0; i < numero_nomes; i++) {
    fprintf(arquivo_saida, "%s\n", nomes[i].nome);
  }

  // Fechar o arquivo
  fclose(arquivo_saida);

  // Liberar a memória alocada
  free(nomes);

  printf("Programa finalizado com sucesso!\n");

  return 0;
}
