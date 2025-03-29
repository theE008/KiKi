#include "kikore/arranjo.h"
#include "kikore/campo.h"

// gcc -o main main.c && main

void main (void)
{
    M
        valor a = novo_texto ("Testando");
        valor d = nova_memoria (a, NULL, 4944);
        valor f = novo_campo ("teste", d);

        valor teste [2];
        teste [0] = a;
        teste [1] = d;

        valor g = novo_arranjo (teste, 2);

        imprimirBitsAteh (g, 21);
    W

    finalizar (0, "Funcionando");
}