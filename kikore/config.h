#ifndef CONFIG_H
#define CONFIG_H

/** CONFIG_H
 * 
 * Descrição: Aqui estarão o código de criação e manipulação do byte de configuração
 * Data de início: 3/2025
 * 
 */

////////////////////////////////////////////////// 
// BIBLIOTECAS

#include "valor.h"
#include "byte.h"

//////////////////////////////////////////////////
// PROTÓTIPOS

codigo modificadorAtual ();

//////////////////////////////////////////////////
// Valores especiais

const bool  morto      =  true;
const bool  vivo       = false;
codigo codigoConstante =    64;
codigo codigoMaleavel  =    32;
codigo codigoRigido    =    96;
codigo codigoFixado    =     0;
codigo codigoPadrao    =   255;

// Código de Config
codigo codigoConfig = 6;

// O que está sendo usado agora no programa
codigo valorComumDaVariavelDeModificadorAtual = 32; // 32 (árvore de ponteiros)
byte variavelDeModificadorAtual = valorComumDaVariavelDeModificadorAtual; 

// Atualizadores
#define maleavel  variavelDeModificadorAtual =  codigoMaleavel;
#define constante variavelDeModificadorAtual = codigoConstante;
#define rigido    variavelDeModificadorAtual =    codigoRigido;
#define fixado    variavelDeModificadorAtual =    codigoFixado;

////////////////////////////////////////////////// 
// DEFINIÇÃO DO BYTE CONFIG

// Construtor de configuração (NÃO PODE INVOLVER MODIFICADOR ATUAL)
byte nova_configuracao (const bool vivo_morto, codigo tipo_dado, codigo modificador, codigo padrao)
{
    verificarErro 
    (
        (modificador == codigoPadrao) && codigoPadrao == padrao,  
        "Input inexistente nas funcoes de configuracao"
    );

    if (modificador == codigoPadrao)
        return vivo_morto * 128 + padrao + tipo_dado;
    else
        return vivo_morto * 128 + modificador + tipo_dado;
}

//////////////////////////////////////////////////
// FUNÇÕES DA CONFIGURAÇÃO

// Pega o modificador atual e dá reset nele
codigo modificadorAtual ()
{
    byte tmp = variavelDeModificadorAtual;
    variavelDeModificadorAtual = codigoPadrao;

    return tmp;
}

// Pega o modificador atual
codigo pegarModificadorAtual ()
{
    return variavelDeModificadorAtual;
}

// Retorna a configuração de um Valor
byte pegar_configuracao (valor val)
{
    verificarErro (val == NULL, "Input inexistente nas funcoes de configuracao");

    return acessar (byte, val, 0);
}

// Retorna um byte de tipo de um Valor simples
codigo pegar_tipo (valor val)
{
    byte config = pegar_configuracao (val);

    return (config % 32);
}

//////////////////////////////////////////////////

#endif
 