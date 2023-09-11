#### 1. instruções:

Veja como baixar este laboratório em seu próprio CS50 IDE. Faça login no CS50 IDE e, em uma janela de terminal, execute cada um dos itens abaixo.

- Execute cd para garantir que você está em ~/ (ou seja, seu diretório pessoal, também conhecido como ~ ).
- Execute wget https://cdn.cs50.net/2020/fall/labs/7/lab7.zip para baixar um arquivo ZIP (compactado) com a distribuição desse problema.
- Execute unzip lab7.zip para descompactar esse arquivo.
- Execute rm lab7.zip seguido por yes ou y para excluir o arquivo ZIP.
- Execute ls. Você deve ver um diretório chamado lab7 , que estava dentro desse arquivo ZIP.
- Execute cd lab7.zip para mudar para esse diretório.
- Execute ls. Você deve ver um arquivo songs.db , e alguns arquivos .sql vazios também.

#### 2. Entendendo o problema

Foi fornecido a você é um arquivo chamado songs.db, um banco de dados SQLite que armazena dados do Spotify sobre músicas e seus artistas. Este conjunto de dados contém as 100 principais músicas transmitidas no Spotify em 2018. Em uma janela de terminal, execute sqlite3 songs.db para que você possa começar a executar consultas no banco de dados.

Primeiro, quando sqlite3 solicitar que você forneça uma consulta, digite .schema e pressione Enter. Isso produzirá as declarações de output CREATE TABLE que foram usadas para gerar cada uma das tabelas no banco de dados. Ao examinar essas declarações, você pode identificar as colunas presentes em cada tabela.

Observe que todo artist tem um id e um name . Observe, também, que cada música tem um name , um artist_id (correspondendo ao id do artista da música), bem como valores para dançabilidade, energia, tonalidade, volume, prolixidade (presença de palavras faladas em uma música), valência, ritmo e duração da música (medido em milissegundos).

O desafio à sua frente é escrever consultas SQL para responder a uma variedade de perguntas diferentes, selecionando dados de uma ou mais dessas tabelas.

#### 3. Detalhes de implementação

Para cada um dos problemas a seguir, você deve escrever uma única consulta SQL que produza os resultados especificados por cada problema. Sua resposta deve ter a forma de uma única consulta SQL, embora você possa aninhar outras consultas dentro de sua consulta. Você não deve presumir nada sobre os ids de nenhuma música ou artista em particular: suas perguntas devem ser precisas mesmo se o id de qualquer música ou pessoa em particular for diferente. Finalmente, cada consulta deve retornar apenas os dados necessários para responder à pergunta: se o problema pede apenas que você envie os nomes das músicas, por exemplo, sua consulta não deve também produzir o tempo de cada música.

- No 1.sql, escreva uma consulta SQL para listar os nomes de todas as músicas no banco de dados.
Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada música.
```sql
SELECT name AS song_name
FROM songs;
```
- No 2.sql, escreva uma consulta SQL para listar os nomes de todas as músicas em ordem crescente de ritmo.
Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada música.
```sql
SELECT name AS song_name
FROM songs
ORDER BY tempo ASC;

```
- No 3.sql, escreva uma consulta SQL para listar os nomes das 5 músicas mais longas, em ordem decrescente de duração.
Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada música.
```sql
SELECT name AS song_name
FROM songs
ORDER BY duration_ms DESC
LIMIT 5;
```
- No 4.sql, escreva uma consulta SQL que liste os nomes de quaisquer músicas que tenham dançabilidade, energia e valência maior que 0,75.
Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada música.
```sql
SELECT name AS song_name
FROM songs
WHERE danceability > 0.75 AND energy > 0.75 AND valence > 0.75;

```
- No 5.sql, escreva uma consulta SQL que retorne a energia média de todas as músicas.
Sua consulta deve gerar uma tabela com uma única coluna e uma única linha contendo a energia média.
```sql
SELECT AVG(energy) AS average_energy
FROM songs;
```
- No 6.sql, escreva uma consulta SQL que lista os nomes das músicas de Post Malone.
Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada música.
Você não deve fazer suposições sobre qual é o artist_id de Post Malone.
```sql
SELECT s.name AS song_name
FROM songs s
JOIN artists a ON s.artist_id = a.id
WHERE a.name = 'Post Malone';
```
- No 7.sql, escreva uma consulta SQL que retorne a energia média das músicas de Drake.
Sua consulta deve gerar uma tabela com uma única coluna e uma única linha contendo a energia média.
Você não deve fazer suposições sobre qual é o artist_id de Drake.
```sql
SELECT AVG(s.energy) AS average_energy
FROM songs s
JOIN artists a ON s.artist_id = a.id
WHERE a.name = 'Drake';
```
- No 8.sql, escreva uma consulta SQL que lista os nomes das músicas que apresentam “feat.” (participação) de outros artistas.
Músicas que apresentam outros artistas incluirão “feat.” no nome da música.
Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada música.
```sql
SELECT name AS song_name
FROM songs
WHERE name LIKE '%feat.%';
```