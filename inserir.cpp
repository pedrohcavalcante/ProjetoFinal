#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include "PreProcessing.h"
#include "inserir.h"


void OpenFile(char** fileName, DOCS** lista){
	std::string namefile;
	std::ofstream base_busca;
	base_busca.open("base_busca.txt",std::ofstream::app);
	if (!base_busca.is_open()){
		std::cout << "Não foi possível abrir o arquivo" << std::endl;
	}
	std::ifstream testa_exist;
	testa_exist.open(*fileName);
	if (!testa_exist.is_open()){
		std::cout << ">> Arquivo '" << *fileName << "' não foi encontrado no caminho indicado" << std::endl;
	}else{
		base_busca << *fileName << '\n';
		std::cout << ">> Arquivo '" << *fileName << "' inserido na base de buscas" << std::endl;
		inserir(lista, *fileName, true);
		testa_exist.close();
	}
	base_busca.close();
}

void inserir(DOCS** lista, char nome[], bool occasion){
	DOCS* aux = *lista;
	DOCS* anterior = NULL;
	DOCS* novo = (DOCS*) new DOCS;
	
	strcpy(novo->NameDoc,nome);
	novo->prox = NULL;

	if(*lista == NULL){
		*lista = novo;
	}
	else{


		while(aux != NULL){
			
			if( strcmp(aux->NameDoc, novo->NameDoc) == 0){
				//std::cout << "O arquivo " << novo->NameDoc << " ja existe" << std::endl;
				goto end;	

			}

			anterior = aux;
			aux = aux->prox;

		}

		anterior->prox = novo;
	}

	if (occasion == true){
		contadorPalavras( &novo);
	}
	
	end:
	
	occasion = false;

	//OpenFile( &nome);
}

bool inserir(DOCS** lista, char nome[]){
	DOCS* aux = *lista;
	DOCS* anterior = NULL;
	DOCS* novo = (DOCS*) new DOCS;
	
	strcpy(novo->NameDoc,nome);
	novo->prox = NULL;

	if(*lista == NULL){
		*lista = novo;
	}
	else{


		while(aux != NULL){
			
			if( strcmp(aux->NameDoc, novo->NameDoc) == 0){
				//std::cout << "O arquivo " << novo->NameDoc << " ja existe" << std::endl;
				return true;	

			}

			anterior = aux;
			aux = aux->prox;

		}

		anterior->prox = novo;
	}
	return false;

	//OpenFile( &nome);
}	

void contadorPalavras( DOCS** lista ){

	DOCS* aux = *lista;
	
	aux->Palavras = 0;

	std::ifstream stream(aux->NameDoc);
	std::string word;
	
	while ( stream >> word){
		++aux->Palavras;
	}
	
	*lista = aux;
	
	
	inserirPalavras( lista);
}

void inserirPalavras( DOCS** lista){

	INDICE *hash;
	int i = 0, linha = 1;
	DOCS* aux = *lista;
	


	hash = new INDICE[26];
	
	while (i < 26){
		hash[i].Controle = 0;
		i++;
	}
	i = 0;

	std::ifstream stream(aux->NameDoc);
	std::string word;
	
	while ( stream >> word){
		
		hashCreation( hash, word.c_str(), linha);
		
		if ( stream.peek() == '\n' || stream.eof()){
			linha++;
		}
		i++;
	
	}

	aux->Ind = hash;

	*lista = aux;
}

int hashFunction( char const nome[]){
	int ia = (int)nome[0];
	return ia-97;
}

void hashCreation(INDICE* hash, char const word[], int linha){

	int auxInt = hashFunction( word);

	INDICE *anterior;
	INDICE *novo = (INDICE*) new INDICE;
	//INDICE *aux = (INDICE*) new INDICE;

	strcpy(novo->Palavra, word);
	novo->Controle = 1;

	int i = 0;

	if( auxInt < 0){
		
		INDICE *aux = &hash[auxInt + 32];

		if( hash[auxInt + 32].Controle == 0 ){
			
			novo->IndLinha[i] = linha;
			hash[auxInt + 32] = *novo;


		}
			
		else {
			
			while( aux != NULL){
				if( aux->Palavra == novo->Palavra){
					while( novo->IndLinha[i] != 0){
						i++;
					}
					goto end1;
				}
				anterior = aux;
				aux = aux->prox;
				//i += 1;
			}

			novo->IndLinha[i] = linha;
			anterior->prox = novo;
			end1:
			i = 0;
		}

	}
	else{

		INDICE *aux = &hash[auxInt];

		if( hash[auxInt].Controle == 0 ){

			novo->IndLinha[i] = linha;					
			hash[auxInt] = *novo;


		}
			
		else {
			
			while( aux != NULL){
				if( aux->Palavra == novo->Palavra){
					while( novo->IndLinha[i] != 0){
						i++;
					}
					goto end2;
				}
				anterior = aux;
				aux = aux->prox;
				//i += 1;
			}

			novo->IndLinha[i] = linha;
			anterior->prox = novo;
			end2:
			i = 0;
		}

	}
}

DOCS* criarLista(){
	return NULL; 
}
