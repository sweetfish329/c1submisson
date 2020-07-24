#include <stdio.h>
#include <time.h>
#include<string.h>
#include "game.h"

// 遅延関数
int sleep(unsigned long x)
{
    clock_t s = clock();
    clock_t c;

    do
    {
        if ((c = clock()) == (clock_t)-1)
            return (0);
    } while (1000UL * (c - s) / CLOCKS_PER_SEC <= x);
    return (1);
}

//ターミナル上に線の出力
void line(char x, int i)
{
    int j;
    for (j = 0; j < i; j++)
    {
        putchar(x);
    }
    putchar('\n');
    return;
}

//y/n,helpの入力とエラー及びhelpの表示
void choose(int *c)
{
    while (1)
    {
        scanf("%d", c);
        printf("\x1b[49m"); 
        printf("\x1b[39m");
        if (*c == 0 || *c == 1)
        {
            // printf("===%d===\n", *c);
            return;
        }
        else if (*c == 3)
        {
            printf("\x1b[49m"); 
            printf("\x1b[39m");
            line('=',40);
            printf("            |b:     |b:\n            |黙秘   |自白\n");
            line('-',40);
            printf("a:          |a-2    |a-10\n黙秘        |b-2    |b-0\n");
            line('-',40);
            printf("a:          |a-0    |a-5\n黙秘        |b-10   |b-5\n");
            line('=',40);
            printf("\x1b[40m");
            printf("\x1b[30m");
        }
        else
        {
            printf("ERROR. 再入力");
            rewind(stdin);
        }
    }
}



//選択を判別してHPに反映
void judge(situation *x)
{
    char w1[10],w2[10];
    if(x->player1.log[x->count]==0){
        strcpy(w1,"黙秘");
    }else{
        strcpy(w1,"自白");
    }
    if(x->player2.log[x->count]==0){
        strcpy(w2,"黙秘");
    }else{
        strcpy(w2,"自白");
    }    
    printf("%sは%sを選択、%sは%sを選択！\n",x->player1.name,w1,x->player2.name,w2);
    // printf("1 is %d\n", x->player1.log[x->count]);
    // printf("2 is %d\n", x->player2.log[x->count]);
    sleep(600);
    if (x->player1.log[x->count] == 0)
    {
        if (x->player2.log[x->count] == 0)
        {
            x->player1.hpleft -= 2;
            x->player2.hpleft -= 2;
        }
        else
        {
            x->player1.hpleft -= 10;
        }
    }
    else
    {
        if (x->player2.log[x->count] == 0)
        {
            x->player2.hpleft -= 10;
        }
        else
        {
            x->player1.hpleft -= 5;
            x->player2.hpleft -= 5;
        }
    }

    x->count++;
    // printf("%d",x->count);
    return;
}

// HPの状態の表示
void result(situation *x)
{
    putchar('\n');
    sleep(200);
    printf("%sのHPは%d\n", x->player1.name, x->player1.hpleft);
    printf("\x1b[35m");
    line('=', x->player1.hpleft);
    printf("\x1b[39m");
    putchar('\n');
    sleep(200);
    printf("%sのHPは%d\n", x->player2.name, x->player2.hpleft);
    printf("\x1b[35m");
    line('=', x->player2.hpleft);
    printf("\x1b[39m"); 
    putchar('\n');
    sleep(800);
    return;
}

// 協調及び自白の決断
void decision(status *x,int count) {
        printf("%sのターン\n", x->name);
        printf("どちらの択を取りますか？\n");
        printf("0.黙秘\t1.自白\t3.HELP\n");
        printf("\x1b[40m");
        printf("\x1b[30m");
        choose(&x->log[count]);
        printf("\x1b[49m"); 
        printf("\x1b[39m");

}

void bluff(int x){
    if(x==40){
        printf("パーフェクト！\n");
    }else if(x<40&&x>29){
        printf("なかなかによき。\n");
    }else if(x<30&&x>20){
        printf("及第点…ですかねぇ…。\n");
    }
    else if(x<21){
        printf("まぁまぁじゃないですか。\n");
    }else if(x<11){
        printf("危なかったね。次はもう少し余裕持っていこう。");
    }
}
//format char array ->strcpy()
// void chclean(char *x)
// {
//     int size, i;
//     size = sizeof(x) / sizeof(char);
//     for (i = 0; i < size; i++)
//     {
//         x[i] = "";
//     }
//     return;
// }