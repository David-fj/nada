#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "coisas.h"

void imprimirSecao(char* secao){
    FILE * f = fopen("C:/Users/Diego/Desktop/nada/historia.txt", "r");
    if(f == NULL){
        printf("historia.txt, not find\n");
        exit(1);
    }

    char linha[100];
    int exibir = 0;
    char choice = '0';

    while(fgets(linha, 100, f) != NULL){
        
        if(exibir){
            if(linha[0] == '@'){
                printf("Faca a sua escolha: ");
                scanf(" %c", &choice);
                break;
            }
            printf("%s", linha);
        }
        
        if(strcmp(linha, secao) == 0)
            exibir = 1;
        
    }

    if(choice == '0')
        strcpy(secao, fgets(linha, 100, f));
    else{
        char c[2] = "0\0", nextSection[30];
        while(c[0] != choice){
            fscanf(f, "%s %s", c, nextSection);
        }
        int len = strlen(nextSection);
        nextSection[len] = '\n';
        nextSection[len+1] = '\0';
        strcpy(secao, nextSection);
    }

    fclose(f);
}

void save(PLAYER * p){
    FILE * f = fopen("C:/Users/Diego/Desktop/nada/save.txt", "w");
    if(f == NULL){
        printf("save.txt, not find\n");
        exit(1);
    }
    
    fprintf(f, "%s %d %d %d %d %d %d %d", p->name, p->hp, p->ep, p->dm, p->ca, p->lk, p->lv, p->lv);

    fclose(f);
}