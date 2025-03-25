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
- **Bit 2** - Maleável (quando este e o anterior forem 0, falta decidir)
- **Bit 3** - Ainda a ser definido

Valor morto nega acesso.
Valor constante nega atualização, e seu construtor o define sem ponteiros.
Valor rígido permite atualização, mas apenas reescrevendo todo o valor.
Valor maleável usa ponteiros para tudo que pode mudar. (campos de string ou até toda a estrutura)

### Subtipos

Os subtipos são limitados a 4 bits, permitindo a representação de 31 tipos diferentes. Abaixo está a lista de tipos planejados:

| Valor | Subtipo |
|-------|---------|
| 19    | Número Imaginário |
| 18    | Número Real |
| 17    | Número Racional |
| 16    | Número Inteiro |
| 15    | Número Natural |
| 14    | Complexo |
| 13    | Componente | <- Outdated
| 12    | Campo |
| 11    | Função |
| 10    | Arranjo |
| 09    | Texto |
| 08    | Manipulador |
| 07    | Memória |
| 06    | Configuração |
| 05    | Ponteiro |
| 04    | Double |
| 03    | Int |
| 02    | Char |
| 01    | Byte |
| 00    | Vazio |

Os tipos 20-31 estão vagos para ideias futuras.

A organização dos componentes ainda pode ser ajustada para otimizar a flexibilidade da biblioteca.

---

## Estrutura da Biblioteca

A implementação será modular, com cada tipo definido em seu próprio arquivo. No entanto, todos os tipos pertencerão à mesma biblioteca, sem divisões de namespace separadas. Isso permitirá que as interações entre os diferentes tipos sejam claramente definidas e facilmente gerenciadas.

Por exemplo, uma função de soma precisará lidar com todos os tipos numéricos e também interpretar corretamente operações como concatenação de `texto`. Se uma operação não fizer sentido, um erro será retornado.

---

## Expansão Futura

Atualmente, há um bit de propriedade ainda não utilizado. Esse bit poderia ser usado para expandir a quantidade de subtipos para 63, permitindo a adição de conceitos mais avançados, como:

- Tipo `Língua`
- Tipo `Neurônio`
- Tipo `Pessoa`
- Tipo `Localização`

Isso abriria um vasto leque de possibilidades para a biblioteca, tornando-a altamente extensível.