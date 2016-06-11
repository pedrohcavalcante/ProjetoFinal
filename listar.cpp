#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include "listar.h"


using namespace std;

void printFile(){
	// ================ DIRETIVAS DE ARQUIVO ================
	std::istringstream iss;
	std::ifstream base_busca;
	std::string namefile;
	// ================ FIM ================
	// ================ VARIAVEIS ================
	// ================ FIM ================
	base_busca.open("base_busca.txt", std::ofstream::app);
	if (!base_busca.is_open()){
		std::cout << "Errado ao abrir" << std::endl;
	}else{
		std::cout << ">> Arquivos contidos na base de buscas: " << std::endl;
		while(!base_busca.eof()){
			std::getline(base_busca, namefile);
			std::cout << "- '" <<  namefile << "'" <<  std::endl;
		}
	}
	base_busca.close();
}

void printFileCresc(){
	// ================ DIRETIVAS DE ARQUIVO ================
	std::istringstream iss;
	std::fstream base_busca;
	std::string namefile;
	std::string linha;
	// ================ FIM ================
	// VARIÁVEIS
	//int tamanho  = contaLinha();
	//std::cout << tamanho << std::endl;
	//Fila* arq_fila = criarFila(tamanho);
	// FIM
	base_busca.open("base_busca.txt", std::ofstream::app);
	if(!base_busca.is_open()){
		std::cout << "Erro ao abrir arquivo" << std::endl;
	}
	//ESBOÇO DE COMO PEGAR NO ARQUIVO O NOME E O TAMANHO ;
	//FALTA CRIAR LISTA ENCADEADA PARA ARMAZENAR TODOS OS NOMES;

	//Ordernar arquivo pela ordem do tamanho e depois imprimir 
	//só então pode testar
}

int contaLinha(){
	FILE *arq;
	char ch;
	int linhas = 0;;
	arq=fopen("base_busca.txt", "r");
	while( (ch=fgetc(arq))!= EOF ){

		if (ch == '\n'){
			linhas++;
		}
	}
	//std::cout << "linhas: " << linhas << std::endl;
	fclose(arq);
	return linhas;
}