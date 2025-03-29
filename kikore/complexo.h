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

#include "arranjo.h"
#include "campo.h"

//////////////////////////////////////////////////
// Valores especiais

// Código de Complexo
const byte codigoComplexo = 13;

////////////////////////////////////////////////// 
// DEFINIÇÃO DO SUBTIPO COMPLEXO

// Construtor de Complexo
valor novo_complexo (int qntsComponentes, valor arr)
{
    // TODOS OS ARRANJOS DE CAMPOS SERÃO TIPOS COMPLEXOS. TALVEZ LISTA SEJA MELHOR
} 


//////////////////////////////////////////////////

#endif