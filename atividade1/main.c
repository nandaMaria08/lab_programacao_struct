#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
} Produto;

Produto criarProduto(int codigo, char nome[], float preco, int quantidade){
    Produto p;
    p.codigo = codigo;
    strcpy(p.nome, nome);
    p.preco = preco;
    p.quantidade = quantidade;
    return p;
}

void exibirProduto(Produto p){
    float valorTotal = p.preco * p.quantidade;
    printf("---Dados do produto---\n");
    printf("Codigo: %d\n", p.codigo);
    printf("Nome: %s\n", p.nome);
    printf("Preco Unitario: R$ %.2f\n", p.preco);
    printf("Quantidade: %d\n", p.quantidade);
    printf("Valor total: %.2f\n", valorTotal);
}

int main()
{
    Produto p1 = criarProduto(101, "Teclado", 250.0, 10);
    Produto p2 = criarProduto(102, "Mouse", 120.50, 15);

    exibirProduto(p1);
    exibirProduto(p2);
}
