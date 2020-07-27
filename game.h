#ifndef GAME_H 
#define GAME_H

#define NAMESIZE 20
#define LOGSIZE 20

// array size
#define NAMESIZE 20
#define LOGSIZE 20
// sleep time default
#define SLPDEF 200
// color
#define BLANK 0
#define SETBLANK colorselect(BLANK)
#define RED 1
#define SETRED colorselect(RED)
#define HIDE 2
#define SETHIDE colorselect(HIDE)

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

int colmode;

void choose(int *c);
void judge(situation* x);
void line(char x,int i);
int sleep(unsigned long x);
void result(situation *x);
void decision(status *x,int count);
void bluff(int x);
void colorselect(int x);

// void chclean(char* x);

#endif