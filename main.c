#include "kikore/arranjo.h"
#include "kikore/campo.h"
#include "kikore/BST.h"

void main (void)
{
    M
        valor novaLinha = novo_texto ("\n");

        valor texto_nome    = novo_texto ("Thiago");
        valor texto_idade   = novo_int (12);
        valor texto_online  = novo_texto ("true");
        valor texto_status  = novo_texto ("ativo");
        
        DEBUGLINE_DEBUGLINE_DEBUGLINE_DEBUGLINE_DEBUGLINE;
        valor campo_nome    = novo_campo ("nome", texto_nome);
        valor campo_idade   = novo_campo ("idade", texto_idade);
        valor campo_online  = novo_campo ("online", texto_online);
        valor campo_status  = novo_campo ("status", texto_status);
        DEBUGLINE_DEBUGLINE_DEBUGLINE_DEBUGLINE_DEBUGLINE;

        valor perfil = novo_complexo (campo_nome);
        adicionar (perfil, campo_idade);
        adicionar (perfil, campo_online);
        adicionar (perfil, campo_status);
        DEBUGLINE_DEBUGLINE_DEBUGLINE_DEBUGLINE_DEBUGLINE;

        imprimir (perfil, O);

        valor campo_usuario = novo_campo ("usuario", perfil);
        DEBUGLINE_DEBUGLINE_DEBUGLINE_DEBUGLINE_DEBUGLINE;

        imprimir (campo_usuario, O);

        DEBUGLINE_DEBUGLINE_DEBUGLINE_DEBUGLINE_DEBUGLINE;
        valor campo_repetido = novo_campo ("nome", novo_texto ("outro"));

        valor complexa_lista = novo_complexo (campo_repetido);
        DEBUGLINE_DEBUGLINE_DEBUGLINE_DEBUGLINE_DEBUGLINE;


        DEBUGLINE_DEBUGLINE_DEBUGLINE_DEBUGLINE_DEBUGLINE;

        adicionar (complexa_lista, campo_usuario);
        DEBUGLINE_DEBUGLINE_DEBUGLINE_DEBUGLINE_DEBUGLINE;

        valor campo_com_lista = novo_campo ("dados", complexa_lista);
        DEBUGLINE_DEBUGLINE_DEBUGLINE_DEBUGLINE_DEBUGLINE;

        valor principal = novo_complexo (campo_com_lista);
        adicionar (principal, novo_campo ("versão", novo_texto ("1.0")));
        adicionar (principal, novo_campo ("ativo", novo_texto ("true")));

        imprimir (principal, novaLinha, novaLinha, O);

        //imprimir (novo_int (0) ,O);

    W

    finalizar (0, "Teste extrapolado finalizado");
}
