/*
4. Considere que a instituição possui um cadastro de seus alunos com os seguintes dados:
Aluno(prontuario, nome)

Possui também um cadastro dos livros existentes na biblioteca com os seguintes dados:
Livro(ISBN, titulo)

Devemos implementar um sistema que permita o cadastro eletrônico dos alunos e dos livros da instituição. O sistema deve permitir o empréstimo de livros da biblioteca aos alunos e deve armazenar os dados de qual livro está com qual aluno. O sistema deve imprimir uma lista com os livros emprestados para cada um dos alunos.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXINPUT 15

struct student{
    char prontuary[10];
    char studentName[30];
};
struct book{
    int isbn; // 13 digitos
    char bookTitle[100];
};
struct lentBook{
    char prontuary[10];
    char bookTitle[100];
    char studentName[30];
};

int menu();
void insertStudent(struct student elements[], int size);
void insertBook(struct book element[], int size);
int lendBook(struct student element1[], struct book element2[], struct lentBook element3[], int sizeLentBookData, int sizeBookData, int sizeStudentData);
void printLentBookList(struct lentBook element[], int sizeLentBookData);

int main(){
    struct student studentData[MAXINPUT];
    struct book bookData[MAXINPUT];
    struct lentBook lentBookData[MAXINPUT];

    int selected, sizeStudentData = 0, sizeBookData = 0, sizeLentBookData = 0;

    do{
        selected = menu();
        switch (selected){
        case 1:
            printf("\n---- DADOS DO ALUNO ----\n");
            insertStudent(studentData, sizeStudentData);
            sizeStudentData++;

            break;
        case 2:
            printf("\n---- DADOS DO LIVRO ----\n");
            insertBook(bookData, sizeBookData);
            sizeBookData++;

            break;
        case 3:
            sizeLentBookData = lendBook(studentData, bookData, lentBookData, sizeLentBookData, sizeBookData, sizeStudentData);

            break;
        case 4:
            printf("\n----LIVROS EMPRESTADOS-----------\n");
            printLentBookList(lentBookData, sizeLentBookData);
            break;
        default:
            printf("Êxito em Sair.\n\n");
            break;
        }

    }while(selected != 0);

    return 0;
}
void insertStudent(struct student element[], int size){
    printf("Prontuário: ");
    fgets(element[size].prontuary, 10, stdin);
    element[size].prontuary[strcspn(element[size].prontuary, "\n")] = '\0';
    strcpy(element[size].prontuary, strupr(element[size].prontuary));
    getchar();

    printf("Nome: ");
    fgets(element[size].studentName, 30, stdin);
    element[size].studentName[strcspn(element[size].studentName, "\n")] = '\0';
    strcpy(element[size].studentName, strupr(element[size].studentName));
}
void insertBook(struct book element[], int size){
    printf("ISBN: ");
    scanf("%d", &element[size].isbn);
    getchar();

    printf("Título: ");
    fgets(element[size].bookTitle, 100, stdin);
    element[size].bookTitle[strcspn(element[size].bookTitle, "\n")] = '\0';
    strcpy(element[size].bookTitle, strupr(element[size].bookTitle));
}
int lendBook(struct student element1[], struct book element2[], struct lentBook element3[], int sizeLentBookData, int sizeBookData, int sizeStudentData){
    int selectBook;
    char studentSrch[10];
    if(sizeBookData != 0){
        printf("\n----LIVROS CADASTRADOS--------\n\n");
        for(int i = 0; i < sizeBookData; i++){
            printf("> (%d) %s\n", i+1, element2[i].bookTitle);
        }

        printf("\nOpção desejada: ");
        scanf("%d", &selectBook);
        getchar();

        for(int i = 0; i < sizeBookData; i++){
            if(i+1 == selectBook){
                strcpy(element3[sizeLentBookData].bookTitle, element2[i].bookTitle);
            }
        }
        
        printf("Prontuário: ");
        fgets(studentSrch, 10, stdin);

        for(int j = 0; j < sizeStudentData; j++){
            if(strcasecmp(element1[j].prontuary, studentSrch) == 0){
                strcpy(element3[sizeLentBookData].prontuary, element1[j].prontuary);
                strcpy(element3[sizeLentBookData].studentName, element1[j].studentName);
                printf("Livro emprestado com sucesso.\n");
            }
        }

        sizeLentBookData++;
    }else{
        printf("\n----NENHUM LIVRO CADASTRADO-----\n");
    }

    return sizeLentBookData;
}
void printLentBookList(struct lentBook element[], int sizeLentBookData){
    for(int i = 0; i < sizeLentBookData;  i++){
        printf("\n> Título:  %s \t\t Aluno(a):  %s\n", element[i].bookTitle, element[i].studentName);    
    }
}
int menu(){
    int option;
    do{
        printf("\n---- MENU BIBLIOTECA ----\n");
        printf("(1) - Inserir dados de aluno\n");
        printf("(2) - Inserir dados de livro\n");
        printf("(3) - Empréstimo de livro\n");
        printf("(4) - Lista de livros emprestados\n");
        printf("(0) - Sair\n");
        printf("\nOpção desejada: ");
        scanf("%d", &option);
        getchar();
        system("cls");
    }while(option < 0 || option > 4);
    return option;
}