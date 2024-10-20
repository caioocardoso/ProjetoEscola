#include "definicoes.h"

typedef struct Pessoa{
  int Matricula;
  char nome[MAX];
  int sexo;
  char dataNascimento[MAX_DATA]; 
  char CPF[MAX_CPF];
} pessoa; 

typedef struct Materia {
  int codigo;
  char nome[MAX];
  int semestre;
  char professor[MAX]; 
} materia;