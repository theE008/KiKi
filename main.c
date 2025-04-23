#include "kikore/arranjo.h"
#include "kikore/campo.h"
#include "kikore/BST.h"

#include "kikore/semantica.h"
#include "kikore/funcao.h"

/*
    double imprimirIntegral (funcao f, double a, double b)
    {
        static int q = 1;
        printf ("Integral de %g ate %g da questao %d: %lf\n", a, b, q++, integrar (f, 0, a, b));
    }
*/

construirFuncao (integralParaTexto)
{
    seTiverArgumento (limSup, "Limite superior") adicionarNaResposta ("Limite superior", limSup);
    seTiverArgumento (limInf, "Limite inferior") adicionarNaResposta ("Limite inferior", limInf);
    seTiverArgumento (funcao, "Funcao") adicionarNaResposta ("Funcao", funcao);

    adicionarNaResposta ("para_string", nova_funcao (integralParaTexto));
}
construido;

void main (void)
{
    M
        valor novaLinha = novo_texto ("\n");

        valor complexo = listar 
        (
            novo_campo ("Limite superior", novo_texto ("2")),
            novo_campo ("Limite inferior", novo_texto ("4")),
            O
        );

        imprimir 
        (
            integralParaTexto (complexo, O),            

            novaLinha,
            novaLinha,
            O
        );
    W
        
    finalizar (0, "Teste extrapolado finalizado");
}
