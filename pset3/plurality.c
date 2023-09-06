#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX 9

// Define a struct candidate
typedef struct
{
    char name[30];
    int votes;
} candidate;

// Declare a global array of candidates
candidate candidates[MAX];

// Declare the number of candidates
int candidate_count = 0;

// Function prototypes
bool vote(const char *name);
void print_winner(void);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s candidate1 candidate2 ... candidate9\n", argv[0]);
        return 1;
    }

    // Populate candidates array with names from command line arguments
    for (int i = 1; i < argc; i++)
    {
        if (candidate_count < MAX)
        {
            strcpy(candidates[candidate_count].name, argv[i]);
            candidates[candidate_count].votes = 0;
            candidate_count++;
        }
        else
        {
            printf("Maximum number of candidates exceeded. Only %d candidates allowed.\n", MAX);
            return 2;
        }
    }

    int voters;
    printf("Number of voters: ");
    scanf("%d", &voters);

    for (int i = 0; i < voters; i++)
    {
        char name[30];
        printf("Vote: ");
        scanf("%s", name);

        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    print_winner();
    return 0;
}

// Update vote totals given a new vote
bool vote(const char *name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int max_votes = 0;

    // Find the maximum number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    // Print the name(s) of the winner(s)
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
