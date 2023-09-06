Exercício 2: Fiftyville

Escreva consultas SQL para resolver um mistério.

Um mistério em Fiftyville

O pato de estimação do CC50 foi roubado! A cidade de Fiftyville o convocou para resolver o mistério do pato roubado. Autoridades acreditam que o ladrão roubou o pato e, pouco depois, voou para fora da cidade com a ajuda de um cúmplice. Seu objetivo é identificar:

- Quem é o ladrão,
- Para qual cidade o ladrão fugiu, e
- Quem é o cúmplice do ladrão que os ajudou a escapar

Tudo o que você sabe é que o roubo ocorreu em 28 de julho de 2020 na Chamberlin Street.

Como você resolverá esse mistério? As autoridades de Fiftyville pegaram alguns dos registros da cidade na época do roubo e prepararam um banco de dados SQLite para você, fiftyville.db, que contém tabelas de dados de toda a cidade. Você pode consultar essa tabela usando consultas SQL SELECT para acessar os dados de seu interesse. Usando apenas as informações do banco de dados, sua tarefa é resolver o mistério.

Começando: Veja como baixar esse problema em seu próprio IDE CS50. Faça login no CS50 IDE e, em uma janela de terminal, execute cada um dos itens abaixo.

- Navegue até o diretório pset7 que já deve existir.
- Execute wget https://cdn.cs50.net/2020/fall/psets/7/fiftyville/fiftyville.zip para baixar um arquivo ZIP (compactado) com a distribuição desse problema.
- Execute unzip fiftyville.zip para descompactar esse arquivo.
- Execute rm fiftyville.zip seguido por yes ou y para excluir o arquivo ZIP.
- Execute ls. Você deve ver um diretório chamado fiftyville, que estava dentro desse arquivo ZIP.
- Execute cd fiftyville para mudar para esse diretório.
- Execute ls. Você deve ver um arquivo fiftyville.db, um arquivo log.sql e um arquivo answers.txt.
- Execute .tables, .schema pra visualizar os nomes das tabelas e do esquema, essa é uma dica.

Minha solução:

Para identificar o ladrão, a cidade em que ele fugiu e o cúmplice que o ajudou a escapar, precisamos realizar várias consultas SQL nas tabelas relevantes. Vamos abordar cada parte do mistério separadamente.

1. Identificar o Ladrão:
   Primeiro, vamos procurar por registros de crime na Chamberlin Street que ocorreram em 28 de julho de 2020. Vamos assumir que o ladrão esteja associado a esse crime. Precisamos verificar a tabela crime_scene_reports para obter informações sobre o crime e depois relacioná-las com as pessoas envolvidas. Aqui está uma consulta SQL que pode ajudar:

```sql
SELECT c.id AS crime_id, c.year, c.month, c.day, c.description, p.name AS suspect_name
FROM crime_scene_reports c
JOIN phone_calls pc ON c.year = pc.year AND c.month = pc.month AND c.day = pc.day AND c.street = 'Chamberlin Street'
JOIN people p ON pc.caller = p.phone_number;

```

Essa consulta relaciona os registros de crime na Chamberlin Street em 28 de julho de 2020 com a pessoa associada à conta bancária usada naquele local e data. Isso pode nos ajudar a identificar o ladrão.

2.Identificar a Cidade de Fuga:
Depois de identificar o ladrão, podemos procurar registros de voos relacionados a essa pessoa no mesmo dia ou dias subsequentes. A tabela flights contém informações sobre voos, incluindo origem e destino. Aqui está uma consulta para encontrar a cidade de fuga:
Primeiro, vamos encontrar o voo associado ao ladrão:
```sql
SELECT DISTINCT f.id AS flight_id
FROM flights f
JOIN passengers p ON f.id = p.flight_id
JOIN people pe ON p.passport_number = pe.passport_number
WHERE pe.name = 'Logan' AND f.year = 2020 AND f.month = 7 AND f.day = 28;

```

Substitua 'NOME_DO_LADRÃO' pelo nome do ladrão que identificamos na primeira consulta.

Em seguida, vamos encontrar a cidade de destino desse voo:

``` sql
SELECT DISTINCT a.city AS destination_city
FROM flights f
JOIN airports a ON f.destination_airport_id = a.id
WHERE f.id = 'ID_DO_VOO_ASSOCIADO_AO_LADRÃO';

```
Substitua 'ID_DO_VOO_ASSOCIADO_AO_LADRÃO'(41) pelo ID do voo que você encontrou na consulta anterior. Isso deve fornecer a cidade de destino do voo do ladrão.
ou faça tudo de uma vez com:

``` sql
SELECT DISTINCT a.city AS destination_city
FROM flights f
JOIN airports a ON f.destination_airport_id = a.id
WHERE f.year = 2020 AND f.month = 7 AND f.day >= 28
AND f.origin_airport_id = (
    SELECT origin_airport_id
    FROM flights
    WHERE id = (
        SELECT flight_id
        FROM passengers
        WHERE passport_number = (SELECT passport_number FROM people WHERE name = 'Logan')
    )
);

```

Finalmente, vamos encontrar o possível cúmplice olhando para os passageiros do mesmo voo!

3.Identificar o Cúmplice:
Agora que temos a cidade de fuga, podemos procurar por pessoas associadas a voos com o mesmo destino na mesma data. Essas pessoas podem ser cúmplices do ladrão. Aqui está uma consulta para encontrar o cúmplice:

```sql
SELECT DISTINCT pe.name AS accomplice_name
FROM passengers pa
JOIN people pe ON pa.passport_number = pe.passport_number
WHERE pa.flight_id = 'ID_DO_VOO_ASSOCIADO_AO_LADRÃO' AND pe.name != 'NOME_DO_LADRÃO';
```

The THIEF is: Logan
The thief ESCAPED TO:fiftyville
The ACCOMPLICE is:
Gregory
Debra
Jeremy
Frances
Barbara
Austin
Dorothy
