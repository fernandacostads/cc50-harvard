#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(const char *word);

int main(void)
{
    char word1[100], word2[100];
    
    printf("Player 1: ");
    fgets(word1, sizeof(word1), stdin);
    
    printf("Player 2: ");
    fgets(word2, sizeof(word2), stdin);

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Determine the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}

int compute_score(const char *word)
{
    int score = 0;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // Convert the letter to uppercase to look up its point value
        char letter = toupper(word[i]);

        // Check if the character is an uppercase letter
        if (isalpha(letter))
        {
            // Calculate the index in POINTS array for the letter
            int index = letter - 'A';

            // Add the corresponding point value to the score
            score += POINTS[index];
        }
    }

    return score;
}
