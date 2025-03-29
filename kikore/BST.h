#ifndef BST_H
#define BST_H

/** BST_H
 * 
 * Descrição: Arvore binária de pesquisa
 * Data de início: 3/2025
 * 
 */

////////////////////////////////////////////////// 
// BIBLIOTECAS

#include "GC.h" // Para ir pegando tudo

//////////////////////////////////////////////////
// Valores especiais

// Código de BST
codigo codigoBST = 19;

////////////////////////////////////////////////// 
// DEFINIÇÃO DO SUBTIPO BST

// Construtor de BST
valor nova_BST (valor nucleo)
{
    verificarErro (nucleo == NULL, "Entrada nula no construtor");
    valor tmp = NULL;

    if (modificadorAtual () == codigoMaleavel || modificadorAtual () == codigoFixado)
    {
        tmp = novo_valor (tamanhoByte + 3 * tamanhoValor); // valor do nó, esquerda, direita
        naoSalvar valor mnp = novo_manipulador (tmp);
        anotar_configuracoes (mnp, vivo, codigoBST);  
        anotar_valor (mnp, nucleo);

        // O resto fica vazio

        anotar_valor (mnp, NULL);
        anotar_valor (mnp, NULL);
        
        limpar (mnp);
    }
    else // Possível
    {
        verificarErro (1, "Ainda nao implementado");

        // provavelmente usa "nucleo" (sendo núcleo sub-int) para simplesmente reservar o espaço
        
        // Ou talvez um vetor, em. Nucleo sendo um vetor
    }

    return tmp;
}

//////////////////////////////////////////////////

#endif
