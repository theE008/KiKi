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

#include <stdbool.h> // para bool
#include "byte.h"    // para byte
#include "GC.h"      // para registrarNaMemoria

////////////////////////////////////////////////// 
// PROTÓTIPOS

void registrarNaMemoria (ptr pon);

//////////////////////////////////////////////////
// Tipos Especiais

// Valor do sistema
typedef byte * valor;
const short tamanhoValor = sizeof (valor);

// Função
typedef valor (* funcao) (valor, ...);
const short tamanhoFuncao = sizeof (funcao);

// Código de Valor Vazio
const byte codigoVazio = 0;

// Garantia que não vai entrar em recursão
bool usadoPelaMemoria = false;

//////////////////////////////////////////////////
// Construtores

// Construtor vazio (um byte apenas com zeros é um tipo vazio)
valor novo_valor (size_t tam)
{
    valor tmp = NULL;

    malocar (tmp, valor, tam);

    loop (x, tam) * (tmp + x) = 255; // 255 para teste

    if (!usadoPelaMemoria) registrarNaMemoria (tmp);

    return tmp;
}

//////////////////////////////////////////////////
// Imprimir

// Imprime bit a bit
valor imprimirBitsAteh (valor val, size_t tam)
{
    verificarErro (val == NULL, "Valor inexistente");

    loop (i, tam)
    {
        for (int j = 7; j >= 0; j--)
        {
            printf ("%d", (val[i] >> j) & 1);
        }
        
        printf (" ");
    }
    printf ("\n");

    return val;
}

//////////////////////////////////////////////////
// DEBUG

// Testar a biblioteca
int DEBUGAR_VALOR_H ()
{
    valor a = novo_valor (5);

    imprimirBitsAteh (a, 5);

    limpar (a);
}

//////////////////////////////////////////////////

#endif