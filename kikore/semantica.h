#ifndef SEMANTICA_H
#define SEMANTICA_H

/** SEMANTICA_H
 * 
 * Descrição: Define o escopo geral da semântica que quero na biblioteca
 * 
 * Data de início: 4/2025
 * 
 */

////////////////////////////////////////////////// 
// BIBLIOTECAS

#include "complexo.h"

//////////////////////////////////////////////////
// SEMÂNTICA

////////////////// GERAL
#define naoExistir == NULL 
#define forDiferente !=
#define existir != NULL
#define ouSe else if 
#define forIgual == 
#define seNao else 
#define nao !
#define se if
#define ou ||
#define e &&

// Já que existe o GC, não acho que deveria importar se tem retorno ou não.
// (A não ser que se por eficiência, algo que não consegui fazer.)

// Construtor geral
#define construtor(o_a, que) \
valor nov##o_a##_##que (valor argumentos, ...) \
{ \
    va_list args; \
    va_start (args, argumentos); \
    valor resposta = novo_complexo (novo_campo ("Tipo", novo_texto (#que))); \
    do \
    {

// Faz funções no sistema da biblioteca
#define construirFuncao(nome) \
valor nome (valor argumentos, ...) \
{ \
    va_list args; \
    va_start (args, argumentos); \
    valor resposta = novo_complexo (novo_campo ("Tipo", novo_texto ("Resposta"))); \
    do \
    {

// fazem o que o nome sugere
#define adicionarTextoNaResposta(nome,texto) adicionar (resposta, novo_campo (nome, novo_texto (texto)));
#define adicionarNaResposta(nome,val) adicionar (resposta, novo_campo (nome, val));

// Se tiver o argumento nome, jogue ele em var e entre no bloco se ele existir.
#define seTiverArgumento(var,nome) valor var = NULL; \
if (argumentos) var = pegar (argumentos, nome); if (var)

// Se tiver tal campo na resposta
#define seTiverNaResposta(var,nome) valor var = NULL; \
if (resposta) var = pegar (resposta, nome); if (var)

// Retorna a resposta
#define construido \
        if (argumentos != NULL) argumentos = va_arg (args, valor); \
    } while (argumentos != NULL); \
    return resposta; \
}

//////////////////////////////////////////////////

#endif