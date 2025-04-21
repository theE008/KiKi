#ifndef TEXTO_H
#define TEXTO_H

/** TEXTO_H
 * 
 * Descrição: Basicamente o tipo string em C.
 * Data de início: 3/2025
 * 
 */

////////////////////////////////////////////////// 
// BIBLIOTECAS

#include "GC.h"

////////////////////////////////////////////////// 
// PROTÓTIPOS

codigo anotar_configuracoes (valor mnp, bool vivo_morto, codigo tipo_dado, codigo modPadrao);
valor anotar_string (valor mnp, string str);
valor anotar_int (valor mnp, int t);
valor novo_manipulador (valor val);
char* ler_string (valor mnp);
valor ler_valor  (valor mnp);
byte ler_byte (valor mnp);
char ler_char (valor mnp);
int  ler_int  (valor mnp);

//////////////////////////////////////////////////
// Valores especiais

// Código de Texto
const byte codigoTexto = 9;

////////////////////////////////////////////////// 
// Definição de função necessária

// pega o tamanho de uma string
int tamanhoDaString (string entrada)
{
    verificarErro (entrada == NULL, "Texto inexistente");
    bool continuar = true;
    int tamanho = 0;

    while (continuar)
    {
        if (entrada [tamanho++] == '\0') continuar = false;
    }

    return tamanho - 1;
}

// Compara duas strings lexicograficamente
int compararStrings (char* a, char* b) 
{
    while (*a && *b && *a == *b) 
    {
        a++;
        b++;
    }
    
    return (unsigned char)(*b) - (unsigned char)(*a); // negativo, a é maior
}


////////////////////////////////////////////////// 
// DEFINIÇÃO DO SUBTIPO TEXTO

// Construtor de Texto
valor novo_texto (string str)
{
    verificarErro (str == NULL, "Input inexistente no construtor");
    valor tmp = NULL;

    // constante e rigido são normalmente a implementação comum do texto. Fixado não faz sentido.
    // Texto não vai ter maleável nem nada, muito trabalho cara

    int tam = tamanhoDaString (str);

    tmp = novo_valor (tamanhoByte + tamanhoInt + tam * tamanhoChar);

    naoSalvar valor mnp = novo_manipulador (tmp);

    anotar_configuracoes (mnp, vivo, codigoTexto, codigoRigido);

    anotar_int (mnp, tam);

    anotar_string (mnp, str);

    limpar (mnp);
    return tmp;
}

//////////////////////////////////////////////////
// CONVERSÕES

// valor -> string
string para_string (valor texto)
{
    // verificarSubtipo (texto, codigoTexto);
    string tmp = NULL;

    if (texto == NULL)
    {
        malocar (tmp, char*, 8);
        char * aux = "#vazio";

        loop (z, 7) tmp [z] = aux [z];

        tmp [7] = '\0';        

        return tmp;
    }
    else
    {
        naoSalvar valor mnp = novo_manipulador (texto);

        codigo cdg  = pegar_modificador (texto);
        byte tipo   = ler_byte (mnp) % 32;
        static bool cabeca = true;
        string aux1 = NULL;
        string aux2 = NULL;
        string aux3 = NULL;
        valor Va = NULL;
        valor Vb = NULL;
        valor Vc = NULL;
        int x = 0;
        int y = 0;
        int z = 0;

        switch (tipo)
        {
            case 9:
                tmp = ler_string (mnp);
            break;

            case 12:
                aux1  = para_string (ler_valor (mnp));
                aux2  = nome    (texto);

                x = tamanhoDaString (aux1);
                y = tamanhoDaString (aux2);

                malocar (tmp, char*, (x + y + 2) * tamanhoChar);

                loop (a, y)
                {
                    tmp [a] = aux2 [a];
                }                

                tmp [y]     = ':';
                tmp [y + 1] = ' ';

                loop (a, x)
                {
                    tmp [a + y + 2] = aux1 [a];
                }
                tmp [x + y + 2] = '\0';

                limpar (aux1);
                limpar (aux2);
            break;

            case 13: 
                cabeca = true;

            case 19: // BST TAMBÉM (por hora)
                verificarErro (cdg == codigoRigido || cdg == codigoConstante, "Não implementado!");


                bool holder = cabeca;

                Va = ler_valor (mnp);
                Vb = ler_valor (mnp);
                Vc = ler_valor (mnp);

                cabeca = false;

                if (Va) { aux1 = para_string (Va); x = tamanhoDaString (aux1); }
                if (Vb) { aux2 = para_string (Vb); y = tamanhoDaString (aux2); }
                if (Vc) { aux3 = para_string (Vc); z = tamanhoDaString (aux3); }

                cabeca = holder;

                malocar (tmp, char*, (x + y + z + 2 + 3 + 3 + 1 + 4 * (cabeca == true)) * tamanhoChar);

                int cont = 0;
                bool escrita = false;

                if (cabeca)
                {
                    tmp [cont++] = '{';
                    tmp [cont++] = '\n';
                }

                if (Vb)
                {
                    //tmp [cont++] = '\t';

                    loop (a, y)
                    {
                        tmp [cont++] = aux2 [a];
                    }

                    escrita = true;
                }

                if (Va)
                {
                    if (escrita == true) {tmp [cont++] = ','; tmp [cont++] = '\n';}
                    tmp [cont++] = '\t';

                    loop (a, x)
                    {
                        tmp [cont++] = aux1 [a];
                    }

                    escrita = true;
                }

                if (Vc)
                {
                    if (escrita == true) {tmp [cont++] = ','; tmp [cont++] = '\n';}
                    //tmp [cont++] = '\t';

                    loop (a, z)
                    {
                        tmp [cont++] = aux3 [a];
                    }
                }

                if (cabeca)
                {
                    tmp [cont++] = '\n';
                    tmp [cont++] = '}';
                }
                
                tmp [cont++] = '\0';

                if (Va) limpar (aux1);
                if (Vb) limpar (aux2);
                if (Vc) limpar (aux3);
            break;
        
            default:
                verificarErro ((tipo)?tipo:404, "Convertendo tipo estranho para string");
            break;
        }

        /*
        int tam = ler_int (mnp);

        malocar (tmp, string, tam); // não coloquei + 1
    
        loop (x, tam)
        {
            tmp [x] = ler_char (mnp);
        }
    
        tmp [tam] = '\0';
        */
    
        limpar (mnp);
        return tmp;
    }
}

// Valor -> Texto
valor para_Texto (valor val)
{
    valor aux = NULL;
 
    if (pegar_tipo (val) != codigoTexto)
    {
        string tmp = para_string (val);

        aux = novo_texto (tmp);

        limpar (tmp);
    }
    else 
    {
        verificarErro (1, "Para isso funcionar, crie a funcao de duplicar");
        // Para retornar uma cópia do valor original, não usa-lo
    }

    return aux;
}

// Imprimir 
string imprimirValorUnico (valor val)
{
    string tmp = para_string (val);

    printf ("%s", tmp); 

    registrarNaMemoria (tmp);

    return tmp;
}

void imprimir (valor argumentos, ...)
{
    va_list args;
    va_start (args, argumentos);

    valor atual = argumentos;

    while (atual != NULL)
    {
        string tmp = para_string (atual);

        printf ("%s", tmp);

        limpar (tmp); // limpar se não for usar depois

        atual = va_arg (args, valor);
    }

    va_end (args);
}

//////////////////////////////////////////////////

#endif