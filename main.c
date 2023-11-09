#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coisas.h"

int menu(){
    int choice = 0;
    while(choice < 1 || choice > 3){
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

    PLAYER * p = (PLAYER *)malloc(sizeof(PLAYER));
    switch (menu()){
        //case 1:
        case 2:
            printf("Como se chama? ");
            scanf("%s", p->name);
            classSelect(p);
            printf("%d %d %d\n", p->constituicao, p->sentidos, p->intelecto);
        //case 3:
    }
    getc(stdin);
    getc(stdin);
    return 1;
}