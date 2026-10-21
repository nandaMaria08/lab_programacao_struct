#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int matricula;
    char nome[50];
    float media;
}Aluno;

void lerTurma(Aluno turma[], int n){
    for(int i = 0; i < n; i++){
        printf("--- Cadastro do Aluno %d ---\n", i + 1);
        printf("Matrícula: ");
        scanf("%d", &turma[i].matricula);

        printf("Nome: ");
        scanf(" %[^\n]", turma[i].nome);

        printf("Média: ");
        scanf("%f", &turma[i].media);
        printf("\n");

    }
}

Aluno alunoMaiorMedia(Aluno turma[], int n){
    int indiceMaior = 0;
    for(int i = 0; i < n; i++){
        if(turma[i].media > turma[indiceMaior].media){
            indiceMaior = i;
        }
    }
    return turma[indiceMaior];
}

int main()
{
    const int TAM = 5;
    Aluno turma[TAM];

    printf("=== CADASTRO DE TURMA (%d ALUNOS) ===\n\n", TAM);
    lerTurma(turma, TAM);

    Aluno campeao = alunoMaiorMedia(turma, TAM);

    printf("=== ALUNO DE MAIOR DESTAQUE ===\n");
    printf("Nome: %s\n", campeao.nome);
    printf("Média: %.2f\n", campeao.media);

}
