#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "coisas.h"

// MENU

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

// HISTORIA

void imprimirSecao(char* secao){
    FILE * f = fopen("historia.txt", "r");
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

// PLAYER

void save(PLAYER * p){
    FILE * f = fopen("save.txt", "w");
    if(f == NULL){
        printf("save.txt, not find\n");
        exit(1);
    }
    
    fprintf(f, "%s %d %d %d %d %d %d %d", p->name, p->hp, p->ep, p->dm, p->ca, p->lk, p->lv, p->lv);

    fclose(f);
}

void attStatus(PLAYER * p){
    p->hp = p->base.hp_base + (p->constituicao * 40) + (p->lv * 2);
    p->ep = p->base.ep_base + (p->intelecto * 100) + (p->constituicao * 10) + (p->sentidos * 15);
    p->dm = p->base.dm_base + (p->constituicao * 25) + (p->sentidos * 35);
    p->ca = p->base.ca_base + (p->constituicao * 25) + (p->sentidos * 20);
    p->lk = p->base.lk_base + (p->sentidos * 35) + p->lv;
}

void classSelect(PLAYER * p){
    printf("Ola %s, selecione a sua classe.\n", p->name);
    FILE * f = fopen("classes.txt", "r");
    
    char linha[100];
    int exibir = 1;
    char class;

    while(fgets(linha, 100, f) != NULL){

        if(linha[0] == '@'){
            exibir = 0;
            scanf(" %c", &class);
        }

        if(exibir)
            printf("%s", linha);
        else {

            if(linha[0] == '#' && class == '1'){
                fscanf(f, "%d %d %d %d %d %d %d %d %d %d", &p->constituicao, &p->sentidos, &p->intelecto, &p->base.hp_base, &p->base.ep_base, &p->base.dm_base, &p->base.ca_base, &p->base.lk_base, &p->lv, &p->xp);
                p->xp_prox = 10;
                break;
            }
            else if(linha[0] && class != '1'){
                exibir = 1;
                rewind(f);
            }

            if(linha[0] == class)
                exibir = 1;
        }

    }

    fclose(f);
}