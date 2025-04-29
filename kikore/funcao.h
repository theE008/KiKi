#ifndef FUNCAO_H
#define FUNCAO_H

/** FUNCAO_H
 * 
 * Descrição: Trata valores de função
 * Data de início: 4/2025
 * 
 */

////////////////////////////////////////////////// 
// BIBLIOTECAS

#include "manipulador.h"

//////////////////////////////////////////////////
// Protótipos

valor anotar_funcao (valor mnp, funcao t);

//////////////////////////////////////////////////
// Tipos Especiais

// Tamanho
const short tamanhoFuncao = tamanhoByte + tamanhoPtrFuncao; // quando maleável

// Código de Funcao
const byte codigoFuncao = 11;


//////////////////////////////////////////////////
// CONSTRUTOR

valor nova_funcao (funcao func)
{
    verificarErro (func == NULL, "Funcao inexistente");

    valor tmp = novo_valor (tamanhoFuncao);

    naoSalvar valor mnp = novo_manipulador (tmp);

    anotar_configuracoes (mnp, vivo, codigoFuncao, codigoRigido);
    anotar_funcao (mnp, func);

    limpar (mnp);
    return tmp;
}

//////////////////////////////////////////////////
// CONVERSÕES

// VFUNC -> func
funcao para_funcao (valor val)
{
    verificarSubtipo (val, codigoFuncao);

    return acessar (funcao, val, tamanhoByte);
}

//////////////////////////////////////////////////

#endif