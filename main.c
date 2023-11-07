#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coisas.h"

int main() {
    char secaoAtual[30] = "Start\n";
    PLAYER * p = (PLAYER *)malloc(sizeof(PLAYER));
    strcpy(p->name, "David");
    p->hp = 10;
    p->ep = 10;
    p->dm = 10;
    p->ca = 10;
    p->lk = 10;
    p->lv = 10;
    p->xp = 10;

    while(1){
        imprimirSecao(secaoAtual);
    }

    save(p);
    return 1;
}