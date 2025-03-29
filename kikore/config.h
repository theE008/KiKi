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

#include <stdbool.h> // bool
#include "valor.h"
#include "byte.h"

//////////////////////////////////////////////////
// Valores especiais

const bool  morto     =  true;
const bool  vivo      = false;
const byte codigoMaleavel  =    32;
const byte codigoConstante =    64;
const byte codigoRigido    =    96;

// Código de Config
codigo codigoConfig = 6;

// O que está sendo usado agora no programa?
byte modificadorAtual = 96;

// Atualizadores
#define maleavel  modificadorAtual =  codigoMaleavel;
#define constante modificadorAtual = codigoConstante;
#define rigido    modificadorAtual =   codigoRrigido;

////////////////////////////////////////////////// 
// DEFINIÇÃO DO SUBTIPO CONFIG

// Construtor de configuração
byte nova_configuracao (const bool vivo_morto, const byte modificador, codigo tipo_dado)
{
    return vivo_morto * 128 + modificador + tipo_dado;
}

//////////////////////////////////////////////////
// FUNÇÕES DA CONFIGURAÇÃO

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
