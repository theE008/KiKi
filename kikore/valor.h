#ifndef VALOR_H
#define VALOR_H

/** VALOR_H
 * 
 * Descrição: Aqui estará a declaração do que é um valor, seu tamanho, e um construtor simples
 * Data de início: 3/2025
 * 
 */

////////////////////////////////////////////////// 
// BIBLIOTECAS

#include "byte.h"
#include "GC.h"

//////////////////////////////////////////////////
// Tipos Especiais

// Valor do sistema
typedef byte * valor;
short tamanhoValor = sizeof (valor);

// Função
typedef valor (* funcao) (valor, ...);
short tamanhoFuncao = sizeof (funcao);

// Código de Valor Vazio
const byte codigoVazio = 0;

//////////////////////////////////////////////////
// Construtores

// Construtor vazio (um byte apenas com zeros é um tipo vazio)
valor novo_valor (size_t tam)
{
    valor tmp = NULL;

    malocar (tmp, valor, tam);

    loop (x, tam) * (tmp + x) = 0;

    registrarNaMemoria (tmp);

    return tmp;
}

//////////////////////////////////////////////////

#endif