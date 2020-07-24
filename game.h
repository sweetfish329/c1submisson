#ifndef GAME_H 
#define GAME_H

#define NAMESIZE 20
#define LOGSIZE 20

typedef struct {
    char name[NAMESIZE];
    int hpleft;
    int log[LOGSIZE];
}status;

typedef struct {
    status player1;
    status player2;
    int count;
    int aimode;
}situation;


void choose(int *c);
void judge(situation* x);
void line(char x,int i);
int sleep(unsigned long x);
void result(situation *x);
void decision(status *x,int count);
void bluff(int x);
// void chclean(char* x);

#endif