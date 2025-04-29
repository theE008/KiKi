#ifndef MATEMATICA_H
#define MATEMATICA_H

/** MATEMATICA_H
 * 
 * Descrição: Primeiro uso da Kiki: Matemática
 * 
 * Data de início: 4/2025
 * 
 */

////////////////////////////////////////////////// 
// BIBLIOTECAS

#include "semantica.h"
#include "GC.h"

//////////////////////////////////////////////////
// INTEGRAL

construirFuncao (integrar)
{
    seTiverArgumento (sub, "Limite inferior")
    {
        seTiverArgumento (sup, "Limite superior")
        {
            seTiverArgumento (func, "Função")
            {
                long long N = 2000000; // 10000000

                double a = para_double (sub);
                double b = para_double (sup);

                double deltaX = (b - a) / N; // Largura que será usada nos retângulos
            
                double soma = 0; // Soma total da área
            
                for (int i = 1; i < N; i ++) // Anda por todo o gráfico
                M
                    double x = a + i * deltaX; // Pega a posição X do termo atual
                
                    valor Vx = novo_double (x);

                    valor Vy = para_funcao (func) (Vx, O);

                    double y = para_double (Vy);
                    
                    soma += y * deltaX; // Base * Altura do retângulo
                W

                resposta = novo_double (soma);
            }
            seNao verificarErro (1, "Argumentos insuficientes");
        }
        seNao verificarErro (1, "Argumentos insuficientes");
    }
    seNao verificarErro (1, "Argumentos insuficientes");
}
construido;

//////////////////////////////////////////////////

#endif