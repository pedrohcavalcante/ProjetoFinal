#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
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
		base_busca << *fileName << ' ' << std::char_traits<char>::length(*fileName) << endl;
		std::cout << ">> Arquivo '" << *fileName << "' inserido na base de buscas" << std::endl;
		testa_exist.close();
	}
	base_busca.close();
}
