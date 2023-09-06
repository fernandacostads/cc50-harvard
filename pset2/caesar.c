#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Função para criptografar um caractere usando a cifra de César
char encrypt_char(char c, int k)
{
  if (isalpha(c))
  {
    char base = islower(c) ? 'a' : 'A';
    return (c - base + k) % 26 + base;
  }
  return c;
}

int main(int argc, char *argv[])
{
  // Verificar o número correto de argumentos da linha de comando
  if (argc != 2)
  {
    printf("Use: ./caesar key\n");
    return 1;
  }

  // Converter a chave fornecida como argumento para um número inteiro
  int k = atoi(argv[1]);

  // Verificar se a chave é um número inteiro não negativo
  if (k < 0)
  {
    printf("A chave deve ser um inteiro não negativo.\n");
    return 1;
  }

  // Solicitar ao usuário o texto simples
  char plaintext[1000];
  printf("plaintext: ");
  fgets(plaintext, sizeof(plaintext), stdin);

  // Criptografar e imprimir o texto cifrado
  printf("ciphertext: ");
  for (int i = 0, n = strlen(plaintext); i < n; i++)
  {
    char encrypted_char = encrypt_char(plaintext[i], k);
    printf("%c", encrypted_char);
  }
  printf("\n");

  return 0;
}
