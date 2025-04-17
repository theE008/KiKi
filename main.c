#include "kikore/arranjo.h"
#include "kikore/campo.h"
#include "kikore/BST.h"

// gcc -o main main.c && main

void main (void)
{
    M
        valor y = novo_campo ("Tipo", novo_texto ("Teste"));

        valor a = novo_complexo (y);

        valor b = novo_campo ("Valor", novo_texto ("555"));

        adicionar (a, b);

        maleavel valor bst = nova_BST (a);
        
        imprimirBitsAteh (a, 25);
    W

    finalizar (0, "Funcionando");
}