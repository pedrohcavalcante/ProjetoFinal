#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <algorithm> 
#include <vector>
#include <string.h>
#include "listar.h"
#include "PreProcessing.h"

using namespace std;

void printFile(){
	// ================ DIRETIVAS DE ARQUIVO ================
	std::istringstream iss;
	std::fstream base_busca;
	std::string namefile;
	// ================ FIM ================
	// ================ VARIAVEIS ================
	// ================ FIM ================
	base_busca.open("base_busca.txt");
	if (!base_busca.is_open()){
		std::cout << "Errado ao abrir" << std::endl;
	}else{
		std::cout << ">> Arquivos contidos na base de buscas: " << std::endl;
		while(!base_busca.eof()){
			std::getline(base_busca, namefile);
			//file_names.push_back(namefile);
			if (namefile.compare("")){
				std::cout << "- '" <<  namefile << "'" <<  std::endl;
			}
		}
	}
	base_busca.close();
}

void printAlf(DOCS** lista){
	openDocFile(lista);
	DOCS* aux = *lista;
	DOCS* anterior = NULL;
	
	int i = 0;
	
	std::string strAux[10];
	
	while(aux != NULL){
		
		strAux[i] = aux->NameDoc;	
		
		//std::cout << strAux[i] << std::endl;

		i++;

		aux = aux->prox;
		
	}

	QuickSort (strAux, 0, i);
	int j = 0;
	while ( j < i+1 ){
		std::cout << strAux[j] << std::endl;
		j++;
	}
}


void QuickSort( std::string v[], int left, int right){
	int pivo = ( right + left)/2;
	int i = left, j = right;
	std::string temp;

	while ( i <= j){
		if ( v[i] < v[pivo] ){
			i++;
		}
		else if ( v[j] > v[pivo] ){
			j--;
		}
		else if (i <= j){
			temp = v[i];
			v[i] = v[j];
			v[j] = temp;
			i++;
			j--;
		}

	}

	if (left < j){
		QuickSort( v, left, j );
	}

	if (right > i){
		QuickSort( v, i, right );
	}
}