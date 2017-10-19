#ifndef interface_hpp
#define interface_hpp
#include "domino.hpp"
class interface
{
	private:
		int ret1,ret2,ret3,ret4;
		int opcao,opcao1,aux,aux2,aux3;
		jogo play;
		int mao[21];
		int mao_D[21],mao_E[21];
		int tabuleir_E[60],tabuleir_D[60];
		int mv1[21],mv2[21],mv3[21];
		int tabuleir[60];
		int cont;
		int esq,dir;
	public:
	void controle_jogo(); // Declaracao do metodo que realiza as entrada e a saida da interface do jogo de domino
};
#endif

