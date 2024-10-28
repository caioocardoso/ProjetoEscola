#include <stdio.h>
#include <stdbool.h>
#include "definicoes.h"
#include <string.h>
#include "models.h"


int cadastrarProf (pessoa listaProfessor[], int qtdProfessor){
  printf ("Cadrasto de professor\n");

  int Codigo;
  printf ("digite o codigo do professor\n");
  scanf("%d", &Codigo);
  getchar();
  //G: fazer validacao Codigo

  
  if (Codigo <= 0)
    return MATRICULA_INVALIDA;
  else{
    for (int icont = 0; icont < TAM_PESSOA; icont++)
      if(Codigo == listaProfessor[icont].matricula && listaProfessor[icont].ativo == true){
          return MATRICULA_INVALIDA;
      }
  }

  char nome[MAX];
  printf ("digite o nome do professor\n");
  fgets (nome, MAX, stdin);
  
  int sexo;
  printf ("digite o sexo, 1 para masculino 0 para feminino\n");
  scanf("%d", &sexo);
  getchar();

  if (sexo != 1 && sexo != 0)
    return SEXO_INVALIDO;

  int dia, mes, ano;
  printf("digite o dia: (data de nascimento)\n");
  scanf("%d", &dia);
  getchar();
  printf("digite o mes: (data de nascimento)\n");
  scanf("%d", &mes);
  getchar();
  printf("digite o ano: (data de nascimento)\n");
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
      listaProfessor[qtdProfessor].CPF[icont] = cpf[icont];

    for (int icont = 0; icont < MAX; icont++)
      listaProfessor[qtdProfessor].nome[icont] = nome[icont];

    listaProfessor[qtdProfessor].matricula = Codigo;
    listaProfessor[qtdProfessor].sexo = sexo;
    listaProfessor[qtdProfessor].dataNascimento->dia = dia;
    listaProfessor[qtdProfessor].dataNascimento->mes = mes;
    listaProfessor[qtdProfessor].dataNascimento->ano = ano;
    listaProfessor[qtdProfessor].ativo = true;
  }
  return 0;
}

int listarProfessor(pessoa listaProfessor[]){
  char opcaoLista;
  int sairLista = false;
  int achou = false;
  int Codigo;
  printf("Lista de professores ativos no sistema!\n");

  for(int iCont = 0; iCont < TAM_PESSOA; iCont++){
    if(listaProfessor[iCont].ativo == true){
      printf("Codigo: %d Nome: %s", listaProfessor[iCont].matricula, listaProfessor[iCont].nome);
      achou = true;
    }
  }
  if(!achou)
    printf("Nenhum professor cadastrado.\n");
  else{
    do{
      achou = false;   	
      printf("Deseja verificar informacoes mais detalhadas de algum professor? (y/n): ");
      scanf("%c", &opcaoLista);
      getchar();

      if(opcaoLista == 'y'){
        printf("digite o numero de Codigo: ");
        scanf("%d", &Codigo);
        getchar();

        for(int iCont = 0; iCont < TAM_PESSOA; iCont++){       	
          if(listaProfessor[iCont].matricula == Codigo && listaProfessor[iCont].ativo == true){
            achou = true;
            printf("\n\n");
            printf("Codigo: %d\n", Codigo);
            printf("Nome: %s", listaProfessor[iCont].nome);
            printf("Sexo: ");
            if(listaProfessor[iCont].sexo == 1)
              printf("Masculino\n");
            else
              printf("Feminino\n");
            printf("Data de Nascimento: %02d/%02d/%02d\n", listaProfessor[iCont].dataNascimento->dia,
                                                  		   listaProfessor[iCont].dataNascimento->mes,
                                                  		   listaProfessor[iCont].dataNascimento->ano);
            printf("CPF: %s\n", listaProfessor[iCont].CPF);
            printf("\n");              
          }
        }
        if(!achou)
          printf("Codigo Inexistente!\n");        
      }
      else
        sairLista = true;
    }while(!sairLista);
  }
}