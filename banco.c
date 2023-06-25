/*
3. Uma instituição bancária armazena os dados de todas as movimentações bancárias de seus clientes. Sabe-se que são armazenados os seguintes dados:

CLIENTE (nro_conta, cpf, nome, saldo)

MOVIMENTACAO(id, nro_conta, tipo[credito/debito], valor)

O sistema deve apresentar ao cliente seu extrato e atualizar o saldo do cliente sempre que houver alguma movimentação.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXINPUT 10

struct client{
    int accountNumber;
    int cpf;
    char clientName[50];
    double clientBalance;
};
struct bankMove{
    int accountNumber;
    int moveId;
    char moveType[8];
    double moveValue;
};

int menu();
void insertClient(struct client element[], int size);
void insertBankMove(struct bankMove element[], int size);
void updateBalance(struct client elementClient[], struct bankMove elementBankMove[], int sizeClientData, int sizeBankMoveData);
void printExtract(struct client element[], int filter,int size);
void printBankMove(struct bankMove elements[], struct bankMove element[], int filter, int size);


int main(){

    struct client dataClient[MAXINPUT];
    struct bankMove dataMove[MAXINPUT];

    int selected, sizeClientData = 0, sizeBankMoveData = 0;
    int filterAccountNumber;

    do{
        selected = menu();
        switch (selected){
        case 1:
            insertClient(dataClient, sizeClientData);
            sizeClientData++;

            break;
        case 2:
            insertBankMove(dataMove, sizeBankMoveData);
            updateBalance(dataClient, dataMove, sizeClientData, sizeBankMoveData);
            sizeBankMoveData++;

            break;
        case 3:
            printf("---- VER EXTRATO ----\n");
            printf("Insira o número da conta: ");
            scanf("%d", &filterAccountNumber);

            printExtract(dataClient, filterAccountNumber, sizeClientData);
            printBankMove(dataMove, dataMove, filterAccountNumber, sizeBankMoveData);

            break;
        default:
            printf("Êxito em Sair.\n\n");
            break;
        }
    }while(selected != 0);

    
    return 0;
}
void insertClient(struct client element[], int size){
    printf("---- DADOS DO CLIENTE ----\n");
    printf("Número da conta: ");
    scanf("%d", &element[size].accountNumber);
    getchar();

    printf("CPF: ");
    scanf("%d", &element[size].cpf);
    getchar();

    printf("Nome: ");
    fgets(element[size].clientName, 50, stdin);
    strcpy(element[size].clientName, strupr(element[size].clientName));

    printf("Saldo: ");
    scanf("%lf", &element[size].clientBalance);
    getchar();
}
void insertBankMove(struct bankMove element[], int size){
    printf("---- DADOS DA MOVIMENTAÇÃO ----\n");
    printf("Número da conta: ");
    scanf("%d", &element[size].accountNumber);
    getchar();

    printf("ID da movimentaçao: ");
    scanf("%d", &element[size].moveId);
    getchar();

    printf("Credito ou debito: ");
    fgets(element[size].moveType, 8, stdin);
    element[size].moveType[strcspn(element[size].moveType, "\n")] = '\0';
    strcpy(element[size].moveType, strupr(element[size].moveType));

    printf("Valor: ");
    scanf("%lf", &element[size].moveValue);
    getchar();
}
void updateBalance(struct client elementClient[], struct bankMove elementBankMove[], int sizeClientData, int sizeBankMoveData){
    int index = 0;
    int findClient = 0;
    while((index < sizeClientData) && (findClient != 1)){
        if(elementBankMove[sizeBankMoveData].accountNumber == elementClient[index].accountNumber){
            if(strcasecmp(elementBankMove[sizeBankMoveData].moveType, "credito") == 0){      
                elementClient[index].clientBalance += elementBankMove[sizeBankMoveData].moveValue;
            }else{
                if(strcasecmp(elementBankMove[sizeBankMoveData].moveType, "debito") == 0){
                    elementClient[index].clientBalance -= elementBankMove[sizeBankMoveData].moveValue;
                }else{
                    printf("Tipo digitado inválido.");
                }
            }
            findClient = 1;
            printf("\n>> Saldo: R$ %.2lf\n", elementClient[index].clientBalance);
        }
        index++;
    }
}
void printExtract(struct client element[], int filter, int size){
    int index = 0;
    int findClient = 0;
    while((index < size) && (findClient != 1)){
        if(element[index].accountNumber == filter){
            printf("\n---- EXTRATO ----\n");
            printf("\n*CONTA* \t\t *NOME*");
            printf("\n %d  \t\t\t  %s  ", element[index].accountNumber, element[index].clientName);
            findClient = 1;
            printf("\n\n>> Saldo: \t\t R$ %.2lf\n", element[index].clientBalance);
        }
        index++;
    }
}
void printBankMove(struct bankMove elements[], struct bankMove element[], int filter, int size){
    if(size != 0){
        printf("\n---- MOVIMENTAÇÕES----\n");
        for (int j = 0; j < size; j++) {
            if (elements[j].accountNumber == filter) {
                printf("\n> Tipo:  %s \t Valor: %.2lf \t\t ID: %d\n", element[j].moveType, element[j].moveValue, element[j].moveId);
            }
        }
    }
}
int menu(){
    int option;
    do{
        printf("\n---- MENU BANCO ----\n\n");
        printf("(1) - Inserir dados do cliente\n");
        printf("(2) - Inserir movimentação bancária\n");
        printf("(3) - Exibir extrato\n");
        printf("(0) - Sair\n");
        printf("\nOpção desejada: ");
        scanf("%d", &option);
        getchar();
        system("cls");
    }while(option < 0 || option > 3);
    return option;
}