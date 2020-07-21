#include <stdio.h>
#include <time.h>
#include <string.h>

#include "game.h"

#define HP 20

int main()
{
    int i,o;
    char w2[20];
    struct situation situation = {
        player1:{choice : 0, hpleft : HP},
        player2:{choice : 0, hpleft : HP},
        count:1};
    
    printf("The game is based on a game in game theory called Prisoner's Dilemma.\n");
    printf("Do you want to know about more information about Prisoner's Dilemma?\n");
    printf("0.yes 1.no\n");
    // sleep(20000);

    printf("choose gamemode\n");
    printf("0.vsAI 1.vsPlayer \n");

    choose(&i);
    if (i == 0)
    {
        strcpy(situation.player2.name, "AI");
        printf("Do you want to choose AI's move?\n0.yes 1.no");
        choose(&o);
        if(o==0){
            // show options and scanf it.
        }
    }

    printf("Input Player1's username.\n");
    scanf("%s", w2);
    strcpy(situation.player1.name,w2);
    printf("Input Player2's username.\n");
    rewind(stdin);
    strcpy(w2,"");
    scanf("%s", w2);
    strcpy(situation.player2.name,w2);

    do
    {
        printf("%s's tern\n", situation.player1.name);
        printf("Which way you choose is?\n");
        printf("0.keep silent 1.confession\n");
        choose(&situation.player1.choice);

        printf("%s's tern\n", situation.player2.name);
        printf("Which way you choose is?\n");
        printf("0.keep silent 1.confession\n");
        if (strcmp(situation.player2.name, "AI") == 0)
        {
            strcpy(situation.player2.choice,situation.player1.choice);
        }
        choose(&situation.player2.choice);

        judge(&situation);

        printf("%s's left HP is %d\n", situation.player1.name, situation.player1.hpleft);
        printf("%s's left HP is %d\n", situation.player2.name, situation.player2.hpleft);

    } while (situation.player1.hpleft > 0 && situation.player2.hpleft > 0);
    // printf("%s WIN!");
    
}
