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
	char *ifile = NULL;
	FILE* fp;
	bool iflag = false;
	bool rflag = false;
	bool liflag = false;
	bool laflag = false;
	bool ltflag = false;
	int index;
	int iarg = 0;
	char* next;
	opterr = 0;
	//Fim variáveis	
	const struct option longopts[] = {
	    {"Inserir novo arquivo na base de buscas",                        required_argument,        0, 'i'},
    	{"Remove arquivo da base de buscas",                              required_argument,        0, 'r'},
    	{"Lista arquivos em ordem de inserção",                           required_argument,        0, 'l'},
    	{"Lista arquivos em ordem alfabética",                            no_argument,  0, 'a'},
    	{"Lista todos os arquivos em ordem descrescente de tamanho",      no_argument,  0, 't'},
    	{0,0,0,0},
	};

	while (iarg != -1){
		iarg = getopt_long(argc, argv, "i:", longopts, &index);
		switch(iarg){
			case 'i':
				std::cout << "ENTROU I " << std::endl;
				std::cout << "Opcao Testar" << std::endl;
				std::cout << optarg << std::endl;
				fp = fopen(optarg,"w");
				OpenFile(fp);
				break;
		}
	}
	


	return 0;
}
