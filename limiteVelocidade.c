/*
1. Usando estruturas, implemente um programa que armazene placa e velocidade aferida dos veículos que trafegam em uma rodovia. O programa deve calcular a velocidade considerada (7% abaixo da aferida). Ao final apresentar os veículos que estão com excesso de velocidade, e se estiver em excesso, se até 20% ou acima de 20%, para isso considere como máxima a velocidade de 80 km/h.
*/
#include <stdio.h>
#include <ctype.h>
#define MAXSIZE 10

struct car {
    int plate;
    float vel;
};

int menu();
void insert(struct car elements[], int size);
void prints(struct car element);

int main(){

    struct car dataset[MAXSIZE];

    int selected, size;


    size = 0;
    do{
        selected = menu();
        switch (selected){
        case 1:
            insert(dataset, size);
            size += 1;
            break;
        case 2:
            for(int index = 0; index != size; index++){
                if(dataset[index].vel > 80.0){
                    prints(dataset[index]);
                }
            }
            break;
        case 3:
            for(int index = 0; index != size; index++){
                if((dataset[index].vel > 80.0) && (dataset[index].vel <= 96.0)){
                    prints(dataset[index]);
                }
            }
            break;
        case 4:
            for(int index = 0; index != size; index++){
                if(dataset[index].vel > 96.0){
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
void insert(struct car elements[], int size){
    printf("Placa: ");
    scanf("%d", &elements[size].plate);
    fflush(stdin);
    printf("Velocidade aferida: ");
    scanf("%f", &elements[size].vel);
    fflush(stdin);
    elements[size].vel *= 0.93;
}
void prints(struct car element){
    printf("> Placa: %4d \t Velocidade: %.1f ", element.plate, element.vel);
}
int menu(){
    int option;
    do{
        printf("\n\n---- SELECIONE UMA OPÇÃO ----\n");
        printf("(1) - Inserir dados do carro\n");
        printf("(2) - Mostrar veículos com excesso de velocidade\n");
        printf("(3) - Mostrar veículos com até 20%% acima do limite\n");
        printf("(4) - Mostrar veículos acima de 20%% do limite\n");
        printf("(0) - Sair\n");
        printf("\nOpção desejada: ");
        scanf("%d", &option);
        fflush(stdin);
    }while(option < 0 || option > 4);
    return option;
}