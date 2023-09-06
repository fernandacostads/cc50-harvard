#include <stdio.h>
#include <string.h>
#include <math.h>

// Compilar com gcc -o readability readability.c -lm

// Função para contar o número de letras em uma string
int count_letters(const char *text)
{
  int letters = 0;
  for (int i = 0, n = strlen(text); i < n; i++)
  {
    if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
    {
      letters++;
    }
  }
  return letters;
}

// Função para contar o número de palavras em uma string
int count_words(const char *text)
{
  int words = 1;
  for (int i = 0, n = strlen(text); i < n; i++)
  {
    if (text[i] == ' ')
    {
      words++;
    }
  }
  return words;
}

// Função para contar o número de frases em uma string
int count_sentences(const char *text)
{
  int sentences = 0;
  for (int i = 0, n = strlen(text); i < n; i++)
  {
    if (text[i] == '.' || text[i] == '!' || text[i] == '?')
    {
      sentences++;
    }
  }
  return sentences;
}

int main(void)
{
  char text[1000]; // Defina o tamanho máximo da entrada
  printf("Texto: ");
  fgets(text, sizeof(text), stdin);

  // Contar o número de letras, palavras e frases
  int letters = count_letters(text);
  int words = count_words(text);
  int sentences = count_sentences(text);

  // Calcular o índice Coleman-Liau
  float L = (float)letters / words * 100;
  float S = (float)sentences / words * 100;
  int index = round(0.0588 * L - 0.296 * S - 15.8);

  // Imprimir o resultado
  if (index < 1)
  {
    printf("Before Grade 1\n");
  }
  else if (index >= 16)
  {
    printf("Grade 16+\n");
  }
  else
  {
    printf("Grade %i\n", index);
  }

  return 0;
}
