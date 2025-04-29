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

#include "math.h"
#include "double.h"

////////////////////////////////////////////////// 
// PROTÓTIPOS

codigo anotar_configuracoes (valor mnp, bool vivo_morto, codigo tipo_dado, codigo modPadrao);
void anotar_string (valor mnp, string str);
valor anotar_int (valor mnp, int t);
valor novo_manipulador (valor val);
double ler_double  (valor mnp);
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

        int quantos_espacos_tab = 4;
        bool chaves_corretas = true;

        codigo cdg  = pegar_modificador (texto);
        byte tipos  = ler_byte (mnp) % 32;
        static bool cabeca = true;
        static int nivel = 1;
        string aux1 = NULL;
        string aux2 = NULL;
        string aux3 = NULL;
        string aux4 = NULL;
        valor Va = NULL;
        valor Vb = NULL;
        valor Vc = NULL;
        double dbl = 0;
        int x = 0;
        int y = 0;
        int z = 0;

        switch (tipos)
        {
            case 3:
                y = ler_int (mnp);
                x = (y == 0) ? 1 : floor (log10 (abs (y))) + 1;
                z = 0;
                
                if (y == 0)
                {
                    malocar (tmp, string, 2);
                
                    tmp [0] = '0';
                    tmp [1] = '\0';
                }
                else
                {
                    int negativo = (y < 0);
                    int tamanho_total = x + negativo + 1;
                
                    malocar (tmp, string, tamanho_total);
                
                    if (negativo)
                    {
                        tmp [z++] = '-';
                        y = -y;
                    }
                
                    // Armazena os dígitos de trás pra frente num buffer temporário
                    char reverso [x];
                    int i = 0;
                
                    while (y > 0)
                    {
                        reverso [i++] = (y % 10) + '0';
                        y /= 10;
                    }
                
                    while (i--)
                    {
                        tmp [z++] = reverso [i];
                    }
                
                    tmp [z] = '\0';
                }            
            break;

            case 4:
                dbl = ler_double (mnp);
                malocar (tmp, string, 32);     
                snprintf (tmp, 32, "%g", dbl);           
            break;

            case 9:
                tmp = ler_string (mnp);
            break;

            case 12:
                Va = ler_valor (mnp);
                aux1  = para_string (Va);
                aux2  = nome    (texto);

                bool textual = false;

                if (pegar_tipo (Va) == 9) textual = true;

                x = tamanhoDaString (aux1);
                y = tamanhoDaString (aux2);

                malocar (tmp, char*, (x + y + 2 + 2 * textual) * tamanhoChar);

                loop (a, y)
                {
                    tmp [z++] = aux2 [a];
                }                

                tmp [z++]     = ':';
                tmp [z++]     = ' ';

                if (textual) tmp [z++] = '\"';
 
                loop (a, x)
                {
                    tmp [z++] = aux1 [a];
                }
                
                if (textual) tmp [z++] = '\"';
                tmp [z++] = '\0';

                limpar (aux1);
                limpar (aux2);
            break;

            case 11:
                malocar (tmp, string, 12); 

                aux4 = "<função>";

                loop (a, 11) tmp [a] = aux4 [a];

                tmp [11] = '\0';
            break;

            case 13: 
                //cabeca = true;

            case 19: // BST TAMBÉM (por hora)
                verificarErro (cdg == codigoRigido || cdg == codigoConstante, "Não implementado!");

                bool holder = cabeca;

                Va = ler_valor (mnp);
                Vb = ler_valor (mnp);
                Vc = ler_valor (mnp);

                cabeca = false;

                if (Vb) { aux2 = para_string (Vb); y = tamanhoDaString (aux2); }
                if (Vc) { aux3 = para_string (Vc); z = tamanhoDaString (aux3); }
                
                codigo tipo = pegar_tipo (acessar (valor, Va, tamanhoByte));

                if (tipo == 13) {cabeca = true; nivel ++;}
                
                if (Va) { aux1 = para_string (Va); x = tamanhoDaString (aux1);}

                //printf ("\n<%d>\nA:%s\nB:%s\nC:%s\n------", pegar_tipo (acessar (valor, Va, tamanhoByte)), aux2, aux1, aux3);

                if (cabeca == true) nivel--;

                //bool c = cabeca;

                cabeca = holder;

                malocar 
                (
                    tmp, 
                    char*, 
                    (
                        x + y + z + 
                        quantos_espacos_tab * 2 * nivel + 
                        2 + 3 + 1 + 
                        chaves_corretas * (quantos_espacos_tab + 1) +
                        4 * (cabeca == true)
                    ) * tamanhoChar
                );

                int cont = 0;
                bool escrita = false;

                if (cabeca)
                {
                    if (chaves_corretas) 
                    {
                        tmp [cont++] = '\n';
                        loop (a, quantos_espacos_tab * (nivel - 1)) {tmp [cont++] = ' ';}
                    }
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

                    loop (a, quantos_espacos_tab * nivel) {tmp [cont++] = ' ';}

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

                    loop (a, quantos_espacos_tab * (nivel - 1)) {tmp [cont++] = ' ';}
                    
                    tmp [cont++] = '}';
                }
                
                tmp [cont++] = '\0';

                if (Va) limpar (aux1);
                if (Vb) limpar (aux2);
                if (Vc) limpar (aux3);
            break;
        
            default:
                verificarErro ((tipos)?tipos:404, "Convertendo tipo estranho para string");
            break;
        }
    
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
// CONSTANTES

valor nL = NULL;

__attribute__ ((constructor)) void construtor_texto () 
{
    noNivel (1) constante nL = novo_texto ("\n");
}

//////////////////////////////////////////////////

#endif