/* Universidade Regional Integrada do Alto uruguai e das Missões */
/* Metodos de jogabilidade do jogo de dominó orientado a objetos */
/* Disciplina : Linguagem de programacão II - 3 Semestre */
/* Professor : Mr.Luciano Lores Caimi */
/* Alunos : Raffael Bottoli Schemmer,Amilcar Bittencourt,Henrique Maurer,Roni Bigolin */
/* Data Termino : 10/07/2008 */
#ifndef domino_cpp 
#define domino_cpp
#include "domino.hpp" 
#include<time.h>
#include<cstdlib>
using namespace std;
//////////////////////////////////////////////////////// Definicao do metodo que inicializa o jogo de domino
void jogo::inicio_jogo(int num_jogadores)
{
	num_jogador = num_jogadores;
	obj_monte.criar_monte(); // Chama o metodo que cria o monte
	obj_monte.embaralhar_monte(); // Chama o metodo que embaralha o monte
	tabua.inicia_tabuleiro(); // Chama o metodo que inicializa o tabuleiro com zeros
	switch(num_jogadores) // Cria os jogadores de acordo com a entrada da interface (1,2,3) 
	{
		case(1): // Cria 2 jogadores(fisico-virtual)
		{
			j1.criar_jogador(obj_monte); // Cria jogador1(fisico) passando o monte como parametro
			j2.criar_jogador(obj_monte); // Cria jogador2(virtual) passando o monte como parametro
			break;
		}
		case(2): // Cria 3 jogadores(fisico-virtual-virtual)
		{
			j1.criar_jogador(obj_monte); // Cria jogador1(fisico) passando o monte como parametro
			j2.criar_jogador(obj_monte); // Cria jogador2(virtual) passando o monte como parametro
			j3.criar_jogador(obj_monte); // Cria jogador3(virtual) passando o monte como parametro
			break;
		}
		case(3): // Cria 3 jogadores(fisico-virtual-virtual-virtual)
		{
			j1.criar_jogador(obj_monte); // Cria jogador1(fisico) passando o monte como parametro
			j2.criar_jogador(obj_monte); // Cria jogador2(virtual) passando o monte como parametro
			j3.criar_jogador(obj_monte); // Cria jogador3(virtual) passando o monte como parametro
			j4.criar_jogador(obj_monte); // Cria jogador4(virtual) passando o monte como parametro
			break;
		}
	}
	faz_primeira_jogada(num_jogadores); // Chama o metodo controle do jogo passando o numero de jogadores como parametro
}
//////////////////////////////////////////////////////// Definicao do metodo que realiza o controle do jogo de domino
void jogo::faz_primeira_jogada(int num_jogadores) // Declaraco do metodo que controla o jogo
{
	switch(num_jogadores)
	{
		case(1):
		{
			j1.procurar_peca(aux,auxp1,obj_monte,dir1,esq1); // Procura a maior pedra da mao do jogador 1
			j2.procurar_peca(aux2,auxp2,obj_monte,dir2,esq2); // Procura a maior pedra do jogador 2
			if(aux > aux2) // Se o jogador 1 tiver a maior pedra a sequencia de jogadas é (jogador1 - jogador2)
			{
				j1.fazer_primeira_jogada(auxp1,dir1,esq1,tabua,j1);  // Jogador 1 faz a primeira jogada	
				j2.fazer_jogada(obj_monte,tabua);
			}
			if(aux2 > aux) // Se o jogador 2 tiver a maior pedra a sequencia de jogadas é (jogador2 - jogador1)
			{
				j2.fazer_primeira_jogada(auxp2,dir2,esq2,tabua,j2);
			}
			break;
		}
		case(2):
		{
			j1.procurar_peca(aux,auxp1,obj_monte,dir1,esq1); // Procura a maior pedra da mao do jogador 1
			j2.procurar_peca(aux2,auxp2,obj_monte,dir2,esq2); // Procura a maior pedra do jogador 2
			j3.procurar_peca(aux3,auxp3,obj_monte,dir2,esq2); // Procura a maior pedra do jogador 3
			if((aux > aux2) && (aux2 > aux3)) // Se o jogador 1 tiver a maior pedra a sequencia de jogadas é (jogador1 - jogador2 - jogador3)
			{
				j1.fazer_primeira_jogada(auxp1,dir1,esq1,tabua,j1);
				j2.fazer_jogada(obj_monte,tabua);
				j3.fazer_jogada(obj_monte,tabua);
			}
			if((aux2 > aux) && (aux2 > aux3)) // Se o jogador 2 tiver a maior pedra a sequencia de jogadas é (jogador2 - jogador1 - jogador3)
			{
				j2.fazer_primeira_jogada(auxp2,dir2,esq2,tabua,j2);
				j3.fazer_jogada(obj_monte,tabua);
			}
			if((aux3 > aux) && (aux3 > aux2)) // Se o jogador 3 tiver a maior pedra a sequencia de jogadas é (jogador3 - jogador1 - jogador2)
			{
				j3.fazer_primeira_jogada(auxp3,dir3,esq3,tabua,j3);
			}
			break;
		}
		case(3): 
		{
			j1.procurar_peca(aux,auxp1,obj_monte,dir1,esq1); // Procura a maior pedra do jogador 1
			j2.procurar_peca(aux2,auxp2,obj_monte,dir2,esq2); // Procura a maior pedra do jogador 2
			j3.procurar_peca(aux3,auxp3,obj_monte,dir3,esq3); // Procura a maior pedra do jogador 3
			j4.procurar_peca(aux4,auxp4,obj_monte,dir4,esq4); // Procura a maior pedra do jogador 4
			if((aux > aux2) && (aux > aux3) && (aux > aux4)) // Se o jogador 1 tiver a maior pedra a sequencia de jogadas é (jogador1 - jogador2 - jogador3 - jogador4)
			{
				j1.fazer_primeira_jogada(auxp1,dir1,esq1,tabua,j1);
				j2.fazer_jogada(obj_monte,tabua);
				j3.fazer_jogada(obj_monte,tabua);
				j4.fazer_jogada(obj_monte,tabua);
			}
			if((aux2  > aux) && (aux2 > aux3) && (aux2 > aux4)) // Se o jogador 2 tiver a maior pedra a sequencia de jogadas é (jogador2 - jogador1 - jogador3 - jogador4)
			{
				j2.fazer_primeira_jogada(auxp2,dir2,esq2,tabua,j2);
				j3.fazer_jogada(obj_monte,tabua);
				j4.fazer_jogada(obj_monte,tabua);
			}
			if((aux3 > aux) && (aux3 > aux2) && (aux3 > aux4)) // Se o jogador 3 tiver a maior pedra a sequencia de jogadas é (jogador3 - jogador1 - jogador2 - jogador4)
			{
				j3.fazer_primeira_jogada(auxp3,dir3,esq3,tabua,j3);
				j4.fazer_jogada(obj_monte,tabua);
			}
			if((aux4 > aux) && (aux4 > aux2) && (aux4 > aux3)) // Se o jogador 4 tiver a maior pedra a sequencia de jogadas é (jogador4 - jogador1 - jogador2 - jogador3)
			{
				j4.fazer_primeira_jogada(auxp4,dir4,esq4,tabua,j4);
			}
			break;
		}
	}
}
void peca::criar_peca(int cont)
{
	int vetor_pos_E[28],vetor_pos_D[28];
	vetor_pos_E[0] =0; // Sequencia de mapeamento dos indices das pedras do jogo de dominó
    vetor_pos_E[1] =0;
    vetor_pos_E[2] =0;
    vetor_pos_E[3] =0;
    vetor_pos_E[4] =0;
    vetor_pos_E[5] =0;
    vetor_pos_E[6] =0;
    vetor_pos_E[7] =1;
    vetor_pos_E[8] =1;
    vetor_pos_E[9] =1;
    vetor_pos_E[10]=1;
    vetor_pos_E[11]=1;
    vetor_pos_E[12]=1;
    vetor_pos_E[13]=2;
    vetor_pos_E[14]=2;
    vetor_pos_E[15]=2;
    vetor_pos_E[16]=2;
    vetor_pos_E[17]=2;
    vetor_pos_E[18]=3;
    vetor_pos_E[19]=3;
    vetor_pos_E[20]=3;
    vetor_pos_E[21]=3;
    vetor_pos_E[22]=4;
    vetor_pos_E[23]=4;
    vetor_pos_E[24]=4;
    vetor_pos_E[25]=5;
    vetor_pos_E[26]=5;
    vetor_pos_E[27]=6;
    vetor_pos_D[0]=0;
    vetor_pos_D[1]=1;
    vetor_pos_D[2]=2;
    vetor_pos_D[3]=3;
    vetor_pos_D[4]=4;
    vetor_pos_D[5]=5;
    vetor_pos_D[6]=6;
    vetor_pos_D[7]=1;
    vetor_pos_D[8]=2;
    vetor_pos_D[9]=3;
    vetor_pos_D[10]=4;
    vetor_pos_D[11]=5;
    vetor_pos_D[12]=6;
    vetor_pos_D[13]=2;
    vetor_pos_D[14]=3;
    vetor_pos_D[15]=4;
    vetor_pos_D[16]=5;
    vetor_pos_D[17]=6;
    vetor_pos_D[18]=3;
    vetor_pos_D[19]=4;
    vetor_pos_D[20]=5;
    vetor_pos_D[21]=6;
    vetor_pos_D[22]=4;
    vetor_pos_D[23]=5;
    vetor_pos_D[24]=6;
    vetor_pos_D[25]=5;
    vetor_pos_D[26]=6;
    vetor_pos_D[27]=6;
    esquerda = vetor_pos_E[cont]; // Retorna o valor da pedra a esquerda de acordo com o indice do contador informado
	direita = vetor_pos_D[cont]; // Retorna o valor da pedra a direita de acordo com o indice do contador informado
}
//////////////////////////////////////////////////////// Definicao do metodo que retorna o valor das casas (direita-esquerda) de uma determinada peca
void peca::ler_peca(int cont,int &_esquerda,int &_direita)  
{
	_direita = direita; // Retorna o valor da direita da pedra para o parametro de referencia _dirieta
	_esquerda = esquerda; // Retorna o valor da e esquerda pedra para o parametro de referencia _esquerda
}
//////////////////////////////////////////////////////// Definicao do metodo responsavel por criar o monte de pecas do jogo de domino
void monte::criar_monte()  
{
	for(montes.topo = 0;montes.topo < 28;montes.topo++) // Varre as 28 posicoes do monte
	{
		pecas[montes.topo].criar_peca(montes.topo); // Chama criar peca passando como parametro o valor do indice do monte
		montes.posicao[montes.topo] = montes.topo; // O valor da posicao do monte recebe o valor do contador
	}
	montes.topo--; // Decrementa topo para sincronizar a posicao de acordo com o contador
}
//////////////////////////////////////////////////////// Definicao do metodo responsavel por embaralhar o monte
void monte::embaralhar_monte() 
{
	int cont,cont1,aux;
	srand(time(NULL)); // Gerador de sementes
	for(cont=0;cont<28;cont++) // Varre as 28 pedras do monte alternando tais de posicao
	{
		do
		{
			cont1 = rand()%28; // Gera um valor aleatorio entre 0-28
		}while(cont1 < 0 || cont1 > 28);
		aux = montes.posicao[cont1]; // Faz uma variavel auxiliar receber o valor da posicao do monte indice contador
		montes.posicao[cont1] = montes.posicao[cont]; // A posicao recebe o valor presente no topo de indice do contador da estrutura
		montes.posicao[cont] = aux; // A posicao indice estrutura recebe o valor contido em aux
	}
}
//////////////////////////////////////////////////////// Definicao do metodo que retorna a peca do topo do monte
void monte::ler_topo_monte(int &cont) 
{
	if(montes.topo == -1)// Se o monte estiver vazio retorna (-1)
	{
		cont = -1;
	}
	else // Senao retorna o valor do topo do monte e decrementa o topo do monte
	{
		cont = montes.posicao[montes.topo];
		montes.topo--;
	}
}
//////////////////////////////////////////////////////// Definicao do metodo que retorna o valor das casas (direita-esquerda) de uma peca
void monte::retorno_valor_peca(int cont,int &_direita,int &_esquerda)
{
	pecas[cont].ler_peca(cont,_direita,_esquerda); // Retorna os valores lidos do retorno da chamada ao metodo ler peca da classe peca
}
//////////////////////////////////////////////////////// Definicao do metodo responsavel por criar jogadores
void jogador::criar_jogador(monte &obj_monte)
{
	int cont,cont1;
	for(cont=0;cont<7;cont++) // Cria 7 pecas para cada jogador
	{
		obj_monte.ler_topo_monte(cont1); // Le o topo do monte e coloca o valor lido na mao do jogador
		mao[cont] = cont1;
	}
	num_pedras=7; // Depois de dar as 7 pedras coloca o contador de numero de pedras em 7
}
//////////////////////////////////////////////////////// Definicao do metodo responsavel por procurar um valor na mão do jogador
void jogador::procurar_peca(int &cont1,int &cont2,monte &obj_monte,int &dir,int &esq)
{
	int cont=0,temp=0,aux=0,aux2=0,aux3=0,cont3=0,flag=0,cont4=0,aux4=0,aux5=0;
	for(cont=0;cont<7;cont++) // Procura na mao do jogador qual a maior pedra
	{
		obj_monte.retorno_valor_peca(mao[cont],aux,aux2); // Chama o metodo para obter o valor da pedra presente na mao
		aux3 = aux+aux2; // realiza o somatorio das pontas da pedra
		if(aux == aux2) // verifica se as pontas da pedra sao iguais
		{
			flag = 1; // se sim o flag marca em 1
			if(aux3 > (cont4)) // verifica se o somatorio das pontas(aux3) é maior que o cont4(var temp)
			{
				cont3 = cont; // se sim ele guarda a posicao da pedra em uma var temp(cont3)
				cont4 = aux + aux2; // troca o valor da variavel temp(cont4) pelo somatorio das pontas da pedra
				aux4 = aux; // troca o valor da esquerda
				aux5 = aux2; // troca o valor da direita
			}
		}
		else if(aux3 > temp) // caso as pontas nao sejam iguais ele testa se o somatorio das pontas(aux3) é maior que temp(var temp)
		{
			cont2 = cont; // se sim ele guarda a posicao da pedra em uma variavel temp(cont2)
			cont1 = aux+aux2; // guarda o somatorio das pontas na variavel cont1
			temp = aux3; // atualiza o valor da variavel temporaria com o novo valor de aux3
			esq = aux; // troca o valor da esquerda
			dir = aux2; // troca o valor da direita
		}
	}
	if(flag == 1) // caso o flag seja 1(indica que encontrou uma pedra com 2 lados iguais)
	{
		cont2 = cont3; // o cont2(retorno da posicao) recebe cont3 que armazena a posicao da pedra na mao do jogador
		cont1 = 100 + cont4; // o cont1(retorno valor da maior pedra) recebe 100 para dar superioridade de pedra de pontas iguais perante outras
		esq = aux4; // a ponta de retorno da esquerda recebe o valor contido na aux4
		dir = aux5; // a ponta de retorno da direita recebe o valor contido na aux5
	}
}
//////////////////////////////////////////////////////// Definicao do metodo responsavel por fazer as jogadas dos jogadores virtuais no jogo
int jogador::fazer_jogada(monte &obj_monte,tabuleiro &tabua)
{
	int cont,cont1,cont2,cont3,aux,aux2,flag=0;
	tabua.listar_posicao(cont,cont1); // solicita que o tabuleiro informe quais são as extremidades corrente do jogo 
	for(cont2=0;cont2<num_pedras;cont2++) // Verifica as pedras de acordo com o numero de pedras da mao do jogador
	{
		if(mao[cont2] != -1) // se o valor da pedra for diferente de -1 ele processa
		{
			obj_monte.retorno_valor_peca(mao[cont2],aux,aux2); // Solicita que o monte retorne as pontas do valor da pedra
			if(aux == cont) // verifica se as extremidades retornadas pelo monte batem com as pontas do tabuleiro
			{
				tabua.inserir(mao[cont2],aux,aux2); // Se sim insere essa nova pedra no tabuleiro
				flag = 1; // Marca o flag indicando que não vai ser preciso buscar no monte
				mao[cont2] = -1; // Apaga a peca da mao do jogador colocando -1
				return(1); // Retorna 1 se jogou com sucesso (encontrou pedra)
			}
			if(aux == cont1)
			{
				tabua.inserir(mao[cont2],aux,aux2);
				flag = 1;
				mao[cont2] = -1;
				return(1); // Retorna 1 se jogou com sucesso (encontrou pedra)
			}
			if(aux2 == cont)
			{
				tabua.inserir(mao[cont2],aux,aux2);
				flag = 1;
				mao[cont2] = -1;
				return(1); // Retorna 1 se jogou com sucesso (encontrou pedra)
			}
			if(aux2 == cont1)
			{
				tabua.inserir(mao[cont2],aux,aux2);
				flag = 1;
				mao[cont2] = -1;
				return(1); // Retorna 1 se jogou com sucesso (encontrou pedra)
			}
		}
	}
	if(flag == 0) // Se o flag não estiver em um quer dizer que ele nao encontrou pedras na mão
	{
		while(1) // Busca no monte enquanto não existir condicao de parada
		{
			obj_monte.ler_topo_monte(cont2); // Solicita leitura do topo do monte
			if(cont2 == -1) // Verifica se o topo do monte não é vasio
			{
				return(2); // Retorna 2 se ele não tem como jogar pedras
			}
			else // se o topo do monte não for vazio coloca a pedra na mão do jogador e verifica se ela é valida para ser inserida no tabuleiro
			{
				cont3 = num_pedras;
				num_pedras = num_pedras + 1;
				mao[cont3] = cont2; // coloca a pedra na mao do jogador
				obj_monte.retorno_valor_peca(mao[cont3],aux,aux2); // solicita que o monte retorne o valor da pedra
				if(aux == cont) // verifica se as extremidades retornadas pelo monte batem com as pontas do tabuleiro
				{
					tabua.inserir(mao[cont3],aux,aux2); // Se sim insere essa nova pedra no tabuleiro
					mao[cont3] = -1; // Marca com -1 a casa da mao informando que a peca foi consumida
					return(1); // Retorna 1 se jogou com sucesso (encontrou pedra)
				}
				if(aux == cont1)
				{
					tabua.inserir(mao[cont3],aux,aux2);
					mao[cont3] = -1;
					return(1); // Retorna 1 se jogou com sucesso (encontrou pedra)
				}
				if(aux2 == cont)
				{
					tabua.inserir(mao[cont3],aux,aux2);
					mao[cont3] = -1;
					return(1); // Retorna 1 se jogou com sucesso (encontrou pedra)
				}
				if(aux2 == cont1)
				{
					tabua.inserir(mao[cont3],aux,aux2);
					mao[cont3] = -1;
					return(1); // Retorna 1 se jogou com sucesso (encontrou pedra)
				}
			}
		}
	}
	return(0);
}
//////////////////////////////////////////////////////// Definicao do metodo responsavel por fazer as jogadas dos jogadores fisicos no jogo
int jogador::fazer_jogada_fisica(monte &obj_monte,tabuleiro &tabua,int &cont,int &cont2)
{
	int dir,esq,cont1,cont3;
	if(cont2 == 1) // Busca valor na mão
	{
		obj_monte.retorno_valor_peca(mao[cont],dir,esq);
		tabua.listar_posicao(cont1,cont3);
		if(dir == cont1)
		{
			tabua.inserir(mao[cont],dir,esq);
			mao[cont] = -1;
			return(1); // retorna 1 caso encontrou a pedra
		}
		if(dir == cont3)
		{
			tabua.inserir(mao[cont],dir,esq);
			mao[cont] = -1; 
			return(1); // retorna 1 caso encontrou a pedra
		}
		if(esq == cont1)
		{
			tabua.inserir(mao[cont],dir,esq);
			mao[cont] = -1;
			return(1); // retorna 1 caso encontrou a pedra
		}	
		if(esq == cont3)
		{
			tabua.inserir(mao[cont],dir,esq);
			mao[cont] = -1;
			return(1); // retorna 1 caso encontrou a pedra
		}
		return(3);
	}
	if(cont2 == 2) // Busca valor no monte
	{
		obj_monte.ler_topo_monte(cont3);
		if(cont3 == -1)
		{
			return(3); // Monte vazio
		}
		else
		{
			mao[num_pedras] = cont3;
			num_pedras = num_pedras + 1;
			return(0);
		}
	}
	if(cont2 == 3) // solicitou para pular
	{
		while(1)
		{
			obj_monte.ler_topo_monte(cont2);
			if(cont2 == -1)
			{
				return(2); // o monte esta vazio
			}
			else
			{
				return(3);// erro
			}
		}
	}
	return(0);
}	
//////////////////////////////////////////////////////// Definicão do metodo que realiza a primeira jogada do jogo
void jogador::fazer_primeira_jogada(int cont,int esq,int dir,tabuleiro &tabua,jogador &joga)
{
	tabua.inserir(mao[cont],esq,dir); // Insere os elemtnso passados como parametros no tabuleiro
	mao[cont] = -1; // coloca -1 para dizer que foi consumido o valor da mão
}
//////////////////////////////////////////////////////// Definicao do metodo que verifica se o jogador ganhou
int jogador::verificar_vitoria()
{
	int cont,cont1=0;
	for(cont=0;cont < num_pedras;cont++) // varre a mao atravez do numero de pedras
	{
		if(mao[cont] != -1) // se um dos valores da mao for diferente de -1 incrementa o contador
		{
			cont1++;
		}
	}
	if(cont1 != 0) // se no final do for o contador nao for incrementado é sinal que o jogador ganhou o jogo
	{
		return(0);
	}
	else
	{
		return(1);
	}
}
//////////////////////////////////////////////////////// Definicao do metodo que soma os valores das pecas restantes nas mãos de cada jogador
int jogador::soma_pecas()
{
	int cont,cont1=0;
	for(cont=0;cont<num_pedras;cont++) // verifica em toda a mao do jogador pelos valores diferentes de -1 e a cada encontrado incrementa o contador
	{
		if(mao[cont] != -1)
		{
			cont1 = cont1++;
		}
	}
	return(cont1); // retorna o valor somado para a chamada do metodo
}
//////////////////////////////////////////////////////// Definicao do metodo que insere no tabuleiro uma peca informada pela jogada
int tabuleiro::inserir(int &pos,int &esq,int &dir)
{
	if(num_jogadas == 0)
	{
		ponta_D = dir;
		ponta_E = esq;
		tabuleiro[30] = pos;
		num_jogadas++;
		return(1);
	}
	if(dir == ponta_E)  
	{
		ponta_E = esq;
		tabuleiro[30-num_jogadas] = pos;
		num_jogadas++;
		return(1);
	}
	if(esq == ponta_E) 
	{
		ponta_E = dir;
		tabuleiro[30-num_jogadas] = pos;
		num_jogadas++;
		return(1);
	}
	if(dir == ponta_D)
	{
		ponta_D = esq;
		tabuleiro[30+num_jogadas] = pos;
		num_jogadas++;
		return(1);
	}
	if(esq == ponta_D)
	{
		ponta_D = dir;
		tabuleiro[30+num_jogadas] = pos;
		num_jogadas++;
		return(1);
	}
	return(0);
}
//////////////////////////////////////////////////////// Definicao do metodo que lista as posicoes livres do tabuleiro para serem jogadas
void tabuleiro::listar_posicao(int &cont,int &cont1)
{
	cont = ponta_D; // retorna para cont o valor da ponta direita do tabuleiro
	cont1 = ponta_E; // retorna para cont1 o valor da ponta esquerda do tabuleiro
}
//////////////////////////////////////////////////////// Definicao do metodo que inicia as posicoes do tabuleiro com zero
int jogo::verifica_somatorio_vitoria(int &aux1,int aux2,int aux3,int aux4)
{
	int num1=0,num2=0,num3=0,num4=0;
	switch(num_jogador) // Verifica qual numero de jogadores estão jogando
	{
		case(1): // Dois jogadores
		{
			if(aux1 == 2 && aux2 == 2) // verifica se o retorno das jogadas for igual a 2
			{
				num1 = j1.soma_pecas(); // realiza o somatorio do numero de pedras do jogador 1
				num2 = j2.soma_pecas(); // realiza o somatorio do numero de pedras do jogador 2
				if(num1 < num2) // Se o jogador 1 tem mais pedras retorna 2 para o parametro por referencia(jogador 2 ganhou)
				{
					aux1 = 1;
					return(1);
				}
				if(num2 < num1) // Se o jogador 2 tem mais pedras retorna 1 para o parametro por referencia(jogador 1 ganhou)
				{
					aux1 = 2;
					return(1);
				}
			}
			break;
		}
		case(2): // Tres jogadores
		{ 
			if(aux1 == 2 && aux2 == 2 && aux3 == 2)
			{
				aux1 = j1.soma_pecas();
				aux2 = j2.soma_pecas();
				aux3 = j3.soma_pecas();
				if(num1 < num2 < num3)
				{
					aux1 = 1;
					return(1);
				}
				if(num2 < num1 < num3)
				{
					aux1 = 2;
					return(1);
				}
				if(num3 < num1 < num2)
				{
					aux1 = 3;
					return(1);
				}
			}
			break;
		}
		case(3): // Quatro jogadores
		{
			if(aux1 == 2 && aux2 == 2 && aux3 == 2 && aux4 == 2)
			{
				num1 = j1.soma_pecas();
				num2 = j2.soma_pecas();
				num3 = j3.soma_pecas();
				num4 = j4.soma_pecas();
				if(num1 < num2 < num3 < num4) 
				{
					aux1 = 1;
					return(1);
				}	
				if(num2 < num1 < num3 < num4)
				{
					aux1 = 2;
					return(1);
				}
				if(num3 < num1 < num2 < num4)
				{
					aux1 = 3;
					return(1);
				}	
				if(num4 < num1 < num2 < num3)
				{
					aux1 = 4;
					return(1);
				}
			}
			break;
		}
	}
	return(0);
}
//////////////////////////////////////////////////////// Definicao do metodo que imprime os valores da mão do jogador
void tabuleiro::inicia_tabuleiro()
{
	int cont;
	num_jogadas=0;
	for(cont=0;cont<60;cont++) // Inicializa todo o tabuleiro com (-1) posicao livre
	{
		tabuleiro[cont] = -1;
	}
}
//////////////////////////////////////////////////////// Definicao do metodo que retorna os valores da mao do jogador virtual para a classe jogo
void jogador::retorno_mao_virtual(monte &obj_monte,int mv[21],int &ret1) 
{
	int cont,aux,aux2,cont2; // Variaveis temporarias
	for(cont=0;cont<num_pedras;cont++) // Imprime enquanto o contador for menor que o numero de pedras da mao
	{
		cont2 = cont;// variavel auxiliar recebe o valor do contador
		cont = mao[cont]; // contador recebe o conteudo da mao de indice contador
		if(cont != -1) // Se o valor for -1 quer dizer que a pedra não é valida
		{
			obj_monte.retorno_valor_peca(cont,aux,aux2); // Chama o metodo que retorna para aux e aux2 os valores da pedra indice contador
			mv[cont2] = cont;
			cont = cont2; // Contador recebe seu valor antigo armazenado por cont2
		}
		else
		{
			mv[cont2] = -1;
		}
		cont = cont2; // Contador recebe seu valor antigo armazenado por cont2
	}
	ret1 = num_pedras; // retorna para jogo o valor do numero de pedras do jogador virtual
}
//////////////////////////////////////////////////////// Definicao do metodo que retorna os valores da mao do jogaor fisico para a classe jogo
void jogador::retorno_mao_fisica(monte &obj_monte, int maos[21],int maos_D[21],int maos_E[21], int &pedra) 
{
	int cont,aux,aux2,cont2; // Variaveis temporarias
	for(cont=0;cont<num_pedras;cont++) // Imprime enquanto o contador for menor que o numero de pedras da mao
	{
		cont2 = cont;// variavel auxiliar recebe o valor do contador
		cont = mao[cont]; // contador recebe o conteudo da mao de indice contador
		if(cont != -1) // Se o valor for -1 quer dizer que a pedra não é valida
		{
			obj_monte.retorno_valor_peca(cont,aux,aux2); // Chama o metodo que retorna para aux e aux2 os valores da pedra indice contador
			maos[cont2] = cont;
			maos_E[cont2] = aux;
			maos_D[cont2] = aux2;
			cont = cont2; // Contador recebe seu valor antigo armazenado por cont2
		}
		else
		{
			maos[cont2] = -1;
		}
		cont = cont2; // Contador recebe seu valor antigo armazenado por cont2
	}
	pedra = num_pedras;
}
//////////////////////////////////////////////////////// Definicao do metodo que retorna os valores do tabuleiro para a classe jogo
void tabuleiro::retorno_tabuleiro(monte &obj_monte,int tabu[60],int tabu_D[60],int tabu_E[60],int &jogadas)
{
	int cont,esq,dir; // Variaveis temporarias
	for(cont=0;cont<60;cont++) // Varre o tabuleiro imprimindo suas posicoes
	{
		if(tabuleiro[cont] != -1)
		{
			obj_monte.retorno_valor_peca(tabuleiro[cont],esq,dir); // Solicita o valor contido em tabuleiro indice contador para o metodo que retorna os valores da pedra para esq e dir
			tabu[cont] = tabuleiro[cont];
			tabu_D[cont] = dir; // tabuleiro indice cont vai receber o valor dir retornado pelo monte 
			tabu_E[cont] = esq; // tabuleiro indice cont vai receber o valor esq retornado pelo monte 
		}	
		else
		{	
			tabu[cont] = -1; // caso o tabuleiro não for -1 ele deve receber (-1)
		}
	}
	jogadas = num_jogadas;
}
//////////////////////////////////////////////////////// Definicao do metodo que retorna os valores das maos do jogadores como do tabuleiro e flags informando o numero de pedras em cada mão e se existe algum vencedor a cada rodada executada
void jogo::get(int mv1[21],int mv2[21],int mv3[21],int tabuleir[60],int tabuleiro_D[60],int tabuleiro_E[60],int mao[21],int mao_D[21],int mao_E[21],int & ret1,int & ret2,int & ret3, int & ret4, int & aux,int & aux2,int & aux3,int &esq,int &dir)
{
	switch(num_jogador) // Retorna os valores do jogo para a interface de acordo com o numero de jogadores em execucao
	{
		case(1):
		{
			j1.retorno_mao_fisica(obj_monte,mao,mao_D,mao_E,ret4); // Chama o metodo que retorna os valores da mao do jogador fisico
			j2.retorno_mao_virtual(obj_monte,mv1,ret1); // Chama o metodo que retorna os valores da mao do jogador virtual 
			tabua.retorno_tabuleiro(obj_monte,tabuleir,tabuleiro_D,tabuleiro_E,jogadas); // Chama o metodo que retorna os valores do tabuleiro
			tabua.listar_posicao(esq,dir); // Chama o metodo que retorna os valores das extremidades do tabuleiro
			break; 
		}
		case(2):
		{
			j1.retorno_mao_fisica(obj_monte,mao,mao_D,mao_E,ret4);
			j2.retorno_mao_virtual(obj_monte,mv1,ret1);
			j3.retorno_mao_virtual(obj_monte,mv2,ret1);
			tabua.retorno_tabuleiro(obj_monte,tabuleir,tabuleiro_D,tabuleiro_E,jogadas);
			tabua.listar_posicao(esq,dir);
			break;
		}
		case(3):
		{
			j1.retorno_mao_fisica(obj_monte,mao,mao_D,mao_E,ret4);
			j2.retorno_mao_virtual(obj_monte,mv1,ret1);
			j3.retorno_mao_virtual(obj_monte,mv2,ret1);
			j4.retorno_mao_virtual(obj_monte,mv3,ret1);
			tabua.retorno_tabuleiro(obj_monte,tabuleir,tabuleiro_D,tabuleiro_E,jogadas);
			tabua.listar_posicao(esq,dir);
			break;
		}
	}
}
//////////////////////////////////////////////////////// Definicao do metodo que recebe os valores da jogada do jogador fisico como da posicao da pedra em sua mao e retorna se na rodada já existe algum vencedor
void jogo::set(int &ret1,int &ret2,int &ret3,int &ret4)
{	
	int cont1;
	ret3=0;
	switch(num_jogador) // Seta os valores provindos da interface de acordo com o numero de jogadores em execucao
	{
		case(1):
		{
			cont1 = ret1; // Salva temporariamente em cont1 o valor de ret1 vindo da interface
			aux = j1.fazer_jogada_fisica(obj_monte,tabua,ret2,ret1); // Realiza a jogada do jogador fisico com os dados vindos da interface
			ret1 = cont1; // Coloca novamente o valor de ret1 que estava na temporaria cont1
			if(aux == 3 && ret1 == 1){ret1 = 1;ret2 = 2;break;} 
			// Caso o valor retornado pelo metodo fazer jogada fisica for (3) e a entrada do jogador tinha sido (1) ele retorna em ret1 1(Sinal de que a jogada tem erros) e em ret2 (3) indicando que a pedra informada não bate com as extremidades do tabuleiro
			if(aux == 2 && ret1 == 2){ret1 = 1;ret2 = 3;break;} // Retorna em ret2 3 informando que o monte esta vazio
			if(aux == 0 && ret1 == 2){break;} 
			if(aux == 3 && ret1 == 2){ret1 = 1;ret2 = 3;break;} 
			if(aux == 3 && ret1 == 3){ret1 = 1;ret2 = 1;break;}
			ret1 = 0; // Zera a variavel de retorno de erros caso nao tenha sido encontrado erros na jogada do jogador fisico
			if(j1.verificar_vitoria() == 1){ret3 = 1;ret4 = 1;break;} // Verifica se o jogador fisico ganhou
			aux2 = j2.fazer_jogada(obj_monte,tabua); // Realiza a jogada do jogador virtual
			if(j2.verificar_vitoria() == 1){ret3 = 1;ret4 = 2;break;} // Verifica se o jogador virtual ganhou
			if(verifica_somatorio_vitoria(aux,aux2,aux3,aux4) == 1){ret3 = 1;ret4 = aux;break;}; // Verifica se os jogadores não tem mais pedras a jogar e faz o somatorio das pedras restantes retornando o vencedor
			ret3 = 0;
			break;
		}
		case(2): // Condicao para 3 jogadores (Fisico-Virtual-Virtual)
		{
			cont1 = ret1;
			aux = j1.fazer_jogada_fisica(obj_monte,tabua,ret2,ret1);
			ret1 = cont1;
			if(aux == 3 && ret1 == 1){ret1 = 1;ret2 = 2;break;}
			if(aux == 2 && ret1 == 2){ret1 = 1;ret2 = 3;break;}
			if(aux == 0 && ret1 == 2){break;}
			if(aux == 3 && ret1 == 2){ret1 = 1;ret2 = 3;break;}
			if(aux == 3 && ret1 == 3){ret1 = 1;ret2 = 1;break;}
			ret1 = 0;
			if(j1.verificar_vitoria() == 1){ret3 = 1;ret4 = 1;break;}			
			aux2 = j2.fazer_jogada(obj_monte,tabua);
			if(j2.verificar_vitoria() == 1){ret3 = 1;ret4 = 2;break;}
			aux3 = j3.fazer_jogada(obj_monte,tabua);			
			if(j3.verificar_vitoria() == 1){ret3 = 1;ret4 = 3;break;}
			if(verifica_somatorio_vitoria(aux,aux2,aux3,aux4) == 1){ret3 = 1;ret4 = aux;break;};
			ret3 = 0;
			break;
		}
		case(3): // Condicao para 4 jogadores (Fisico-Virtual-Virtual-Virtual)
		{
			cont1 = ret1;
			aux = j1.fazer_jogada_fisica(obj_monte,tabua,ret2,ret1);
			ret1 = cont1;
			if(aux == 3 && ret1 == 1){ret1 = 1;ret2 = 2;break;}
			if(aux == 2 && ret1 == 2){ret1 = 1;ret2 = 3;break;}
			if(aux == 0 && ret1 == 2){break;}
			if(aux == 3 && ret1 == 2){ret1 = 1;ret2 = 3;break;}
			if(aux == 3 && ret1 == 3){ret1 = 1;ret2 = 1;break;}
			ret1 = 0;
			if(j1.verificar_vitoria() == 1){ret3 = 1;ret4 = 1;break;}			
			aux2 = j2.fazer_jogada(obj_monte,tabua);
			if(j2.verificar_vitoria() == 1){ret3 = 1;ret4 = 2;break;}
			aux3 = j3.fazer_jogada(obj_monte,tabua);			
			if(j3.verificar_vitoria() == 1){ret3 = 1;ret4 = 3;break;}
			if(verifica_somatorio_vitoria(aux,aux2,aux3,aux4) == 1){ret3 = 1;ret4 = aux;break;};
			aux4 = j4.fazer_jogada(obj_monte,tabua);			
			if(j4.verificar_vitoria() == 1){ret3 = 1;ret4 = 4;break;}
			if(verifica_somatorio_vitoria(aux,aux2,aux3,aux4) == 1){ret3 = 1;ret4 = aux;break;};
			ret3 = 0;
			break;
		}
	}
}
#endif
