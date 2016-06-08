#ifndef _LISTAR_H_
#define _LISTAR_L_

#include <iostream>
#include <getopt.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "inserir.h"

typedef struct{
	int inicio;
	int tamanho;
	int fim;
	int *elementos;
}Fila;

Fila* criarFila();
Fila* criarFila(int tamanho);
bool enqueue(Fila* fila, int valor);
bool dequeue(Fila* fila);
bool filaVazia(Fila* fila);
bool filaCheia(Fila* fila);
void movimentar(Fila* fila);
void imprimir(Fila* fila);
void testes(Fila* fila);

void printFile();
void printFileCresc();
int contaLinha();


#endif