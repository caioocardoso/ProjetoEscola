#include <stdio.h>
#include <stdbool.h>
#include "definicoes.h"
#include <string.h>
#include "models.h"


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