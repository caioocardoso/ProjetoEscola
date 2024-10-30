#include <stdio.h>
#include <stdbool.h>
#include "definicoes.h"
#include <string.h>
#include "models.h"

int cadastrarAlu (pessoa listaAluno[], int qtdAluno){
  printf ("Cadrasto de aluno\n");

  int Matricula;
  printf ("digite a matricula\n");
  scanf("%d", &Matricula);
  getchar();
  //G: fazer validacao matricula

  
  if (Matricula <= 0)
    return MATRICULA_INVALIDA;
  else{
    for (int icont = 0; icont < TAM_PESSOA; icont++)
      if(Matricula == listaAluno[icont].matricula){
          return MATRICULA_INVALIDA;
      }
  }

  char nome[MAX];
  printf ("digite o nome do aluno\n");
  fgets (nome, MAX, stdin);
  
  int sexo;
  printf ("digite o sexo, 1 para masculino 0 para feminino\n");
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
      listaAluno[qtdAluno].CPF[icont] = cpf[icont];

    for (int icont = 0; icont < MAX; icont++)
      listaAluno[qtdAluno].nome[icont] = nome[icont];

      listaAluno[qtdAluno].matricula = Matricula;
      listaAluno[qtdAluno].sexo = sexo;
      listaAluno[qtdAluno].dataNascimento->dia = dia;
      listaAluno[qtdAluno].dataNascimento->mes = mes;
      listaAluno[qtdAluno].dataNascimento->ano = ano;
      listaAluno[qtdAluno].ativo = true;

  }return 0;
}

int listarAluno(){
    int opcaoListar;
    printf ("Como deseja listar os alunos?\n");
    printf ("1 - Listar por ordem de matricula\n");
    printf ("2 - Listar por sexo\n");
    printf ("3 - Listar por nome\n");
    printf ("4 - Listar alunos matriculados em menos de 3 materias\n");
    scanf ("%d", &opcaoListar);
    getchar();

    switch (opcaoListar)
    {
    case 1:{
        listarAlunoPadrao(listaAluno);
        break;
    }
    case 2:{
        listarAlunoSexo(listaAluno);
        break;
    }
    case 3: {
        listarAlunosNome(listaAluno, qtdAluno);
        break;
    }
    case 4:{
      listarAlunos3Disciplinas(listaAluno);
      break;
    }
    default:
      printf ("Opcao invalida");
        break;
    }


}

int listarAlunoPadrao(pessoa listaAluno[]){
  char opcaoLista;
  int sairLista = false;
  int achou = false;
  int Matricula;
  printf("Lista de alunos ativos no sistema!\n");

  for(int iCont = 0; iCont < TAM_PESSOA; iCont++){
    if(listaAluno[iCont].ativo == true){
      printf("Matricula: %d Nome: %s", listaAluno[iCont].matricula, listaAluno[iCont].nome);
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
          if(listaAluno[iCont].matricula == Matricula && listaAluno[iCont].ativo == true){
            achou = true;
            printf("\n\n");
            printf("Matricula: %d\n", Matricula);
            printf("Nome: %s", listaAluno[iCont].nome);
            printf("Sexo: ");
            if(listaAluno[iCont].sexo == 1)
              printf("Masculino\n");
            else
              printf("Feminino\n");
            printf("Data de Nascimento: %02d/%02d/%02d\n", listaAluno[iCont].dataNascimento->dia,
                                                  		   listaAluno[iCont].dataNascimento->mes,
                                                  		   listaAluno[iCont].dataNascimento->ano);
            printf("CPF: %s\n", listaAluno[iCont].CPF);
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

void listarAlunoSexo(pessoa listaAluno[]){
  char opcaoLista;
  int sairLista = false;
  int achou = false;
  int Matricula;
  printf("Lista de alunos ativos no sistema por sexo!\n");

  for(int iCont = 0; iCont < TAM_PESSOA; iCont++){
    if(listaAluno[iCont].ativo == true && listaAluno[iCont].sexo == 1){
      printf("Matricula: %d Nome: %s", listaAluno[iCont].matricula, listaAluno[iCont].nome);
      achou = true;
    }
  }
  for(int iCont = 0; iCont < TAM_PESSOA; iCont++){
    if(listaAluno[iCont].ativo == true && listaAluno[iCont].sexo == 0){
      printf("Matricula: %d Nome: %s", listaAluno[iCont].matricula, listaAluno[iCont].nome);
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
          if(listaAluno[iCont].matricula == Matricula && listaAluno[iCont].ativo == true){
            achou = true;
            printf("\n\n");
            printf("Matricula: %d\n", Matricula);
            printf("Nome: %s", listaAluno[iCont].nome);
            printf("Sexo: ");
            if(listaAluno[iCont].sexo == 1)
              printf("Masculino\n");
            else
              printf("Feminino\n");
            printf("Data de Nascimento: %02d/%02d/%02d\n", listaAluno[iCont].dataNascimento->dia,
                                                  		   listaAluno[iCont].dataNascimento->mes,
                                                  		   listaAluno[iCont].dataNascimento->ano);
            printf("CPF: %s\n", listaAluno[iCont].CPF);
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

void listarAlunosNome(pessoa listaAluno[], int qtdAluno){

    char opcaoLista;
    int sairLista = false;
    int achou = false;
    int Matricula;
    
    char nome [MAX][MAX];
    int matorigin[MAX];

    for (int icont = 0; icont < qtdAluno; icont++)
      for (int jcont = 0; jcont < MAX; jcont++){
        nome[icont][jcont] = listaAluno[icont].nome[jcont];
        matorigin[icont] = listaAluno[icont].matricula;
      }

    printf("Lista de alunos ativos no sistema!\n");

    // Ordenação dos nomes e matrículas
    char tempNome[MAX];
    int tempMatricula;

    for (int icont = 0; icont < qtdAluno - 1; icont++) {
        for (int jcont = 0; jcont < qtdAluno - icont - 1; jcont++) {
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


     for(int iCont = 0; iCont < qtdAluno; iCont++){
    if(listaAluno[iCont].ativo == true){
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
          if(listaAluno[iCont].matricula == Matricula && listaAluno[iCont].ativo == true){
            achou = true;
            printf("\n\n");
            printf("Matricula: %d\n", Matricula);
            printf("Nome: %s", listaAluno[iCont].nome);
            printf("Sexo: ");
            if(listaAluno[iCont].sexo == 1)
              printf("Masculino\n");
            else
              printf("Feminino\n");
            printf("Data de Nascimento: %02d/%02d/%02d\n", listaAluno[iCont].dataNascimento->dia,
                                                  		   listaAluno[iCont].dataNascimento->mes,
                                                  		   listaAluno[iCont].dataNascimento->ano);
            printf("CPF: %s\n", listaAluno[iCont].CPF);
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

void listarAlunos3Disciplinas (pessoa listaAluno[]){
  char opcaoLista;
  int sairLista = false;
  int achou = false;
  int Matricula;

  printf("Lista de alunos ativos no sistema matriculados em menos de 3 disicplinas!\n");

  for(int iCont = 0; iCont < TAM_PESSOA; iCont++){
    if(listaAluno[iCont].ativo == true && listaAluno[iCont].disciplinas < 3){
      printf ("%d", listaAluno[iCont].disciplinas);
      printf("Matricula: %d Nome: %s", listaAluno[iCont].matricula, listaAluno[iCont].nome);
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
          if(listaAluno[iCont].matricula == Matricula && listaAluno[iCont].ativo == true){
            achou = true;
            printf("\n\n");
            printf("Matricula: %d\n", Matricula);
            printf("Nome: %s", listaAluno[iCont].nome);
            printf("Sexo: ");
            if(listaAluno[iCont].sexo == 1)
              printf("Masculino\n");
            else
              printf("Feminino\n");
            printf("Data de Nascimento: %02d/%02d/%02d\n", listaAluno[iCont].dataNascimento->dia,
                                                  		   listaAluno[iCont].dataNascimento->mes,
                                                  		   listaAluno[iCont].dataNascimento->ano);
            printf("CPF: %s\n", listaAluno[iCont].CPF);
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

int atualizarAluno(pessoa listaAluno[], int qtdAluno){
  int Matricula;
  int iCont;
  bool achou = false;
  bool sair = false;
  
  printf("Menu Atualizacao\n");
  if(qtdAluno == 0){
    return LISTA_VAZIA;
    } else {
      printf("Digite a matricula do Aluno que deseja atualizar: ");
      scanf("%d", &Matricula);
      getchar();
        
      for(iCont = 0; iCont < TAM_PESSOA; iCont++){
        if(listaAluno[iCont].matricula == Matricula){
          achou = true;
          if (listaAluno[iCont].ativo == true){
          int opcaoAtualizar; 
            do{
            printf("Digite a opcao que deseja atualizar: \n");
            printf ("0 - Voltar\n");
            printf ("1 - Nome\n");
            printf ("2 - CPF\n");
            printf ("3 - Data de nascimento\n");
            scanf("%d", &opcaoAtualizar); 
            getchar();

            switch (opcaoAtualizar){
              case 0:{
                sair = true;
                break;
              }
              case 1:{
                char novoNome [MAX];
                printf("digite o novo nome:\n");
                fgets(novoNome, MAX, stdin);
                strcpy(listaAluno[iCont].nome, novoNome);
                
                break;
              }
              case 2:{
                char novoCpf[MAX_CPF];
                printf("Digite o novo CPF: \n");
                fgets(novoCpf, MAX_CPF, stdin);
                strcpy(listaAluno[iCont].CPF, novoCpf);
                break;
              }
              case 3:{
                  int novoDia, novoMes, novoAno;
                  printf("digite o dia correto: (data de nascimento) ");
                  scanf("%d", &novoDia);
                  getchar();
                  printf("digite o mes correto: (data de nascimento) ");
                  scanf("%d", &novoMes);
                  getchar();
                  printf("digite o ano correto: (data de nascimento) ");
                  scanf("%d", &novoAno);
                  getchar();

                  listaAluno[iCont].dataNascimento->dia = novoDia;
                  listaAluno[iCont].dataNascimento->mes = novoMes;
                  listaAluno[iCont].dataNascimento->ano = novoAno;

                break;
              }
              default:{
                printf("Opcao invalida\n");
              }
            }   
          } while(sair == false);
        }  
      }  
    }
    if (!achou){
      return MATRICULA_INVALIDA;
    }
  }
} 

int exclusaoAluno(pessoa listaAluno[]){
  int Matricula;
  int iCont;
  printf("Menu Exclusão\n");
  printf("Digite a matricula do Aluno que se deseja excluir: ");
  scanf("%d", &Matricula);
  getchar();

  for(iCont = 0; iCont < TAM_PESSOA; iCont++){
    if(listaAluno[iCont].matricula == Matricula){
      if(listaAluno[iCont].ativo == true){
        listaAluno[iCont].ativo = false;
        return EXCLUSAO_SUCESSO;
      }
    }
  }
}
