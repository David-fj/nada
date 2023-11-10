#ifndef COISAS_H_INCLUDED
#define COISAS_H_INCLUDED

typedef struct {
    int hp_base;
    int ep_base;
    int dm_base;
    int ca_base;
    int lk_base;
    int xp_base;
}STATUS;

typedef struct {
    char name[30];
    int constituicao;
    int sentidos;
    int intelecto;
    STATUS base;
    int hp;
    int ep;
    int dm;
    int ca;
    int lk;
    int lv;
    int xp;
    int xp_prox;
}PLAYER;

int menu();

void imprimirSecao(char* secao);

void save(PLAYER * p);

void attStatus(PLAYER * p);

void classSelect(PLAYER * p);

#endif
