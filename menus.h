#include <stdio.h>
#include <stdbool.h>
#include "definicoes.h"
#include <string.h>
#include "models.h"

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

int menuDisciplina(){
  int opcaoDisciplina;
  printf ("Menu Disciplina\n");
  printf ("0 - Voltar\n");
  printf ("1 - Cadastrar Disciplina\n");
  printf ("2 - Listar Disciplina\n");
  printf ("3 - Atualizar Disciplina\n");
  printf ("4 - inserir aluno lembrar de zerar o vetor de podicao (faz isso dento do switch na opcao 4) \n");
  printf ("5 - excluir aluno\n");
  printf ("5 - Excluir Disciplina\n");
  scanf ("%d", &opcaoDisciplina);
  getchar();

  return opcaoDisciplina;
}