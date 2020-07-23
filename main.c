#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#include "game.h"
#include "ai.h"

#define HP 40

int main()
{
    //変数及び構造体の宣言
    int i, o;
    char w2[20];
    situation sit = {
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
    sit.aimode=i;
    if (i == 1)
    {
        strcpy(sit.player2.name, "AI");
        printf("Do you want to choose AI's move?\n0.yes 1.no");
        choose(&o);
        if (o == 1)
        {
            scanf("%d",&sit.aimode);
            // show options and scanf it.
        }else{
            srand((unsigned int)time(NULL));
            sit.aimode=rand()%8+1;
        }
    }

    // プレイヤー名の入力
    printf("Input Player1's username.\n");
    scanf("%s", w2);
    strcpy(sit.player1.name, w2);
    if(sit.aimode==0){
        printf("Input Player2's username.\n");
        rewind(stdin);
        strcpy(w2, "");
        scanf("%s", w2);
        strcpy(sit.player2.name, w2);
    }
    // ゲーム本編ループ HPが0で終了
    do
    {
        result(&sit);

        // 協調及び裏切りの選択
        decision(&sit.player1,sit.count);

        // AI
        if(sit.aimode==0){
        decision(&sit.player2,sit.count);
        }else{
            sel(sit.aimode,&sit);
        }
        // 入力内容をもとにHPに反映
        judge(&sit);

    } while (sit.player1.hpleft > 0 && sit.player2.hpleft > 0);

    // 勝者の出力
    result(&sit);
    // printf("%s WIN!");
}
