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
// PROTÓTIPOS

codigo anotar_configuracoes (valor mnp, bool vivo_morto, byte tipo_dado);
valor anotar_string (valor mnp, string str);
valor anotar_int (valor mnp, int t);
valor novo_manipulador (valor val);

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
    valor tmp = NULL;

    // constante e rigido são normalmente a implementação comum do texto. Fixado não faz sentido.
    // Texto não vai ter maleável nem nada, muito trabalho cara

    int tam = tamanhoDaString (str);

    tmp = novo_valor (tamanhoByte + tamanhoInt + tam * tamanhoChar);

    naoSalvar valor mnp = novo_manipulador (tmp);

    anotar_configuracoes (mnp, vivo, codigoTexto);

    anotar_int (mnp, tam);

    anotar_string (mnp, str);

    limpar (mnp);
    return tmp;
}

//////////////////////////////////////////////////

#endif