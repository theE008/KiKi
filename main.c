#include "kikore/arranjo.h"
#include "kikore/campo.h"
#include "kikore/BST.h"

// gcc -o main main.c && main

void main (void)
{
    M
        valor t = novo_texto ("Teste");

        valor y = novo_campo ("Tipo", t);
        valor z = novo_campo ("Bomga", t);

        valor a = novo_complexo (y);

        valor b = novo_campo ("Valor", novo_texto ("555"));

        adicionar (a, z);
        adicionar (a, b);

        // maleavel valor bst = nova_BST (a);
        
        imprimirBitsAteh (a, tamanhoComplexo);

        //printf ("<%s>", nome (z));
    W

    finalizar (0, "Funcionando");
}
