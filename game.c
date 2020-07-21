#include <stdio.h>
#include <time.h>
#include "game.h"


// sleep func without windows.h
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


//print line
void line(char x)
{
    int i;
    for (i = 0; i < 40; i++)
    {
        putchar(x);
    }
    putchar('\n');
    return;
}

// scan y or n as 0 or 1, return err and show help 
void choose(int *c)
{
    while (1)
    {
        scanf("%d", c);
        if (*c == 0 || *c == 1)
        {
            printf("===%d===\n", *c);
            return;
        }
        else if (*c == 3)
        {
            printf("======================================\n            |b:     |b:\n            |silemt |confession\n----------------------------------\na:          |a-2    |a-10\nsilent      |b-2    |b-0\n-----------------------------------\na:          |a-0    |a-5\nconfession  |b-10   |b-5\n========================================\n");
        }
        else
        {
            printf("ERROR. Input again.");
            rewind(stdin);
        }
    }
}

//decreace hp 
void judge(situation *x)
{
    printf("1 is %d\n", (*x).player1.choice);
    printf("2 is %d\n", (*x).player2.choice);
    if ((*x).player1.choice == 0)
    {
        if ((*x).player2.choice == 0)
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
        if ((*x).player2.choice == 0)
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
    return;
}


//format char array
void chclean(char *x)
{
    int size, i;
    size = sizeof(x) / sizeof(char);
    for (i = 0; i < size; i++)
    {
        x[i] = "";
    }
    return;
}