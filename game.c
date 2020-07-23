#include <stdio.h>
#include <time.h>
#include "game.h"

// 遅延関数
int sleep(unsigned long x)
{
    clock_t s = clock();
    clock_t c;

    do
    {
        if ((c = clock()) == (clock_t)-1) /* エラー */
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
        if (*c == 0 || *c == 1)
        {
            // printf("===%d===\n", *c);
            return;
        }
        else if (*c == 3)
        {
            line('=',40);
            printf("            |b:     |b:\n            |silemt |confession\n");
            line('-',40);
            printf("a:          |a-2    |a-10\nsilent      |b-2    |b-0\n");
            line('-',40);
            printf("a:          |a-0    |a-5\nconfession  |b-10   |b-5\n");
            line('=',40);
        }
        else
        {
            printf("ERROR. Input again.");
            rewind(stdin);
        }
    }
}

//選択を判別してHPに反映
void judge(situation *x)
{
    printf("1 is %d\n", (*x).player1.log[(*x).count]);
    printf("2 is %d\n", (*x).player2.log[(*x).count]);
    if ((*x).player1.log[(*x).count] == 0)
    {
        if ((*x).player2.log[(*x).count] == 0)
        {
            (*x).player1.hpleft -= 2;
            (*x).player2.hpleft -= 2;
        }
        else
        {
            (*x).player1.hpleft -= 10;
        }
    }
    else
    {
        if ((*x).player2.log[(*x).count] == 0)
        {
            (*x).player2.hpleft -= 10;
        }
        else
        {
            (*x).player1.hpleft -= 5;
            (*x).player2.hpleft -= 5;
        }
    }

    (*x).count++;
    // printf("%d",(*x).count);
    return;
}

// HPの状態の表示
void result(situation *x)
{
    printf("%s's left HP is %d\n", (*x).player1.name, (*x).player1.hpleft);
    line('=', (*x).player1.hpleft);
    putchar('\n');
    printf("%s's left HP is %d\n", (*x).player2.name, (*x).player2.hpleft);
    line('=', (*x).player2.hpleft);
    putchar('\n');
    return;
}

// 協調及び裏切りの決断
void decision(status *x,int count) {
        printf("%s's tern\n", (*x).name);
        printf("Which way you choose is?\n");
        printf("0.keep silent 1.confession\n");
        choose(&x->log[count]);
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