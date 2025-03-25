#ifndef TEXTO_H
#define TEXTO_H

/** TEXTO_H
 * 
 * Descrição: Basicamente o tipo string em C.
 * Data de início: 3/2025
 * 
 */

////////////////////////////////////////////////// 
// BIBLIOTECAS

#include "GC.h"

//////////////////////////////////////////////////
// Valores especiais

// Código de Texto
const byte codigoTexto = 9;

////////////////////////////////////////////////// 
// Definição de função necessária

// pega o tamanho de uma string
int tamanhoDaString (string entrada)
{
    verificarErro (entrada == NULL, "Texto inexistente");
    bool continuar = true;
    int tamanho = 0;

    while (continuar)
    {
        if (entrada [tamanho++] == '\0') continuar = false;
    }

    return tamanho - 1;
}

////////////////////////////////////////////////// 
// DEFINIÇÃO DO SUBTIPO TEXTO

// Construtor de Texto
valor novo_texto (string str)
{
    verificarErro (str == NULL, "Input inexistente no construtor");

    int tam = tamanhoDaString (str);

    valor tmp = novo_valor (tamanhoByte + tamanhoInt + tam * tamanhoChar);

    valor mnp = novo_manipulador (tmp);

    anotar_configuracoes (mnp, vivo, rigido, codigoTexto);

    anotar_int (mnp, tam);

    anotar_string (mnp, str);

    return tmp;
}

//////////////////////////////////////////////////

#endif