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
    int  o;
    situation sit = {
        player1 : {hpleft : HP},
        player2 : {hpleft : HP},
        count : 0,
        aimode : 0
    };

    // 囚人のジレンマの紹介
    printf("これは囚人のジレンマというものを参考にしたゲームです。\n");
    sleep(200);
    printf("囚人のジレンマについてさらに知りたい方はWikipediaを参照してください。\n");
    sleep(800);
    putchar('\n');
    printf("これは2人の囚人が協調するか、裏切るかを選択するゲームです。\n");
    sleep(800);
    printf("今回はその影響がわかりやすいようにHP形式にしてみました！\n");
    sleep(200);
    printf("それぞれの行動と結果を表にしました。\n");
    sleep(1000);
        line('=',40);
        printf("            |b:     |b:\n            |黙秘   |自白\n");
        line('-',40);
        printf("a:          |a-2    |a-10\n黙秘        |b-2    |b-0\n");
        line('-',40);
        printf("a:          |a-0    |a-5\n黙秘        |b-10   |b-5\n");
        line('=',40);
    sleep(1200);
    printf("相手を一方的に裏切れば相手を出し抜けますが、裏切り合うと二人で黙秘するより大きなダメージを受けてしまいます。\n");
    sleep(200);
    printf("できるだけ多くHPを残したほうの勝ちです。頑張って！\n");
    sleep(1000);
    putchar('\n');
    line('=',70);
    // 対人/対AI
    printf("ゲームモードを選択してください。\n");
    printf("0.プレイヤーと対戦\t1.AIと対戦 \n");

    // AIのアルゴリズムの選択
    choose(&sit.aimode);
    if (sit.aimode == 1)
    {
        strcpy(sit.player2.name, "AI");
        printf("AIのアルゴリズムを決めますか?\n0.yes 1.no\n");
        choose(&o);
        if (o == 0)
        {
            printf("1.しっぺ返し戦略\t2.逆しっぺ返し戦略\t3.堪忍袋戦略\t4.フリードマン戦略\n5.ヨッス戦略\t6.デービス戦略\t7.でたらめ戦略\t8.悪人戦略\t.9.善人戦略\n");
            scanf("%d",&sit.aimode);
            // show options and scanf it.
        }else{
            srand((unsigned int)time(NULL));
            sit.aimode=rand()%8+1;
        }
    }

    // プレイヤー名の入力
    printf("Player1の名前を入力。\n");
    scanf("%s", sit.player1.name);
    if(sit.aimode==0){
        printf("Player2の名前を入力。\n");
        rewind(stdin);
        scanf("%s", sit.player2.name);
    }

    // 

    // ゲーム本編ループ HPが0で終了
    // printf("\x1b[40m");
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
    if(sit.player2.hpleft<=0){
    printf("%s WIN!\n",sit.player1.name);
    bluff(sit.player2.hpleft);
    }else if(sit.player1.hpleft<=0&&sit.player2.hpleft<=0){
        printf("引き分け！\n");
    }
    else{
        if(sit.aimode==0){
            printf("%s WIN\n",sit.player2.name);
            bluff(sit.player2.hpleft);
        }else{
            printf("AIの勝ち。なんで負けたか、考えといてください。\n");
        }
    }
}
