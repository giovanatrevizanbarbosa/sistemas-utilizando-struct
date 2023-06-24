/*  
2. Implemente um sistema para a portaria do IFSP Câmpus Araraquara. O sistema deve armazenar marca, modelo, cor, placas de um carro e também nome e prontuário do aluno motorista. O sistema deve permitir dois tipos de busca: 
Busca pela placa do carro;
Busca pelo prontuário do aluno.
*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAXINPUT 10
#define MAXCHARACTER 50

struct car {
    char brand[MAXCHARACTER];
    char model[MAXCHARACTER];
    char color[MAXCHARACTER];
    char prontuary[MAXINPUT];
    char studentName[MAXCHARACTER];
    int plate;
};

int menu();
void insertCarStudentData(struct car element[], int sizeCarData);
void searchByCarPlate(struct car elements[], int filter, int size);
void searchByProntuary(struct car elements[], char filter[MAXINPUT], int size);
void prints(struct car element);

int main(){

    struct car carData[MAXINPUT];

    int selected, sizeCarData;
    int filterPlate;
    char filterProntuary[MAXINPUT];

    sizeCarData = 0;
    do{
        selected = menu();
        switch (selected){
        case 1:
            insertCarStudentData(carData, sizeCarData);
            sizeCarData++;

            break;
        case 2:
            printf("---- BUSCA ----\n");
            printf("\nPlaca a buscar: ");
            scanf("%d", &filterPlate);

            searchByCarPlate(carData, filterPlate, sizeCarData);

            break;
        case 3:
            printf("---- BUSCA ----\n");
            printf("\nProntuário a buscar: ");
            fgets(filterProntuary, MAXINPUT, stdin);
            filterProntuary[strcspn(filterProntuary, "\n")] = '\0';
            
            searchByProntuary(carData, filterProntuary, sizeCarData);

            break;
        default:
            printf("Êxito em Sair.\n\n");
            break;
        }
    }while(selected != 0);

    
    return 0;
}
void insertCarStudentData(struct car element[], int sizeCarData){
    printf("---- DADOS DO CARRO E ALUNO ----\n");
    printf("Placa: ");
    scanf("%d", &element[sizeCarData].plate);
    getchar();

    printf("Marca: ");
    scanf("%s", element[sizeCarData].brand);
    element[sizeCarData].brand[strcspn(element[sizeCarData].brand, "\n")] = '\0';
    strcpy(element[sizeCarData].brand, strupr(element[sizeCarData].brand));
    getchar();

    printf("Modelo: ");
    scanf("%s", element[sizeCarData].model);
    strcpy(element[sizeCarData].model, strupr(element[sizeCarData].model));
    getchar();

    printf("Cor: ");
    scanf("%s", element[sizeCarData].color);
    element[sizeCarData].color[strcspn(element[sizeCarData].color, "\n")] = '\0';
    strcpy(element[sizeCarData].color, strupr(element[sizeCarData].color));
    getchar();

    printf("Nome do aluno: ");
    scanf("%s", element[sizeCarData].studentName);
    element[sizeCarData].studentName[strcspn(element[sizeCarData].studentName, "\n")] = '\0';
    strcpy(element[sizeCarData].studentName, strupr(element[sizeCarData].studentName));
    getchar();

    printf("Prontuário do aluno: ");
    scanf("%s", element[sizeCarData].prontuary);
    element[sizeCarData].prontuary[strcspn(element[sizeCarData].prontuary, "\n")] = '\0';
    strcpy(element[sizeCarData].prontuary, strupr(element[sizeCarData].prontuary));
    getchar();
}
void prints(struct car element){
    printf("\n> Marca: %s \t Modelo: %s \tCor: %s \t Nome: %s\n", element.brand, element.model, element.color, element.studentName);
}
void searchByCarPlate(struct car elements[], int filter, int size){
    printf("\n---- CARRO REFERENTE A PLACA: %d ----\n", filter);
    for(int index = 0; index != size; index++){
        if(elements[index].plate == filter){
            prints(elements[index]);
        }
    }
}
void searchByProntuary(struct car elements[], char filter[MAXINPUT], int size){
    printf("---- CARRO REFERENTE AO PRONTUARIO: %s----\n", filter);
    for(int index = 0; index != size; index++){
        if(strcasecmp(filter, elements[index].prontuary) == 0){
            prints(elements[index]);
        }
    }
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
        getchar();
        system("cls");
    }while(option < 0 || option > 3);
    return option;
}