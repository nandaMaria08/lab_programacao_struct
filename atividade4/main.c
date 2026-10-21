#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    float x, y;
}Ponto2D;

float calcularDistancia(Ponto2D p1, Ponto2D p2){
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main()
{
    Ponto2D p1, p2;

    printf("=== CALCULO DE DISTANCIA EUCLIDIANA ===\n");
    printf("Digite as coordenadas (x y) do primeiro ponto: ");
    scanf("%f %f", &p1.x, &p1.y);

    printf("Digite as coordenadas (x y) do segundo ponto: ");
    scanf("%f %f", &p2.x, &p2.y);

    float distancia = calcularDistancia(p1, p2);
    printf("A distancia euclidiana entre os pontos e: %.2f\n", distancia);
}
