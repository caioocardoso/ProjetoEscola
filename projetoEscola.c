
#include <stdio.h>
#include <stdbool.h>
#include "definicoes.h"

typedef struct {
  int dia;
  int mes;
  int ano;
}data;

typedef struct {
  int Matricula;
  char nome[MAX];
  int sexo;
  data dataNascimento[MAX_DATA];
  char CPF[MAX_CPF];
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
                int retorno = cadastrarAlu(listaAluno, qtdAluno);

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
                  qtdAluno++;
                }
                
              }
              
            } 
            
          } while (!sairAluno);

          break;
        }
        case 2:{
          printf ("Você está no Menu professor\n");

          break;
        }
        case 3:{
          printf ("Você está no Menu disciplina\n");
          
          break;
        }
        default:{
          printf ("Opcao invalida\n");
        }
    }
  } while (!sair);
}













int menuAluno(){
  int opcaoAluno;
  printf ("/Você está no Menu aluno\\ \n");
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

  int matricula;
  printf ("digite a matricula\n");
  scanf("%d", &matricula);
  getchar();
  //G: fazer validacao matricula

  
  if (matricula <= 0)
    return MATRICULA_INVALIDA;
  else{
    for (int icont; icont < TAM_PESSOA; icont++)
      if(matricula == listaAluno[icont].Matricula){
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
  printf("digite a dia da sua data de nascimento");
  scanf("%d", &dia);
  getchar();
  printf("digite a mes da sua data de nascimento");
  scanf("%d", &mes);
  getchar();
  printf("digite a ano da sua data de nascimento");
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

      listaAluno[qtdAluno].Matricula = matricula;

      listaAluno[qtdAluno].sexo = sexo;

      listaAluno->dataNascimento->dia = dia;
      listaAluno->dataNascimento->mes = mes;
      listaAluno->dataNascimento->ano = ano;
      

  }
  
  return 0;
}
