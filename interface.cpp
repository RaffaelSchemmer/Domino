/* Universidade Regional Integrada do Alto uruguai e das Missões */
/* Interface em modo texto do jogo de dominó orientado a objetos */
/* Disciplina : Linguagem de programacão II - 3 Semestre */
/* Professor : Mr.Luciano Lores Caimi */
/* Alunos : Raffael Bottoli Schemmer,Amilcar Bittencourt,Henrique Maurer,Roni Bigolin */
/* Data Termino : 10/07/2008 */
#ifndef interface_cpp
#define inetrface_cpp
#include <iostream>
#include "interface.hpp"
#include <cstdlib>
using namespace std;
void interface::controle_jogo()
{
	while(1)
	{
		system("cls");
		do
		{
			cout << "\n\n\t\t       || ------------- Domino ------------- ||"; // Menu de interacão com o usuario
			cout << "\n\n\n\n\t\t\t      1 - Jogar\n\n\t\t\t      2 - Sair\n\n\t\t\t\t\t\t Opcao [ ]\b\b";
			cin >> opcao1;
			if(opcao1 != 1 && opcao1 != 2) // Testa a entrada do usuario
			{
				cout << "\n\nOpcao invalida !!\n\n";
				system("pause");
				system("cls");
			}
		}while(opcao1 != 1 && opcao1 != 2); // Condicao de entrada de valor
		if(opcao1 == 2) // Teste para sair do jogo
		{
			break;
		}
		do
		{
			system("cls");
			cout << "\n\nEntre com o numero de jogadores virtuais {1,2,3} : [ ]\b\b"; // Solicita o numero de jogadores virtuais
			cin >> opcao;
			if(opcao != 1 && opcao != 2 && opcao != 3) // Testa a entrada do usuario
			{
				cout << "\nOpcao invalida !!\n\n";
				system("pause");
			}
		}while(opcao != 1 && opcao != 2 && opcao != 3); // Condicao de entrada de valor
		play.inicio_jogo(opcao); // Chama o metodo inicio de jogo que cria o tabuleiro o monte e os jogadores de acordo com o numero passado por parametro
		if(opcao == 1) // (Fisico/Virtual)
		{
			while(1) // Condicao para executar enquanto não houver ganhador
			{
				system("cls");
				play.get(mv1,mv2,mv3,tabuleir,tabuleir_D,tabuleir_E,mao,mao_D,mao_E,ret1,ret2,ret3,ret4,aux,aux2,aux3,esq,dir); 
				// Chama o metodo get que retorna os valores da rodada em execucao da mao do jogadores como do tabuleiro
				cout << "\t\t       || ------------- Domino ------------- ||";
				cout << "\n\n\n\n Mao Virtual : { ";
				for(cont=0;cont<ret1;cont++) // Imprime o numero de pedras em forma de * da mao virtual
				{
					if(mv1[cont] != -1)
					{
						cout << "[*] ";
					}
				}
				cout << "}\n";
				cout << "\n\n Tabuleiro : ";
				cout << "Pontas [" << dir << ":" << esq << "] { ";
				for(cont=0;cont<60;cont++) // Imprime o tabuleiro na interface
				{
					if(tabuleir[cont] != -1)
					{
						cout << "[" << tabuleir_E[cont] << tabuleir_D[cont] <<  "] ";
					}
				}
				cout << "}\n";
				cout << "\n\n Mao Fisica : { ";
				for(cont=0;cont <ret4;cont++) // Imprime o valor da mao fisica do jogador
				{
					if(mao[cont] != -1)
					{
						cout << cont+1 << ":[" << mao_E[cont] << mao_D[cont] << "] ";
					}
				}
				cout << "}\n\n";
				// Solicita que o usuario entre com a jogada (jogar pedra/busca no monte/ passa a jogada)
				cout << "\n\n Entre com o que voce deseja fazer : " << endl << "\n 1 - Jogar Pedra\n 2 - Pescar Monte\n 3 - Pular\n\n\t\t    Opcao [ ]\b\b";
				cin >> ret1;
				if(ret1 == 2 || ret1 == 3) // verifica se a jogada foi busca ou passa
				{
					play.set(ret1,ret2,ret3,ret4); // Chama o metodo set que realiza a jogada e retorna se tal foi concluida ou não com sucesso como se existe algum vencedor
				}
				else if(ret1 == 1) // verifica se a jogada foi jogar pedra
				{
					cout << "\n\n Entre com o indice da pedra a jogar : [  ]\b\b\b"; // Solicita que o usuario entre com o indice da pedra de sua mao
					cin >> ret2;
					ret2--;
					play.set(ret1,ret2,ret3,ret4);
				}
				if(ret1 == 1 && ret2 == 2) // Verifica se o retorno tem erro(ret1 == 1) e qual o tipo de erro (2 = valores da pedra jogada nao batem com os do tabuleiro na rodada)
				{
					cout << "\n\nA pedra jogada nao e valida para as extremidades do tabuleiro !!\n\n";
					system("pause");
				}	
				if(ret1 == 1 && ret2 == 3) // Verifica se o retorno tem erro(ret1 == 1) e qual o tipo de erro (3 = O monte esta vazio, por isso nao é possivel comprar pedras)
				{
					cout << "\n\nNao e possivel comprar pedras do monte pois ele esta vazio !!\n\n";
					system("pause");
				}
				if(ret1 == 1 && ret2 == 1) // Verifica se o retorno tem erro(ret1 == 1) e qual o tipo de erro (3 = Não é possivel passar a vez enquanto o monte não estiver vazio)
				{
					cout << "\n\nVoce nao pode pular pois existem pedras a serem compradas ainda !!\n\n";
					system("pause");
				}
				if(ret3 == 1) // Verifica se o retorno ret3 for 1(condicao de que alguem venceu o jogo)
				{
					if(ret4 == 1)// Verifica o valor presente no ret4 que informa quem ganhou o jogo (1(j1)(Fisico) 2(j2)(Virtual) 3(j3)(Virtual) 4(j4)(Virtual))
					{
						cout << "\n\nJogador fisico ganhou !!\n\n";
					}
					if(ret4 == 2)
					{
						cout << "\n\nJogador virtual ganhou !!\n\n";
					}
					cout << "\n\n";
					system("pause");
					break;
				}
			}
		}
		if(opcao == 2) // (Fisico/Virtual/Virtual)
		{
			while(1)
			{
				system("cls");
				play.get(mv1,mv2,mv3,tabuleir,tabuleir_D,tabuleir_E,mao,mao_D,mao_E,ret1,ret2,ret3,ret4,aux,aux2,aux3,esq,dir);
				cout << "\t\t       || ------------- Domino ------------- ||";
				cout << "\n\n\n\n Mao Virtual 1 : { ";
				for(cont=0;cont<ret1;cont++) // Imprime o numero de pedras em forma de * da mao virtual
				{
					if(mv1[cont] != -1)
					{
						cout << "[*] ";
					}
				}
				cout << "}\n";
				cout << "\n\n Mao Virtual 2 : { ";
				for(cont=0;cont<ret1;cont++) // Imprime o numero de pedras em forma de * da mao virtual
				{
					if(mv1[cont] != -1)
					{
						cout << "[*] ";
					}
				}
				cout << "}\n";
				cout << "\n\n Tabuleiro : ";
				cout << "Pontas [" << dir << ":" << esq << "] { ";
				for(cont=0;cont<60;cont++) // Imprime o tabuleiro na interface
				{
					if(tabuleir[cont] != -1)
					{
						cout << "[" << tabuleir_E[cont] << tabuleir_D[cont] <<  "] ";
					}
				}
				cout << "}\n";
				cout << "\n\n Mao Fisica : { ";
				for(cont=0;cont <ret4;cont++) // Imprime o valor da mao fisica do jogador
				{
					if(mao[cont] != -1)
					{
						cout << cont+1 << ":[" << mao_E[cont] << mao_D[cont] << "] ";
					}
				}
				cout << "}\n\n";
				cout << "\n\n Entre com o que voce deseja fazer : " << endl << "\n 1 - Jogar Pedra\n 2 - Pescar Monte\n 3 - Pular\n\n\t\t    Opcao [ ]\b\b";
				cin >> ret1;
				if(ret1 == 2 || ret1 == 3)
				{
					play.set(ret1,ret2,ret3,ret4);
				}
				else if(ret1 == 1)
				{
					cout << "\n\n Entre com o indice da pedra a jogar : [  ]\b\b\b";
					cin >> ret2;
					ret2--;
					play.set(ret1,ret2,ret3,ret4);
				}
				if(ret1 == 1 && ret2 == 2)
				{
					cout << "\n\nA pedra jogada nao e valida para as extremidades do tabuleiro !!\n\n";
					system("pause");
				}	
				if(ret1 == 1 && ret2 == 3)
				{
					cout << "\n\nNao e possivel comprar pedras do monte pois ele esta vazio !!\n\n";
					system("pause");
				}
				if(ret1 == 1 && ret2 == 1)
				{
					cout << "\n\nVoce nao pode pular pois existem pedras a serem compradas ainda !!\n\n";
					system("pause");
				}
				if(ret3 == 1)
				{
					system("pause");
					if(ret4 == 1)
					{
						cout << "\n\nJogador fisico ganhou !!\n\n";
					}
					if(ret4 == 2)
					{
						cout << "\n\nJogador virtual 1 ganhou !!\n\n";
					}
					if(ret4 == 3)
					{
						cout << "\n\nJogador virtual 2 ganhou !!\n\n";
					}
					cout << "\n\n";
					system("pause");
					break;
				}
			}
		}
		if(opcao == 3) // (Fisico/Virtual/Virtual/Virtual)
		{
			while(1)
			{
				// ret1 = tamanho mao 1 // ret2 = tamanho mao 2 // aux = condicao de vitoria 
				// aux2 = jogador que ganhou // aux3 = condicao de jogada do jogador
				system("cls");
				play.get(mv1,mv2,mv3,tabuleir,tabuleir_D,tabuleir_E,mao,mao_D,mao_E,ret1,ret2,ret3,ret4,aux,aux2,aux3,esq,dir);
				cout << "\t\t       || ------------- Domino ------------- ||";
				cout << "\n\n\n\n Mao Virtual 1 : { ";
				for(cont=0;cont<ret1;cont++) // Imprime o numero de pedras em forma de * da mao virtual
				{
					if(mv1[cont] != -1)
					{
						cout << "[*] ";
					}
				}
				cout << "}\n";
				cout << "\n\n Mao Virtual 2 : { ";
				for(cont=0;cont<ret1;cont++) // Imprime o numero de pedras em forma de * da mao virtual
				{
					if(mv1[cont] != -1)
					{
						cout << "[*] ";
					}
				}
				cout << "}\n";
				cout << "\n\n Mao Virtual 3 : { ";
				for(cont=0;cont<ret1;cont++) // Imprime o numero de pedras em forma de * da mao virtual
				{
					if(mv1[cont] != -1)
					{
						cout << "[*] ";
					}
				}
				cout << "}\n";
				cout << "\n\n Tabuleiro : ";
				cout << "Pontas [" << dir << ":" << esq << "] { ";
				for(cont=0;cont<60;cont++) // Imprime o tabuleiro na interface
				{
					if(tabuleir[cont] != -1)
					{
						cout << "[" << tabuleir_E[cont] << tabuleir_D[cont] <<  "] ";
					}
				}
				cout << "}\n";
					cout << "\n\n Mao Fisica : { ";
				for(cont=0;cont <ret4;cont++) // Imprime o valor da mao fisica do jogador
				{
					if(mao[cont] != -1)
					{
						cout << cont+1 << ":[" << mao_E[cont] << mao_D[cont] << "] ";
					}
				}
				cout << "}\n\n";
				cout << "\n\n Entre com o que voce deseja fazer : " << endl << "\n 1 - Jogar Pedra\n 2 - Pescar Monte\n 3 - Pular\n\n\t\t    Opcao [ ]\b\b";
				cin >> ret1;
				if(ret1 == 2 || ret1 == 3)
				{
					play.set(ret1,ret2,ret3,ret4);
				}
				else if(ret1 == 1)
				{
					cout << "\n\n Entre com o indice da pedra a jogar : [  ]\b\b\b";
					cin >> ret2;
					ret2--;
					play.set(ret1,ret2,ret3,ret4);
				}
				if(ret1 == 1 && ret2 == 2)
				{
					cout << "\n\nA pedra jogada nao e valida para as extremidades do tabuleiro !!\n\n";
					system("pause");
				}	
				if(ret1 == 1 && ret2 == 3)
				{
					cout << "\n\nNao e possivel comprar pedras do monte pois ele esta vazio !!\n\n";
					system("pause");
				}
				if(ret1 == 1 && ret2 == 1)
				{
					cout << "\n\nVoce nao pode pular pois existem pedras a serem compradas ainda !!\n\n";
					system("pause");
				}
				if(ret3 == 1)
				{
					system("pause");
					if(ret4 == 1)
					{
						cout << "\n\nJogador fisico ganhou !!\n\n";
					}
					if(ret4 == 2)
					{
						cout << "\n\nJogador virtual 1 ganhou !!\n\n";
					}
					if(ret4 == 3)
					{
						cout << "\n\nJogador virtual 2 ganhou !!\n\n";
					}
					if(ret4 == 4)
					{
						cout << "\n\nJogador virtual 3 ganhou !!\n\n";
					}
					cout << "\n\n";
					system("pause");
					break;
				}
			}
		}
	}
}
#endif 
