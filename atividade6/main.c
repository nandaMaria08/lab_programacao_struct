#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char placa[10];
    int quilometragem;
    int statusRevisao;
}Veiculo;

int contarPendencias(Veiculo frota[], int n){
    int contador = 0;
    for (int i = 0; i < n; i++) {
        if (frota[i].statusRevisao == 0) {
            contador++;
        }
    }
    return contador;
}

void atualizarQuilometragem(Veiculo *v, int kmAdicional) {
    v->quilometragem += kmAdicional;
    if (v->quilometragem > 10000) {
        v->statusRevisao = 0;
    }
}


int main()
{
    #define TAM 4
    Veiculo frota[TAM] = {
        {"ABC-1234", 4500, 1},
        {"XYZ-9876", 9200, 1},
        {"DEF-5678", 10100, 0},
        {"GHI-4321", 2000, 1}
    };

    int opcao, indice, km;

    do {
        printf("\n=== GERENCIADOR DE FROTA ===\n");
        printf("1. Exibir Frota\n");
        printf("2. Atualizar Quilometragem de um Veiculo\n");
        printf("3. Consultar Veiculos com Pendencia de Revisao\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n--- Status Atual da Frota ---\n");
                for (int i = 0; i < TAM; i++) {
                    printf("[%d] Placa: %s | Km: %d | Status: %s\n",
                           i, frota[i].placa, frota[i].quilometragem,
                           frota[i].statusRevisao == 1 ? "Em Dia" : "Necessita Revisao");
                }
                break;

            case 2:
                printf("Digite o indice do veiculo (0 a %d): ", TAM - 1);
                scanf("%d", &indice);
                if (indice >= 0 && indice < TAM) {
                    printf("Digite a quilometragem a adicionar: ");
                    scanf("%d", &km);
                    atualizarQuilometragem(&frota[indice], km);
                    printf("Quilometragem atualizada com sucesso!\n");
                } else {
                    printf("Indice invalido!\n");
                }
                break;

            case 3:
                {
                    int pendentes = contarPendencias(frota, TAM);
                    printf("Total de veiculos que necessitam de revisao: %d\n", pendentes);
                }
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);
}
