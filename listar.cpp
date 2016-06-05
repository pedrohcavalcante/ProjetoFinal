#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
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
	}
	while(!base_busca.eof()){
		std::getline(base_busca, namefile);
		std::cout << namefile << std::endl;
	}
	base_busca.close();
}

void printFileCresc(){
	// ================ DIRETIVAS DE ARQUIVO ================
	std::istringstream iss;
	std::ifstream base_busca;
	std::string namefile;
	std::string linha;
	// ================ FIM ================
	// VARIÁVEIS
	file_names arquivo_teste;
	// FIM
	base_busca.open("base_busca.txt", std::ofstream::app);
	if(!base_busca.is_open()){
		std::cout << "Erro ao abrir arquivo" << std::endl;
	}
	//ESBOÇO DE COMO PEGAR NO ARQUIVO O NOME E O TAMANHO ;
	//FALTA CRIAR LISTA ENCADEADA PARA ARMAZENAR TODOS OS NOMES;
	while (!base_busca.eof()){
		std::getline(base_busca, linha);
		if (base_busca.eof()){
			iss.str(linha);
			iss >> arquivo_teste.nome >> arquivo_teste.tamanho;
		}
		std::cout << arquivo_teste.nome << arquivo_teste.tamanho << std::endl;
	}
	//Ordernar arquivo pela ordem do tamanho e depois imprimir 
	//só então pode testar
}