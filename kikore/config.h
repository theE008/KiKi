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
// Valores especiais

const bool  morto     =  true;
const bool  vivo      = false;
codigo codigoMaleavel  =    32;
codigo codigoConstante =    64;
codigo codigoRigido    =    96;
codigo codigoFixado    =     0;

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
// DEFINIÇÃO DO SUBTIPO CONFIG

// Construtor de configuração
byte nova_configuracao (const bool vivo_morto, codigo modificador, codigo tipo_dado)
{
    return vivo_morto * 128 + modificador + tipo_dado;
}

//////////////////////////////////////////////////
// FUNÇÕES DA CONFIGURAÇÃO

// Pega o modificador atual e dá reset nele
codigo modificadorAtual ()
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
 