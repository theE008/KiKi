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

#include "config.h"

#include "byte.h"    // para byte
#include "GC.h"      // para registrarNaMemoria

////////////////////////////////////////////////// 
// PROTÓTIPOS

int compararStrings (char* a, char* b);
void registrarNaMemoria (ptr pon);

//////////////////////////////////////////////////
// Tipos Especiais

// Valor do sistema
typedef byte * valor;
const short tamanhoValor = sizeof (valor);

// Tipo código
typedef const byte codigo;

// Função
typedef valor (* funcao) (valor, ...);
const short tamanhoFuncao = sizeof (funcao);

// Código de Valor Vazio
const byte codigoVazio = 0;

// Garantia que não vai entrar em recursão
bool usadoPelaMemoria = false;

// Para não adicionar na memória uma vez
bool naoSalvarUmaVez = false;

// DEFINE para simplificar
#define naoSalvar naoSalvarUmaVez = true;

//////////////////////////////////////////////////
// Construtores

// Construtor vazio (um byte apenas com zeros é um tipo vazio)
valor novo_valor (size_t tam)
{
    valor tmp = NULL;

    malocar (tmp, valor, tam);

    loop (x, tam) * (tmp + x) = 255; // 255 para teste

    if (naoSalvarUmaVez) naoSalvarUmaVez = false;
    else
    if (!usadoPelaMemoria) registrarNaMemoria (tmp);

    return tmp;
}

//////////////////////////////////////////////////
// Funções gerais

// Compara valores de vários subtipos
int comparar (valor a, valor b)
{
    verificarErro (a == NULL, "Valor A inexistente no comparar");
    verificarErro (b == NULL, "Valor B inexistente no comparar");
    int tmp = 0;

    codigo cfg_a = acessar (byte, a, 0) % 32;
    codigo cfg_b = acessar (byte, b, 0) % 32;

    if (cfg_a == 9)
    {
        if (cfg_b == 9)
        {
            tmp = compararStrings (); // agora uma função de texto -> string
        }
    }

    return 0;
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