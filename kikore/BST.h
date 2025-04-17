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

#include "GC.h"  // Para ir pegando tudo
#include "int.h" // Para para_int
#include "complexo.h" // para adicionar em valores complexos

//////////////////////////////////////////////////
// Valores especiais

// Código de BST
codigo codigoBST = 19;

////////////////////////////////////////////////// 
// DEFINIÇÃO DO SUBTIPO BST

// Construtor de Célula
valor nova_BST (valor nucleo)
{
    verificarErro (nucleo == NULL, "Entrada nula no construtor");
    valor tmp = NULL;

    codigo mod = modificadorAtual ();

    if 
    (
        mod == codigoMaleavel || 
        mod == codigoFixado   ||
        mod == codigoPadrao
    )
    {
        tmp = novo_valor (tamanhoByte + 3 * tamanhoValor); // valor do nó, esquerda, direita
        naoSalvar valor mnp = novo_manipulador (tmp);
        anotar_configuracoes (mnp, vivo, codigoBST, codigoMaleavel);  
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

// Adiciona na árvore. Usa a função comparador para dizer qual deve ir antes e depois
void adicionar (valor val, valor oque)
{
    verificarErro (oque == NULL, "Valor vazio em adicionar");
    // verificarErro (val  == NULL, "Valor vazio em adicionar"); // não acho que necessita
    
    if (pegar_tipo (val) == codigoComplexo) 
    {
        verificarSubtipo (oque, codigoCampo); // apenas campos podem ser adicionados em Val. Complexos 
    }
    else verificarSubtipo (val, codigoBST);

    int resp = comparar (acessar (valor, val, tamanhoByte), oque);

    if (resp > 0) 
    {
        if (acessar (valor, val, tamanhoByte + 2 * tamanhoValor) == NULL) 
            acessar (valor, val, tamanhoByte + 2 * tamanhoValor) = nova_BST (oque);
        else 
            adicionar (acessar (valor, val, tamanhoByte + 2 * tamanhoValor), oque);
    }
    else if (resp < 0)
    {
        if (acessar (valor, val, tamanhoByte + tamanhoValor) == NULL) 
            acessar (valor, val, tamanhoByte + tamanhoValor) = nova_BST (oque);
        else 
            adicionar (acessar (valor, val, tamanhoByte + tamanhoValor), oque);        
    }
    else 
    {
        acessar (valor, val, tamanhoByte) = nova_BST (oque);
    }
}

//////////////////////////////////////////////////

#endif
