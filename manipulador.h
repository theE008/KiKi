#ifndef MANIPULADOR_H
#define MANIPULADOR_H

/** MANIPULADOR_H
 * 
 * Descrição: Usado para manipular/ler/construir valores
 * Data de início: 3/2025
 * 
 *   Os manipuladores carregam o ponteiro para um valor, juntamente com um index.
 *   Eles acessam esse valor para leitura e escrita pelo index (int).
 * 
 */

////////////////////////////////////////////////// 
// BIBLIOTECAS

#include "valor.h"
#include "config.h"

//////////////////////////////////////////////////
// Valores especiais

// Código de Byte
const byte codigoManipulador = 8;

////////////////////////////////////////////////// 
// DEFINIÇÃO DO SUBTIPO MANIPULADOR

// Construtor de Manipulador
valor novo_manipulador (valor val)
{
    verificarErro (val == NULL, "Input inexistente no construtor");

    valor tmp = novo_valor (tamanhoByte + tamanhoInt + tamanhoPtr);   

    acessar (byte, tmp, 0) = nova_configuracao (vivo, maleavel, codigoManipulador);
    acessar (int, tmp, tamanhoByte) = 0; // Indice
    acessar (ptr, tmp, tamanhoByte + tamanhoInt) = val;        

    // Registrar na memória

    return tmp;
}

//////////////////////////////////////////////////
// FUNÇÕES DE GET DO MANIPULADOR

// Retorna o índice do Manipulador
int pegar_indice (valor mnp)
{
    verificarSubtipo (mnp, codigoManipulador);

    return acessar (int, mnp, tamanhoByte);
}

// Retorna o Valor do qual o Manipulador aponta
valor pegar_valor (valor mnp)
{
    verificarSubtipo (mnp, codigoManipulador);

    valor val = acessar (valor, mnp, tamanhoByte + tamanhoInt);

    return val;
}

//////////////////////////////////////////////////
// FUNÇÕES DE SET DO MANIPULADOR

// Atualiza o índice do manipulador
valor mudar_indice (valor mnp, int indice)
{
    verificarSubtipo (mnp, codigoManipulador);

    acessar (int, mnp, tamanhoByte) = indice;

    return mnp;
}

// Retorna o indice antes de o atualizar
int usar_indice (valor mnp, int indice)
{
    int tmp = pegar_indice (mnp);

    mudar_indice (mnp, tmp + indice);

    return tmp;
}

//////////////////////////////////////////////////
// FUNÇÕES DE ANOTAR

// Macro de definição de funções de anotaçoes
#define novaFuncaoDeAnotarNoManipulador(tipo,tamanho) \
valor anotar_##tipo (valor mnp, tipo t) \
{ \
    verificarSubtipo (mnp, codigoManipulador); \
    int x = usar_indice (mnp, tamanho); \
    valor val = pegar_valor (mnp); \
    acessar (tipo, val, x) = t; \
    return mnp; \
}

novaFuncaoDeAnotarNoManipulador (byte, tamanhoByte);
novaFuncaoDeAnotarNoManipulador (ptr , tamanhoPtr );
novaFuncaoDeAnotarNoManipulador (int , tamanhoInt );

//////////////////////////////////////////////////

#endif