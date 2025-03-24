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
const byte maleavel  =    32;
const byte constante =    64;
const byte rigido    =    96;

// Código de Byte
const byte codigoVazio = 6;

////////////////////////////////////////////////// 
// DEFINIÇÃO DO SUBTIPO CONFIG

// Construtor de configuração
byte nova_configuracao (const bool vivo_morto, const byte modificador, const byte tipo_dado)
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
byte pegar_tipo (valor val)
{
    byte config = pegar_configuracao (val);

    return (config % 64);
}

//////////////////////////////////////////////////

#endif
