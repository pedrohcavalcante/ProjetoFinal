#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <getopt.h>
#include "listar.h"
#include "inserir.h"
#include <unistd.h>

#define no_argument 0
#define required_argument 1
#define optional_argument 2

int main(int argc, char * argv[]){

	//Variáveis
	const struct option longopts[] = {
	    {"inserir",        required_argument,        0, 'i'}, 
    	{"remover",        required_argument,        0, 'r'},
    	{"lista_insercao", required_argument,        0, 'l'},
    	{"la",             no_argument,              0, 'a'}, 
    	{"lt",             no_argument,              0, 't'},
    	{0,0,0,0},
	};
	bool iflag = false;
	bool rflag = false;
	bool lflag = false;
	bool laflag = false;
	bool ltflag = false;
	int index;
	int iarg = 0;
	char* next;
	opterr = 0;
	//Fim variáveis	


	while (iarg != -1){
		iarg = getopt_long_only(argc, argv, "i:r:l:at", longopts, &index);
		switch(iarg){
			case 'i':
				if (iflag){
					std::cout << "Flag repetida" << std::endl;
					return 0;
				}
				iflag = true;
				std::cout << "ENTROU I " << std::endl;
				std::cout << "Opcao Testar" << std::endl;
				std::cout << optarg << std::endl;
				OpenFile(&optarg);
				break;
			case 'r':
				std::cout << "ENtrou R" << std::endl;
				rflag = true;
				break;
			case 'l':
				std::cout << "ENtrou em L" << std::endl;
				lflag = true;
				break;
			case 'a':
				std::cout << "Entrou em la" << std::endl;
				laflag = true;
				printFile();
				break;
			case 't':
				std::cout << "Entrou em lt" << std::endl;
				ltflag = true;
				break;
			case '?':
				std::cout << "entrou em ?" << std::endl;
				break;
		}
	}
	


	return 0;
}
