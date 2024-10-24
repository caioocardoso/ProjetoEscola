
#include <stdio.h>
#include <stdbool.h>
#include "definicoes.h"

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
  int ativo;
} pessoa; 

typedef struct {
  int codigo;
  char nome[MAX];
  int semestre;
  int professor; 
  int ativo;
} disciplina;

pessoa listaAluno[TAM_PESSOA];
pessoa listaProfessor[TAM_PESSOA];
disciplina listaDisciplina[TAM_DISCIPLINA];

int qtdAluno = 0;
int qtdProfessor = 0;
int qtdDisciplina = 0;


int menuAluno();
int cadastrarAlu (pessoa listaAluno[], int qtdAluno);
int listarAluno(pessoa listaAluno[]);
int exclusaoAluno(pessoa listaAluno[]);
int menuProfessor();
int cadastrarProf (pessoa listaProfessor[], int qtdProfessor);
int menuDisciplina();
int cadastrarDisc(disciplina listaDisciplina[], int qtdDisciplina);

void main() {
  int opcao, sair = false;

  do {
      printf ("Menu projeto escola\n");
      printf ("0 - sair\n");
      printf ("1 - Menu aluno\n");
      printf ("2 - Menu professor\n");
      printf ("3 - Menu disciplina\n");

      scanf ("%d", &opcao);
      getchar();
      
      switch (opcao){
        case 0:{
          sair = true;
          break;
        }
        case 1:{
          
          int opcaoAluno;
          int sairAluno = false;
          
         
          
          do{
            opcaoAluno = menuAluno();

            switch (opcaoAluno){
              case 0:{
                sairAluno = true;
                break;
              }
              case 1:{
                opcaoAluno = 0;
                int retorno = cadastrarAlu(listaAluno, qtdAluno);

                if (retorno == MATRICULA_INVALIDA)
                    printf("Matricula invalida\n");
                else if (retorno == SEXO_INVALIDO)
                    printf("sexo invalido\n");
                else if (retorno == DATA_INVALIDA)
                    printf("data invalida\n");
                else if (retorno == CPF_INVALIDO)
                    printf("CPF invalido\n");
                else
                {
                  printf ("Cadrasto realizado com sucesso\n");
                  qtdAluno++;
                }
                break;
              }
              case 2:{
                listarAluno(listaAluno);
                break;
              }
              case 3:{
                
                break;
              }
              case 4:{
                opcaoAluno = 0;
                opcaoAluno = exclusaoAluno(listaAluno);
                
                if(opcaoAluno == EXCLUSAO_SUCESSO)
                  printf("Usuario excluido com sucesso!\n");
                else
                  printf("Nao foi possivel excluir este aluno!\n");
                break;
              }
              
            } 
            
          } while (!sairAluno);
          break;
        }
        /*case 2:{
          int opcaoProfessor;
          int sairProfessor = false;
          
         
          
          do{
            printf("\e[H\e[2J");
            opcaoProfessor = menuProfessor();

            switch (opcaoProfessor){
              case 0:{
                sairProfessor = true;
                break;
              }
              case 1:{
                int retorno = cadastrarProf(listaProfessor, qtdProfessor);

                if (retorno == MATRICULA_INVALIDA)
                    printf("Matricula invalida");
                else if (retorno == SEXO_INVALIDO)
                    printf("sexo invalido");
                else if (retorno == DATA_INVALIDA)
                    printf("data invalida");
                else if (retorno == CPF_INVALIDO)
                    printf("CPF invalido");
                else
                {
                  printf ("Cadrasto realizado com sucesso");
                  qtdProfessor++;
                }
              
              break;             
              }
            }
          } while (!sairProfessor);
          break;
        }*/
        case 3:{
          printf ("Você está no Menu disciplina\n");

          int opcaoDisc;
          int sairDisc = false;

          do{
              opcaoDisc = menuDisciplina();

              switch (opcaoDisc)
              {
                case 0:{
                  sairDisc = true;
                  break;
                }

                case 1:{
                  int retorno = cadastrarDisc(listaDisciplina, qtdDisciplina);

                  if (retorno == TA_CHEIO_PAIZAO)
                      printf ("Nao tem espaco para noas disciplinas, paizao");
                  else if (retorno == CODIGO_INVALIDO)
                      printf ("Codigo invalido");
                  else if (retorno == SEMESTRE_INVALIDO)
                      printf ("Semestre invalido");
                  else if (retorno == NOME_INVALIDO)
                      printf ("Nome invalido");
                  else if (retorno == PROFESSOR_INVALIDO)
                      printf ("Professor invalido");
                  else{
                      printf ("Cadrasto realizado com sucesso!");
                      qtdDisciplina++;
                  }
                  

                  break;
                }

                case 2:{
                  sairDisc = true;
                  break;
                }
                case 3:{
                  sairDisc = true;
                  break;
                }


                default:
                  break;
              }


          }while (!sairDisc);

          break;
        }
        default:{
          printf ("Opcao invalida\n");
        }
    }
  } while (!sair);
}




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

int listarAluno(pessoa listaAluno[]){
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


// disciplina


int menuDisciplina(){
  int opcaoDisciplina;
  printf ("Menu Disciplina\n");
  printf ("0 - Voltar\n");
  printf ("1 - Cadastrar Disciplina\n");
  printf ("2 - Listar Disciplina\n");
  printf ("3 - Atualizar Disciplina\n");
  printf ("4 - inserir aluno\n");
  printf ("5 - excluir aluno\n");
  printf ("5 - Excluir Disciplina\n");
  scanf ("%d", &opcaoDisciplina);
  getchar();

  return opcaoDisciplina;
}

int cadastrarDisc(disciplina listaDisciplina[], int qtdDisciplina){

  if (qtdDisciplina == TAM_DISCIPLINA)
      return TA_CHEIO_PAIZAO;

  printf ("Cadrasto de disciplinas\n");

  int codigo;
  printf ("Digite o codigo da disciplina\n");
  scanf ("%d", &codigo);
  getchar();

  if (codigo <= 0)
    return CODIGO_INVALIDO;
  else
    for (int icont = 0; icont < TAM_DISCIPLINA; icont++)
        if (codigo == listaDisciplina[icont].codigo)
            return CODIGO_INVALIDO;
  
  char nome[MAX];
  int igual = 0;
  printf ("Digite o nome da disciplina\n");
  fgets (nome, MAX, stdin);

  for (int icont = 0; icont < TAM_DISCIPLINA; icont++)
    for (int jcont = 0; jcont < TAM_DISCIPLINA; jcont++)
        if (nome[jcont] == listaDisciplina[icont].nome[jcont])
            igual++;

//G: isso foi uma tentativa de comparacao de strings. Se alguem tiver uma ideia melhor que a minha
// sinta-se a vontade para aplica-la.

  if(igual == TAM_DISCIPLINA)
    return NOME_INVALIDO;

  int semestre;
  printf ("Digite o semestre da disciplina\n");
  scanf ("%d", &semestre);
  getchar();


  if (semestre <= 0)
      return SEMESTRE_INVALIDO;
  else if (semestre > 15)
      return SEMESTRE_INVALIDO;


  int professor;
  int achou = false;
  printf ("Digite a matricula do professor da disciplina\n");
  scanf ("%d", &professor);
  getchar();

  for (int icont = 0; icont < TAM_PESSOA; icont++)
      if (professor == listaProfessor[icont].matricula)
          achou = true;

  if (achou != true)
      return PROFESSOR_INVALIDO;
  else {
    listaDisciplina[qtdDisciplina].codigo = codigo;
    listaDisciplina[qtdDisciplina].professor = professor;
    listaDisciplina[qtdDisciplina].semestre = semestre;
    listaDisciplina[qtdDisciplina].ativo = true;
        

    for (int icont = 0; icont < MAX; icont++)
      listaDisciplina[qtdDisciplina].nome[icont] = nome[icont];
  }
}