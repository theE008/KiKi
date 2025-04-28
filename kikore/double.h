#ifndef DOUBLE_H
#define DOUBLE_H

/** DOUBLE_H
 * 
 * Descrição: Tratamento de DOUBLE
 * Data de início: 4/2025
 * 
 */

////////////////////////////////////////////////// 
// BIBLIOTECAS

#include "GC.h"

//////////////////////////////////////////////////
// Valores especiais

// Código de Campo
const byte codigoDouble = 4;

////////////////////////////////////////////////// 
// DEFINIÇÃO DO SUBTIPO DOUBLE

// Construtor de Double
valor novo_double (double val)
{
    valor tmp = novo_valor (tamanhoByte + tamanhoDouble);
    naoSalvar valor mnp = novo_manipulador (tmp);

    anotar_configuracoes (mnp, vivo, codigoDouble, codigoRigido);
    anotar_double (mnp, val);

    limpar (mnp);
    return tmp;
}

//////////////////////////////////////////////////
// CONVERSÕES

// VDOUBLE -> double
double para_double (valor val)
{
    verificarSubtipo (val, codigoDouble);

    return acessar (double, val, tamanhoByte);
}

//////////////////////////////////////////////////

#endif