#include <stdio.h>
#include <time.h>
#include <string.h>

#include "game.h"

#define HP 40

int main()
{
    //変数及び構造体の宣言
    int i, o;
    char w2[20];
    struct situation situation = {
        player1 : {hpleft : HP},
        player2 : {hpleft : HP},
        count : 0,
        aimode : 0
    };

    // 囚人のジレンマの紹介
    printf("The game is based on a game in game theory called Prisoner's Dilemma.\n");
    printf("Do you want to know about more information about Prisoner's Dilemma?\n");
    printf("0.yes 1.no\n");

    // 対人/対AI
    printf("choose gamemode\n");
    printf("0.vsPlayer\t1.vsAI \n");

    // AIのアルゴリズムの選択
    choose(&i);
    if (i == 0)
    {
        strcpy(situation.player2.name, "AI");
        printf("Do you want to choose AI's move?\n0.yes 1.no");
        choose(&o);
        if (o == 1)
        {
            // show options and scanf it.
        }else{
            srand((unsigned int)time(NULL));
            situation.aimode=rand()%9;
        }
    }

    // プレイヤー名の入力
    printf("Input Player1's username.\n");
    scanf("%s", w2);
    strcpy(situation.player1.name, w2);
    printf("Input Player2's username.\n");
    rewind(stdin);
    strcpy(w2, "");
    scanf("%s", w2);
    strcpy(situation.player2.name, w2);

    // ゲーム本編ループ HPが0で終了
    do
    {
        result(&situation);

        // 協調及び裏切りの選択
        decision(&situation.player1,situation.count);
        decision(&situation.player2,situation.count);

        // 入力内容をもとにHPに反映
        judge(&situation);

    } while (situation.player1.hpleft > 0 && situation.player2.hpleft > 0);

    // 勝者の出力
    // printf("%s WIN!");
}
