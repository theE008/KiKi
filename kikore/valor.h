#ifndef VALOR_H
#define VALOR_H

/** VALOR_H
 * 
 * Descrição: Aqui estará a declaração do que é um valor, seu tamanho, e um construtor simples
 * Data de início: 3/2025
 * 
 */

////////////////////////////////////////////////// 
// BIBLIOTECAS

#include "config.h"

#include "byte.h"    // para byte
#include "GC.h"      // para registrarNaMemoria

//////////////////////////////////////////////////
// Tipos Especiais

// Valor do sistema
typedef byte * valor;
const short tamanhoValor = sizeof (valor);

// Tipo código
typedef const byte codigo;

// Função
typedef valor (* funcao) (valor, ...);
const short tamanhoFuncao = sizeof (funcao);

// Código de Valor Vazio
const byte codigoVazio = 0;

// Garantia que não vai entrar em recursão
bool usadoPelaMemoria = false;

// Para não adicionar na memória uma vez
bool naoSalvarUmaVez = false;

// DEFINE para simplificar
#define naoSalvar naoSalvarUmaVez = true;

////////////////////////////////////////////////// 
// PROTÓTIPOS (necessitam estar abaixo da declaração de valor)

int compararStrings (char* a, char* b);
void registrarNaMemoria (ptr pon);
string para_string (valor texto);
valor novo_texto (string str);
char * nome (valor val);

//////////////////////////////////////////////////
// Construtores

// Construtor vazio (um byte apenas com zeros é um tipo vazio)
valor novo_valor (size_t tam)
{
    valor tmp = NULL;

    malocar (tmp, valor, tam);

    loop (x, tam) * (tmp + x) = 255; // 255 para teste

    if (naoSalvarUmaVez) naoSalvarUmaVez = false;
    else
    if (!usadoPelaMemoria) registrarNaMemoria (tmp);

    return tmp;
}

//////////////////////////////////////////////////
// Funções gerais

// Compara valores de vários subtipos
int comparar (valor a, valor b)
{
    verificarErro (a == NULL, "Valor A inexistente no comparar");
    verificarErro (b == NULL, "Valor B inexistente no comparar");
    int tmp = 0;

    codigo cfg_a = acessar (byte, a, 0) % 32;
    codigo cfg_b = acessar (byte, b, 0) % 32;

    if (cfg_a == 9) // se for string
    {
        if (cfg_b == 9) // se ambos forem string
        {
            string str1 = para_string (a); // Implementar um compararTexto e apagar o compararStrings
            string str2 = para_string (b); // Complexidade desnecessária e fora do tema da biblioteca

            tmp = compararStrings (str1, str2); // agora uma função de texto -> string

            limpar (str1);
            limpar (str2); //🔥🔥🔥 ESCUTA AQUI, NÃO ESQUEÇA DE LER ISSO, IMPORTANTE! 🔥🔥🔥🔥🔥🔥
        }                  //🔥🔥🔥🔥 CONSTRUA O TOSTRING ANTES DE CONTINUAR ESSA FUNÇÃO! ELE VAI SER
    }                      //🔥🔥🔥🔥🔥 ESSENCIAL PRA ISSO FICAR SIMPLE STUPID!!! 🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥
    else if (cfg_a == 12) // se for campo
    {
        if (cfg_b == 12) // se ambos forem campos
        {
            // campo varia, eu REALMENTE DEVERIA deixar esse conceito descansar um pouco
            string str1 = nome (a);
            string str2 = nome (b);
            
            tmp = comparar (novo_texto (str1), novo_texto (str2)); 
            // ISSO TÁ ERRADO E RUIM EM TANTOS NÍVEIS!

            // Motivos de porque isso tá horrível:
            // 1 - a função nome não retorna texto, retorna string! não é um valor que a biblioteca trata
            // 2 - é recursivo, então eu uso o outro sistema de comparação dessa mesma função, mas o outro sistema TAMBÉM é ineficiente!
            // 3 - para a função aceitar os valores, eles ainda precisam serem tornados em textos! 

            limpar (str1);
            limpar (str2);

            // Funções de dentro das classes para fazer tudo por mim, e aí eu só uso, parece ser way2go
        }
    }

    // que os deuses da computação me perdoem, Turing deve estar decepcionado comigo agora
    // Não senhor Turing, não passei no recaptcha u-u

    return tmp;
}

//////////////////////////////////////////////////
// Imprimir

// Imprime bit a bit
valor imprimirBitsAteh (valor val, size_t tam)
{
    verificarErro (val == NULL, "Valor inexistente");

    loop (i, tam)
    {
        for (int j = 7; j >= 0; j--)
        {
            printf ("%d", (val[i] >> j) & 1);
        }
        
        printf (" ");
    }
    printf ("\n");

    return val;
}

//////////////////////////////////////////////////
// DEBUG

// Testar a biblioteca
int DEBUGAR_VALOR_H ()
{
    valor a = novo_valor (5);

    imprimirBitsAteh (a, 5);

    limpar (a);
}

//////////////////////////////////////////////////

#endif