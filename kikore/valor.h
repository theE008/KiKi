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
// Tipos Especiais

// Valor do sistema
typedef byte * valor;
const short tamanhoValor = sizeof (valor);

// Função
typedef valor (* funcao) (valor, ...);
const short tamanhoPtrFuncao = sizeof (funcao);

// Tipo código
typedef const byte codigo;

// Código de Valor Vazio
const byte codigoVazio = 0;

// Garantia que não vai entrar em recursão
bool usadoPelaMemoria = false;

// Para não adicionar na memória uma vez
bool naoSalvarUmaVez = false;

// DEFINE para simplificar
#define naoSalvar naoSalvarUmaVez = true;

////////////////////////////////////////////////// 
// PROTÓTIPOS (necessitam estar abaixo da declaração de valor)

int compararStrings (char* a, char* b);
void registrarNaMemoria (ptr pon);
string para_string (valor texto);
valor novo_texto (string str);
char * nome (valor val);

//////////////////////////////////////////////////
// Construtores

// Construtor vazio (um byte apenas com zeros é um tipo vazio)
valor novo_valor (size_t tam)
{
    valor tmp = NULL;

    // tam += 10; // worth da shot

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

    string sa = para_string (a);
    string sb = para_string (b);

    tmp = compararStrings (sa, sb); // Não é bonito e elegante?

    limpar (sa);
    limpar (sb);

    return tmp;
}

// Duplica o valor
valor duplicar (valor val)
{
    verificarErro (1, "Implementa isso");

    return NULL;
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
/*
int DEBUGAR_VALOR_H ()
{
    valor a = novo_valor (5);

    imprimirBitsAteh (a, 5);

    limpar (a);
}
*/

//////////////////////////////////////////////////

#endif