#ifndef COMPLEXO_H
#define COMPLEXO_H

/** COMPLEXO_H
 * 
 * Descrição: Estruturado como um JSON, é o subtipo mais interessante da biblioteca. 
 * Subtipos do sistema tem um panteão limitado de IDs, e para isto o tipo complexo existe.
 * ele é capaz de carregar tipos variados de informação sem problema, e ele carrega até a 
 * forma que ele deseja ser tratado pelas funções do sistema - criando uma espécie de tipos
 * sub-sub-tipos, quais os usuários podem personalizar sem precisar se preocupar com todo o
 * tratamento automático que a biblioteca irá fazer.
 * 
 * Data de início: 3/2025
 * 
 */

////////////////////////////////////////////////// 
// BIBLIOTECAS

#include "campo.h"
#include "BST.h"

//////////////////////////////////////////////////
// Protótipos

valor nova_BST (valor nucleo);

//////////////////////////////////////////////////
// Valores especiais


// Código de Complexo
const byte codigoComplexo = 13;

////////////////////////////////////////////////// 
// DEFINIÇÃO DO SUBTIPO COMPLEXO

// Construtor de Complexo
valor novo_complexo (valor comp)
{
    verificarSubtipo (comp, codigoCampo);
    valor tmp = NULL;

    codigo mod = modificadorAtual ();
    
    if 
    (
        mod == codigoMaleavel || 
        mod == codigoFixado   || 
        mod == codigoPadrao   
    )
    {
        tmp = nova_BST (comp);

        //codigo mod = modificadorAtual ();
    
        //variavelDeModificadorAtual = valorComumDaVariavelDeModificadorAtual;
    
        //acessar (byte, tmp, 0) = nova_configuracao (vivo, mod, codigoComplexo);
    }
    else 
    {
        verificarErro (1, "Nao implementado");
    }

    return tmp;
} 


//////////////////////////////////////////////////

#endif