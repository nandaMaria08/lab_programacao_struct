#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char modelo[30];
    int ano;
    float preco;
}Carro;

void buscarPorPreco(Carro frota[], int n, float precoMax){
    int encontrados = 0;

    printf("\n--- Veiculos com preco ate R$ %.2f ---\n", precoMax);
    for (int i = 0; i < n; i++) {
        if (frota[i].preco <= precoMax) {
            printf("Modelo: %s | Ano: %d | Preco: R$ %.2f\n", frota[i].modelo, frota[i].ano, frota[i].preco);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum carro encontrado nesta faixa de preco.\n");
    }
}

int main()
{
    Carro frota[6] = {
        {"Fiat Uno", 2015, 35000.00},
        {"Chevrolet Onix", 2020, 60000.00},
        {"Volkswagen Gol", 2018, 45000.00},
        {"Toyota Corolla", 2022, 110000.00},
        {"Honda Civic", 2019, 95000.00},
        {"Renault Kwid", 2021, 50000.00}
    };

    float precoLimite;
    printf("Digite o valor maximo para busca de carros: ");
    scanf("%f", &precoLimite);

    buscarPorPreco(frota, 6, precoLimite);

    return 0;
}
