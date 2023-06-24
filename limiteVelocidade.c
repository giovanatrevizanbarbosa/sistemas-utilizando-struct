/*
1. Usando estruturas, implemente um programa que armazene placa e velocidade aferida dos veículos que trafegam em uma rodovia. O programa deve calcular a velocidade considerada (7% abaixo da aferida). Ao final apresentar os veículos que estão com excesso de velocidade, e se estiver em excesso, se até 20% ou acima de 20%, para isso considere como máxima a velocidade de 80 km/h.
*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXINPUT 10

struct car {
    int plate;
    float velocity;
};

int menu();
void insertCarData(struct car elements[], int size);
void printOverLimit(struct car elements[], int size);
void printUpToTwentyPercentLimit(struct car elements[], int size);
void printOverTwentyPercentLimit(struct car elements[], int size);
void prints(struct car element);

int main(){

    struct car carData[MAXINPUT];

    int selected, sizeCarData;


    sizeCarData = 0;
    do{
        selected = menu();
        switch (selected){
        case 1:
            insertCarData(carData, sizeCarData);
            sizeCarData++;
            break;
        case 2:
            printOverLimit(carData, sizeCarData);
            break;
        case 3:
            printUpToTwentyPercentLimit(carData, sizeCarData);
            break;
        case 4:
            printOverTwentyPercentLimit(carData, sizeCarData);
            break;
        default:
            printf("Êxito em Sair.\n\n");
            break;
        }
    }while(selected != 0);

    
    return 0;
}
void insertCarData(struct car elements[], int size){
    printf("---- DADOS DO CARRO ----\n");
    printf("Placa: ");
    scanf("%d", &elements[size].plate);
    getchar();

    printf("Velocidade aferida: ");
    scanf("%f", &elements[size].velocity);
    getchar();
    elements[size].velocity *= 0.93;
}
void prints(struct car element){
    printf("\n> Placa: %d \t Velocidade: %.1f \n", element.plate, element.velocity);
}
void printOverLimit(struct car elements[], int size){
    int findOverLimit = 0;
    printf("---- CARROS ACIMA DO LIMITE ----\n");
    for(int index = 0; index != size; index++){
        if(elements[index].velocity > 80.0){
            prints(elements[index]);
            findOverLimit = 1;
        }
    }
    if(findOverLimit == 0){
        printf("\n> Não há carros acima do limite.");
    }
}
void printUpToTwentyPercentLimit(struct car elements[], int size){
    int findOverLimit = 0;
    printf("---- CARROS ATÉ 20%% ACIMA DO LIMITE ----\n");
    for(int index = 0; index != size; index++){
        if((elements[index].velocity > 80.0) && (elements[index].velocity <= 96.0)){
            prints(elements[index]);
            findOverLimit = 1;
        }
    }
    if(findOverLimit == 0){
        printf("\n> Não há carros acima do limite.");
    }
}
void printOverTwentyPercentLimit(struct car elements[], int size){
    int findOverLimit = 0;
    printf("---- CARROS ACIMA DE 20%% DO LIMITE ----\n");
    for(int index = 0; index != size; index++){
        if(elements[index].velocity > 96.0){
            prints(elements[index]);
            findOverLimit = 1;
        }
    }
    if(findOverLimit == 0){
        printf("\n> Não há carros acima do limite.");
    }
}
int menu(){
    int option;
    do{
        printf("\n---- SELECIONE UMA OPÇÃO ----\n");
        printf("(1) - Inserir dados do carro\n");
        printf("(2) - Buscar veículos com excesso de velocidade\n");
        printf("(3) - Buscar veículos com até 20%% acima do limite\n");
        printf("(4) - Buscar veículos acima de 20%% do limite\n");
        printf("(0) - Sair\n");
        printf("\nOpção desejada: ");
        scanf("%d", &option);
        getchar();
        system("cls");
    }while(option < 0 || option > 4);
    return option;
}