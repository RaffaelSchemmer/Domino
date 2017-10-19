#ifndef domino_hpp
#define domino_hpp
struct pilha
{
	int topo;
	int posicao[28];
};
class peca // Declaracao da classe peca
{
	private:
		int direita; // Variaveis privadas que armazenam os valores das pedras
		int esquerda;
	public:
		void criar_peca(int); // Declaracao do metodo responsavel por criar valores as pedras de acordo com os indices passados a ela
		void ler_peca(int cont,int&,int&);  // Declaracao do metodo responsavel por ler os valores das pedras de acordo com o indice informado
};
class monte // Declaracao da classe monte
{
	private:
		struct pilha montes; // Estrutura que representa o monte de pedras como seu topo
		peca pecas[28]; // Instacia das 28 pedras do jogo
	public:
		void criar_monte(); // Declaracao do metodo responsavel por criar o monte(coloca valores em forma sequencial)
		void embaralhar_monte(); // Declaracao do metodo responsavel por embaralhar as pedras presentes no monte
		void retorno_valor_peca(int,int&,int&); // Declaracao do metodo que retorna o valor da pedra informada
		void ler_topo_monte(int&); // Declaraco do metodo que le o valor da pedra do topo do monte.
};	
class tabuleiro // Declaracao da classe tabuleiro
{
	private:
		int num_jogadas; // Variavel que armazena o numero de jogadas feitas no tabuleiro
		int tabuleiro[60]; // Vetor que armazena as posicoes do tabuleiro 
		int ponta_D; // Variavel que armazena o valor real da ponta direita do jogo
		int ponta_E; // Variavel que armazena o valor real da ponta esquerda do jogo
	public:
		int inserir(int&,int&,int&); // Declaracao do metodo respnsavel por inserir pedras no tabuleiro e atualizar seus valores
		void listar_posicao(int&,int&); // Declaracao do metodo responsavel por listar as posicoes da (direita-esquerda) do tabuleiro
		void inicia_tabuleiro(); // Declaracao do metodo responsavel por iniciar as posicoes (-1) do tabuleiro
		void retorno_tabuleiro(monte&,int[],int[],int[],int&); // Declaracao do metodo que retorna os valores atuais do tabuleiro
};
class jogador // Declaracao da classe jogador
{
	private:
		int mao[21]; // Variavel que armazena os valores da mao do jogador
		int num_pedras; // Armazena o numero de pedras da mao do jogador
	public:
		void criar_jogador(monte&); // Declaracao do metodo responsavel por criar um jogador
		int fazer_jogada(monte&,tabuleiro&); // Declaracao do metodo responsavel por fazer jogada do jogador virtual
		int fazer_jogada_fisica(monte&,tabuleiro&,int&,int&); // Declaracao do metodo responsavel por fazer as jogadas do jogador fisico
		void fazer_primeira_jogada(int,int,int,tabuleiro&,jogador&); // Declaracao do metodo responsavel por fazer as jogadas do jogador(Fisico-Virtual)
		void procurar_peca(int&,int&,monte&,int&,int&); // Declaracao do metodo que procura uma peca na mao do jogador
		int soma_pecas(); // Declaracao do metodo que soma o numero de pedras do jogador
		int verificar_vitoria(); // Declaracao do metodo que verifica se o jogador venceu
		void retorno_mao_virtual(monte&,int[],int&); // Declaracao do metodo que retorna os valores da mao virtual do jogador
		void retorno_mao_fisica(monte&,int[],int[],int[],int&);  // Declaraco do metodo que retorna os valores da mao fisica do jogador

};
class jogo // Declaracao da classe jogo
{
	private:
		jogador j1,j2,j3,j4; // Variaveis que instanciam a classe jogador
		monte obj_monte; // Variavel que instancia a classe monte
		tabuleiro tabua; // Variavel que instancia a classe tabuleiro
		int aux,auxp1,dir1,esq1,aux2,auxp4,auxp2,dir2,esq2,aux3,dir4,esq4,dir3,esq3,aux4,auxp3;
		int tabuleiro_D[60],tabuleiro_E[60];
		int mao_D[21],mao_E[21];
		int mv1[21],mv2[21],mv3[21];
		int tabuleir[60]; 
		int mao[21]; 
		int num_jogador,cont,jogadas;
		public:
		void inicio_jogo(int); // Declaracao do metodo que incia o jogo
		void controle_jogo(int); // Declaraco do metodo que controla o jogo
		void faz_primeira_jogada(int); // Declaraco do metodo que controla o jogo
		int verifica_somatorio_vitoria(int&,int,int,int);
		void set(int&,int&,int&,int&); // Declaracao do metodo que recebe os valores da interface do jogador fisico
		void get(int[],int[],int[],int[],int[],int[],int[],int[],int[],int&,int&,int&,int&,int&,int&,int&,int&,int&); // Declaracao do metodo que retorna os valores dos metodos internos do jogo a interface
};
#endif
