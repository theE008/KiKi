#include "kikore/arranjo.h"
#include "kikore/campo.h"
#include "kikore/BST.h"
#include "kikore/semantica.h"
#include "kikore/double.h"
/*
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

    }

    seTiverArgumento (sup, "Limite superior")
    {

    }

    seTiverArgumento (func, "Função")
    {

    }
}
construido;*/

PROGRAMA
M 
    listar 
    (
        novo_campo ("Limite superior", novo_double (22.33)),
        novo_campo ("Limite inferior", novo_double (22.24)),
        // novo_campo ("Função"         , nova_funcao (f    )),
        O
    );
W
DEBUGAR;