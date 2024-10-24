
#include <stdio.h>
#include <stdbool.h>
#include "definicoes.h"
#include <string.h>

typedef struct {
  int dia;
  int mes;
  int ano;
}data;

typedef struct {
  int matricula;
  char nome[MAX];
  int sexo;
  data dataNascimento[MAX_DATA];
  char CPF[MAX_CPF];
  int ativo;
} pessoa; 

typedef struct {
  int codigo;
  char nome[MAX];
  int semestre;
  char professor[MAX]; 
} materia;

pessoa listaAluno[TAM_PESSOA];
pessoa listaProfessor[TAM_PESSOA];
int qtdAluno = 0;
int qtdProfessor = 0;
int menuAluno();
int cadastrarAlu (pessoa listaAluno[], int qtdAluno);

void main() {
  int opcao, sair = false;

  do {
      printf ("Menu projeto escola\n");
      printf ("0 - sair\n");
      printf ("1 - Menu aluno\n");
      printf ("2 - Menu professor\n");
      printf ("3 - Menu disciplina\n");

      scanf ("%d", &opcao);
      getchar();
      
      switch (opcao){
        case 0:{
          sair = true;
          break;
        }
        case 1:{
          
          int opcaoAluno;
          int sairAluno = false;
          
         
          
          do{
            opcaoAluno = menuAluno();

            switch (opcaoAluno){
              case 0:{
                sairAluno = true;
                break;
              }
              case 1:{
                opcaoAluno = 0;
                if (qtdAluno == TAM_PESSOA){
                  printf("Lista Cheia, impossivel cadastrar mais alunos!\n");
                } else{
                  int retorno = cadastrarAlu(listaAluno, qtdAluno);

                  if (retorno == MATRICULA_INVALIDA)
                      printf("Matricula invalida\n");
                  else if (retorno == SEXO_INVALIDO)
                      printf("sexo invalido\n");
                  else if (retorno == DATA_INVALIDA)
                      printf("data invalida\n");
                  else if (retorno == CPF_INVALIDO)
                      printf("CPF invalido\n");
                  else
                  {
                    printf ("Cadrasto realizado com sucesso\n");
                    qtdAluno++;
                  }
                }
                break;
              }
              case 2:{
                listarAluno(listaAluno, qtdAluno);
                 
                break;
              }
              case 3:{
                int retorno = atualizarAluno(listaAluno, qtdAluno);
                if (retorno == MATRICULA_INVALIDA)
                printf("Matricula inválida\n");
                else if (retorno == LISTA_VAZIA)
                printf("Lista Vazia.\n");
                else 
                printf("Aluno atualizado!\n");
                break;
              }
              case 4:{
                opcaoAluno = 0;
                opcaoAluno = exclusaoAluno(listaAluno, qtdAluno);
                
                if(opcaoAluno == EXCLUSAO_SUCESSO)
                  printf("Usuario excluido com sucesso!\n");
                else
                  printf("Nao foi possivel excluir este aluno!\n");
                break;
              }
              
            } 
            
          } while (!sairAluno);
          break;
        }
        /*case 2:{
          int opcaoProfessor;
          int sairProfessor = false;
          
         
          
          do{
            printf("\e[H\e[2J");
            opcaoProfessor = menuProfessor();

            switch (opcaoProfessor){
              case 0:{
                sairProfessor = true;
                break;
              }
              case 1:{
                int retorno = cadastrarProf(listaProfessor, qtdProfessor);

                if (retorno == MATRICULA_INVALIDA)
                    printf("Matricula invalida");
                else if (retorno == SEXO_INVALIDO)
                    printf("sexo invalido");
                else if (retorno == DATA_INVALIDA)
                    printf("data invalida");
                else if (retorno == CPF_INVALIDO)
                    printf("CPF invalido");
                else
                {
                  printf ("Cadrasto realizado com sucesso");
                  qtdProfessor++;
                }
              
              break;             
              }
            }
          } while (!sairProfessor);
          break;
        }
        case 3:{
          printf ("Você está no Menu disciplina\n");
          
          break;
        }*/
        default:{
          printf ("Opcao invalida\n");
        }
    }
  } while (!sair);
}




int menuAluno(){
  int opcaoAluno;
  printf ("Menu aluno\n");
  printf ("0 - Voltar\n");
  printf ("1 - Cadastrar aluno\n");
  printf ("2 - Listar aluno\n");
  printf ("3 - Atualizar aluno\n");
  printf ("4 - Excluir aluno\n");
  scanf ("%d", &opcaoAluno);
  getchar();

  return opcaoAluno;
}

int cadastrarAlu (pessoa listaAluno[], int qtdAluno){
  printf ("Cadrasto de aluno\n");

  int Matricula;
  printf ("digite a matricula\n");
  scanf("%d", &Matricula);
  getchar();
  //G: fazer validacao matricula

  
  if (Matricula <= 0)
    return MATRICULA_INVALIDA;
  else{
    for (int icont = 0; icont < TAM_PESSOA; icont++)
      if(Matricula == listaAluno[icont].matricula){
          return MATRICULA_INVALIDA;
      }
  }

  char nome[MAX];
  printf ("digite o nome do aluno\n");
  fgets (nome, MAX, stdin);
  
  int sexo;
  printf ("digite o sexo, 1 para masculino 0 para feminino\n");
  scanf("%d", &sexo);
  getchar();

  if (sexo != 1 && sexo != 0)
    return SEXO_INVALIDO;

  //G: falta pegar a data de nascimento
  // G: talvez seja interessante transformara a data em um struct
  //com dia, mes e ano. assim da pra ver qm e mais velho mais facil.

  int dia, mes, ano;
  printf("digite o dia: (data de nascimento) ");
  scanf("%d", &dia);
  getchar();
  printf("digite o mes: (data de nascimento) ");
  scanf("%d", &mes);
  getchar();
  printf("digite o ano: (data de nascimento) ");
  scanf("%d", &ano);
  getchar();

  if (dia > 31 || dia < 1 || mes < 1 || mes > 12)
    return DATA_INVALIDA;

  char cpf[MAX_CPF];
  printf ("digite o CPF\n");
  fgets (cpf, MAX_CPF, stdin);

  int icont = 0;
  while (cpf[icont] != '\n')
    icont++;
  
  if (icont != 11){
    //G: fazer o resto da validacao do cpf e ver se n tem cpf repetido
    return CPF_INVALIDO;
  }
  else{
    for (icont = 0; icont < MAX_CPF; icont++)
      listaAluno[qtdAluno].CPF[icont] = cpf[icont];

    for (int icont = 0; icont < MAX; icont++)
      listaAluno[qtdAluno].nome[icont] = nome[icont];

      listaAluno[qtdAluno].matricula = Matricula;
      listaAluno[qtdAluno].sexo = sexo;
      listaAluno[qtdAluno].dataNascimento->dia = dia;
      listaAluno[qtdAluno].dataNascimento->mes = mes;
      listaAluno[qtdAluno].dataNascimento->ano = ano;
      listaAluno[qtdAluno].ativo = true;
  }return 0;
}
  
int listarAluno(pessoa listaAluno[], int qtdAluno){
  char opcaoLista;
  int sairLista = false;
  int achou = false;
  int Matricula;
  printf("Lista de alunos ativos no sistema!\n");

  for(int iCont = 0; iCont < TAM_PESSOA; iCont++){
    if(listaAluno[iCont].ativo == true){
      printf("Matricula: %d Nome: %s", listaAluno[iCont].matricula, listaAluno[iCont].nome);
      achou = true;
    }
  }
  if(!achou)
    printf("Nenhum Aluno cadastrado.\n");
  else{
    do{
      achou = false;   	
      printf("Deseja verificar informacoes mais detalhadas de algum usuario? (y/n): ");
      scanf("%c", &opcaoLista);
      getchar();

      if(opcaoLista == 'y'){
        printf("digite o numero de matricula: ");
        scanf("%d", &Matricula);
        getchar();

        for(int iCont = 0; iCont < TAM_PESSOA; iCont++){       	
          if(listaAluno[iCont].matricula == Matricula && listaAluno[iCont].ativo == true){
            achou = true;
            printf("\n\n");
            printf("Matricula: %d\n", Matricula);
            printf("Nome: %s", listaAluno[iCont].nome);
            printf("Sexo: ");
            if(listaAluno[iCont].sexo == 1)
              printf("Masculino\n");
            else
              printf("Feminino\n");
            printf("Data de Nascimento: %02d/%02d/%02d\n", listaAluno[iCont].dataNascimento->dia,
                                                  		   listaAluno[iCont].dataNascimento->mes,
                                                  		   listaAluno[iCont].dataNascimento->ano);
            printf("CPF: %s\n", listaAluno[iCont].CPF);
            printf("\n");              
          }
        }
        if(!achou)
          printf("Matricula Inexistente!\n");        
      }
      else
        sairLista = true;
    }while(!sairLista);
  }

}

int atualizarAluno(pessoa listaAluno[], int qtdAluno, data dia, data mes, data ano){
  int Matricula;
  int iCont;
  bool achou = false;
  bool sair = false;
  
  printf("Menu Atualizacao\n");
  if(qtdAluno == 0){
    return LISTA_VAZIA;
    } else {
      printf("Digite a matricula do Aluno que deseja atualizar: ");
      scanf("%d", &Matricula);
      getchar();
        
      for(iCont = 0; iCont < TAM_PESSOA; iCont++){
        if(listaAluno[iCont].matricula == Matricula){
          achou = true;
          if (listaAluno[iCont].ativo == true){
          int opcaoAtualizar; 
            do{
            printf("Digite a opcao que deseja atualizar: \n");
            printf ("0 - Voltar\n");
            printf ("1 - Nome\n");
            printf ("2 - CPF\n");
            printf ("3 - Data de nascimento\n");
            scanf("%d", &opcaoAtualizar); 
            getchar();

            switch (opcaoAtualizar){
              case 0:{
                sair = true;
                break;
              }
              case 1:{
                char novoNome [MAX];
                printf("digite o novo nome:\n");
                fgets(novoNome, MAX, stdin);
                strcpy(listaAluno[iCont].nome, novoNome);
                
                break;
              }
              case 2:{
                char novoCpf[MAX_CPF];
                printf("Digite o novo CPF: \n");
                fgets(novoCpf, MAX_CPF, stdin);
                strcpy(listaAluno[iCont].CPF, novoCpf);
                break;
              }
              case 3:{
                  int novoDia, novoMes, novoAno;
                  printf("digite o dia correto: (data de nascimento) ");
                  scanf("%d", &novoDia);
                  getchar();
                  printf("digite o mes correto: (data de nascimento) ");
                  scanf("%d", &novoMes);
                  getchar();
                  printf("digite o ano correto: (data de nascimento) ");
                  scanf("%d", &novoAno);
                  getchar();

                  listaAluno[iCont].dataNascimento->dia = novoDia;
                  listaAluno[iCont].dataNascimento->mes = novoMes;
                  listaAluno[iCont].dataNascimento->ano = novoAno;

                break;
              }
              default:{
                printf("Opcao invalida\n");
              }
            }   
          } while(sair == false);
        }  
      }  
    }
    if (!achou){
      return MATRICULA_INVALIDA;
    }
  }
} 

  

int exclusaoAluno(pessoa listaAluno[], int qtdAluno){
  int Matricula;
  int iCont;
  printf("Menu Exclusão\n");
  printf("Digite a matricula do Aluno que se deseja excluir: ");
  scanf("%d", &Matricula);
  getchar();

  for(iCont = 0; iCont < TAM_PESSOA; iCont++){
    if(listaAluno[iCont].matricula == Matricula){
      if(listaAluno[iCont].ativo == true){
        listaAluno[iCont].ativo = false;
        return EXCLUSAO_SUCESSO;
      }
    }
  }
}

int menuProfessor(){
  int opcaoProfessor;
  printf ("/Você está no Menu Professor\\ \n");
  printf ("Menu Professor\n");
  printf ("0 - Voltar\n");
  printf ("1 - Cadastrar professor\n");
  printf ("2 - Listar professor\n");
  printf ("3 - Atualizar professor\n");
  printf ("4 - Excluir professor\n");
  scanf ("%d", &opcaoProfessor);
  getchar();

  return opcaoProfessor;
}

int cadastrarProf (pessoa listaProfessor[], int qtdProfessor){
  printf ("Cadrasto de professor\n");

  int Matricula;
  printf ("digite a matricula: ");
  scanf("%d", &Matricula);
  getchar();
  //G: fazer validacao matricula

  
  if (Matricula <= 0)
    return MATRICULA_INVALIDA;
  else{
    for (int icont; icont < TAM_PESSOA; icont++)
      if(Matricula == listaProfessor[icont].matricula){
          return MATRICULA_INVALIDA;
      }
  }

  char nome[MAX];
  printf ("digite o nome do professor\n");
  fgets (nome, MAX, stdin);
  
  int sexo;
  printf ("digite o sexo, 1 para masculino 0 para feminino: ");
  scanf("%d", &sexo);
  getchar();

  if (sexo != 1 && sexo != 0)
    return SEXO_INVALIDO;

  //G: falta pegar a data de nascimento
  // G: talvez seja interessante transformara a data em um struct
  //com dia, mes e ano. assim da pra ver qm e mais velho mais facil.

  int dia, mes, ano;
  printf("digite o dia: (data de nascimento) ");
  scanf("%d", &dia);
  getchar();
  printf("digite o mes: (data de nascimento) ");
  scanf("%d", &mes);
  getchar();
  printf("digite o ano: (data de nascimento) ");
  scanf("%d", &ano);
  getchar();

  if (dia > 31 || dia < 1 || mes < 1 || mes > 12)
    return DATA_INVALIDA;

  char cpf[MAX_CPF];
  printf ("digite o CPF: ");
  fgets (cpf, MAX_CPF, stdin);

  int icont = 0;
  while (cpf[icont] != '\n')
    icont++;
  
  if (icont != 11){
    //G: fazer o resto da validacao do cpf e ver se n tem cpf repetido
    return CPF_INVALIDO;
  }
  else{
    for (icont = 0; icont < MAX_CPF; icont++)
      listaProfessor[qtdProfessor].CPF[icont] = cpf[icont];

    for (int icont = 0; icont < MAX; icont++)
      listaProfessor[qtdProfessor].nome[icont] = nome[icont];

      listaProfessor[qtdProfessor].matricula = Matricula;
      listaProfessor[qtdProfessor].sexo = sexo;
      listaProfessor->dataNascimento->dia = dia;
      listaProfessor->dataNascimento->mes = mes;
      listaProfessor->dataNascimento->ano = ano;
      listaProfessor[qtdProfessor].ativo = true;
  }return 0;
}
