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

#include "GC.h"

#include "manipulador.h"
#include "texto.h"

//////////////////////////////////////////////////
// Valores especiais

// Tamanho
const short tamanhoCampo = tamanhoByte + 2 * tamanhoValor;

// Código de Campo
const byte codigoCampo = 12;

////////////////////////////////////////////////// 
// DEFINIÇÃO DO SUBTIPO CAMPO

// Construtor de Campo
valor novo_campo (string nome, valor val)
{
    verificarErro (nome == NULL, "String invalida");
    verificarErro (val  == NULL, "Valor invalido" );

    valor tmp = novo_valor (tamanhoCampo);
    naoSalvar valor mnp = novo_manipulador (tmp);
    valor txt = novo_texto (nome);
    
    anotar_configuracoes (mnp, vivo, modificadorAtual, codigoCampo);
    anotar_valor  (mnp,  txt);
    anotar_valor  (mnp,  val);

    limpar (mnp);
    
    return tmp;
}

//////////////////////////////////////////////////

#endif