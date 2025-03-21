# Biblioteca KiKi para C

 * Criador: Thiago Pereira de Oliveira
 * Data de inicio: 01/2025
 * Data de recomeço: 03/2025
 * Objetivo: Ser a criação e o tratamento de um tipo 'valor' unificada em propósito. 

 ## Descrição

 O tipo 'valor' será apenas um vetor de bytes, e a biblioteca inteira será ao redor dele.
 Nela teremos diversas implementações de usos possíveis a uma estrutura assim, mesmo que simples.
 Ela propõe resolver problemas como a falta de polimorfismo em C, para o tornar algo mais alto nível.
 Valores do sistema como 'int', 'double' ou 'char' poderão ser convertidos em valor.
 Outros valores que a biblioteeca adicionará é o valor 'texto', e o valor 'complexo'.
 O valor complexo irá abrir portas para o usuário da biblioteca construir os seus próprios valores.
 Os valores irão sempre começar em um byte de configuração. 

 ## BYTE DE CONFIGURAÇÃO
 * 
 *   Antes de iniciar os dados, os valores irão ter um
 * byte de configuração.
 * 
 *   O byte irá ser dividido em dois, a primeira metade
 * falando propriedades do valor, e a segunda metade 
 * falando o sbutipo do valor. 
 * 
 *  -- PROPRIEDADES
 *  
 *  0 - valor morto
 *  0 - constante \_ Quando ambos estão 1, modificador rígido
 *  0 - maleável  /  Quando ambos estão 0? FALTA DECIDIR
 *  0 - FALTA DECIDIR
 * 
 *  -- SUBTIPO
 * 
 *   Subtipos vão ser os selecionados ao sistema, para garantir
 * que tenha os essenciais, sem passar do limite de bits.
 *   
 *   Para a representação, teremos quatro bits.
 * 
 *  0 - 16
 *  0 - 8
 *  0 - 4
 *  0 - 2
 * 
 *   Somando todos, temos um total de 31 tipos do sistema possíveis.
 * 
 *   Organizando componentes de acordo com a forma decidida ser eventualmente a melhor. 
 *   
 *   19 - Número Imaginário
 *   18 - Número Real
 *   17 - Número Racional
 *   16 - Número Inteiro
 *   15 - Número Natural
 *   14 - Complexo
 *   13 - Componente
 *   12 - Campo <- vai ser algo para nomear o objeto usado
 *   11 - Função
 *   10 - Arranjo
 *   09 - Texto
 *   08 - Manipulador
 *   07 - Memória
 *   06 - Configuração <- o byte de configuração. Vai ser retorno de uma das funções. E é melhor ser só o byte mesmo
 *   05 - Ponteiro
 *   04 - Double
 *   03 - Int
 *   02 - Char
 *   01 - Byte
 *   00 - Vazio

  *   Todos os tipos terão seus respectivos arquivos. Mas não suas respectivas bibliotecas, todos serão da mesma.
 *   A divisão entre arquivos será utilizada pois todas as funções de todos os tipos, e todos os tipos em si vão
 * precisar de declarar qual é a sua relação com todos os outros. 
 *   Exemplo, uma eventual biblioteca de soma precisa somar números de todos os tipos, mas também somar bytes, e caso
 * receba textos, enviar para a função de concatenação. Caso ela receba tipos que REALMENTE nem uma mente criativa conseguiria
 * dizer o que fazer naquele contexto, aí sim dará erro. Mas a biblioteca deve ser estritamente fechadinha, sempre que possível.
 *   Tem um bit de propriedade que ainda não está sendo usado. Provavelmente seria bom ter ele como mais um bit de tipo, para realmente
 * poder eventualmente extrapolar, e fazer 63 subtipos na biblioteca.
 *   Por exemplo o tipo língua, ou o tipo Neurônio. Pessoa, nome, localização. 
 *   O sistema pode ter MUITOS tipos implementados.  (63);