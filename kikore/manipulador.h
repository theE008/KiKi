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

#include "config.h"
#include "texto.h"
#include "valor.h"
#include "GC.h"

//////////////////////////////////////////////////
// PROTÓTIPOS

void imprimirPilhaDeMemoria ();

//////////////////////////////////////////////////
// Valores especiais

// Código de Manipulador
const byte codigoManipulador = 8;

// Tamanho de Manipulador
const byte tamanhoManipulador = sizeof (byte) + sizeof (int) + sizeof (valor); // 13

////////////////////////////////////////////////// 
// DEFINIÇÃO DO SUBTIPO MANIPULADOR

// Construtor de Manipuladorz
valor novo_manipulador (valor val)
{
    verificarErro (val == NULL, "Input inexistente no construtor");

    // Manipulador não se importa com modificadores, iria dar um imenso trabalho

    valor tmp = novo_valor (tamanhoManipulador);   

    acessar (byte, tmp, 0) = nova_configuracao 
    (
        vivo, codigoManipulador, codigoRigido
    );
    acessar (int, tmp, tamanhoByte) = 0; // Indice
    acessar (valor, tmp, tamanhoByte + tamanhoInt) = val;

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
#define novaFuncaoDeAnotarELerNoManipulador(tipo,tamanho) \
valor anotar_##tipo (valor mnp, tipo t) \
{ \
    verificarSubtipo (mnp, codigoManipulador); \
    int x = usar_indice (mnp, tamanho); \
    valor val = pegar_valor (mnp); \
    acessar (tipo, val, x) = t; \
    return mnp; \
} \
tipo ler_##tipo (valor mnp) \
{                           \
    verificarSubtipo    (mnp, codigoManipulador); \
    int x = usar_indice (mnp,           tamanho); \
    valor val = pegar_valor (mnp); \
    return acessar (tipo, val, x); \
}

novaFuncaoDeAnotarELerNoManipulador (valor , tamanhoValor );
novaFuncaoDeAnotarELerNoManipulador (byte  , tamanhoByte  );
novaFuncaoDeAnotarELerNoManipulador (char  , tamanhoChar  );
novaFuncaoDeAnotarELerNoManipulador (ptr   , tamanhoPtr   );
novaFuncaoDeAnotarELerNoManipulador (int   , tamanhoInt   );

// Anota as configurações
codigo anotar_configuracoes (valor mnp, bool vivo_morto, codigo tipo_dado, codigo modPadrao)
{
    anotar_byte (mnp, nova_configuracao (vivo_morto, tipo_dado, modPadrao));

    return modPadrao;
}

// Anota string
valor anotar_string (valor mnp, string str)
{
    verificarSubtipo (mnp, codigoManipulador);
    verificarErro (str == NULL, "String invalida");

    int x = pegar_indice (mnp);

    valor val = pegar_valor     (mnp);
    int   tam = tamanhoDaString (str);

    loop (z, tam)
    {
        acessar (char, val, x + z * tamanhoChar) = str [z];
    }

    mudar_indice (mnp, x + tam * tamanhoChar);
}

//////////////////////////////////////////////////
// DEBUG

// Função de teste
int DEBUGAR_MANIPULADOR_H ()
{
    //valor a = novo_valor (10);
    //valor b = novo_manipulador (a);

    //imprimirBitsAteh (b, tamanhoManipulador);
}

//////////////////////////////////////////////////

#endif