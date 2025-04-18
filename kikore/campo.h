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
const short tamanhoCampo = tamanhoByte + 2 * tamanhoValor; // quando maleável

// Código de Campo
const byte codigoCampo = 12;

////////////////////////////////////////////////// 
// DEFINIÇÃO DO SUBTIPO CAMPO

// Construtor de Campo
valor novo_campo (string nome, valor val)
{
    verificarErro (nome == NULL, "String invalida");
    verificarErro (val  == NULL, "Valor invalido" );

    valor tmp = NULL;

    codigo mod = pegarModificadorAtual ();

    if (mod == codigoMaleavel || mod == codigoFixado)
    {
        tmp = novo_valor (tamanhoCampo);
        naoSalvar valor mnp = novo_manipulador (tmp);
        anotar_configuracoes (mnp, vivo, codigoCampo, codigoMaleavel); // ANOTE AS CONFIGURAÇÕES ANTES DE QUALQUER COISA
        valor txt = novo_texto (nome);
        anotar_valor  (mnp,  val); // Val primeiro para sintonizar com o de baixo
        anotar_valor  (mnp,  txt);
    
        limpar (mnp);
    }
    else 
    {
        int tam = tamanhoDaString (nome);

        tmp = novo_valor (tamanhoByte + tamanhoValor + tamanhoInt + tam * tamanhoChar);
        naoSalvar valor mnp = novo_manipulador (tmp);
        anotar_configuracoes (mnp, vivo, codigoCampo, codigoRigido);
        anotar_valor (mnp, val); // Eu deveria mudar isso????
        anotar_int (mnp, tam);
        anotar_string (mnp, nome);

        limpar (mnp);
    }
    
    return tmp;
}

//////////////////////////////////////////////////

#endif