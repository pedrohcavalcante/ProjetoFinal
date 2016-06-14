#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <getopt.h>
#include "listar.h"
#include "PreProcessing.h"
#include "inserir.h"
#include <unistd.h>

#define no_argument 0
#define required_argument 1
#define optional_argument 2

void ajuda(){
	std::cout << "Sintaxe geral de comandos: " << std::endl;
	std::cout << "<executavel> <opcao> <nome_arquivo>" << std::endl;
	std::cout << "\n";
	std::cout << "Os comandos permitidos são: " << std::endl;
	std::cout << "-i" << "     "<<"<nome_arquivo>" << "Insere um novo arquivo na base de buscas." << std::endl;
	std::cout << "-r" << "     "<<"<nome_arquivo>" << "Remove um arquivo da base de buscas. " << std::endl;
	std::cout << "-li" << "    " << "Lista todos os arquivos contidos na base de buscas na ordem em\n       que foram inseridos à base" << std::endl;
	std::cout << "-la" << "    " << "Lista todos os arquivos contidos na base de buscas em ordem\n       alfabética" << std::endl;
	std::cout << "-lt" << "    " << "Lista todos os arquivos contidos na base de buscas em ordem\n       decrescente da quantidade de 	palavras em cada arquivos" << std::endl;			

}

int main(int argc, char * argv[]){

	//Variáveis
	DOCS* lista;
	lista = criarLista();
	const struct option longopts[] = {
	    {"inserir",        required_argument,        0, 'i'}, 
    	{"remover",        required_argument,        0, 'r'},
    	{"li",             no_argument,              0, 'o'},
    	{"la",             no_argument,              0, 'a'}, 
    	{"lt",             no_argument,              0, 't'},
    	{"h",              no_argument,              0, 'h'},
    	{0,0,0,0},
	};
	bool iflag = false;
	bool rflag = false;
	bool liflag = false;
	bool laflag = false;
	bool ltflag = false;
	bool hflag = false;
	int index;
	int iarg = 0;
	//char* next;
	opterr = 0;
	//Fim variáveis	


	while (iarg != -1){
		iarg = getopt_long_only(argc, argv, "i:r:oath", longopts, &index);
		switch(iarg){
			case 'i':
			//Inserir arquivo na base de dados
				if (iflag){
					std::cout << "Flag repetida" << std::endl;
					return 0;
				}
				iflag = true;
				//std::cout << "ENTROU I " << std::endl;
				//std::cout << "Opcao Testar" << std::endl;
				//std::cout << optarg << std::endl;
				OpenFile(&optarg, &lista);
				index = optind;
				if (argv[index] != NULL && argv[index][0]!='-'){
					while(index < argc && argv[index][0]!='-'){
						//std::cout << "Excesso: " << argv[index] << std::endl;
						OpenFile(&argv[index], &lista);
						index++;
					}
					optind = index-1;
				}
				break;
			case 'r':
			//Remover arquivos da base de dados
				//std::cout << "ENtrou R" << std::endl;
				if (rflag){
					std::cout << "Flag repetida" << std::endl;
					return 0.;
				}
				rflag = true;
				//remover_file(&optarg);
				break;
			case 'o':
			//Lista todos os arquivos contidos na base de buscas na ordem em que foram inseridos à base
				//std::cout << "Entrou em LI" << std::endl;
				if (liflag){
					std::cout << "Flag repetida" << std::endl;
					return 0.;
				}
				liflag = true;
				printFile();
				break;
			case 'a':
				// Lista em ordem alfabética
				//std::cout << "Entrou em la" << std::endl;
				if (laflag){
					std::cout << "Flag repetida" << std::endl;
					return 0.;
				}
				laflag = true;
				printAlf(&lista);
				break;
			case 't':
				//Ordem decrescente
				//std::cout << "Entrou em lt" << std::endl;
				if (ltflag){
					std::cout << "Flag repetida" << std::endl;
					return 0.;
				}
				ltflag = true;
				//std::cout << contaLinha() << std::endl;
				break;
			case 'h':
				//Ajuda

				if (hflag){
					std::cout << "Flag repetida" << std::endl;
					return 0;
				}
				hflag = true;
				ajuda();
				break;
			case '?':
				std::cout << "Comando inválido" << std::endl;
				ajuda();
				break;
		}
	}
	


	return 0;
}
