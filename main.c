#include "kikore/arranjo.h"
#include "kikore/campo.h"
#include "kikore/BST.h"

// gcc -o main main.c && main

void main (void)
{
    M
        valor z = novo_texto ("aa");
        valor a = nova_BST (z);

        valor b = novo_texto ("bb");

        adicionar (a, b);
        
        imprimirBitsAteh (a, 25);
    W

    finalizar (0, "Funcionando");
}