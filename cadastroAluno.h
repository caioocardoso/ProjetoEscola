#include <stdio.h>
#include <stdbool.h>
#include "models.h"
#include "definicoes.h"

int cadastrarAlu (pessoa listaAluno[], int qtdAluno){
  printf ("Cadrasto de aluno\n");

  int matricula;
  printf ("digite a matricula\n");
  scanf("%d", &matricula);
  //G: fazer validacao matricula
  listaAluno[qtdAluno].Matricula = matricula;

  char nome[MAX];
  printf ("digite o nome do aluno\n");
  fgets (nome, MAX, stdin);
  for (int icont = 0; icont < MAX; icont++)
      listaAluno[qtdAluno].nome[icont] = nome[icont];

  int sexo;
  printf ("digite o sexo, 1 para masculino 0 para feminino\n");
  scanf("%d", &sexo);
  
  if (sexo != 1 && sexo != 0)
    return SEXO_INVALIDO;
  else
    listaAluno[qtdAluno].sexo = sexo;

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
        listaAluno[qtdAluno].CPF[icont] = cpf[icont];
    
  
  return 0;
}