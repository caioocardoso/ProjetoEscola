#include <stdio.h>
#include <stdbool.h>
#include "menus.h"
#define MAX_DATA 10
#define MAX 255 
#define TAM_ALU 255
#define MAX_CPF 13

#define MATRICULA_INVALIDA -1
#define SEXO_INVALIDO -2
#define CPF_INVALIDO -3

typedef struct alu {
  int Matricula;
  char nome[MAX];
  int sexo;
  char dataNascimento[MAX_DATA]; 
  char CPF[MAX_CPF];
} Aluno; 

Aluno listAluno[TAM_ALU];
int qtdAluno = 0;
int menuAluno();
int cadastrarAlu (Aluno listAluno[], int qtdAluno);

typedef struct prof {
  int Matricula;
  char nome[MAX];
  int sexo;
  char dataNascimento[MAX_DATA]; 
  char CPF[MAX_CPF];
} Professor; 

typedef struct disc {
  int codigo;
  char nome[MAX];
  int semestre;
  char professor[MAX]; 
} Disciplina; 

void main() {
  int opcao, sair = false;

  do {
      printf ("Menu projeto escola\n");
      printf ("0 - sair\n");
      printf ("1 - Menu aluno\n");
      printf ("2 - Menu professor\n");
      printf ("3 - Menu disciplina\n");

      scanf ("%d", &opcao);
    
      switch (opcao){
        case 0:{
          sair = true;
          break;
        }
        case 1:{
          
          int opcaoAluno;
          int sairAluno = false;
          
          opcaoAluno = menuAluno();
          
          do{
            switch (opcaoAluno){
              case 0:{
                sairAluno = true;
                break;
              }
              case 1:{
                int retorno = cadastrarAlu(listAluno, qtdAluno);
                
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



    
     /* VALIDAÇÃO DO CPF
     if (CPF > 99999999 || CPF < 10000000)
        puts("CPF inválido") */
}

int cadastrarAlu (Aluno listAluno[], int qtdAluno){
  printf ("Cadrasto de aluno\n");

  int matricula;
  printf ("digite a matricula\n");
  scanf("%d", &matricula);
  //G: fazer validacao matricula
  listAluno[qtdAluno].Matricula = matricula;

  char nome[MAX];
  printf ("digite o nome do aluno\n");
  fgets (nome, MAX, stdin);
  for (int icont = 0; icont < MAX; icont++)
      listAluno[qtdAluno].nome[icont] = nome[icont];

  int sexo;
  printf ("digite o sexo, 1 para masculino 0 para feminino\n");
  scanf("%d", &sexo);
  
  if (sexo != 1 && sexo != 0)
    return SEXO_INVALIDO;
  else
    listAluno[qtdAluno].sexo = sexo;

  //G: falta pegar a data de nascimento
  // G: talvez seja interessante transformara a data em um struct
  //com dia, mes e ano. assim da pra ver qm e mais velho mais facil.

  char cpf[MAX_CPF];
  printf ("digite o CPF\n");
  fgets (cpf, MAX_CPF, stdin);

  int icont = 0;
  while (cpf[icont] != '\n')
    icont++;
  
  if (icont == 10)
    //G: fazer o resto da validacao do cpf e ver se n tem cpf repetido
    for (icont = 0; icont < MAX_CPF; icont++)
        listAluno[qtdAluno].CPF[icont] = cpf[icont];
    
  
  return 0;
}



