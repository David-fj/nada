#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coisas.h"

int menu(){
    int choice;
    while(choice < 1 && choice > 3){
        system("cls");
        printf("----------------\n");
        printf("1-CARREGAR\n");
        printf("2-NOVO JOGO\n");
        printf("3-SAIR\n");
        printf("----------------\n");
        scanf("%d", &choice);
    }
    return choice;
}

int main() {

    switch (menu()){
        case 1:
        case 2:
            PLAYER * p = (PLAYER *)malloc(sizeof(PLAYER));
            printf("Como se chama? ");
            scanf("%s", p->name);
            classSelect(p);
        case 3:
    }
    
    return 1;
}