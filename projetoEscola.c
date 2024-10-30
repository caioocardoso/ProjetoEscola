#include <stdio.h>
#include <stdbool.h>
#include "definicoes.h"
#include <string.h>
#include "models.h"

#include "menus.h"
#include "funcoesAluno.h"
#include "funcoesProfessores.h"
#include "funcoesDisciplinas.h"

int menuAluno();
int cadastrarAlu (pessoa listaAluno[], int qtdAluno);
int listarAluno();
int listarAlunoPadrao(pessoa listaAluno[]);
void listarAlunoSexo(pessoa listaAluno[]);
void listarAlunosNome(pessoa listaAluno[], int qtdAluno);
void listarAlunos3Disciplinas (pessoa listaAluno[]);
int atualizarAluno(pessoa listaAluno[], int qtdAluno);
int exclusaoAluno(pessoa listaAluno[]);

int menuProfessor();
int cadastrarProf (pessoa listaProfessor[], int qtdProfessor);
void listarProfessor(pessoa listaProfessor[]);
void listarProfessorPadrao(pessoa listaProfessor[]);
void listarProfessorSexo(pessoa listaProfessor[]);
void listarProfessorNome(pessoa listaProfessor[], int qtdProfessor);
int atualizarProfessor(pessoa listaProfessor[], int qtdProfessor);
int excluirProfessor(pessoa listaProfessor[]);



int menuDisciplina();
int cadastrarDisc(disciplina listaDisciplina[], int qtdDisciplina);
int inserirAluno(disciplina listaDisciplina[]);

void main() {
  int opcao, sair = false;

for (int icont = 0; icont <TAM_DISCIPLINA; icont++){
    listaDisciplina[icont].posicaoDisciplina = 0;
    listaAluno[icont].disciplinas = 0;
}
//limpa as posicoes dos alunos dentro para poder ser usado no vetor de alunos dentro do struct de disciplinas
// para que seja possivel incrementalas;

for (int icont = 0; icont < TAM_DISCIPLINA; icont++)
  for (int jcont = 0; jcont < MAX_ALUNO; jcont++)
      listaDisciplina[icont].alunos[jcont] = 0;
//limpa o vetor de alunos do struct de disciplinas para que nao haja erros na hora de pesquisar umas matricula


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
                if (qtdAluno == TAM_PESSOA){
                  printf("Lista Cheia, impossivel cadastrar mais alunos!\n");
                } else{
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
                }
                break;
              }
              case 2:{
                listarAluno(listaAluno);
                 
                break;
              }
              case 3:{
                int retorno = atualizarAluno(listaAluno, qtdAluno);
                if (retorno == MATRICULA_INVALIDA)
                printf("Matricula inválida\n");
                else if (retorno == LISTA_VAZIA)
                printf("Lista Vazia.\n");
                else 
                printf("Aluno atualizado!\n");
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
        case 2:{
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
                  qtdProfessor++;
                }
              
              break;             
              }
              case 2:{
                listarProfessor(listaProfessor);
                
                break;
              }
              case 3:{
                int retorno = atualizarProfessor(listaProfessor, qtdProfessor);

                if (retorno == LISTA_VAZIA)
                  printf ("Lista vazia\n");
                else if (retorno == MATRICULA_INVALIDA)
                  printf ("Matricula invalida\n");
                else
                  printf ("Atualizado com sucesso\n");

                break;

              }
              case 4: {
                int retorno = excluirProfessor(listaProfessor);

                if (retorno == EXCLUSAO_SUCESSO)
                  printf ("Professor excluido com sucesso\n");
                else 
                  printf ("falha na exclusao do professor");

                break;
              }
            }
          } while (!sairProfessor);
          break;
        }
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
                  printf ("Listar Disciplina\n");
                  break;
                }
                case 3:{
                  printf ("Atualizar Disciplina\n");
                  break;
                }
                case 4:{
                  printf ("Inserir aluno \n");

                  int retorno = inserirAluno(listaDisciplina);

                  if (retorno == TA_CHEIO_PAIZAO)
                    printf ("Nao tem mais espaco na sala paizao\n");
                  else if (retorno == CODIGO_INVALIDO)
                    printf ("Codigo invalido\n");
                  else if (retorno == MATRICULA_INVALIDA)
                    printf ("Matricula invalida\n");
                  else{
                    printf ("Aluno inserido com sucesso");
                  }
                  break;
                }
                case 5:{
                  int retorno = desinserirAluno(listaDisciplina);

                  if (retorno == CODIGO_INVALIDO)
                    printf ("Codigo invalido");
                  else if (retorno == MATRICULA_INVALIDA)

                    printf ("Matricula invalida");

                    break;
                  
                }
                case 6:{
                  printf ("Excluir Disciplina\n");

                  int retorno = excluirDisciplina(listaDisciplina);

                  if (retorno == EXCLUSAO_SUCESSO)
                      printf ("Exclusao realizada com sucesso!");
                  else
                      printf ("Nao foi possivel excluir a disciplina");

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