#ifndef INT_H
#define INT_H

/** VINT_H
 * 
 * Descrição: Tratamento de INT
 * Data de início: 3/2025
 * 
 */

////////////////////////////////////////////////// 
// BIBLIOTECAS

#include "GC.h"

//////////////////////////////////////////////////
// Valores especiais

// Código de Campo
const byte codigoInt = 3;

////////////////////////////////////////////////// 
// DEFINIÇÃO DO SUBTIPO INT

// Construtor de Int
valor novo_int (int val)
{
    valor tmp = novo_valor (tamanhoByte + tamanhoInt);
    naoSalvar valor mnp = novo_manipulador (mnp);

    anotar_configuracoes (mnp, vivo, codigoInt);
    anotar_int (mnp, val);

    limpar (mnp);
    return tmp;
}

//////////////////////////////////////////////////
// CONVERSÕES

// VINT -> int
int para_int (valor val)
{
    verificarSubtipo (val, codigoInt);

    return acessar (int, val, tamanhoByte);
}

//////////////////////////////////////////////////

#endif