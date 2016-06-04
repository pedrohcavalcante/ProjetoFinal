#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "listar.h"


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
	base_busca.close();
}