#ifndef OBJETO_H
#define OBJETO_H

/**
 * Criador: Thiago Pereira de Oliveira
 * Data: 01/2025
 * Objetivo: Ser a criação e o tratamento de um tipo 'objeto' unificada em propósito. 
*/

/**
 * -- DESCRIÇÃO DA BIBLIOTECA --
 *   Ela é baseada no conceito de objeto. Eles são um tipo de dado genérico que pode segurar todos os outros tipos. O ObjetoComplexo possui uma estrutura semelhante a de árvore em memória, mas de JSON ao imprimir e para o programa.
 *   O único tipo de dado definido para isto foi o tipo "Objeto", que é um struct composto por um boolean, um caractere, um ponteiro para outro objeto, e um union entre outro ponteiro para objeto e um ponteiro para função.
 *   O subtipo baseado em objeto que o usuário poderá criar será construído acima do ObjetoComplexo. Mas para o ObjetoComplexo existir, toda uma hierarquia de dados e subtipos é construida antes.
 * 
 * -- SUBTIPOS DA BIBLIOTECA --
 * 
 * - objeto vazio
 * - caractere
 * - texto
 * - campo
 * - componente
 * - arranjo
 * - função
 * - objeto complexo
 * 
 *   Os subtipos que o usuário terá acesso são os seguintes:
 * 
 * - objeto vazio - pois é o tipo mais básico de objeto.
 * - texto - é o sistema de strings que o objeto pode receber.
 * - arranjo - para o usuário ser capaz de realizar mais ações.
 * - objeto complexo - todos os subtipos criados pelo usuário serão dessa categoria.
 * 
 *   Os subtipos que o usuário não terá acesso são os seguintes:
 * 
 * - caractere - ele terá que usar texto, para garantir que o sistema não precise de funções tratando objetos semelhantes.
 * - campo - guarda um nome e um objeto complexo. Será oculto pois o usuário não precisa ver o funcionamento interno da biblioteca.
 * - componente - emprega o campo para fazer uma pilha de caracteristicas no ObjetoComplexo, o usuário não precisa saber que existe.
 * - função - um dos tipos de argumentos no objeto complexo. Novamente, desnecessário do usuário ter acesso direto.
 */

/////////////////////////////////////////////////////////////////
// BIBLIOTECAS

#include <stdbool.h>
#include  <stdlib.h>
#include  <stdarg.h> // para argumentos variados
#include   <stdio.h>

/////////////////////////////////////////////////////////////////
// PROTÓTIPOS

typedef struct  semPtr_objeto semPtr_objeto;
typedef         semPtr_objeto*       objeto;
objeto adicionarLetraAoFinalDo_texto (objeto texto, char letra);

/////////////////////////////////////////////////////////////////
// DEFINIÇÕES DE LOOPS

/**
 * Para: Usuários
 * Descrição: Faz um FOR simplificado.
*/
#define loop(var,qnts) \
for (int var = 0, max = qnts, continuar = 1; \
var < max && continuar; var++)

/**
 * Para: Usuários
 * Descrição: Para o LOOP.
*/
#define pararLoop continuar = 0;

/////////////////////////////////////////////////////////////////
// ERRO, DEBUG E FINALIZAÇÃO

////////////////// VARIÁVEIS
long int memoriaTotal = 0; // total de memoria usada
     int lixo         = 0; // lixo do programa não limpo

/**
 * Para: Programador
 * Descrição: Finaliza o programa com um código.
*/       
void finalizar (int val)
{
     if (val)
        printf ("\n\n\tPROGRAMA FINALZADO COM ERRO CODIGO '%d'\n\n", -val); 
     
    printf 
    (
        "\n\n\t%s\n\t%s '%d' %s\n\n\t'%d' %s\n", 
        "FIM DO PROGRAMA", "Finalizado com um total de", 
        lixo, "lixo", memoriaTotal, "memoria usada"
    );

    printf ("\n");

    exit (val);
}

/**
 * Para: Programador
 * Descrição: Finaliza o programa se um erro for percebido.
*/   
void VERIFY_ERROR (int erro, char* arquivo, int linha, const char* funcao)
{
    if (erro)
    {
        printf 
        (
            "\n\n\tERRO NO ARQUIVO: %s\n\tDA FUNCAO: %s\n\tNA LINHA : %d\n\n", 
            arquivo,
            funcao,
            linha
        );

        finalizar (erro);
    }
}

/**
 * Para: Usuário
 * Descrição: Uma forma mais enxuta od VERIFY_ERROR, tendo apenas um valor como condição. Se o valor for verdadeiro, a função dispara um erro.
*/  
#define verificarErro(erro) VERIFY_ERROR (erro, __FILE__, __LINE__, __func__);

/**
 * Para: Programador
 * Descrição: Uma linha de DEBUG que ajuda a identificar erros no código. Fácil de ver após debugar e fácil de limpar.
*/ 
#define DEBUGLINE_DEBUGLINE_DEBUGLINE_DEBUGLINE_DEBUGLINE \
printf ("\n\tlinha %d\n", __LINE__);

/////////////////////////////////////////////////////////////////
// TIPO MEMÓRIA

////////////////// DEFINIÇÃO DO TIPO MEMORIA
typedef struct semPtr_memoria semPtr_memoria;
typedef        semPtr_memoria*       memoria;
typedef struct semPtr_memoria
{
    memoria prox; // ponteiro para próxima memória da pilha
    void*  dados; // ponteiro para os dados armazenados
    int    nivel; // guarda a data de validade do tipo de dado
}
semPtr_memoria;

/**
 * Para: Programador
 * Descrição: Reserva memória com uma segurança. Desnecessário considerando o resto da biblioteca, já que outras funções de criação de dados serão mais apetitosas.
*/   
void* mallocarSimples (size_t tam) 
{
    void* tmp = malloc (tam); 

    verificarErro (tmp == NULL); 
    
    return tmp;
}

////////////////// CONSTRUTOR
memoria nova_memoria (void* ptr, int nivel)
{
    memoria tmp = (memoria) mallocarSimples (sizeof (semPtr_memoria));

    tmp->nivel = nivel;
    tmp->prox  =  NULL;
    tmp->dados =   ptr;

    return tmp;
}

////////////////// DESTRUTOR
void limpar_memoria (memoria *mem)
{
    verificarErro (  mem == NULL || *mem == NULL);
    verificarErro ((*mem)->dados         == NULL);

    free ((*mem)->dados);
    free  (*mem);

    lixo --;

    printf ("<");

    mem = NULL;
}

/////////////////////////////////////////////////////////////////
// TIPO GARBAGE COLLECTOR

////////////////// DEFINIÇÃO DO TIPO GARBAGE COLLECTOR
typedef struct semPtr_ColetorDeLixo semPtr_ColetorDeLixo;
typedef        semPtr_ColetorDeLixo*       ColetorDeLixo;
typedef struct semPtr_ColetorDeLixo
{
    memoria topo; // denota o topo da pilha de memória

    int nivel; // denota a data de validade do tipo
}
semPtr_ColetorDeLixo;
ColetorDeLixo coletor_de_lixo;

////////////////// CONSTRUTOR
ColetorDeLixo novo_ColetorDeLixo ()
{
    ColetorDeLixo tmp = (ColetorDeLixo) mallocarSimples 
    (
        sizeof (semPtr_ColetorDeLixo)
    );

    tmp->nivel = 0;

    // célula cabeça
    tmp->topo = nova_memoria (mallocarSimples (sizeof (char)), 0);

    return tmp;
} 

/**
 * Para: Programador
 * Descrição: Adiciona um ponteiro no coletor
*/  
void adicionarNo_ColetorDeLixo (ColetorDeLixo cdl, void* ptr)
{
    verificarErro (cdl       == NULL);
    verificarErro (cdl->topo == NULL);

    memoria nova_mem = nova_memoria (ptr, cdl->nivel);

    nova_mem->prox = cdl->topo->prox;
    cdl->topo->prox = nova_mem;    
}

/**
 * Para: Programador
 * Descrição: Apaga o primeiro ponteiro
*/  
void limparTopoDo_ColetorDeLixo (ColetorDeLixo cdl)
{
    verificarErro (cdl             == NULL);
    verificarErro (cdl->topo       == NULL);
    verificarErro (cdl->topo->prox == NULL);

    memoria tmp = cdl->topo->prox;

    cdl->topo->prox = cdl->topo->prox->prox;

    limpar_memoria (&tmp);
}

/**
 * Para: Programador
 * Descrição: Pega o nível do topo da pilha
*/  
int nivelDoTopoDo_ColetorDeLixo (ColetorDeLixo cdl)
{
    verificarErro (cdl             == NULL);
    verificarErro (cdl->topo       == NULL);

    int resp = -1;

    if (cdl->topo->prox != NULL) resp = cdl->topo->prox->nivel;

    return resp;
}

/**
 * Para: Programador
 * Descrição: Avisa o CDL que chaves foram abertas.
*/   
void subirNivel_ColetorDeLixo (ColetorDeLixo cdl)
{
    cdl->nivel ++;
}

/**
 * Para: Programador
 * Descrição: Avisa o CDL que chaves foram fechadas.
*/   
void descerNivel_ColetorDeLixo (ColetorDeLixo cdl)
{
    cdl->nivel --;

    while (nivelDoTopoDo_ColetorDeLixo (cdl) > cdl->nivel)
    {
        limparTopoDo_ColetorDeLixo (cdl);
    }
}

////////////////// DESTRUTOR
void limpar_ColetorDeLixo (ColetorDeLixo *cdl)
{
    verificarErro (  cdl == NULL || *cdl == NULL);
    verificarErro ((*cdl)->topo          == NULL);

    memoria tmpProx = (*cdl)->topo->prox;

    limpar_memoria (&(*cdl)->topo);

    while (tmpProx != NULL)
    {
        memoria aux = tmpProx->prox;
        limpar_memoria (&tmpProx);
        tmpProx = aux;
    }

    free (*cdl);
    *cdl = NULL;

    lixo ++; // uso a função de limpar memória no nó cabeça
    // devo somar lixo para equilibrar ele, já que o nó cabeça 
    // não é considerado memória.
}

/**
 * Para: Usuário
 * Descrição: Serve de chaves {}, mas se usadas corretamente, irão agir como garbage collector.
*/   
#define M {subirNivel_ColetorDeLixo (coletor_de_lixo);
#define W descerNivel_ColetorDeLixo (coletor_de_lixo);}

/////////////////////////////////////////////////////////////////
// FUNÇÕES DE RESERVA

/**
 * Para: Programador
 * Descrição: Reserva memória com uma segurança. Desnecessário considerando o resto da biblioteca, já que outras funções de criação de dados serão mais apetitosas.
*/   
void* mallocar (size_t tam) 
{
    void* tmp = malloc (tam); 

    verificarErro (tmp == NULL); 
    memoriaTotal++; 
    lixo++; 

    adicionarNo_ColetorDeLixo (coletor_de_lixo, tmp);
    printf (">");
    
    return tmp;
}

/**
 * Para: Programador
 * Descrição: Um encapsulamento da função mallocar para facilitar o Programador. Novamente, existem sistemas melhores para reserva de memória nesta biblioteca. Todavia, são construídos acima destes dois.
*/   
#define reservar(qnts,tipo) \
(tipo*) mallocar(qnts * sizeof (tipo));

/////////////////////////////////////////////////////////////////
// ORDEM DO PROGRAMA

/**
 * Para: Usuário
 * Descrição: Substitui o main
*/ 
#define INICIO_DO_PROGRAMA \
int main (void) \
{ \
coletor_de_lixo = novo_ColetorDeLixo (); \
if (1)

/**
 * Para: Usuário
 * Descrição: Substitui o return 0
*/ 
#define FIM_DO_PROGRAMA \
limpar_ColetorDeLixo (&coletor_de_lixo); \
return (0); }

/**
 * Para: Usuário
 * Descrição: Substitui o finalizar 0
*/ 
#define DEBUGAR_FIM_DO_PROGRAMA \
limpar_ColetorDeLixo (&coletor_de_lixo); \
finalizar (0); }

/**
 * Para: Programador
 * Descrição: Finaliza o programa sem apagar a memória
 * (usado para debug)
*/ 
#define PARAR_PROGRAMA \
finalizar (0); }

/////////////////////////////////////////////////////////////////
// FUNÇÕES NECESSÁRIAS PARA O TEXTO

/**
 * Para: Programador
 * Descrição: Retorna o tamanho de uma string 
 * (necessário para mim, desnecessário pro usuário)
*/   
int pegar_tamanho_da_string (char* entrada)
{
    verificarErro (entrada == NULL);
    bool continuar = true;
    int tamanho = 0;

    while (continuar)
    {
        if (entrada [tamanho++] == '\0') continuar = false;
    }

    return tamanho - 1;
}

/**
 * Para: Programador
 * Descrição: Retorna um malloc de texto
 * (necessário para mim, desnecessário pro usuário)
*/   
char* reservar_string (size_t tam)
{ 
    char* tmp = (char*) mallocar (tam * sizeof (char));

    loop (x, tam) tmp [x] = ' ';

    tmp [tam] = '\0';

    return tmp;
}

/////////////////////////////////////////////////////////////////
// TIPO OBJETO

////////////////// DEFINIÇÃO DO TIPO OBJETO
typedef struct semPtr_objeto semPtr_objeto ;
typedef        semPtr_objeto*       objeto ;
typedef           objeto (*funcao) (objeto); // tipo função
typedef struct semPtr_objeto
{
    bool tipo; // complexo ou simples
    char dado; // informação que esse objeto carrega

    objeto alfa; // ponteiro pra outro objeto

    union 
    {
        funcao func; // caso eu queira salvar uma função no objeto
        objeto obj;  // o comum, salvar um objeto no objeto
    }
    beta;
}
semPtr_objeto;

/////////////////////////////////////////////////////////////////
// CONSTRUTORES

/**
 * Para: Usuário
 * Descrição: Retorna uma nova instância de objeto vazio.
*/ 
objeto novo_objeto ()
{
    objeto tmp = (objeto) reservar (1, semPtr_objeto);

    tmp->tipo   = false;
    tmp->dado   =  '\0';

    tmp->beta.obj = NULL;
    tmp->alfa     = NULL;

    return tmp;
}

/**
 * Para: Programador
 * Descrição: Retorna um caractere.
*/ 
objeto novo_caractere (char* c)
{
    verificarErro (c == NULL);

    objeto tmp = novo_objeto ();

    tmp->dado = c [0];

    return tmp;
}

/**
 * Para: Programador
 * Descrição: Retorna um texto configurado, mas vazio.
*/ 
objeto novo_textoVazio ()
{
    objeto resposta = novo_objeto ();

    resposta->dado =  't'; // código do sistema para componente de texto
    resposta->tipo = true; // para afirmar que ele é complexo

    // células cabeça e cauda
    resposta->alfa     = novo_caractere ("\0");
    resposta->beta.obj = novo_caractere ("\0");

    resposta->alfa->tipo     = true; // para fazer ambos serem limpos
    resposta->beta.obj->tipo = true;

    resposta->beta.obj->alfa = resposta->alfa;
    resposta->alfa->beta = resposta->beta;

    resposta->alfa->alfa         = NULL;
    resposta->beta.obj->beta.obj = NULL;  

    return resposta;
}

/**
 * Para: Usuário
 * Descrição: Retorna um texto.
*/ 
objeto novo_texto (char* texto)
{
    objeto resposta = novo_textoVazio ();

    if (texto != NULL)
    {
        int tamanho = pegar_tamanho_da_string (texto);

        loop (x, tamanho)
        {
            adicionarLetraAoFinalDo_texto (resposta, texto [x]);
        }
    }

    return resposta;
}

/**
 * Para: Programador
 * Descrição: Retorna um campo, não totalmente estruturado.
*/
objeto novo_campoSemComponente (char* nome, objeto conteudo)
{
    verificarErro (nome     == NULL);
    verificarErro (conteudo == NULL);
    verificarErro (!conteudo-> tipo);
    verificarErro (conteudo->dado != 't' && conteudo->dado != 'o'); // t é o código para texto | o é o código para complexo

    objeto tmp = novo_objeto ();

    tmp->tipo = true;
    tmp->dado =  'c';
    
    tmp->alfa = novo_texto (nome);

    tmp->beta.obj = conteudo;

    return tmp;
}

/**
 * Para: Programador
 * Descrição: Retorna um compnente, não totalmente estruturado.
*/
objeto novo_componenteSemCampo (objeto campo)
{
    verificarErro (campo == NULL);
    verificarErro (!campo-> tipo);
    verificarErro (campo->dado != 'c');

    objeto tmp = novo_objeto ();
    tmp->tipo  = true;
    tmp->dado  =  'k';

    tmp->beta.obj = campo;

    return tmp;
}

/**
 * Para: Programador
 * Descrição: Retorna um compnente, o usuário não deveria acessar, para reduzir a complexidade do que ele deve acessar.
*/
objeto novo_componente (char* nome, objeto obj)
{
    return novo_componenteSemCampo (novo_campoSemComponente (nome, obj));
}

/**
 * Para: Programador
 * Descrição: O usuário não deveria precisar dizer que o objeto é complexo.
*/
objeto novo_objetoComplexo ()
{
    objeto tmp = novo_objeto ();
    tmp->tipo  = true;
    tmp->dado  =  'o';

    tmp->alfa  = novo_componente ("cabeca", novo_texto ("vazio"));
    tmp->beta.obj  = tmp->alfa;

    return tmp;
}

/**
 * Para: Programador
 * Descrição: O usuário não deveria precisar converter objeto de volta a texto.
*/
char* novo_chars (objeto texto)
{
    verificarErro (texto == NULL);
    verificarErro (texto->tipo != true);
    verificarErro (texto->dado != 't');

    char* resp = reservar_string (tamanho (texto) + 1);
    int ptr = 0;

    objeto index = texto->alfa->beta.obj;

    while (index != texto->beta.obj && index != NULL)
    {
        resp [ptr++] = index->dado;

        index = index->beta.obj;
    }

    resp [ptr] = '\0';

    return resp;
}

/**
 * Para: Usuário
 * Descrição: Permite a definição de um objeto complexo estruturadamente. 
 * Usado para passar vários argumentos como um objeto em uma função.
*/
objeto nova_listagem (char* nome, objeto comp, ...)
{
    objeto tmp = novo_objeto ();

    va_list args;
    va_start (args, comp);

    char* n = nome;
    objeto t = comp;

    while (t != NULL)
    {
        adicionar (tmp, n, t);
        
        n = va_arg (args, char*);
        if (n == NULL) break; // Para evitar acessar argumento inválido

        t = va_arg (args, objeto);
        if (t == NULL) break;
    }

    va_end (args);

    return tmp;
}

/////////////////////////////////////////////////////////////////
// ADDERS

/**
 * Para: Programador
 * Descrição: Não tem como fazer um nome mais auto explicativo.
*/ 
objeto adicionarLetraAoFinalDo_texto (objeto texto, char letra)
{
    verificarErro (texto == NULL || texto->alfa == NULL || texto->beta.obj == NULL);

    char a [2] =   " ";
         a [0] = letra;
    objeto   obj_letra = novo_caractere (a);
             obj_letra->tipo = true; // para mostrar que os ponteiros merecem limpeza
    
    obj_letra->alfa = texto->beta.obj->alfa;
    obj_letra->beta.obj   = texto->beta.obj;

    texto->beta.obj->alfa->beta.obj = obj_letra;
    texto->beta.obj->alfa           = obj_letra;

    // não tem como verificar se constante. Textos não tem componentes

    return texto;
}

/**
 * Para: Usuário
 * Descrição: Adiciona um componente no objeto.
*/ 
objeto adicionar (objeto obj, char* nome, objeto cmp)
{
    verificarErro (obj       == NULL);
    verificarErro (cmp       == NULL);

    if (obj->tipo == false && obj->dado == '\0')
    { 
        obj->tipo = true;
        obj->dado =  'o'; // tranformar em tipo complexo antes
        obj->alfa  = novo_componente ("cabeca", novo_texto ("vazio"));
        obj->beta.obj  = obj->alfa;

        objeto componente = novo_componente (nome, cmp);

        obj->beta.obj->alfa = componente; 
        obj->beta.obj       = componente;
    }
    else if (obj->tipo == true && obj->dado == 'o')
    {
        objeto componente = novo_componente (nome, cmp);

        obj->beta.obj->alfa = componente; 
        obj->beta.obj       = componente;
    }
    else verificarErro (1);

    // verificar se o valor não é constante
    objeto mod = novo_texto ("constante");
    objeto inv = pegar (obj, "modificador"); 
    if (inv != NULL && inv->beta.obj != NULL) 
        verificarErro (comparar (mod, inv->beta.obj->beta.obj) == 0.0);
    CLEAR_OBJECT (&mod);

    return obj;
}

/**
 * Para: Usuário
 * Descrição: Adiciona um componente de texto no objeto.
*/ 
objeto adicionarTexto (objeto obj, char* a, char* b)
{
    return adicionar (obj, a, novo_texto (b));
}

/*\ FIM DA DEFINIÇÃO DA BIBLIOTECA OBJETO \*/ #endif