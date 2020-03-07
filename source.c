#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// ispisivanje menija
void Menu() {
    printf("1. Dodaj novi Todo\n");
    printf("2. Obrisi Todo\n");
    printf("3. Uradi toggle na isDone\n\n");
    printf("Unesi 1, 2 ili 3: ");
}

// dodavanje novog TODO-a
void addTodo(Todo* t) {
    printf("Unesite ID: ");
    scanf("%d", &t->id);
    printf("Unesite ime stavke: ");
    scanf("%s",t->name);
    printf("Unesite da li je stavka kompletirana: ");
    scanf("%s", t->isDone);
    getchar();

}

// ucitavanje TODO-a
int ucitajID(Todo* t) {
    FILE* file = fopen("todo.txt", "r");

    if(file == NULL) {
        printf("Ne postoji fajl!\n");
        return 0;
    }

    int id;

    while(!feof(file)) {
        fscanf(file,"%d%*[^\n]",&id);

        if(id == t->id) {
            return 1;
        }

    }


    fclose(file);
    return 0;

}

// brisanje linije sa datim ID
void delLine(int id) {
    // pronalazenje linije
    FILE* file = fopen("todo.txt", "r");

    if(file == NULL) {
        printf("Ne postoji fajl!\n");
        return;
    }

    int id2;
    int cnt = 0;
    int cnt2 = 0;

    while(!feof(file)) {
        fscanf(file,"%d%*[^\n]", &id2);

        if(id == id2) {
            cnt2++;
            break;

        } else {
            cnt++;
            cnt2++;
        }

    }


    fclose(file);

    if(cnt == cnt2) {
        printf("Ovaj ID ne postoji!");
        return;
    }


    // brisanje linije
    char str[100];

    FILE *file2;
    int delLine = cnt + 1;
    int line = 0;

    file = fopen("todo.txt", "r");

    rewind(file);

    file2 = fopen("todo2.txt", "w");

    while(fgets(str, 99, file) != NULL) {
        line++;

        if(line != delLine) {
            fputs(str, file2);
        } else {
            printf("%s", str);
        }
    }

    fclose(file);
    fclose(file2);

    remove("todo.txt");
    rename("todo2.txt", "todo.txt");

}



void add() {
    getchar();
    FILE* file = fopen("todo.txt", "a");
    Todo t1;
    addTodo(&t1);

    fflush(stdin);
    if(ucitajID(&t1) == 1) {
        printf("ID vec postoji.\n");
        printf("Unesite novi ID: ");
        scanf("%d", &t1.id);
    }



    fprintf(file,"%d %s %s \n", t1.id, t1.name, t1.isDone);
    fclose(file);


}

void rm() {
    printf("Unesite ID za brisanje: ");
    int idZaBrisanje;
    scanf("%d", &idZaBrisanje);
    delLine(idZaBrisanje);
}

// trazi se linija sa datim ID i menja joj se zadnja vrednost (true <-> false)
void toggleTodo(int id) {
    FILE* file = fopen("todo.txt", "r");

    if(file == NULL) {
        printf("Ne postoji fajl!\n");
        return;
    }

    int id2;
    int cnt = 0;
    int cnt2 = 0;

    while(!feof(file)) {
        fscanf(file,"%d%*[^\n]", &id2);

        if(id == id2) {
            cnt2++;
            break;

        } else {
            cnt++;
            cnt2++;
        }

    }


    fclose(file);

    if(cnt == cnt2) {
        printf("Ovaj ID ne postoji!");
        return;
    }


    char str[100];

    FILE *file2;
    int isDoneLine = cnt + 1;
    int line = 0;

    file = fopen("todo.txt", "r");

    rewind(file);

    file2 = fopen("todo2.txt", "w");

    // toggle
    while(fgets(str, 99, file) != NULL) {

        line++;

        if(line != isDoneLine) {
            fputs(str, file2);
        } else {
            char newString[30];
            int j=0, i;
            int thirdWord = 0;

            for(i=0; i <= (strlen(str)); i++) {
                if(str[i]==' '||str[i]=='\0') {
                    newString[j]='\0';
                    j=0;
                    thirdWord++;

                    if(thirdWord == 3) {
                        if(strcmp(newString, "true") == 0) {
                            strcpy(newString, "false");
                        } else {
                            strcpy(newString, "true");
                        }
                    }

                    printf("%s ", newString);

                    fprintf(file2,"%s ", newString);

                    strcpy(newString,"");





                } else {
                    newString[j]=str[i];
                    j++;
                }

            }


        }
    }

    fclose(file);
    fclose(file2);

    remove("todo.txt");
    rename("todo2.txt", "todo.txt");

}












