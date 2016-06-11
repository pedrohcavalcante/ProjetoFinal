#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include "inserir.h"

using namespace std;

void OpenFile(char** fileName){
	
	//std::cout << *fileName << std::endl;
	//char file = fileName;
	std::string namefile;
	std::ofstream base_busca;
	base_busca.open("base_busca.txt",std::ofstream::app);
	if (!base_busca.is_open()){
		std::cout << "Não foi possível abrir o arquivo" << std::endl;
		//return 0;
	}
	std::ifstream testa_exist;
	testa_exist.open(*fileName);
	if (!testa_exist.is_open()){
		std::cout << ">> Arquivo '" << *fileName << "' não foi encontrado no caminho indicado" << std::endl;
	}else{
		base_busca << *fileName << '\n';
		std::cout << ">> Arquivo '" << *fileName << "' inserido na base de buscas" << std::endl;
		testa_exist.close();
	}
	base_busca.close();
}

DOCS* criarlista(){
	return NULL;
}


void remover_file(char** fileName){
	std::istringstream iss;
	std::string namefile;
	std::fstream base_busca;
	std::fstream temp;
	//FILE *teste;
	//teste = fopen("base_temp.txt","w+");
	char oldname[] = "base_temp.txt";
	char newname[] = "base_busca.txt";
	temp.open("base_temp.txt");
	base_busca.open("base_busca.txt");
	if (!base_busca.is_open()){
		std::cout << "Não foi possível abrir o arquivo" << std::endl;
	}else{
		while(!base_busca.eof()){
			std::getline(base_busca, namefile);
			if (namefile.compare(*fileName) != 0){
				temp << namefile << '\n';
			}else{
				std::cout << "sao iguais " << *fileName << " " << namefile << std::endl;
			}
			
		}
		rename("base_busca.txt", "temp2.txt");
		rename(oldname, newname);
		rename("temp2.txt", oldname);

	}
	base_busca.close();
	temp.close();
}
// Contar o tamanho da palavra
//<< std::char_traits<char>::length(*fileName)