#include "kikore/arranjo.h"
#include "kikore/campo.h"
#include "kikore/BST.h"

#include "kikore/semantica.h"

/*
    double imprimirIntegral (funcao f, double a, double b)
    {
        static int q = 1;
        printf ("Integral de %g ate %g da questao %d: %lf\n", a, b, q++, integrar (f, 0, a, b));
    }
*/

construirFuncao (integralParaTexto)
{
    adicionarTextoNaResposta ("Limite inferior", "Inexistente");

    
    seTiverArgumento (teste, "Teste")
    {
        adicionarNaResposta ("Aqui oh", teste);
    }
}
construido;

void main (void)
{
    M
        valor novaLinha = novo_texto ("\n");

        valor comp = novo_complexo (novo_campo ("Teste", novo_texto ("Funcionando")));

        imprimir (integralParaTexto (comp, O), novaLinha, novaLinha, O);
    W
        
    finalizar (0, "Teste extrapolado finalizado");
}
