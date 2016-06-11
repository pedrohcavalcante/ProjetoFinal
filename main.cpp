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
    	{"li",             no_argument,              0, 'o'},
    	{"la",             no_argument,              0, 'a'}, 
    	{"lt",             no_argument,              0, 't'},
    	{0,0,0,0},
	};
	bool iflag = false;
	bool rflag = false;
	bool lflag = false;
	bool liflag = false;
	bool laflag = false;
	bool ltflag = false;
	int index;
	int iarg = 0;
	//char* next;
	opterr = 0;
	//Fim variáveis	


	while (iarg != -1){
		iarg = getopt_long_only(argc, argv, "i:r:l:oat", longopts, &index);
		switch(iarg){
			case 'i':
				if (iflag){
					std::cout << "Flag repetida" << std::endl;
					return 0;
				}
				iflag = true;
				//std::cout << "ENTROU I " << std::endl;
				//std::cout << "Opcao Testar" << std::endl;
				std::cout << optarg << std::endl;
				OpenFile(&optarg);
				index = optind;
				if (argv[index] != NULL && argv[index][0]!='-'){
					while(index < argc && argv[index][0]!='-'){
						//std::cout << "Excesso: " << argv[index] << std::endl;
						OpenFile(&argv[index]);
						index++;
					}
					optind = index-1;
				}
				break;
			case 'r':
				//std::cout << "ENtrou R" << std::endl;
				if (rflag){
					std::cout << "Flag repetida" << std::endl;
					return 0.;
				}
				rflag = true;
				remover_file(&optarg);
				break;
			case 'l':
				//std::cout << "Entrou em L" << std::endl;
				if (lflag){
					std::cout << "Flag repetida" << std::endl;
					return 0.;
				}
				lflag = true;
				break;
			case 'o':
				//std::cout << "Entrou em LI" << std::endl;
				if (liflag){
					std::cout << "Flag repetida" << std::endl;
					return 0.;
				}
				liflag = true;
				printFile();
				break;
			case 'a':
				//std::cout << "Entrou em la" << std::endl;
				if (laflag){
					std::cout << "Flag repetida" << std::endl;
					return 0.;
				}
				laflag = true;
				printFileCresc();
				break;
			case 't':
				//std::cout << "Entrou em lt" << std::endl;
				if (ltflag){
					std::cout << "Flag repetida" << std::endl;
					return 0.;
				}
				ltflag = true;
				//std::cout << contaLinha() << std::endl;
				break;
			case '?':
				std::cout << "entrou em ?" << std::endl;
				break;
		}
	}
	


	return 0;
}
