#ifndef MEMORIA_H
#define MEMORIA_H

/** MEMORIA_H
 * 
 * Descrição: Usado para registrar ponteiros e sua validade em uma pilha.
 * Data de início: 3/2025
 * 
 *   As memórias carregam um ponteiro para outra memória, um ponteiro para um valor, e uma validade.
 * 
 */

////////////////////////////////////////////////// 
// BIBLIOTECAS

#include "manipulador.h"
#include "GC.h"

//////////////////////////////////////////////////
// Valores especiais

// Código de Memória
const byte codigoMemoria = 7;

////////////////////////////////////////////////// 
// DEFINIÇÃO DO SUBTIPO MEMÓRIA

// Construtor da memória
valor nova_memoria (ptr val, ptr prox, int nivel)
{
    verificarErro (val == NULL, "Input inexistente");
    verificarSubtipo (((valor) prox), codigoMemoria);

    valor tmp = novo_valor (tamanhoByte + tamanhoInt + tamanhoPtr + tamanhoPtr);

    valor mnp = novo_manipulador (tmp);

    anotar_configuracoes (mnp, vivo, constante, codigoMemoria);
    anotar_int  (mnp, nivel);
    anotar_ptr  (mnp,   val);
    anotar_ptr  (mnp,  prox);

    if (usadoPelaMemoria) limpar (mnp);

    return tmp;
}

//////////////////////////////////////////////////

#endif