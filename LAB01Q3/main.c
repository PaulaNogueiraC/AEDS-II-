#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int contaMaiusculas(char *str)
{
    int contador = 0;
    while (*str)
    {
        if (isupper(*str)) //isupper: eh uma funcao que verifica se o caractere eh maiusculo
        {
            contador++;
        }
        str++; //move o ponteiro para o proximo caractere da string
    }
    return contador;
}

int main()
{
    char string[100];
    int continuar = 1;

    while (continuar)
    {
        fgets(string, sizeof(string), stdin);

        // remove caractere de nova linha, se tiver
        int len = strlen(string);
        if (len > 0 && string[len - 1] == '\n')
        {
            string[len - 1] = '\0'; //Se a condição for verdadeira, substitui a nova linha por um caractere nulo (\0), efetivamente removendo-a da string.
        }

        if (strcmp(string, "FIM") == 0)
        {
            printf("\n");
            continuar = 0;
            return;
        }

        int contador = contaMaiusculas(string);
        printf("%d\n", contador);
    }

    return 0;
}
