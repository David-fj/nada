#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coisas.h"

int main() {

    PLAYER * p = (PLAYER *)malloc(sizeof(PLAYER));
    switch (menu()){
        //case 1:
        case 2:
            printf("Como se chama? ");
            scanf("%s", p->name);
            classSelect(p);
        //case 3:
    }
    getc(stdin);
    getc(stdin);
    return 1;
}