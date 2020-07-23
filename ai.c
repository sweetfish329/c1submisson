#include <stdio.h>
#include <time.h>
#include<string.h>
#include <stdlib.h>
#include "game.h"
#include "ai.h"

void select(int x, situation *y)
{
    if (strcmp((*y).player2.name, "AI") == 0)
    {
        switch (x)
        {
        case 0:tft(y);break;
        case 1:rtft(y);break;
        case 2:tftt(y);break;
        case 3:friedman(y);break;
        case 4:joss(y);break;
        case 5:davis(y);break;
        case 6:random(y);break;
        case 7:alld(y);break;
        case 8:allc(y);break;
        default:
            break;
        }
    }
    else{ }
}

// しっぺ返し　初回協調
void tft(situation *y)
{
    strcpy((*y).player2.log[(*y).count],(*y).player1.log[(*y).count-1]);
    return;
}

// 逆しっぺ返し 初回裏切り
void rtft(situation *y){
    if((*y).count==0){
        (*y).player2.log[(*y).count]=1;
    }else{
        tft(y);
    }
}

// 堪忍袋戦略   初回協調 2連裏切りでしっぺ返し
void tftt(situation *y){
    if((*y).count==0){
        (*y).player2.log[(*y).count]=0;
    }else{
        if(){

        }
    }
}

// フリードマン戦略 初回協調   相手が一回でも裏切りを選んだら最後まで報復
void friedman(situation *y){
    if((*y).count==0){
        (*y).player2.log[(*y).count]=0;
    }
    if((*y).player1.log[(*y).count]==1){

    }
}
// ヨッス戦略　初回協調　以降前回相手が裏切れば裏切り、協調したら9割で協調
void joss(situation *y){

}
// テュロック戦略   10回まで協調    以降相手が初手10回中に選んだ協調の頻度より10%低く協調。
void tullock(situation *y){
    if((*y).count<=10){
        (*y).player2.log[(*y).count]=0;
    }else{

    }

}

// デービス戦略　10回まで協調　10回までに相手が1度でも裏切れば裏切り続ける。
void davis(situation *y){
        if((*y).count<=10){
        (*y).player2.log[(*y).count]=0;
    }else{
        int i;
        for(i=0;i<10;i++){
            if((*y).player1.log==1){
                (*y).player2.log[(*y).count]=1;
            }
        }
    }    
}

// でたらめ戦略
void random(situation *y){
    srand((unsigned int)time(NULL));
    (*y).player2.log[(*y).count]=rand()%2;
}
// 悪人戦略
void alld(situation *y){
    (*y).player2.log[(*y).count]=1;
}
// 善人戦略
void allc(situation *y){
    (*y).player2.log[(*y).count]=0;
}