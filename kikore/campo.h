#ifndef CAMPO_H
#define CAMPO_H

/** CAMPO_H
 * 
 * Descrição: Carrega um ponteiro e o nome daquilo que aponta.
 * Data de início: 3/2025
 * 
 */

////////////////////////////////////////////////// 
// BIBLIOTECAS

#include "manipulador.h"

//////////////////////////////////////////////////
// Valores especiais

// Código de Campo
const byte codigoCampo = 12;

////////////////////////////////////////////////// 
// DEFINIÇÃO DO SUBTIPO CAMPO

// Construtor de Campo
valor novo_campo (string nome, valor val)
{
    verificarErro (nome == NULL, "String invalida");
    verificarErro (val  == NULL, "Valor invalido" );

    int tam = tamanhoDaString (nome);

    valor tmp = novo_valor (tamanhoByte + tamanhoValor + tamanhoInt + tam * tamanhoChar);

    valor mnp = novo_manipulador (tmp);

    anotar_configuracoes (mnp, vivo, rigido, codigoCampo);
    anotar_valor  (mnp,  val);
    anotar_int    (mnp,  tam);
    anotar_string (mnp, nome);
    
}

//////////////////////////////////////////////////

#endif