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

#include <stdlib.h> //   exit
#include <stdio.h>  // printf

//////////////////////////////////////////////////
// COMPATIBILIDADE

#ifndef __func__
#define __func__ "<funcao_desconhecida>"
#endif

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

     if (val) // detector de erro
        printf (VERMELHO "\n\n\tPROGRAMA FINALIZADO COM ERRO CODIGO '%d'\n\t%s\n\n" RESETAR, val, (men != NULL)? men: ""); 
     
    printf 
    ( VERDE
        "\n\n\t%s\n\t%s '%d' %s\n\n\t'%ld' %s\n\t'%ld' %s\n" RESETAR, 
        "FIM DO PROGRAMA", "Finalizado com um total de", 
        alocacoes_feitas, "alocacoes feitas", memoria_usada, "memoria usada", limpezas_feitas, "limpezas feitas"
    );

    printf ("\n");

    exit (val);
}

//////////////////////////////////////////////////
// Análise de erros

/**
 * Descrição: Finaliza o programa se um erro for percebido.
*/   
void VERIFY_ERROR (const string mensagem, string arquivo, const string funcao, int erro, int linha)
{
    if (erro)
    {
        printf 
        ( VERMELHO
            "\n\n\tERRO NO ARQUIVO: %s\n\tDA FUNCAO: %s\n\tNA LINHA : %d\n\n" RESETAR, 
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
do {verificarErro (ptr == NULL, "Limpando ponteiro nulo"); limpezas_feitas ++; free (ptr);} while (0)

//////////////////////////////////////////////////
// LOOPS

// Estrutura de repetição mais simples que o FOR
#define loop(var,val) for (int var = 0, continuar = 1; var < val && continuar; var++)
#define fimDoLoop continuar = 0;

//////////////////////////////////////////////////
// MACRO DE ACESSO

// deixa o acesso mais alto nível
#define acessar(tipo,val,indice) * ((tipo *) val + indice)  

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
#define verificarErro(erro,msg) VERIFY_ERROR (msg, __FILE__, __func__, erro, __LINE__);

/**
 * Descrição: Uma forma mais enxuta do verificarErro, focada em subtipos.
*/  
#define verificarSubtipo(val,codSubtipo) \
verificarErro (val == NULL, "Input inexistente"); \
byte tipo = pegar_tipo (val); \
verificarErro (tipo != codSubtipo, "Valor recebido incompativel com a funcao");

// Função de Debug
int debugar_NUCLEO_H ()
{
    printf ("Iniciando testes da biblioteca NUCLEO_H...\n");

    // Teste de alocação de memória
    string teste_string;
    malocar (teste_string, string, (50 * tamanhoChar));
    snprintf (teste_string, 50, "Teste de alocacao de memoria");
    printf ("String alocada: %s\n", teste_string);

    // Teste de acesso por macro
    acessar (char, teste_string, 5) = 'X';
    printf ("String modificada: %s\n", teste_string);

    // Teste de limpeza de memória
    limpar (teste_string);
    printf ("Memoria liberada com sucesso.\n");

    DEBUGLINE_DEBUGLINE_DEBUGLINE_DEBUGLINE_DEBUGLINE;

    loop (x, 100)
    {
        printf ("loop %d\n", x);

        if (x == 50) fimDoLoop;
    }

    // Teste de verificação de erro
    int erro_teste = 1;
    verificarErro (erro_teste, "Erro simulado para teste.");

    // Teste de finalização (comentado para evitar saída prematura)
    // finalizar (0, "Testes concluídos com sucesso!");

    return 0;
}

//////////////////////////////////////////////////

#endif 