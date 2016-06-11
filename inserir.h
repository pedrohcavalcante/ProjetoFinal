#ifndef _INSERIR_H_
#define _INSERIR_H_

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>

struct INDICE{
	char Palavra[20];
	int IndLinha[30];
	int Controle;
	INDICE* prox = NULL;
};


struct DOCS {
	char NameDoc [20];
	int Palavras;
	DOCS *prox;
	INDICE *Ind;
};


DOCS* criarlista();
void OpenFile(char** fileName);
void OpenFile_noAPP(char** fileName);
void remover_file(char** fileName);



#endif