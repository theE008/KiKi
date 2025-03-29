# Biblioteca KiKi para C

**Criador:** Thiago Pereira de Oliveira  
**Data de início:** 01/2025  
**Data de recomeço:** 03/2025  
**Objetivo:** Criar e tratar um tipo de dado unificado chamado `valor`, oferecendo maior flexibilidade e abstração em C.

## Descrição

O tipo `valor` é uma estrutura baseada em um vetor de bytes, sendo o centro da biblioteca. A proposta é fornecer um meio de lidar com diferentes tipos de dados em C de maneira mais polimórfica e de alto nível.

A biblioteca permitirá a conversão de tipos primitivos do sistema, como `int`, `double` e `char`, para `valor`. Além disso, introduzirá novos tipos, como `texto` e `complexo`. O tipo `complexo` servirá como base para que os usuários criem seus próprios tipos de dados.

Todos os `valores` iniciarão com um byte de configuração, que determinará propriedades essenciais.

---

## Byte de Configuração

Antes do armazenamento dos dados, cada `valor` conterá um byte de configuração. Esse byte será dividido em duas partes:

1. **Propriedades** (4 bits iniciais) - Definem características do `valor`.
2. **Subtipo** (4 bits finais) - Define o tipo específico dentro do sistema.

### Propriedades

Cada um dos 4 bits iniciais do byte de configuração define uma característica do `valor`:

- **Bit 0** - Valor morto
- **Bit 1** - Constante (quando este e o próximo forem 1, valor Rígido)
- **Bit 2** - Maleável (quando este e o anterior forem 0, valor Fixado)
- **Bit 3** - Ainda a ser definido

Valor morto nega acesso.
Valor constante nega atualização, e seu construtor o define sem ponteiros.
Valor rígido permite atualização, mas apenas reescrevendo todo o valor.
Valor maleável usa ponteiros para tudo que pode mudar. (campos de string ou até toda a estrutura)
Valor fixado usa ponteiros para apontar a outros Valores, mas a estrutura em si não pode ser mudada.

### Subtipos

Os subtipos são limitados a 4 bits, permitindo a representação de 31 tipos diferentes. Abaixo está a lista de tipos planejados:

| Código | Subtipo |
|--------|---------|
| 19     | BST |
| 18     | Número Imaginário |
| 17     | Número Real |
| 16     | Número Racional |
| 15     | Número Inteiro |
| 14     | Número Natural |
| 13     | Complexo |
| 12     | Campo |
| 11     | Função |
| 10     | Arranjo |
| 09     | Texto |
| 08     | Manipulador |
| 07     | Memória |
| 06     | Configuração |
| 05     | Ponteiro |
| 04     | Double |
| 03     | Int |
| 02     | Char |
| 01     | Byte |
| 00     | Vazio |

Os tipos 20-31 estão vagos para ideias futuras.

A organização dos componentes ainda pode ser ajustada para otimizar a flexibilidade da biblioteca.

---

## Modificadores

Antes de toda instância, você pode adicionar (preferencialmente apenas um) modificador no subtipo de dado sendo criado.

Os Modificadores serão:

* naoSalvar: Não adiciona o Valor a pilha de memória (requer limpeza manual). Ideal para Valores que você sabe que não serão mais úteis, e que já podem ser limpos para abrir mais espaço de memória com antecedência.

* constante: Cria um Valor não modificável e sem ponteiros. Ideal para Valores que só serão lidos pelo seu tempo de vida, pois ele não os cria como uma árvore de ponteiros, e sim como um arranjo de bytes único.

* rigido: Igual ao anterior, mas permite modificações. Ao ser modificado, ele é realocado para o novo espaço. Ideal para Valores que vão ser modificados raramente, mas talvez precisem ser. A leitura é tão rápida quanto o tipo constante.

* maleavel: Usa ponteiros para tudo que pode mudar. Ideal para poucas leituras e muitas mudanças.

* fixado: Usa ponteiros para tudo, mas não permite mudar os ponteiros. Ideal para arranjos de ponteiros.

* vidaUtil(val): Adiciona mais ou menos vida útil a um Valor.

---

## Estrutura da Biblioteca

A implementação será modular, com cada tipo definido em seu próprio arquivo. No entanto, todos os tipos pertencerão à mesma biblioteca, sem divisões de namespace separadas. Isso permitirá que as interações entre os diferentes tipos sejam claramente definidas e facilmente gerenciadas.

Por exemplo, uma função de soma precisará lidar com todos os tipos numéricos e também interpretar corretamente operações como concatenação de `texto`. Se uma operação não fizer sentido, um erro será retornado.

---

## BST e o Valor Complexo

Uma BST (Binary Search Tree) de Campos será a definição da biblioteca de Valor Complexo. Por isso uma estrutura tão avançada está entre outras como INT e DOUBLE. Ela é essencial para o propósito.

---

## Expansão Futura

Atualmente, há um bit de propriedade ainda não utilizado. Esse bit poderia ser usado para expandir a quantidade de subtipos para 63, permitindo a adição de conceitos mais avançados, como:

- Tipo `Língua`
- Tipo `Neurônio`
- Tipo `Pessoa`
- Tipo `Localização`

Isso abriria um vasto leque de possibilidades para a biblioteca, tornando-a altamente extensível.