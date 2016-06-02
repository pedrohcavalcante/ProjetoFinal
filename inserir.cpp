#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "inserir.h"

void OpenFile(char** fileName){
	
	std::cout << *fileName << std::endl;
	//char file = fileName;
	std::ofstream base_busca;
	base_busca.open("base_busca.txt");
	if (!base_busca.is_open()){
		std::cout << "Não foi possível abrir o arquivo" << std::endl;
		//return 0;
	}else{
		std::cout << "rolou" << std::endl;
	}
	base_busca << *fileName << "\n";
}