#ifndef BOARD_H
#define BOARD_H

void check(char deck[8][8], int test);
void make_move(char deck[8][8], int move[]);
int pawn(char deck[8][8], int move[4]);
int PAWN(char deck[8][8], int move[4]);
int input_check(char str[4]);
int check_figure(char deck[8][8], int move[4]);

#endif
