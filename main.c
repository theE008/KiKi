//////////////////////////////////////////////////
// BIBLIOTECAS (NÃO PRECISA DE TUDO ISSO PRA FUNCIONAR)

#include "kikore/arranjo.h"
#include "kikore/campo.h"
#include "kikore/BST.h"
#include "kikore/semantica.h"
#include "kikore/double.h"
#include "kikore/matematica.h"

//////////////////////////////////////////////////
// DEFINIÇÃO DE VARIÁVEIS

#define pi 3.1415926535897932384626433832795028

//////////////////////////////////////////////////
// DEFINIÇÃO DAS FUNÇÕES

construirFuncao (f)
{
    verificarSubtipo (argumentos, codigoDouble);

    double x = para_double (argumentos);

    resposta = novo_double (4 * sqrt (36 - x * x));
}
construido;

construirFuncao (g)
{
    verificarSubtipo (argumentos, codigoDouble);

    double x = para_double (argumentos);

    resposta = novo_double (2 * pi * (9  - x * x));
}
construido;

construirFuncao (h)
{
    verificarSubtipo (argumentos, codigoDouble);

    double x = para_double (argumentos);

    resposta = novo_double (16/(sqrt (16 - x * x)));
}
construido;

//////////////////////////////////////////////////
// MÉTODO DE IMPRESSÃO

construirFuncao (imprimirIntegral)
M
    seNaoTiverArgumento (sup, "Limite superior") verificarErro (1, "Falta de argumentos");
    seNaoTiverArgumento (inf, "Limite inferior") verificarErro (1, "Falta de argumentos");
    seNaoTiverArgumento (fnc,          "Função") verificarErro (1, "Falta de argumentos");

    imprimir 
    (
        novo_texto ("Integral de "), inf,
        novo_texto (" até "), sup,
        novo_texto (" da função recebida: "), integrar 
        (
            listar 
            (
                novo_campo ("Limite inferior", inf),
                novo_campo ("Limite superior", sup),
                novo_campo ("Função"         , fnc),
                O
            ),
            O
        ),
        nL,
        O
    );
W
construido;

//////////////////////////////////////////////////
// MAIN

PROGRAMA
M 
    imprimirIntegral 
    (
        listar 
        (
            novo_campo ("Limite inferior", novo_double (0)),
            novo_campo ("Limite superior", novo_double (6)),
            novo_campo ("Função"         , nova_funcao (f)),
            O
        ),
        listar 
        (
            novo_campo ("Limite inferior", novo_double (0)),
            novo_campo ("Limite superior", novo_double (3)),
            novo_campo ("Função"         , nova_funcao (g)),
            O
        ),
        listar 
        (
            novo_campo ("Limite inferior", novo_double (0)),
            novo_campo ("Limite superior", novo_double (4)),
            novo_campo ("Função"         , nova_funcao (h)),
            O
        ),
        O
    );
W
DEBUGAR;

//////////////////////////////////////////////////