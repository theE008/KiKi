#include "kikore/arranjo.h"
#include "kikore/campo.h"

// gcc -o main main.c && main

void main (void)
{
    M
        valor a = novo_texto ("abcd");

        constante valor b = novo_campo ("aaa", a);

        imprimirBitsAteh (b, 1 + 8 + 4 + 3);

    W

    finalizar (0, "Funcionando");
}