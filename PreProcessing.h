#ifndef _PROCESSING_H_
#define _PROCESSING_H_

struct INDICE{
	char Palavra[20];
	int IndLinha[30] = {0};
	int Controle;
	INDICE* prox = NULL;
};


struct DOCS {
	char NameDoc [20];
	int Palavras;
	DOCS *prox;
	INDICE *Ind;
};



void imprimirLista( DOCS** lista);
void contadorPalavras( DOCS** lista );

void createHashFile(DOCS** lista);
void openHashFile(INDICE* hash, char DocName[]);
void openDocFile(DOCS** lista);

#endif