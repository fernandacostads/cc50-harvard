#include <stdio.h>
#include <string.h>
#include <ctype.h>

// exemplo, se o usuário inserir uma chave de YTNSHKVEFXRBAUQZCLWDMIPGJO e um texto simples de HELLO :

// $ ./substitution YTNSHKVEFXRBAUQZCLWDMIPGJO
// texto simples: HELLO
// texto cifrado: EHBBQ


// Função para criptografar um caractere usando a cifra de substituição
char encrypt_char(char c, char key[])
{
    if (isalpha(c))
    {
        int index = islower(c) ? c - 'a' : c - 'A';
        return islower(c) ? tolower(key[index]) : toupper(key[index]);
    }
    return c;
}

// Função para verificar se a chave é válida
int is_valid_key(char key[])
{
    if (strlen(key) != 26)
    {
        return 0;
    }

    int freq[26] = {0};
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            return 0;
        }

        int index = tolower(key[i]) - 'a';
        if (freq[index] == 1)
        {
            return 0;
        }
        freq[index] = 1;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    // Verificar o número correto de argumentos da linha de comando
    if (argc != 2)
    {
        printf("Use: ./substitution key\n");
        return 1;
    }

    char *key = argv[1];

    // Verificar se a chave é válida
    if (!is_valid_key(key))
    {
        printf("Chave inválida.\n");
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
        char encrypted_char = encrypt_char(plaintext[i], key);
        printf("%c", encrypted_char);
    }
    printf("\n");

    return 0;
}
