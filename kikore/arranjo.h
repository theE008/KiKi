#ifndef ARRANJO_H
#define ARRANJO_H

/** ARRANJO_H
 * 
 * Descrição: Carrega um vetor de ponteiros para vários valores.
 * Data de início: 3/2025
 * 
 * Um byte de configuração
 * Um byte de configuração de seus elementos (todos DEVERÃO ter o mesmo tipo)
 * Um int de tamanho (quantia de valores)
 * Ponteiros para os valores
 */

////////////////////////////////////////////////// 
// BIBLIOTECAS

#include "GC.h" // Para ir pegando tudo

//////////////////////////////////////////////////
// Valores especiais

// Código de Arranjo
codigo codigoArranjo = 10;

////////////////////////////////////////////////// 
// DEFINIÇÃO DO SUBTIPO ARRANJO

// Construtor de Arranjo
valor novo_arranjo (valor * arr, unsigned int tam)
{
    verificarErro (tam == 0, "Insira um tamanho valido no construtor de arranjos");

    verificarModificador (codigoConstante, "Ainda nao codifiquei constante aqui");
    verificarModificador (codigoRigido, "Ainda nao codifiquei rigido aqui");

    valor tmp = novo_valor (2 * tamanhoByte + tamanhoInt + tam * tamanhoValor);
    naoSalvar valor mnp = novo_manipulador (tmp);

    anotar_configuracoes (mnp, vivo, codigoArranjo, codigoMaleavel);
    anotar_byte (mnp, pegar_configuracao (arr [0]));
    anotar_int (mnp, tam);

    loop (x, tam)
    {
        anotar_valor (mnp, arr [x]);
    }

    limpar (mnp);
    return tmp;
}

//////////////////////////////////////////////////

#endif