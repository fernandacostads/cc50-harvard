# Módulo 0: Scratch

[Ver outros módulos](https://github.com/fernandacostads/cc50-harvard#m%C3%B3dulos)

## **Bem vindo!**

Este ano, o curso de Ciência da Computação de Harvard está no [Loeb Drama Center](https://americanrepertorytheater.org/venue/loeb-drama-center-3/) da Harvard University, onde, graças à colaboração com o [American Repertory Theatre](https://americanrepertorytheater.org/) , tiveram um palco incrível e até mesmo adereços para demonstrações.

Eles transforamaram uma [aquarela](https://images.hollis.harvard.edu/permalink/f/100kie6/HVD_VIAolvwork671391) do século 18 [do campus de Harvard feita](https://images.hollis.harvard.edu/permalink/f/100kie6/HVD_VIAolvwork671391) por um aluno, Jonathan Fisher, no plano de fundo do palco.

Vinte anos atrás, quando era um estudante de graduação, o professor David J. Malan superou sua própria apreensão, saindo de sua zona de conforto e cursou CS50 (para nós, CC50), descobrindo que o curso era menos sobre programação em si e mais sobre solução de problemas. Na verdade, dois terços dos alunos do CS50 nunca fizeram um curso de ciência da computação antes.

**E o mais importante: o que importa neste curso não é tanto onde você termina em relação aos seus colegas, mas onde você termina em relação a si mesmo quando você começou a jornada.**

Para começar o curso, vamos recriar um componente de um jogo do [Super Mario](https://pt.wikipedia.org/wiki/Super_Mario_Bros.) , depois construiremos um aplicativo da web chamado CS50 Finance que permitirá aos usuários comprar e vender ações virtualmente e terminaremos o curso com a criação de seu próprio projeto final.

## **O que é Ciência da Computação?**

A ciência da computação é fundamentalmente sobre resolução de problemas.

Podemos pensar na resolução de problemas como o processo de pegar algumas informações (detalhes sobre nosso problema) e gerar alguns resultados (a solução para nosso problema). A “caixa preta” no meio é a ciência da computação, ou o código que aprenderemos a escrever.

![Entrada [Algoritmo] Saída](https://cs50.harvard.edu/x/2021/notes/0/input_output.png)

_Para começar a fazer isso, precisaremos de uma maneira de representar entradas (inputs) e saídas (outputs), para que possamos armazenar e trabalhar com informações de forma padronizada._

## **Representando números**

Podemos começar com a tarefa de marcar presença, contando o número de pessoas em uma sala. Com a nossa mão, podemos levantar um dedo de cada vez para representar cada pessoa, mas não poderemos contar muito alto. Este sistema é denominado unário, onde cada dígito representa um único valor de um.

Provavelmente aprendemos um sistema mais eficiente para representar números, onde temos dez dígitos, de 0 a 9:

0 1 2 3 4 5 6 7 8 9

- Este sistema é denominado decimal, ou base 10, uma vez que existem dez valores diferentes que um dígito pode representar.

Os computadores usam um sistema mais simples chamado **binário**, ou base dois, com apenas dois dígitos possíveis, **0 e 1**.

- Cada dígito binário também é chamado de **bit**.

Como os computadores funcionam com eletricidade, que pode ser ligada ou desligada, podemos convenientemente representar um bit ligando ou desligando alguma chave para representar 0 ou 1.

- Com uma lâmpada, por exemplo, podemos ligá-la para contar até 1.

Com três lâmpadas, podemos acendê-las em padrões diferentes e contar de 0 (com as três apagadas) a 7 (com as três acesas):

![3 lâmpadas representando os números de 0 a 7, com os estados ligado e desligado.](https://edools-3-production.s3.amazonaws.com/org-6988%2Fschool-7227%2F06b5e354f9340b3effa3ff030e9cf460%2Fbinary.png)

Dentro dos computadores modernos, não existem lâmpadas, mas milhões de pequenos interruptores chamados **transistores** que podem ser ligados e desligados para representar valores diferentes. Por exemplo, sabemos que o seguinte número em decimal representa cento e vinte e três.

1 2 3

- O **3** está na coluna das unidades, o **2** está na coluna das dezenas e o **1** está na coluna das centenas.
- Portanto, **123** é **100 × 1 + 10 × 2 + 1 × 3 = 100 + 20 + 3 = 123**.
- Cada casa de um dígito representa uma potência de dez, pois há dez dígitos possíveis para cada casa. O lugar mais à direita é para 100, o do meio 101 e o lugar mais à esquerda 102

102 101 100  
1     2    3

Em binário, com apenas dois dígitos, temos potências de dois para cada valor de casa:

                             22   21   20  
Equivalente a:      **4     2    1**

Com todas as lâmpadas ou interruptores desligados, ainda teríamos um valor de 0:

22   21   20  
**0    0    0**

Agora, se mudarmos o valor binário para, digamos, 0 1 1 , o valor decimal seria 3, uma vez que somamos o 2 e o 1:

4   2   1  
**0   1   1**

Se tivéssemos mais lâmpadas, poderíamos ter um valor binário de 110010 , que teria o valor decimal equivalente a 50:

32   16   8   4   2   1  
**1     1     0   0   1   0**

_Observe que 32 + 16 + 2 = 50 . Com mais bits, podemos contar até números ainda maiores._

## **Texto**

Para representar as letras, tudo o que precisamos fazer é decidir como os números são mapeados para as letras. Alguns humanos, muitos anos atrás, decidiram coletivamente um mapeamento padrão de números em letras. A letra “A”, por exemplo, é o número 65, e “B” é 66 e assim por diante. Ao usar o contexto, como quando estamos olhando uma planilha ou um e-mail, diferentes programas podem interpretar e exibir os mesmos bits como números ou texto.

O mapeamento padrão, [ASCII](https://pt.wikipedia.org/wiki/ASCII), também inclui letras minúsculas e pontuação.

Se recebêssemos uma mensagem de texto com um padrão de bits que tivesse os valores decimais **72 , 73 e 33**, esses bits seriam mapeados para as letras **HI!**. Cada letra é normalmente representada com um padrão de oito bits, ou um **byte**, então as sequências de bits que receberíamos são **01001000 , 01001001 e 00100001.**

- Podemos já estar familiarizados com o uso de bytes como uma unidade de medida para dados, como em megabytes ou gigabytes, para milhões ou bilhões de bytes.

Com oito bits, ou um byte, podemos ter 28 ou 256 valores diferentes (incluindo zero). (O valor mais alto que podemos contar seria 255.)

Outros caracteres, como letras com acentos e símbolos em outros idiomas, fazem parte de um padrão chamado [Unicode](https://ead.napratica.org.br/enrollments/8898593/courses/84414/course_contents/%E2%80%9Dhttps://pt.wikipedia.org/wiki/Unicode%E2%80%9D), que usa mais bits do que ASCII para acomodar todos esses caracteres.

- Quando recebemos um emoji, nosso computador está apenas recebendo um número binário que mapeia para a imagem do emoji baseado no padrão Unicode. Por exemplo, o emoji “rosto com lágrimas de alegria” tem apenas os bits **000000011111011000000010**:

![Emoji: rosto com lágrima de alegria](https://edools-3-production.s3.amazonaws.com/org-6988%2Fschool-7227%2F512657e41deb7c4ee12bc597ef039e78%2Fface_with_tears_of_joy.png)

## **Imagem, vídeo e sons**

Uma imagem, como a imagem do emoji, é composta de cores. Com apenas bits, podemos mapear números para cores também. Existem muitos sistemas diferentes para representar cores, mas um comum é **RGB**, que representa cores diferentes indicando a quantidade de vermelho, verde e azul dentro de cada cor.

Por exemplo, nosso padrão de bits anterior, **72 , 73 e 33** pode indicar a quantidade de vermelho, verde e azul em uma cor. (E nossos programas saberiam que esses bits são mapeados para uma cor se abríssemos um arquivo de imagem, em vez de recebê-los em uma mensagem de texto.)

Cada número pode ser um byte, com 256 valores possíveis, portanto, com três bytes, podemos representar milhões de cores. Nossos três bytes de cima representariam um tom escuro de amarelo:

**Observe este exemplo.**

Os pontos, ou quadrados, em nossas telas são chamados de **pixels**, e as imagens são compostas por muitos milhares ou milhões desses pixels também. Então, usando três bytes para representar a cor de cada pixel, podemos criar imagens. Podemos ver os pixels em um emoji se aumentarmos o zoom, por exemplo:

![Emoji com zoom](https://edools-3-production.s3.amazonaws.com/org-6988%2Fschool-7227%2F234a04a524c06cb55f22225b0a1fb1c7%2Femoji_zoomed.png)

A **resolução** de uma imagem é o número de pixels que existem, horizontalmente e verticalmente, portanto, uma imagem de alta resolução terá mais pixels e exigirá mais bytes para ser armazenada.

Os vídeos são compostos de muitas imagens, mudando várias vezes por segundo para nos dar a aparência de movimento, como um [flipbook](https://ead.napratica.org.br/enrollments/8898593/courses/84414/course_contents/%E2%80%9Dhttps://www.youtube.com/watch?v=p3q9MM__h-M%E2%80%9D) antigo faria.

A música também pode ser representada com bits, com mapeamentos de números para notas e durações, ou mapeamentos mais complexos de bits para frequências de som em cada momento transcorrido.

Os formatos de arquivo, como JPEG e PNG, ou documentos do Word ou Excel, também são baseados em algum padrão com o qual alguns humanos concordaram, para representar informações com bits.

## **Algoritmos**

Agora que podemos representar inputs e outputs, podemos trabalhar na resolução de problemas.

Os humanos também podem seguir algoritmos, como receitas para cozinhar. Ao programar um computador, precisamos ser mais precisos com nossos algoritmos para que nossas instruções não sejam ambíguas ou mal interpretadas.

Podemos ter um aplicativo em nossos telefones que armazena nossos contatos, com seus nomes e números de telefone classificados em ordem alfabética. O equivalente “old-school” pode ser uma lista telefônica, uma cópia impressa de nomes e números de telefone.

Nossa contribuição para o problema de encontrar o número de alguém seria a lista telefônica e um nome a ser procurado. Podemos abrir o livro e começar da primeira página, procurando um nome uma página de cada vez. Este algoritmo estaria **correto**, já que eventualmente encontraremos o nome que buscamos se ele estiver no livro.

Podemos folhear o livro duas páginas por vez, mas esse algoritmo não estará correto, pois podemos pular a página com nosso nome nela. Podemos consertar esse bug, ou engano, voltando uma página se formos longe demais, pois sabemos que a lista telefônica está classificada em ordem alfabética.

Outro algoritmo seria abrir a lista telefônica ao meio, decidir se nosso nome estará na metade esquerda ou na metade direita do livro (porque o livro está em ordem alfabética) e reduzir o tamanho do nosso problema pela metade. Podemos repetir isso até encontrar nosso nome, dividindo o problema pela metade a cada vez. Com 1.024 páginas para começar, precisaríamos apenas de 10 etapas de divisão ao meio antes de termos apenas uma página restante para verificar. Podemos ver isso visualizado em uma [animação de dividir uma lista telefônica ao meio repetidamente](https://www.youtube.com/watch?v=F5LZhsekEBc), em comparação com a [animação de pesquisar uma página por vez](https://www.youtube.com/watch?v=-yTRajiUi5s).

Na verdade, podemos representar a eficiência de cada um desses algoritmos com um gráfico:

![”Gráfico](https://edools-3-production.s3.amazonaws.com/org-6988%2Fschool-7227%2F157f25644c042b501aa9580fe0358564%2Fgrafico-algoritmo.png)

Nossa primeira solução, pesquisar uma página por vez, pode ser representada pela linha vermelha: nosso tempo para resolver aumenta linearmente à medida que o tamanho do problema aumenta. _n_ é um número que representa o tamanho do problema, portanto, com n páginas em nossas listas telefônicas, temos que realizar até n etapas para encontrar um nome.

A segunda solução, pesquisar duas páginas por vez, pode ser representada pela linha amarela: nossa inclinação é menos acentuada, mas ainda linear. Agora, precisamos apenas de (aproximadamente) _n / 2_ etapas, já que viramos duas páginas de cada vez.

Nossa solução final, dividindo a lista telefônica ao meio a cada vez, pode ser representada pela linha verde, com uma relação fundamentalmente diferente entre o tamanho do problema e o tempo de resolvê-lo: [logarítmica](https://ead.napratica.org.br/enrollments/8898593/courses/84414/course_contents/%E2%80%9Dhttps://pt.wikipedia.org/wiki/Logaritmo%E2%80%9D) , já que nosso tempo de resolução aumenta cada vez mais lentamente conforme o tamanho do problema aumenta.

Em outras palavras, se a lista telefônica fosse de 1.000 para 2.000 páginas, precisaríamos apenas de mais uma etapa para encontrar nosso nome. Se o tamanho dobrasse novamente de 2.000 para 4.000 páginas, ainda precisaríamos de apenas mais uma etapa. A linha verde é rotulada log2 _n_ , ou log base 2 de _n_ , já que estamos dividindo o problema por dois em cada etapa.

Quando escrevemos programas usando algoritmos, geralmente nos preocupamos não apenas com o quão corretos eles são, mas também com o quão bem projetados eles são, considerando fatores como eficiência.

## **Pseudocódigo**

Podemos escrever **pseudocódigo**, que é uma representação de nosso algoritmo em inglês preciso (ou alguma outra linguagem humana):

1 Pegue a lista telefônica  
2 Abra no meio da lista telefônica  
3 Olhe para a página  
4 Se a pessoa estiver na página  
5    Ligar para pessoa  
6 Caso contrário, se a pessoa estiver mais para o início do livro  
7    Abrir no meio da metade esquerda do livro  
8    Volte para a linha 3  
9 Caso contrário, se a pessoa estiver mais para o final do livro  
10   Abrir no meio da metade direita do livro  
11   Volte para a linha 3  
12 Caso contrário  
13   Desistir

- Com essas etapas, verificamos a página do meio, decidimos o que fazer e repetimos. Se a pessoa não estiver na página e não houver mais páginas sobrando no livro, paramos. E esse caso final é particularmente importante para lembrar. Quando outros programas em nossos computadores esquecem esse caso final, eles podem travar ou parar de responder, uma vez que encontraram um caso que não foi contabilizado, ou continuar a repetir o mesmo trabalho continuamente nos bastidores, sem fazer nenhum progresso.

Algumas dessas linhas começam com verbos ou ações. Começaremos chamando estas _funções_:

1 **Pegue** a lista telefônica  
2 **Abra** no meio da lista telefônica  
3 **Olhe** para a página  
4 Se a pessoa estiver na página  
5    **Ligar** para pessoa  
6 Caso contrário, se a pessoa estiver mais para o início do livro  
7    **Abrir** no meio da metade esquerda do livro  
8    Volte para a linha 3  
9 Caso contrário, se a pessoa estiver mais para o final do livro  
10   **Abrir** no meio da metade direita do livro  
11   Volte para a linha 3  
12 Caso contrário  
13   **Desistir**

Também temos ramificações que levam a caminhos diferentes, como bifurcações na estrada, que chamaremos de _condições_:

1 Pegue a lista telefônica  
2 Abra no meio da lista telefônica  
3 Olhe para a página  
4 **Se** a pessoa estiver na página  
5    Ligar para pessoa  
6 **Caso contrário**, se a pessoa estiver mais para o início do livro  
7    Abrir no meio da metade esquerda do livro  
8    Volte para a linha 3  
9 **Caso contrário**, se a pessoa estiver mais para o final do livro  
10   Abrir no meio da metade direita do livro  
11   Volte para a linha 3  
12 **Caso contrário**  
13   Desistir

E as perguntas que decidem para onde vamos são chamadas de _expressões booleanas_ , que eventualmente resultam em um valor de sim ou não, verdadeiro ou falso:

1 Pegue a lista telefônica  
2 Abra no meio da lista telefônica  
3 Olhe para a página  
4 Se **a pessoa estiver na página**  
5    Ligar para pessoa  
6 Caso contrário, se **a pessoa estiver mais para o início do livro**  
7    Abrir no meio da metade esquerda do livro  
8    Volte para a linha 3  
9 Caso contrário, se **a pessoa estiver mais para o final do livro**  
10   Abrir no meio da metade direita do livro  
11   Volte para a linha 3  
12 Caso contrário  
13   Desistir

Por último, temos palavras que criam ciclos, onde podemos repetir partes de nosso programa, chamadas _loops_:

1 Pegue a lista telefônica  
2 Abra no meio da lista telefônica  
3 Olhe para a página  
4 Se a pessoa estiver na página  
5    Ligar para pessoa  
6 Caso contrário, se a pessoa estiver mais para o início do livro  
7    Abrir no meio da metade esquerda do livro  
8    **Volte para a linha 3**  
9 Caso contrário, se a pessoa estiver mais para o final do livro  
10   Abrir no meio da metade direita do livro  
11   **Volte para a linha 3**  
12 Caso contrário  
13   Desistir


## Como mexer no Scratch?

Podemos escrever programas com os blocos de construção que acabamos de descobrir:

- funções
- condições
- Expressões booleanas
- rotações

E descobriremos recursos adicionais, incluindo:

- variáveis
- tópicos
- eventos …

Antes de aprendermos a usar uma linguagem de programação baseada em texto chamada C, usaremos uma linguagem de programação gráfica chamada [Scratch](https://scratch.mit.edu/) , onde arrastaremos e soltaremos blocos que contêm instruções.

Um programa simples em C que imprime “olá, mundo”, ficaria assim:

#include **<stdio.h>**

int main(void)
{
    printf("oi, mundo\n");
}

- Há muitos símbolos e sintaxe, ou seja, o arranjo desses símbolos, que teríamos que descobrir.

O ambiente de programação do Scratch é um pouco mais amigável:

![IDE do Scratch](https://edools-3-production.s3.amazonaws.com/org-6988%2Fschool-7227%2F3d4d6b018f0dca2a36420b19df5a667a%2Fscratch.png)

- No canto superior direito, temos um “palco” que será mostrado pelo nosso programa, onde podemos adicionar ou alterar planos de fundo, personagens (chamados de sprites no Scratch) e muito mais.
- À esquerda, temos peças de quebra-cabeça que representam funções ou variáveis, ou outros conceitos, que podemos arrastar e soltar em nossa área de instrução no centro.
- No canto inferior direito, podemos adicionar mais personagens para nosso programa usar.

Podemos arrastar alguns blocos para fazer o Scratch dizer “olá, mundo”. Ao adicionar o bloco “**green flag clicked**” (“quando a bandeira verde é clicada”) refere-se ao início do nosso programa (já que há uma bandeira verde acima do palco que podemos usar para iniciá-lo), e abaixo dela encaixamos um bloco “**say**"(“dizer”) e digitamos “hello, world” ("olá mundo"). E podemos descobrir o que esses blocos fazem explorando a interface e experimentando.

Também podemos arrastar o bloco “**ask _ and wait**” (“perguntar _ e esperar”), com uma pergunta como “what’s your name” (“qual é o seu nome?”), e combiná-lo com um bloco “**say**” para a resposta. O bloco “**answer**” (“responder”) é uma variável, ou valor, que armazena o que o usuário do programa digita, e podemos colocá-lo em um bloco “**say**” arrastando e soltando também.

Mas não pausamos depois de dizer “Olá” com o primeiro bloco, então podemos usar o bloco “**join**” (“juntar”) para combinar duas frases para que nosso gato possa dizer “olá, David”:

![Exemplo de trecho de código de Olá, [nome dado pelo usuário]!](https://edools-3-production.s3.amazonaws.com/org-6988%2Fschool-7227%2F338df80646ab3220b2dff19d557dd675%2Fcode.png)

Quando tentamos aninhar blocos ou colocá-los uns dentro dos outros, o Scratch nos ajudará a expandir os locais onde eles podem ser usados. Na verdade, o bloco "**say**" em si é como um algoritmo, onde fornecemos um input de "olá, mundo" e ele produziu a output de Scratch (o gato) "dizendo" essa frase.

O bloco "**ask**" também recebe um input (a pergunta que queremos fazer) e produz um output do bloco "answer".

Podemos então usar o bloco “**answer**” junto com nosso próprio texto, “hello,“, como duas entradas para o algoritmo de junção... o output do qual podemos passar como input para o bloco "**say**".

No canto inferior esquerdo da tela, vemos um ícone para extensões, e um deles é chamado "**text-to-speech**”. Depois de adicioná-lo, podemos usar o bloco "**say**" para ouvir nosso gato falar:

![Exemplo de blocos de codigo que utiliza microfone](https://edools-3-production.s3.amazonaws.com/org-6988%2Fschool-7227%2Ff3afba1da1c7d8dd759c2acb04927e63%2Fcode2.png)

A extensão "**text-to-speech**”, graças à nuvem, ou servidores de computador na internet, está convertendo nosso texto em áudio. Podemos tentar fazer o gato dizer miau:

when green flag clicked
play sound: Meow until done
wait 1 seconds
play sound: Meow until done
wait 1 seconds

Podemos dizer miau três vezes, mas agora estamos repetindo blocos indefinidamente. Vamos usar um loop ou um bloco de “**repeat**” (“repetição”):

![Trecho de código com laço de repetição](https://edools-3-production.s3.amazonaws.com/org-6988%2Fschool-7227%2F2c8911ecb2fb6c5a5ecea42aed83f815%2Fcode3.png)

Agora nosso programa atinge os mesmos resultados, mas com menos blocos. Podemos considerar que ele tem um design melhor: se há algo que queremos mudar, só precisaríamos mudar em um lugar ao invés de três.

Podemos fazer com que o gato aponte para o mouse e se mova em direção a ele:

when green flag clicked
forever
   point towards mouse-pointer
   move 1 steps

Experimentamos a extensão da caneta, usando o bloco “**pen down**” ("caneta para baixo") com uma condição:

when green flag clicked
forever
   go to mouse-pointer
   if **mouse down?** then
      pen down
   else
      pen up

Aqui, movemos o gato até o ponteiro do mouse, e se o mouse for clicado, ou para baixo, colocamos o “**pen down**”, que desenha. Caso contrário, colocamos a caneta para cima. Repetimos isso muito rapidamente, uma e outra vez, e então produzimos o efeito de desenhar sempre que mantemos o mouse pressionado.

Scratch também tem diferentes fantasias, ou imagens, que podemos usar para nossos personagens. Faremos um programa que pode contar:

when green flag clicked
set counter to 1
forever
     say counter for 1 seconds
     change counter by 1

Aqui, “counter” é uma variável, cujo valor podemos definir, usar e alterar. Vemos mais alguns programas, como o [salto](https://scratch.mit.edu/projects/277536611/editor/) , em que o gato se move para frente e para trás na tela para sempre, girando sempre que estivermos na borda da tela.

Podemos melhorar a animação fazendo com que o gato mude para uma roupa diferente a cada 10 passos no [bounce1](https://scratch.mit.edu/projects/277536630/editor/). Agora, quando clicamos na bandeira verde para executar nosso programa, vemos o gato alternar o movimento de suas pernas.

Podemos até gravar nossos próprios sons com o microfone de nosso computador e reproduzi-los em nosso programa.

Para construir programas cada vez mais complexos, começamos com cada um desses recursos mais simples e os colocamos em camadas um dentro do outro. Também podemos fazer o Scratch miar se tocarmos com o ponteiro do mouse, no [pet0](https://scratch.mit.edu/projects/277537223/editor/).

Na [bark](https://scratch.mit.edu/projects/326130490/editor/), não temos um, mas dois programas no mesmo projeto Scratch. Ambos os programas serão executados ao mesmo tempo depois que a bandeira verde for clicada. Um deles tocará um som de leão-marinho se a variável **silenciada** for configurada como **falsa**, e o outro configurará a variável silenciada de **verdadeiro** para **falso** ou de **falso** para **verdadeiro**, se a tecla de espaço for pressionada.

Outra extensão olha para o vídeo conforme capturado pela webcam do nosso computador e reproduz o som de miado se o vídeo tiver movimento acima de algum limite.

Com vários sprites ou personagens, podemos ter diferentes conjuntos de blocos para cada um deles:

when green flag clicked
forever
if **key [space]** pressed? then
     say Marco! for 2 seconds
     broadcast **event**

Para um fantoche, temos esses blocos que dizem “Marco!” E, em seguida, um bloco de “**broadcast**” (“transmitir”). Este “evento” é usado para nossos dois sprites se comunicarem, por exemplo enviando uma mensagem nos bastidores. Portanto, o nosso outro fantoche pode simplesmente esperar por este “evento” para dizer “Polo!”:

when I receive event
say _Polo!_ for 2 seconds

Também podemos usar a extensão “Translate” para dizer algo em outros idiomas:

when green flag clicked
ask _Qual é seu nome?_ and wait
say **translate** join [_olá_] answer to _English_

Aqui, o resultado do bloco “**join**” é usado como entrada para o bloco “**translate**”, cujo resultado é passado como entrada para o bloco “**say**”.

Agora que sabemos algumas noções básicas, podemos pensar sobre o design ou a qualidade de nossos programas. Por exemplo, podemos querer que o gato mia três vezes com o bloco "**repeat**"(repetir):

when green flag clicked
repeat 3
 play sound Meow until done
     wait 1 seconds

Podemos usar abstração, o que simplifica um conceito mais complexo. Neste caso, podemos definir nosso próprio bloco “miau” no Scratch e reutilizá-lo em outro lugar em nosso programa, como visto em [miau3](https://scratch.mit.edu/projects/421542702/editor/) . A vantagem é que não precisamos saber como o miado é implementado ou escrito em código, mas apenas usá-lo em nosso programa, tornando-o mais legível.

Podemos até definir um bloco com uma entrada em [meow4](https://scratch.mit.edu/projects/421543064/editor/) , onde temos um bloco que faz o gato miar um certo número de vezes. Agora podemos reutilizar esse bloco em nosso programa para miar qualquer número de vezes, da mesma forma como podemos usar os blocos “traduzir” ou “falar”, sem saber os detalhes de implementação ou como o bloco realmente funciona.

Vamos dar uma olhada em mais algumas demos, incluindo [Gingerbread tales remix](https://scratch.mit.edu/projects/277536784) e [Oscartime](https://scratch.mit.edu/projects/277537196/), que combinam loops, condições e movimento para criar um jogo interativo. Oscartime foi na verdade feito por David muitos anos atrás, e ele começou adicionando um sprite, então um recurso de cada vez, e assim por diante, até que eles acabassem formando um programa mais complicado.

Um ex-aluno, Andrew, criou o [Raining Men](https://scratch.mit.edu/projects/37412/). Embora Andrew tenha acabado não seguindo a ciência da computação como profissão, as habilidades de resolução de problemas, algoritmos e ideias que aprenderemos no curso são aplicáveis ​​em todos os lugares.


[Ver outros módulos](https://github.com/fernandacostads/cc50-harvard#m%C3%B3dulos)