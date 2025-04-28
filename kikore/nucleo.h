#ifndef NUCLEO_H
#define NUCLEO_H

/** NÚCLEO_H
 * 
 * Descrição: Aqui estarão as funções gerais usadas para finalizar o programa / tratar erros
 * Data de início: 3/2025
 * 
 */

////////////////////////////////////////////////// 
// BIBLIOTECAS

#include <stdbool.h> // bool
#include <stdlib.h> //  exit
#include <stdio.h>  //  printf

#include "GC.h" // para limpar a pilha

#include <stdarg.h> // para vários argumentos

//////////////////////////////////////////////////
// Valores Especiais

// Contador de nível
int nivel = 0;

//////////////////////////////////////////////////
// PROTÓTIPOS

void imprimirPilhaDeMemoria ();
void limparPilhaDeMemoria ();

//////////////////////////////////////////////////
// COMPATIBILIDADE

//#ifndef __func__
//#define __func__ "<funcao_desconhecida>"
//#endif

//////////////////////////////////////////////////
// CORES PARA O TERMINAL

#define VERMELHO   "\033[1;31m"
#define VERDE      "\033[1;32m"
#define RESETAR    "\033[0m"
 
//////////////////////////////////////////////////
// Tipos Especiais

// String simples
typedef char * string;
short tamanhoString = sizeof (string);

// Ponteiro
typedef void * ptr;
short tamanhoPtr = sizeof (ptr);

// Char
short tamanhoChar = sizeof (char);

// Int
short tamanhoInt = sizeof (int);

// Double
short tamanhoDouble = sizeof (double);

//////////////////////////////////////////////////
// Contadores Globais

// Mallocs feitos
long alocacoes_feitas = 0;

// Memória sendo usada atualmente (em bytes)
long memoria_usada = 0;

// Frees feitos
long limpezas_feitas = 0;

//////////////////////////////////////////////////
// Finalizadores

/**
 * Descrição: Finaliza o programa com um código.
*/       
void finalizar (int val, string men)
{
    imprimirPilhaDeMemoria ();

     if (val) // detector de erro
        printf (VERMELHO "\n\n\tPROGRAMA FINALIZADO COM ERRO CÓDIGO '%d'\n\t%s\n\n" RESETAR, val, (men != NULL)? men: ""); 
     
    printf 
    ( VERDE
        "\n\n\t%s\n\t%s '%ld' %s\n\n\t'%ld' %s\n\t'%ld' %s\n" RESETAR, 
        "FIM DO PROGRAMA", "Finalizado com um total de", 
        memoria_usada - 34, "memória usada",
        alocacoes_feitas - 2, "alocações feitas", 
        limpezas_feitas - 1, "limpezas feitas"
    );

    nivel = INT_MIN;

    limparPilhaDeMemoria ();

    // imprimirPilhaDeMemoria ();

    printf ("\nEXIT\n\n");

    exit (val);
}

//////////////////////////////////////////////////
// Análise de erros

/**
 * Descrição: Finaliza o programa se um erro for percebido.
*/   
void VERIFY_ERROR (const string mensagem, string arquivo, const char * funcao, int erro, int linha)
{
    if (erro)
    {   
        printf 
        ( VERMELHO
            "\n\n\tERRO NO ARQUIVO: %s\n\tDA FUNÇÃO: %s\n\tNA LINHA : %d\n\n" RESETAR, 
            arquivo,
            funcao,
            linha
        );

        finalizar (erro, mensagem);
    }
}

//////////////////////////////////////////////////
// MEMÓRIA

// Malloca, registra e verifica
#define malocar(ptr,tipo,tam) \
do { ptr = (tipo) malloc(tam); \
    alocacoes_feitas ++; \
    verificarErro (ptr == NULL, "Malloc fracassado"); \
    memoria_usada += tam; }\
    while (0);

// Verifica, registra e limpa
#define limpar(ptr) \
do {verificarErro (ptr == NULL, "Limpando ponteiro nulo"); limpezas_feitas ++; free (ptr); ptr = NULL;} while (0)

//////////////////////////////////////////////////
// LOOPS

// Estrutura de repetição mais simples que o FOR
#define loop(var,val) for (int var = 0, continuar = 1; var < val && continuar; var++)
#define fimDoLoop continuar = 0;

//////////////////////////////////////////////////
// MACRO DE ACESSO

// deixa o acesso mais alto nível
#define acessar(tipo,val,indice) * ((tipo *) ((unsigned char*) val + indice))

//////////////////////////////////////////////////
// Debug

/**
 * Descrição: Uma linha de DEBUG que ajuda a identificar erros no código. 
 * Fácil de ver após debugar e fácil de limpar.
*/ 
#define DEBUGLINE_DEBUGLINE_DEBUGLINE_DEBUGLINE_DEBUGLINE \
printf ("\n\tlinha %d\n", __LINE__);

/**
 * Descrição: Uma forma mais enxuta do VERIFY_ERROR, tendo apenas um valor 
 * como condição. Se o valor for verdadeiro, a função dispara um erro.
*/  
#define verificarErro(erro,msg) VERIFY_ERROR (msg, __FILE__, __func__, erro, __LINE__)

/**
 * Descrição: Uma forma mais enxuta do verificarErro, focada em subtipos.
*/  
#define verificarSubtipo(val,codSubtipo) \
do {verificarErro (val == NULL, "Input inexistente"); \
byte tipo = pegar_tipo (val); \
verificarErro (tipo * (tipo != codSubtipo), "Valor recebido incompativel com a função"); } while (0)

#define verificarModificador(naoPodeSer,porque) \
if (modificadorAtual () == naoPodeSer) {verificarErro (naoPodeSer, porque);}

// Para finalizar funções do jeito correto
#define O ((void *)0)

//////////////////////////////////////////////////

#endif 