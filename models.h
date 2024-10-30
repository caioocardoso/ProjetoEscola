#include <stdio.h>
#include <stdbool.h>
#include "definicoes.h"

#ifndef MODELS_H
#define MODELS_H

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
  int disciplinas;
  int ativo;
} pessoa; 

typedef struct {
  int codigo;
  char nome[MAX];
  int semestre;
  int professor; 
  int alunos[MAX_ALUNO];
  int posicaoDisciplina;
  int ativo;
} disciplina;

pessoa listaAluno[TAM_PESSOA];
pessoa listaProfessor[TAM_PESSOA];
disciplina listaDisciplina[TAM_DISCIPLINA];

int qtdAluno = 0;
int qtdProfessor = 0;
int qtdDisciplina = 0;

#endif