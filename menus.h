#include <stdio.h>
#include <stdbool.h>

int menuAluno(){
  int opcaoAluno;
  //int sairAluno = false;
  //int qtdAluno = 0;
  
  printf ("/Você está no Menu aluno\\ \n");
    printf ("Menu aluno\n");
    printf ("0 - Voltar\n");
    printf ("1 - Cadastrar aluno\n");
    printf ("2 - Listar aluno\n");
    printf ("3 - Atualizar aluno\n");
    printf ("4 - Excluir aluno\n");

    scanf ("%d", &opcaoAluno);

    return opcaoAluno;
/*
    switch (opcaoAluno){
      case 0: {
        sairAluno = true;
        break;
      }
      case 1: {
        printf ("Cadrasto de aluno\n");
        printf ("Digite a matricula\n");
        scanf("%d", &listAluno[qtdAluno].matricula);
      }
    }
  } while (!sairAluno);*/
}
