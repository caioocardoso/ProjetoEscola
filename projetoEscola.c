#include <stdio.h>
#include <stdbool.h>
#include "definicoes.h"
#include "menus.h"
#include "models.h"

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
                int retorno = cadastrarAlu(listaAluno, qtdAluno);
                
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