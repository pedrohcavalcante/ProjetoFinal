#include <iostream>
#include <getopt.h>

#define VERSION "scs_1.0"

#define no_argument 0
#define required_argument 1
#define optional_argument 2
/**
Podem testar:
./argumentos -v
./argumentos -v -h
./argumentos -vh
./argumentos -v -p p1 p2 p3
./argumentos -h -p p1 p2 p3 -h
*/

/**
Mais informacoes sobre o uso do GetOpt em:
https://daemoniolabs.wordpress.com/2011/10/07/usando-com-as-funcoes-getopt-e-getopt_long-em-c/
**/

void ajuda ()
{
    std::cout << "Mostrar como rodar o programa!!!" << std::endl;
}
int main(int argc, char * argv[])
{
  const struct option longopts[] =
  {
    {"versao",      no_argument,        0, 'v'},
    {"ajuda",       no_argument,        0, 'h'},
    {"imprimir",    required_argument,  0, 'p'},
    {"mostrar",     required_argument,  0, 's'},
    {"testar",      required_argument,  0, 't'},
    {0,0,0,0},
  };

  int index;
  int iarg=0;
  char* next;

  bool vflag = false;
  bool hflag = false;
  bool pflag = false;
  bool sflag = false;
  bool tflag = false;

  //desativa as mensagens de erro do getopt
  opterr=0;

  while(iarg != -1)
  {
      //Define todas as variações e possíveis entradas
    iarg = getopt_long(argc, argv, "p:s:t:vh", longopts, &index);

    switch (iarg)
    {
      case 'h':
        if (hflag)
        {
            std::cout << "Flag 'h' repetida" << std::endl;
            break;
        }
        hflag = true;
        std::cout << "Ajuda: " << std::endl;
        ajuda();
        break;

      case 'v':
        std::cout << "Versao do programa: " << VERSION << std::endl;
        break;

      case 'p':
        std::cout << "Opcao imprimir" << std::endl;
        std::cout << "Argumento: " << optarg << std::endl;
        // Lendo os argumentos em excesso
        index = optind;
        if (argv[index] != NULL && argv[index][0]!='-')
        {
            while(index < argc && argv[index][0]!='-'){
                std::cout << "Excesso: " << argv[index] << std::endl;
                index++;
            }
            optind = index-1;
        }
        break;
      case 't':
        std::cout << "Opcao Testar" << std::endl;
        std::cout << "Argumento: " << optarg << std::endl;

        break;
      case 's':
        std::cout << "Opcao Mostrar" << std::endl;
        std::cout << "Argumento: " << optarg << std::endl;
        // Lendo os argumentos em excesso
        index = optind;
        if (argv[index] != NULL  && argv[index][0]!='-')
        {
            while(index < argc && argv[index][0]!='-'){
                std::cout << "Excesso: " << argv[index] << std::endl;
                index++;
            }
            optind = index-1;
        }
        break;
      case '?':      // erro - opcao desconhecida
            std::cout << "Opcao " << (char) optopt << " eh invalida." << std::endl;
            break;
      case -1:      // erro - opcao desconhecida
            std::cout << "Fim da linha de comando." << std::endl;
            break;
    }
  }

  return 0;
}
