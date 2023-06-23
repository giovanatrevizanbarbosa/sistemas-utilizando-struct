/*
3. Uma instituição bancária armazena os dados de todas as movimentações bancárias de seus clientes. Sabe-se que são armazenados os seguintes dados:

CLIENTE (nro_conta, cpf, nome, saldo)

MOVIMENTACAO(id, nro_conta, tipo[credito/debito], valor)

O sistema deve apresentar ao cliente seu extrato e atualizar o saldo do cliente sempre que houver alguma movimentação.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 10

struct client{
    int nroConta;
    int cpf;
    char name[50];
    double balance;
};

struct bankMove{
    int nroConta;
    int id;
    char type[8];
    double value;
};

int menu();
void insertClient(struct client element[], int size);
void insertMove(struct bankMove element[], int size);
void prints(struct bankMove element);

int main(){

    struct client dataClient[MAX];
    struct bankMove dataMove[MAX];

    int selected, sizeOfClient = 0, sizeOfMove = 0;
    int filterNro;

    do{
        selected = menu();
        switch (selected){
        case 1:
            insertClient(dataClient, sizeOfClient);
            sizeOfClient++;

            break;
        case 2:
            insertMove(dataMove, sizeOfMove);

            int index = 0, findClient = 0;
            while((index < sizeOfClient) && (findClient != 1)){
                if(dataMove[sizeOfMove].nroConta == dataClient[index].nroConta){
                    if(strcasecmp(dataMove[sizeOfMove].type, "credito") == 0){      
                        dataClient[index].balance += dataMove[sizeOfMove].value;
                    }else{
                        if(strcasecmp(dataMove[sizeOfMove].type, "debito") == 0){
                            dataClient[index].balance -= dataMove[sizeOfMove].value;
                        }else{
                            printf("Tipo digitado inválido.");
                        }
                    }
                    findClient = 1;
                    printf("\n>> Saldo: R$ %.2lf\n", dataClient[index].balance);
                }
                index++;
            }

            sizeOfMove++;

            break;
        case 3:
            printf("Insira o número da conta: ");
            scanf("%d", &filterNro);

            int i = 0;
            findClient = 0;
            while((i < sizeOfClient) && (findClient != 1)){
                if(dataClient[i].nroConta == filterNro){
                    printf("\n--- EXTRATO ------------\n");
                    printf("\n*CONTA* \t\t *NOME*");
                    printf("\n %d  \t\t\t  %s  ", dataClient[i].nroConta, dataClient[i].name);
                    if(sizeOfMove != 0){
                        printf("\n--- MOVIMENTAÇÕES------------\n");
                        for (int j = 0; j < sizeOfMove; j++) {
                            if (dataMove[j].nroConta == filterNro) {
                                prints(dataMove[j]);
                            }
                        }
                    }
                    findClient = 1;
                    printf("\n\n>> Saldo: \t\t R$ %.2lf\n", dataClient[i].balance);
                }
                i++;
            }

            break;
        default:
            printf("Êxito em Sair.\n\n");
            break;
        }
    }while(selected != 0);

    
    return 0;
}
void insertClient(struct client element[], int size){
    printf("Número da conta: ");
    scanf("%d", &element[size].nroConta);
    getchar();

    printf("CPF: ");
    scanf("%d", &element[size].cpf);
    getchar();

    printf("Nome: ");
    fgets(element[size].name, 50, stdin);
    strcpy(element[size].name, strupr(element[size].name));

    printf("Saldo: ");
    scanf("%lf", &element[size].balance);
    getchar();
}
void insertMove(struct bankMove element[], int size){
    printf("Número da conta: ");
    scanf("%d", &element[size].nroConta);
    getchar();

    printf("ID da movimentaçao: ");
    scanf("%d", &element[size].id);
    getchar();

    printf("Credito ou debito: ");
    fgets(element[size].type, 8, stdin);
    element[size].type[strcspn(element[size].type, "\n")] = '\0';
    strcpy(element[size].type, strupr(element[size].type));

    printf("Valor: ");
    scanf("%lf", &element[size].value);
    getchar();
}
void prints(struct bankMove element){
    printf("\n> Tipo:  %s \t Valor: %.2lf \t\t ID: %d", element.type, element.value, element.id);
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
    }while(option < 0 || option > 3);
    return option;
}