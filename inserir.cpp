#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "inserir.h"
using namespace std;
void OpenFile(char** fileName){
	
	//std::cout << *fileName << std::endl;
	//char file = fileName;
	std::ofstream base_busca;
	base_busca.open("base_busca.txt",std::ofstream::app);
	if (!base_busca.is_open()){
		std::cout << "Não foi possível abrir o arquivo" << std::endl;
		//return 0;
	}else{
		std::cout << "rolou" << std::endl;
	}
	base_busca << *fileName << "\n";
	base_busca.close();
}

void printFile(){
	std::istringstream iss;
	std::ifstream base_busca;
	std::string namefile;
	base_busca.open("base_busca.txt", std::ofstream::app);
	if (!base_busca.is_open()){
		std::cout << "Errado ao abrir" << std::endl;
	}
	while(!base_busca.fail()){
		//std::cout << "entrou" << std::endl;
		std::getline(base_busca, namefile);
		std::cout << namefile << std::endl;
	}
}