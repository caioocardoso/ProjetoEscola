#include <stdio.h>
#include <stdbool.h>
#include "definicoes.h"
#include <string.h>
#include "models.h"


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

int inserirAluno(disciplina listaDisciplina[]) {
    int icont;
    int codigo, matricula;
    int achoucod = false, achoualuno = false;

    if (listaDisciplina->posicaoDisciplina == MAX_ALUNO)
        return TA_CHEIO_PAIZAO;

    printf("Qual codigo da materia que voce quer inserir o aluno: ");
    scanf("%d", &codigo);

    for (icont = 0; icont < TAM_DISCIPLINA && !achoucod; icont++) {
        if (codigo == listaDisciplina[icont].codigo && listaDisciplina[icont].ativo == true) {
            achoucod = true;
        }
    }
    icont--; // Ajusta icont para o índice correto

    if (achoucod) {
        achoucod = false;
        printf("Qual a matricula do aluno que voce quer inserir nessa materia? ");
        scanf("%d", &matricula);
        getchar();

        for (int jcont = 0; jcont < TAM_PESSOA && !achoualuno; jcont++) {
            if (listaAluno[jcont].matricula == matricula && listaAluno[icont].ativo == true) {
                achoualuno = true;
            }
        }

        if (!achoualuno) {
            return MATRICULA_INVALIDA;
        } else {
            listaDisciplina[icont].alunos[listaDisciplina[icont].posicaoDisciplina] = matricula;
            listaDisciplina[icont].posicaoDisciplina++;
        }
    } else {
        return CODIGO_INVALIDO;
    }

}

int desinserirAluno(disciplina listaDisciplina[]){
    printf ("excluir aluno da disciplina\n");

    int codigo, matricula;
    int achouCod = false, achouMat = false;
    int icont = 0;

    printf ("Qual o codigo da materia que voce quer excluir?");
    scanf ("%d", &codigo);
    getchar();

    for (icont; icont < TAM_DISCIPLINA && !achouCod; icont++)
        if (listaDisciplina[icont].codigo == codigo)
            achouCod = true;
    
    icont--;

    if (achouCod){
        printf ("Qual a matricula do aluno que sera excluido?");
        scanf ("%d", &matricula);
        getchar();

        for (int jcont = 0; jcont < TAM_DISCIPLINA && !achouMat; jcont++)
            if (listaDisciplina[icont].alunos[jcont] == matricula){
                listaDisciplina[icont].alunos[jcont] = ALUNO_DESINSERIDO;
                achouMat = true;
            }

            if (!achouMat)
                return MATRICULA_INVALIDA;
            else
                printf ("Aluno excluido com sucesso!");

    } else
        return CODIGO_INVALIDO;

}

int excluirDisciplina(disciplina listaDisciplina[]){
    int codigo;

    printf ("Qual o codigo da materia que voce quer excluir?");
    scanf ("%d", &codigo);
    getchar();

    for (int icont = 0; icont < TAM_DISCIPLINA; icont++)
        if (listaDisciplina[icont].codigo == codigo){
            listaDisciplina[icont].ativo = false;
            return EXCLUSAO_SUCESSO;
        }
}

int atualizarDisciplina(disciplina listaDisciplina[], int qtdDisciplina){
int codigo;
int iCont;
bool achou = false;
bool sair = false;

 printf("Menu Atualizacao\n");
  if(qtdDisciplina == 0){
    return LISTA_VAZIA;
    } else {
      printf("Digite o codigo da disciplina que deseja atualizar: ");
      scanf("%d", &codigo);
      getchar();

        for(iCont = 0; iCont < qtdDisciplina; iCont++){
            if(listaDisciplina[iCont].codigo == codigo){
            achou = true;
            printf(" -Voce esta alterando a disciplina %s .- \n", listaDisciplina[iCont].nome);

            int opcaoAtualizarDisc; 
            do{
            printf("Digite a opcao que deseja atualizar: \n");
            printf ("0 - Voltar\n");
            printf ("1 - Nome\n");
            printf ("2 - Semestre\n");
            printf ("3 - Professor\n");
            scanf("%d", &opcaoAtualizarDisc); 
            getchar();

                switch (opcaoAtualizarDisc){
                    case 0:{
                        sair = true;
                        break;
                    }
                    case 1:{
                        char novoNome [MAX];
                        printf("digite o novo nome da disciplina:\n");
                        fgets(novoNome, MAX, stdin);
                        strcpy(listaDisciplina[iCont].nome, novoNome);
                        break;
                    }
                    case 2:{
                        int novoSemestre;
                        printf("Digite o semestre correto: \n");
                        scanf("%d \n", &novoSemestre);
                        listaDisciplina[iCont].semestre = novoSemestre;
                        break;
                    }
                    case 3:{
                        int codProfNovo;
                        bool achouProf;
                        printf("Digite a matricula do novo professor: \n");
                        scanf("%d \n", &codProfNovo);

                        for (int jcont = 0; jcont < TAM_PESSOA; jcont++)
                            if (codProfNovo == listaProfessor[jcont].matricula)
                                achouProf = true;

                        if (achouProf != true)
                            return CODIGO_INVALIDO;
                    }
                    default:{
                        printf("Opcao invalida \n");
                        break;
                    }
                }
            } while(sair == false);
            }    
        }
        if (!achou)
        return CODIGO_INVALIDO;
    }   
} 