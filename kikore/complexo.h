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

// Tamanho
const short tamanhoBST = tamanhoByte + 3 * tamanhoValor; // quando maleável

// Tamanho
const short tamanhoComplexo = tamanhoBST; // quando maleável

// Código de Complexo
const byte codigoComplexo = 13;

////////////////////////////////////////////////// 
// DEFINIÇÃO DO SUBTIPO COMPLEXO

// Construtor de Complexo
valor novo_complexo (valor comp)
{
    verificarSubtipo (comp, codigoCampo);
    valor tmp = NULL;

    codigo mod = pegarModificadorAtual ();
    
    if 
    (
        mod == codigoMaleavel || 
        mod == codigoFixado   || 
        mod == codigoPadrao   
    )
    {
        tmp = nova_BST (comp);

        naoSalvar valor mnp = novo_manipulador (tmp);

        anotar_configuracoes (mnp, vivo, 13, (mod == codigoPadrao)? codigoMaleavel:mod); 
        // TÁ SUBTRAINDO UM DO TIPO??? ONDE!!! (era do +255, erro absurdo)

        //variavelDeModificadorAtual = valorComumDaVariavelDeModificadorAtual;
    
        //acessar (byte, tmp, 0) = nova_configuracao (vivo, mod, codigoComplexo);

        limpar (mnp);
    }
    else 
    {
        verificarErro (1, "Nao implementado");
        //modificadorAtual (); // essa linha nem roda!
    }

    return tmp;
} 

// Pegar elemento do complexo
valor pegar (valor comp, char* campo)
{
    verificarSubtipo (comp, codigoComplexo);
    verificarErro (campo == NULL, "Nome inexistente");

    valor ptr = comp;

    int tmp = 1;

    while (tmp != 0 && ptr != NULL)
    {
        string name = nome (acessar (valor, ptr, tamanhoByte));
        tmp = compararStrings (name, campo);
        limpar (name);

             if (tmp < 0) {ptr = acessar (valor, ptr, tamanhoByte +     tamanhoValor);}
        else if (tmp > 0) {ptr = acessar (valor, ptr, tamanhoByte + 2 * tamanhoValor);}
    }

    if (ptr == NULL) return NULL;
    else
    return acessar (valor, acessar (valor, ptr, tamanhoByte), tamanhoByte);
}

//////////////////////////////////////////////////

#endif