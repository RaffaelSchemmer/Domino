Implementação e documentação do jogo de dominó orientado a objetos em C++
========

Visão geral do repositório:
-----------
1. domino.cpp: Implementa as classes principais das regras do jogo.
2. domino.hpp: Interface (biblioteca) que permite acesso das classes do arquivo CPP.
3. interface.cpp: Implementa as classes principais das telas da interface do jogo.
4. interface.hpp: Interface (biblioteca) que permite acesso das classes do arquivo CPP.
5. main.cpp: Classe principal que chama a interface gráfica (scanf/printf).

Compilando o código fonte do jogo
-----------
```
g++ domino.cpp domino.hpp interface.cpp interface.hpp main.cpp -o domino
```

Executando o jogo
-----------
```
./domino
```

Como Jogar
-----------
```
1. O jogador humano deve escolher entre um até 3 jogadores virtuais.
2.	Cada jogador recebe 7 peças
3. Quem possuir a maior peca de lados iguais começa jogando. Caso nenhum dos jogadores possuir pedras com lados iguais, todos da mesa devem somar os valores dos lados de cada pedra e qual o jogador tiver o valor do somatório dos lados começa jogando esta pedra na mesa.
4. A seqüência de jogadas acontece no sentido anti-horário do primeiro a jogar.
5. Jogar uma pedra significa ler da mão procurando pedras com lados iguais aos do tabuleiro e jogar tais ao tabuleiro.
6. Caso a mão não conter lados iguais ao tabuleiro o jogador deve se dirigir ao monte e buscar peca por peca verificando se tal contem um dos lados iguais aos do tabuleiro.
7. Caso o monte seja lido até o fim e o jogador não encontre uma pedra valida, ele deve passar a vez para que os jogadores continuem jogando suas pedras.
8. Ganha o jogo quem não tiver nenhuma pedra na mão
9. Se acontecer a exceção de unanimidade dos jogadores não terem mais pedras para jogar na mesa e o monte estiver vazio, soma-se o numero de pedras da mão de cada jogador e quem conter o menor numero de pedras ganha o jogo.

```

Novas funcionalidades (Futuro):
-----------

- Adição de um ranking com as melhores pontuações (utilizando arquivos).
- Desenvolvimento de versão com interface gráfica (Borland C++).
- Adição de níveis de dificuldade para o computador virtual.
