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

void listarProfessor(pessoa listaProfessor[]){
  int opcaoListar;
    printf ("Como deseja listar os alunos?\n");
    printf ("1 - Listar por ordem de matricula\n");
    printf ("2 - Listar por sexo\n");
    printf ("3 - Listar por nome\n");
    scanf ("%d", &opcaoListar);
    getchar();

    switch (opcaoListar)
    {
    case 1:{
        listarProfessorPadrao(listaProfessor);
        break;
    }
    case 2:{
        listarProfessorSexo(listaProfessor);
        break;
    }
    case 3: {
        listarProfessorNome(listaProfessor, qtdProfessor);
        break;
    }
    default:
      printf ("Opcao invalida");
        break;
    }
}

void listarProfessorPadrao(pessoa listaProfessor[]){
  char opcaoLista;
  int sairLista = false;
  int achou = false;
  int Matricula;
  printf("Lista de professores ativos no sistema!\n");

  for(int iCont = 0; iCont < TAM_PESSOA; iCont++){
    if(listaProfessor[iCont].ativo == true){
      printf("Matricula: %d Nome: %s", listaProfessor[iCont].matricula, listaProfessor[iCont].nome);
      achou = true;
    }
  }
  if(!achou)
    printf("Nenhum Aluno cadastrado.\n");
  else{
    do{
      achou = false;   	
      printf("Deseja verificar informacoes mais detalhadas de algum usuario? (y/n): ");
      scanf("%c", &opcaoLista);
      getchar();

      if(opcaoLista == 'y'){
        printf("digite o numero de matricula: ");
        scanf("%d", &Matricula);
        getchar();

        for(int iCont = 0; iCont < TAM_PESSOA; iCont++){       	
          if(listaProfessor[iCont].matricula == Matricula && listaProfessor[iCont].ativo == true){
            achou = true;
            printf("\n\n");
            printf("Matricula: %d\n", Matricula);
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
          printf("Matricula Inexistente!\n");        
      }
      else
        sairLista = true;
    }while(!sairLista);
  }

}

void listarProfessorSexo(pessoa listaProfessor[]){
  char opcaoLista;
  int sairLista = false;
  int achou = false;
  int Matricula;
  printf("Lista de professores ativos no sistema por sexo!\n");

  for(int iCont = 0; iCont < TAM_PESSOA; iCont++){
    if(listaProfessor[iCont].ativo == true && listaProfessor[iCont].sexo == 1){
      printf("Matricula: %d Nome: %s", listaProfessor[iCont].matricula, listaProfessor[iCont].nome);
      achou = true;
    }
  }
  for(int iCont = 0; iCont < TAM_PESSOA; iCont++){
    if(listaProfessor[iCont].ativo == true && listaProfessor[iCont].sexo == 0){
      printf("Matricula: %d Nome: %s", listaProfessor[iCont].matricula, listaProfessor[iCont].nome);
      achou = true;
    }
  }

  if(!achou)
    printf("Nenhum Aluno cadastrado.\n");
  else{
    do{
      achou = false;   	
      printf("Deseja verificar informacoes mais detalhadas de algum usuario? (y/n): ");
      scanf("%c", &opcaoLista);
      getchar();

      if(opcaoLista == 'y'){
        printf("digite o numero de matricula: ");
        scanf("%d", &Matricula);
        getchar();

        for(int iCont = 0; iCont < TAM_PESSOA; iCont++){       	
          if(listaProfessor[iCont].matricula == Matricula && listaProfessor[iCont].ativo == true){
            achou = true;
            printf("\n\n");
            printf("Matricula: %d\n", Matricula);
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
          printf("Matricula Inexistente!\n");        
      }
      else
        sairLista = true;
    }while(!sairLista);
  }

}

void listarProfessorNome(pessoa listaProfessor[], int qtdProfessor){

    char opcaoLista;
    int sairLista = false;
    int achou = false;
    int Matricula;
    
    char nome [MAX][MAX];
    int matorigin[MAX];

    for (int icont = 0; icont < qtdProfessor; icont++)
      for (int jcont = 0; jcont < MAX; jcont++){
        nome[icont][jcont] = listaProfessor[icont].nome[jcont];
        matorigin[icont] = listaProfessor[icont].matricula;
      }

    printf("Lista de alunos ativos no sistema!\n");

    // Ordenação dos nomes e matrículas
    char tempNome[MAX];
    int tempMatricula;

    for (int icont = 0; icont < qtdProfessor - 1; icont++) {
        for (int jcont = 0; jcont < qtdProfessor - icont - 1; jcont++) {
            if (strcmp(nome[jcont], nome[jcont + 1]) > 0) {
                // Troca os nomes
                strcpy(tempNome, nome[jcont]);
                strcpy(nome[jcont], nome[jcont + 1]);
                strcpy(nome[jcont + 1], tempNome);

                // Troca as matrículas correspondentes
                tempMatricula = matorigin[jcont];
                matorigin[jcont] = matorigin[jcont + 1];
                matorigin[jcont + 1] = tempMatricula;
            }
        }
    }


     for(int iCont = 0; iCont < qtdProfessor; iCont++){
    if(listaProfessor[iCont].ativo == true){
      printf("Matricula: %d Nome: %s", matorigin[iCont], nome[iCont]);
      achou = true;
    }
  }
  if(!achou)
    printf("Nenhum Aluno cadastrado.\n");
  else{
    do{
      achou = false;   	
      printf("Deseja verificar informacoes mais detalhadas de algum usuario? (y/n): ");
      scanf("%c", &opcaoLista);
      getchar();

      if(opcaoLista == 'y'){
        printf("digite o numero de matricula: ");
        scanf("%d", &Matricula);
        getchar();

        for(int iCont = 0; iCont < TAM_PESSOA; iCont++){       	
          if(listaProfessor[iCont].matricula == Matricula && listaProfessor[iCont].ativo == true){
            achou = true;
            printf("\n\n");
            printf("Matricula: %d\n", Matricula);
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
          printf("Matricula Inexistente!\n");        
      }
      else
        sairLista = true;
    }while(!sairLista);
  }
}