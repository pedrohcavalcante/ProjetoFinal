#include <iostream>
#include "PreProcessing.h"
#include "inserir.h"
#include <string.h>
#include <fstream>
#include <string>





void imprimirLista(DOCS** lista){
	DOCS* aux = *lista;
	DOCS* anterior = NULL;

	while(aux != NULL){

		int i = 0;
		std::cout << "[" << aux->NameDoc << "]" << " ||| " << aux->Palavras <<std::endl;	
		while(i < 26){
			if(aux->Ind[i].Controle != 0){
			
				std::cout << aux->Ind[i].Palavra << " |||| " << aux->Ind[i].IndLinha[0] << std::endl;
				
				while(aux->Ind[i].prox != NULL){
					
					anterior = aux;
					aux->Ind[i] = *aux->Ind[i].prox; 
					std::cout << aux->Ind[i].Palavra << " |||| " << aux->Ind[i].IndLinha[0] << std::endl;
			
				}
				
				i++;
			}
			else{ 
				
				i++;
			}
		}
		aux = aux->prox;
		
	}
}

void createHashFile(DOCS** lista){
	DOCS* aux = *lista;
	DOCS* anterior = NULL;

	char test[20];

	std::ofstream hashFile;

	while(aux != NULL){

		strcpy(test, "hash");

		int i = 0;

		hashFile.open(strcat(test, aux->NameDoc), std::fstream::out);
		
		if (!hashFile.is_open()){
			std::cout << "Não foi possível abrir o arquivo" << std::endl;
		}
		
		std::cout << "[" << aux->NameDoc << "]" << std::endl;	
		
		while(i < 26){

			if(aux->Ind[i].Controle == 1){

				hashFile << aux->Ind[i].Palavra << std::endl;
				
				while(aux->Ind[i].prox != NULL){
				
					anterior = aux;
					aux->Ind[i] = *aux->Ind[i].prox; 
					hashFile << aux->Ind[i].Palavra << std::endl;
				}
				i++;
			}
			else{ 
				i++;
			}
		}
		
		aux = aux->prox;
		
		hashFile.close();

		std::cout << test << std::endl;

	}


}

void openHashFile(INDICE* hash, char DocName[]){
	//INDICE* aux = *hash;
	//INDICE* anterior = NULL;

	char aux[20] = "hash";

	std::ifstream hashFile;



	hashFile.open(strcat(aux, DocName));

	std::string aux2;

	while( !hashFile.eof()){
		std::getline( hashFile, aux2);

		/*char * writable = new char[aux.size() + 1];
		std::copy(aux.begin(), aux.end(), writable);
		writable[aux.size()] = '\0';*/
		//std::cout << aux2 << std::endl;

		hashCreation( hash,  aux2.c_str(), 0);

	}
	
	hashFile.close();


}
void openDocFile(DOCS** lista){
	INDICE hash[26];
	DOCS* aux = *lista;
	DOCS* anterior = NULL;
	int i = 0;

	//hash = new INDICE[26];
	
	while (i < 26){
		hash[i].Controle = 0;
		i++;
	}

	std::string nome;
	//int i = 0;
	std::ifstream docFile;

	docFile.open("base_busca.txt");


	while( docFile){

		std::getline(docFile, nome);
		if (nome.compare("")){
		
			char * writable = new char[nome.size() + 1];
			std::copy(nome.begin(), nome.end(), writable);
			writable[nome.size()] = '\0';

			inserir (lista, writable, true);
			//openHashFile( hash, writable);
			
			//aux->Ind = hash;

			//*lista = aux;
		}
	}
	//std::cout << "estou em " << std::endl;
	//aux->Ind = hash;
	

	//*lista = aux;


	docFile.close();

}

/*
void openDocFile(DOCS** lista){
	INDICE *hash;
	DOCS* aux = *lista;
	int i = 0;

	hash = new INDICE[26];
	
	while (i < 26){
		hash[i].Controle = 0;
		i++;
	}

	std::string nome;
	//int i = 0;
	std::ifstream docFile;

	docFile.open("base_busca.txt");


	while( docFile){

		std::getline(docFile, nome);

		char * writable = new char[nome.size() + 1];
		std::copy(nome.begin(), nome.end(), writable);
		writable[nome.size()] = '\0';

		//std::cout << "estou em " << writable << std::endl;

		inserir (lista, writable, false);
		openHashFile( hash, writable);
		
		//aux->Ind = hash;

		//*lista = aux;
	}
	std::cout << "estou em" << std::endl;
	aux->Ind = hash;


	*lista = aux;


	docFile.close();

}*/