#ifndef GC_H
#define GC_H

/** GC_H
 * 
 * Descrição: Gargabe collector usando uma pilha de memória.
 * Data de início: 3/2025
 * 
 */

////////////////////////////////////////////////// 
// BIBLIOTECAS

#include "memoria.h"

//////////////////////////////////////////////////
// Valores especiais

// Topo da pilha
valor pilhaDeMemoria = NULL;

//////////////////////////////////////////////////
// CONSTRUTOR

// Amarração da pilha
__attribute__ ((constructor)) void construtor_pilhaDeMemoria () 
{
    ptr dummy = malloc (1);
    
    verificarErro (dummy == NULL, "Erro na alocação");

    usadoPelaMemoria = true;

    pilhaDeMemoria = nova_memoria (dummy, NULL, -1);

    usadoPelaMemoria = false;
}

//////////////////////////////////////////////////
// ADDERS

// Adiciona um ponteiro na pilha de memória
void registrarNaMemoria (ptr pon)
{
    verificarErro (pon == NULL, "Ponteiro sendo registrado não existe");

    if (!usadoPelaMemoria)
    {
        usadoPelaMemoria = true;

        codigo cdg = modificadorAtual ();
        valor tmp = nova_memoria (pon, pilhaDeMemoria, nivel);
        variavelDeModificadorAtual = cdg;
    
        pilhaDeMemoria = tmp;
    
        usadoPelaMemoria = false;
    }
}

//////////////////////////////////////////////////
// Expurgador da pilha

// Remove todos os elementos da pilha de memória com um nível acima do nível atual
void limparPilhaDeMemoria ()
{
    valor atual    = pilhaDeMemoria;
    //valor anterior =           NULL;
    bool continuar =           true;

    while (atual != NULL && continuar)
    {
        int nivelNo = acessar (int, atual, tamanhoByte);

        if (nivelNo <= nivel) continuar = false;
        else 
        {
            valor proximo = acessar (valor, atual, tamanhoByte + tamanhoInt + tamanhoPtr);

            limpar (acessar (valor, atual, tamanhoByte + tamanhoInt)); // Limpa para onde a memória acessa

            limpar (atual); // Limpa a memória em si

            atual = proximo;
        }
    }

    pilhaDeMemoria = atual;
}

//////////////////////////////////////////////////
// Definições para embelezamento

// Sobe na pilha
void subirNaPilha ()
{
    nivel ++;
}

// Desce na pilha
void descerNaPilha ()
{
    nivel --;
    limparPilhaDeMemoria ();
}

// Troca as chaves ({}) por algo que faz a mesma coisa + tratamento de memória
#define M {subirNaPilha ();
#define W descerNaPilha ();}

//////////////////////////////////////////////////
// Debug

// Imprime a pilha
void imprimirPilhaDeMemoria () 
{
    valor atual = pilhaDeMemoria;

    printf("\n\n================ PILHA DE MEMÓRIA ================\n");
    while (atual != NULL) 
    {
        int nvl  = acessar (int, atual, tamanhoByte             );
        ptr dado = acessar (ptr, atual, tamanhoByte + tamanhoInt);
        printf("[Nivel: %3d, Ponteiro: %p]\n", nvl, dado);

        atual = acessar (valor, atual, tamanhoByte + tamanhoInt + tamanhoPtr);
    }
    printf(    "==================================================\n");
}

// Função de Debug

/*
int debugar_GC_H ()
{
    
}*/

//////////////////////////////////////////////////

#endif 