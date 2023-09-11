#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
  char name[50]; // Alterado para um array de caracteres para armazenar nomes
  int votes;
  bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, const char *name); // Alterado para receber uma string
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, const char *argv[])
{
  // Check for invalid usage
  if (argc < 2)
  {
    printf("Usage: runoff [candidate ...]\n");
    return 1;
  }

  // Populate array of candidates
  candidate_count = argc - 1;
  if (candidate_count > MAX)
  {
    printf("Maximum number of candidates is %i\n", MAX);
    return 2;
  }
  for (int i = 0; i < candidate_count; i++)
  {
    strcpy(candidates[i].name, argv[i + 1]); // Usando strcpy para copiar o nome
    candidates[i].votes = 0;
    candidates[i].eliminated = false;
  }

  printf("Number of voters: ");
  scanf("%d", &voter_count); // Usando scanf para receber o número de eleitores
  if (voter_count < 1)
  {
    printf("Invalid number of voters.\n");
    return 3;
  }

  // Keep holding runoffs until winner exists
  while (true)
  {
    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
      for (int j = 0; j < candidate_count; j++)
      {
        char name[50];
        printf("Rank %i: ", j + 1);
        scanf("%s", name);
        // Record vote, unless it's invalid
        if (!vote(i, j, name))
        {
          printf("Invalid vote.\n");
          return 4;
        }
      }
      printf("\n");
    }

    // Calculate votes given remaining candidates
    tabulate();

    // Check if election has been won
    bool won = print_winner();
    if (won)
    {
      break;
    }

    // Eliminate last-place candidates
    int min = find_min();
    bool tie = is_tie(min);

    // If it's a tie, everyone wins
    if (tie)
    {
      for (int i = 0; i < candidate_count; i++)
      {
        if (!candidates[i].eliminated)
        {
          printf("%s\n", candidates[i].name);
        }
      }
      break;
    }

    // Eliminate anyone with the minimum number of votes
    eliminate(min);

    // Reset vote counts back to zero
    for (int i = 0; i < candidate_count; i++)
    {
      if (!candidates[i].eliminated)
      {
        candidates[i].votes = 0;
      }
    }
  }

  return 0;
}

bool vote(int voter, int rank, const char *name)
{
  for (int i = 0; i < candidate_count; i++)
  {
    if (!candidates[i].eliminated && strcmp(candidates[i].name, name) == 0)
    {
      candidates[i].votes += 1;
      return true;
    }
  }
  return false;
}

void tabulate(void)
{
  // Implementação da função tabulate
}

bool print_winner(void)
{
  int majority = voter_count / 2;

  for (int i = 0; i < candidate_count; i++)
  {
    if (!candidates[i].eliminated && candidates[i].votes > majority)
    {
      printf("%s\n", candidates[i].name); // Imprime o nome do vencedor
      return true;
    }
  }

  return false; // Nenhum candidato venceu
}

int find_min(void)
{
  int min = voter_count;

  for (int i = 0; i < candidate_count; i++)
  {
    if (!candidates[i].eliminated && candidates[i].votes < min)
    {
      min = candidates[i].votes; // Atualiza o mínimo se um candidato tem menos votos
    }
  }

  return min; // Retorna o número mínimo de votos
}

bool is_tie(int min)
{
  for (int i = 0; i < candidate_count; i++)
  {
    if (!candidates[i].eliminated && candidates[i].votes != min)
    {
      return false; // Não é um empate, pois há um candidato com mais votos
    }
  }

  return true; // É um empate, pois todos os candidatos têm o mesmo número de votos (min)
}

void eliminate(int min)
{
  for (int i = 0; i < candidate_count; i++)
  {
    if (!candidates[i].eliminated && candidates[i].votes == min)
    {
      candidates[i].eliminated = true; // Elimina candidato com o número mínimo de votos
    }
  }
}
