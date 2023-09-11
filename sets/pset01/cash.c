#include <cs50.h>
#include <stdio.h>

int main(void)
{

    float troco;
    float restante;
    int numMoedas = 0;

    do
    {
        troco = get_float("Insira o valor devido: ");
    }
    while (troco < 0);

    restante = troco * 100;

    while (restante > 0)
    {
        if (restante >= 25)
        {
            restante = restante - 25;
            numMoedas++;
        }
        else if (restante >= 10)
        {
            restante = restante - 10;
            numMoedas++;
        }
        else if (restante >= 5)
        {
            restante = restante - 5;
            numMoedas++;
        }
        else if (restante >= 1)
        {
            restante = restante - 1;
            numMoedas++;
        }
    }

    printf("\nNumero minimo de moedas: %i\n", numMoedas);
}
