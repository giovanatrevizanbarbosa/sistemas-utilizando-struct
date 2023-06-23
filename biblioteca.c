/*
4. Considere que a instituição possui um cadastro de seus alunos com os seguintes dados:
Aluno(prontuario, nome)

Possui também um cadastro dos livros existentes na biblioteca com os seguintes dados:
Livro(ISBN, titulo)

Devemos implementar um sistema que permita o cadastro eletrônico dos alunos e dos livros da instituição. O sistema deve permitir o empréstimo de livros da biblioteca aos alunos e deve armazenar os dados de qual livro está com qual aluno. O sistema deve imprimir uma lista com os livros emprestados para cada um dos alunos.
*/

#include <stdio.h>
#include <string.h>
#define MAX 15

struct student{
    char pront[10];
    char name[30];
};
struct book{
    int isbn; // 13 digitos
    char title[100];
};
struct lentBook{
    char pront[10];
    char title[100];
    char name[30];
};

int menu();
void insertStudent(struct student element[], int size);
void insertBook(struct book element[], int size);
void prints(struct lentBook element);


int main(){
    struct student dataSt[MAX];
    struct book dataBk[MAX];
    struct lentBook dataLent[MAX];

    int selected, sizeOfStd = 0, sizeOfBook = 0, sizeOfLent = 0;
    int selectBook;
    char studentSrch[10];

    do{
        selected = menu();
        switch (selected){
        case 1:
            printf("\n---- DADOS DO ALUNO ----\n\n");
            insertStudent(dataSt, sizeOfStd);
            sizeOfStd++;

            break;
        case 2:
            printf("\n---- DADOS DO LIVRO ----\n\n");
            insertBook(dataBk, sizeOfBook);
            sizeOfBook++;

            break;
        case 3:
            if(sizeOfBook != 0){
                printf("\n----LIVROS CADASTRADOS--------\n\n");
                for(int i = 0; i < sizeOfBook; i++){
                    printf("> (%d) %s\n", i+1, dataBk[i].title);
                }

                printf("\nOpção desejada: ");
                scanf("%d", &selectBook);
                getchar();

                int i = 0, foundBk = 0;
                while((i < sizeOfBook) && (foundBk == 0)){
                    if(i+1 == selectBook){
                        strcpy(dataLent[sizeOfLent].title, dataBk[i].title);
                        foundBk = 1;
                    }
                    i++;
                }

                if(foundBk != 0){
                    printf("Prontuário: ");
                    fgets(studentSrch, 10, stdin);
                    getchar();

                    int j = 0, foundStd = 0;
                    while((j < sizeOfStd) && (foundStd == 0)){
                        if(strcasecmp(dataSt[j].pront, studentSrch) == 0){
                            strcpy(dataLent[sizeOfLent].pront, dataSt[j].pront);
                            strcpy(dataLent[sizeOfLent].name, dataSt[j].name);
                            foundStd = 1;
                            printf("Livro emprestado com sucesso.\n");
                        }
                        j++;
                    }
                    sizeOfLent++;
                }else{
                    printf("\nOpção inválida.\n");
                }
            }else{
                printf("\n----NENHUM LIVRO CADASTRADO-----\n");
            }
            break;
        case 4:
            if(sizeOfLent != 0){
                printf("\n----LIVROS EMPRESTADOS-----------\n");
                for(int i = 0; i < sizeOfLent; i++){
                    prints(dataLent[i]);
                }
            }else{
                printf("\n----NENHUM LIVRO EMPRESTADO-----\n");
            }

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
    fgets(element[size].pront, 10, stdin);
    element[size].pront[strcspn(element[size].pront, "\n")] = '\0';
    strcpy(element[size].pront, strupr(element[size].pront));
    getchar();

    printf("Nome: ");
    fgets(element[size].name, 30, stdin);
    element[size].name[strcspn(element[size].name, "\n")] = '\0';
    strcpy(element[size].name, strupr(element[size].name));
}
void insertBook(struct book element[], int size){
    printf("ISBN: ");
    scanf("%d", &element[size].isbn);
    getchar();

    printf("Título: ");
    fgets(element[size].title, 100, stdin);
    element[size].title[strcspn(element[size].title, "\n")] = '\0';
    strcpy(element[size].title, strupr(element[size].title));
}
void prints(struct lentBook element){
    printf("\n> Título:  %s \t\t Aluno(a):  %s\n", element.title, element.name);
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
    }while(option < 0 || option > 4);
    return option;
}