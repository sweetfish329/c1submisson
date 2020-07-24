#include<stdio.h>
#include<time.h>
#include<string.h>


void arrainput(int *t){
    *t=4;
    return;
}

int main (){
    int t=3;
    arrainput(&t);
    printf("%d",t);
}