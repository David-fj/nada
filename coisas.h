#ifndef COISAS_H_INCLUDED
#define COISAS_H_INCLUDED

typedef struct {
    char name[30];
    int constituicao;
    int sentidos;
    int intelecto;
    int hp;
    int ep;
    int dm;
    int ca;
    int lk;
    int lv;
    int xp;
}PLAYER;

void imprimirSecao(char* secao);

void save(PLAYER * p);

void classSelect(PLAYER * p);

#endif
