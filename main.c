#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main()
{
    int choice;
    int toggle;

    Menu();
    scanf("%d", &choice);

    if(choice == 1) {
        add();
    } else if(choice == 2) {
        rm();
    } else if(choice == 3) {
        printf("Unesite ID: ");
        scanf("%d", &toggle);
        toggleTodo(toggle);
    } else {
        printf("Pick 1, 2 or 3 next time!");
    }

    return 0;
}
