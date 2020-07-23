#ifndef AI_H //二重でincludeされることを防ぐ
#define AI_H

void select(int x, situation *y);

void tft(situation *y);
void rtft(situation *y);
void tftt(situation *y);
void friedman(situation *y);
void joss(situation *y);
void tullock(situation *y);
void davis(situation *y);
void random(situation *y);
void alld(situation *y);
void allc(situation *y);

#endif