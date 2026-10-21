#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int numeroConta;
    char titular[50];
    float saldo;
} ContaBancaria;

void depositar(ContaBancaria *c, float valor){
    if(valor > 0){
        c->saldo += valor;
        printf("Deposito de R$ %.2f realizado com sucesso. \n", valor);
    }else{
        printf("Valor de deposito invalido.\n");
    }
}

int sacar(ContaBancaria *c, float valor){
    if(valor > 0 && c->saldo >= valor){
        c->saldo -= valor;
        return 1;
    }
    return 0;
}

int main()
{
    ContaBancaria conta;
    conta.numeroConta = 12345;
    strcpy(conta.titular, "Maria Silva");
    conta.saldo = 500.000;

    printf("Saldo Inicial: R$ %.2f\n", conta.saldo);

    depositar(&conta, 250.000);
    printf("Saldo após depósito: R$ %.2f\n\n", conta.saldo);

    if(sacar(&conta, 100.00)){
      printf("Saque de R$ 100.00 efetuado com sucesso.\n");
    } else {
        printf("Falha ao efetuar saque: Saldo insuficiente.\n");
    }
    printf("Saldo após saque: R$ %.2f\n\n", conta.saldo);


    if (sacar(&conta, 1000.00)) {
        printf("Saque de R$ 1000.00 efetuado com sucesso.\n");
    } else {
        printf("Falha ao efetuar saque de R$ 1000.00: Saldo insuficiente.\n");
    }
    printf("Saldo Final: R$ %.2f\n", conta.saldo);
}
