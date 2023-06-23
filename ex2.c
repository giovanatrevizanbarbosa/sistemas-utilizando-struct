/*  
2. Implemente um sistema para a portaria do IFSP Câmpus Araraquara. O sistema deve armazenar marca, modelo, cor, placas de um carro e também nome e prontuário do aluno motorista. O sistema deve permitir dois tipos de busca: 
Busca pela placa do carro;
Busca pelo prontuário do aluno.
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXSIZE 10
#define MAXCARC 50

struct car {
    char brand[MAXCARC];
    char model[MAXCARC];
    char color[MAXCARC];
    char pront[10];
    char name[MAXCARC];
    int plate;
};

int menu();
void insert(struct car element[], int size);
void prints(struct car element);

int main(){

    struct car dataset[MAXSIZE];

    int selected, size;
    int filterPlate;
    char filterPront[10];

    size = 0;
    do{
        selected = menu();
        switch (selected){
        case 1:
            insert(dataset, size);
            size++;

            break;
        case 2:
            printf("Placa a buscar: ");
            scanf("%d", &filterPlate);

            for(int index = 0; index != size; index++){
                if(dataset[index].plate == filterPlate){
                    prints(dataset[index]);
                }
            }

            break;
        case 3:
            printf("Prontuário a buscar: ");
            fgets(filterPront, 10, stdin);
            filterPront[strcspn(filterPront, "\n")] = '\0';
            
            for(int index = 0; index != size; index++){
                if(strcasecmp(filterPront, dataset[index].pront) == 0){
                    prints(dataset[index]);
                }
            }
            break;
        default:
            printf("Êxito em Sair.\n\n");
            break;
        }
    }while(selected != 0);

    
    return 0;
}
void insert(struct car element[], int size){
    printf("Placa: ");
    scanf("%d", &element[size].plate);
    getchar();

    printf("Marca: ");
    scanf("%s", element[size].brand);
    element[size].brand[strcspn(element[size].brand, "\n")] = '\0';
    strcpy(element[size].brand, strupr(element[size].brand));
    getchar();

    printf("Modelo: ");
    scanf("%s", element[size].model);
    strcpy(element[size].model, strupr(element[size].model));
    getchar();

    printf("Cor: ");
    scanf("%s", element[size].color);
    element[size].color[strcspn(element[size].color, "\n")] = '\0';
    strcpy(element[size].color, strupr(element[size].color));
    getchar();

    printf("Nome do aluno: ");
    scanf("%s", element[size].name);
    element[size].name[strcspn(element[size].name, "\n")] = '\0';
    strcpy(element[size].name, strupr(element[size].name));
    getchar();

    printf("Prontuário do aluno: ");
    scanf("%s", element[size].pront);
    element[size].pront[strcspn(element[size].pront, "\n")] = '\0';
    strcpy(element[size].pront, strupr(element[size].pront));
    getchar();
}
void prints(struct car element){
    printf("\n> Marca: %s \t Modelo: %s \tCor: %s \t Nome: %s\n\n", element.brand, element.model, element.color, element.name);
}
int menu(){
    int option;
    do{
        printf("\n---- SELECIONE UMA OPÇÃO ----\n");
        printf("(1) - Inserir dados do carro e proprietário\n");
        printf("(2) - Busca pela placa do carro\n");
        printf("(3) - Busca pelo prontuário do aluno\n");
        printf("(0) - Sair\n");
        printf("\nOpção desejada: ");
        scanf("%d", &option);
        fflush(stdin);
    }while(option < 0 || option > 3);
    return option;
}