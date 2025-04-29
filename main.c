#include "kikore/arranjo.h"
#include "kikore/campo.h"
#include "kikore/BST.h"
#include "kikore/semantica.h"
#include "kikore/double.h"

construirFuncao (f)
{
    seTiverArgumento (Vx, "x")
    {
        double x = para_double (Vx);

        resposta = novo_double (x * x);
    }
}
construido;

construirFuncao (integrar)
{
    seTiverArgumento (sub, "Limite inferior")
    {
        seTiverArgumento (sup, "Limite superior")
        {
            seTiverArgumento (func, "Função")
            {
                long long N = 100000000; // 10000000

                double a = para_double (sub);
                double b = para_double (sup);

                double deltaX = (b - a) / N; // Largura que será usada nos retângulos
            
                double soma = 0; // Soma total da área
            
                for (int i = 1; i < N; i ++) // Anda por todo o gráfico
                {
                    double x = a + i * deltaX; // Pega a posição X do termo atual
                    
                    soma += *(para_funcao (func)) (novo_double (x), O) * deltaX; 
                    // Base * Altura do retângulo
                }
            }
            seNao verificarErro (1, "Argumentos insuficientes");
        }
        seNao verificarErro (1, "Argumentos insuficientes");
    }
    seNao verificarErro (1, "Argumentos insuficientes");
}
construido;

PROGRAMA
M 
    integrar 
    (
        listar 
        (
            novo_campo ("Limite superior", novo_double (22.33)),
            novo_campo ("Limite inferior", novo_double (22.24)),
            novo_campo ("Função"         , nova_funcao (f    )),
            O
        ),
        O
    );
W
DEBUGAR;