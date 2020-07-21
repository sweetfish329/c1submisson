#ifndef GAME_H //二重でincludeされることを防ぐ
#define GAME_H

typedef struct status{
    char name[20];
    int choice;
    int hpleft;
}status;

typedef struct situation{
    status player1;
    status player2;
    int count;
}situation;


void choose(int *c);
void judge(situation* x);
void line(char x);
int sleep(unsigned long x);
void chclean(char* x);

#endif