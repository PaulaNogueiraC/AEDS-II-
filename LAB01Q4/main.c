#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int contaMaiusculasRecursivo(char *str)
{
    if (*str == '\0') return 0;

    int contador = 0;
    if (isupper(*str)) //ponteiro
    {
        contador = 1;
    }

    return contador + contaMaiusculasRecursivo(str + 1);
}

void processaString()
{
    char string[100];
    fgets(string, sizeof(string), stdin);

    // remove caractere de nova linha, se tiver
    int len = strlen(string);
    if (len > 0 && string[len - 1] == '\n')
    {
        string[len - 1] = '\0';
    }

    if (strcmp(string, "FIM") == 0)
    {
        printf("\n");
        return;
    }

    int contador = contaMaiusculasRecursivo(string);
    printf("%d\n", contador);

    processaString(); // chamada recursiva para processar a próxima string
}

int main()
{
    processaString(); // inicia o processamento das strings de forma recursiva

    return 0;
}
