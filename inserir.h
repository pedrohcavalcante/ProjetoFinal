#ifndef _INSERIR_H_
#define _INSERIR_H_
#include "PreProcessing.h"


DOCS* criarLista( );
void OpenFile(char** fileName, DOCS** lista);
void inserir(DOCS** lista, char nome[], bool occasion);
void inserirPalavras( DOCS** lista);
int hashFunction( char const nome[]);
void hashCreation( INDICE* hash, char const *word, int linha);
bool inserir(DOCS** lista, char nome[]);

#endif