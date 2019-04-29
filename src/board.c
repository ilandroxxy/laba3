#include "board.h"
#include "board_read.h"
#include "draw.h"
#include "draw_board.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
void make_move(char deck[8][8], int move[])
{
    deck[move[3]][move[2]] = deck[move[1]][move[0]];
    deck[move[1]][move[0]] = ' ';
}
int pawn(char deck[8][8], int move[4])
{
    if ((deck[move[3]][move[2]] == ' ') && (deck[move[1]][move[0]] == 'p')
        && (move[0] == move[2])
        && (((move[3] - move[1]) == 1) || ((move[3] - move[1]) == 2)))
        return 0;
    else
        return 1;
}
int PAWN(char deck[8][8], int move[4])
{
    if ((deck[move[3]][move[2]] == ' ') && (deck[move[1]][move[0]] == 'P')
        && (move[0] == move[2])
        && (((move[1] - move[3]) == 1) || ((move[1] - move[3]) == 2)))
        return 0;
    else
        return 1;
}
int input_check(char str[4])
{
    if (str[0] < 'a' || str[0] > 'h' || str[1] < '1' || str[1] > '8'
        || str[2] < 'a' || str[2] > 'h' || str[3] < '1' || str[3] > '8')
        return 1;
    else
        return 0;
}
int check_figure(char deck[8][8], int move[4])
{
    if ((deck[move[1]][move[0]] == 'p') || (deck[move[1]][move[0]] == 'P')
        || (deck[move[1]][move[0]] == 'q') || (deck[move[1]][move[0]] == 'Q')
        || (deck[move[1]][move[0]] == 'r') || (deck[move[1]][move[0]] == 'R')
        || (deck[move[1]][move[0]] == 'N') || (deck[move[1]][move[0]] == 'n')
        || (deck[move[1]][move[0]] == 'B') || (deck[move[1]][move[0]] == 'b')
        || (deck[move[1]][move[0]] == 'K') || (deck[move[1]][move[0]] == 'k'))
        return 0;
    else
        return 1;
}
void check(char deck[8][8], int test)
{
    char move[5];
    int moveint[4];
    int Counter = 0, tmp1, tmp2;
    if (test == 0) {
        scanf("%s", move);
        input(move, moveint);
    }
    if ((deck[moveint[3]][moveint[2]] == ' ') && (!input_check(move))) {
        if ((deck[moveint[1]][moveint[0]] == 'p') && (!pawn(deck, moveint))) {
            make_move(deck, moveint);
        }
        if ((deck[moveint[1]][moveint[0]] == 'P') && (!PAWN(deck, moveint))) {
            make_move(deck, moveint);
        }

        if (((deck[moveint[1]][moveint[0]] == 'q')
             || (deck[moveint[1]][moveint[0]] == 'Q'))
            && ((move[0] == move[2]) || (move[1] == move[3])
                || (abs(move[0] - move[2]) == abs(move[1] - move[3])))) {
            if (move[0] == move[2])
                for (tmp1 = moveint[1] + 1; tmp1 < moveint[3]; tmp1++) {
                    if (deck[tmp1][moveint[0]] != ' ') {
                        if (abs(deck[moveint[1]][moveint[0]]
                                - deck[tmp1][moveint[0]])
                            > 17)
                            deck[tmp1][moveint[0]] = ' ';
                        else
                            Counter = 1;
                    }
                }
            else if (move[1] == move[3])
                for (tmp2 = moveint[0] + 1; tmp2 < moveint[2]; tmp2++) {
                    if (deck[moveint[1]][tmp2] != ' ') {
                        if (abs(deck[moveint[1]][moveint[0]]
                                - deck[moveint[1]][tmp2])
                            > 17)
                            deck[moveint[1]][tmp2] = ' ';
                        else
                            Counter = 1;
                    }
                }
            if (abs(move[0] - move[2]) == abs(move[1] - move[3])) {
                for (tmp1 = moveint[1] + 1, tmp2 = moveint[0] + 1;
                     tmp1 < moveint[3];
                     tmp1++, tmp2++) {
                    if (deck[tmp1][tmp2] != ' ') {
                        if (abs(deck[moveint[1]][moveint[0]] - deck[tmp1][tmp2])
                            > 17)
                            deck[tmp1][tmp2] = ' ';
                        else
                            Counter = 1;
                    }
                }
            }
            if (Counter < 1 || Counter > 1) {
                if (deck[moveint[1]][moveint[0]] == 'Q') {
                    make_move(deck, moveint);
                }
                if (deck[moveint[1]][moveint[0]] == 'q') {
                    make_move(deck, moveint);
                }
                Counter = 0;
            }
        }

        if (((deck[moveint[1]][moveint[0]] == 'B')
             || (deck[moveint[1]][moveint[0]] == 'b'))
            && (abs(move[0] - move[2]) == abs(move[1] - move[3]))) {
            for (tmp1 = moveint[1] + 1, tmp2 = moveint[0] + 1;
                 tmp1 < moveint[3];
                 tmp1++, tmp2++) {
                if (deck[tmp1][tmp2] != ' ') {
                    if (abs(deck[moveint[1]][moveint[0]] - deck[tmp1][tmp2])
                        > 17)
                        deck[tmp1][tmp2] = ' ';
                    else
                        Counter = 1;
                }
            }

            if (Counter < 1 || Counter > 1) {
                if (deck[moveint[1]][moveint[0]] == 'B') {
                    make_move(deck, moveint);
                }
                if (deck[moveint[1]][moveint[0]] == 'b') {
                    make_move(deck, moveint);
                }
                Counter = 0;
            }
        }

        if (((deck[moveint[1]][moveint[0]] == 'R')
             || (deck[moveint[1]][moveint[0]] == 'r'))
            && ((move[0] == move[2]) || (move[1] == move[3]))) {
            if (move[0] == move[2])
                for (tmp1 = moveint[1] + 1; tmp1 < moveint[3]; tmp1++) {
                    if (deck[tmp1][moveint[0]] != ' ') {
                        if (abs(deck[moveint[1]][moveint[0]]
                                - deck[tmp1][moveint[0]])
                            > 17)
                            deck[tmp1][moveint[0]] = ' ';
                        else
                            Counter = 1;
                    }
                }
            else if (move[1] == move[3])
                for (tmp2 = moveint[0] + 1; tmp2 < moveint[2]; tmp2++) {
                    if (deck[moveint[1]][tmp2] != ' ') {
                        if (abs(deck[moveint[1]][moveint[0]]
                                - deck[moveint[1]][tmp2])
                            > 17)
                            deck[moveint[1]][tmp2] = ' ';
                        else
                            Counter = 1;
                    }
                }
            if (Counter < 1 || Counter > 1) {
                if (deck[moveint[1]][moveint[0]] == 'R') {
                    make_move(deck, moveint);
                }
                if (deck[moveint[1]][moveint[0]] == 'r') {
                    make_move(deck, moveint);
                }
            }
            Counter = 0;
        }

        //Êîíü

        if (((deck[moveint[1]][moveint[0]] == 'N')
             || (deck[moveint[1]][moveint[0]] == 'n'))
            && (((abs(move[1] - move[3]) == 1) && (abs(move[0] - move[2]) == 2))
                || ((abs(move[1] - move[3]) == 2)
                    && (abs(move[0] - move[2]) == 1)))) {
            if (Counter < 1 || Counter > 1) {
                if (deck[moveint[1]][moveint[0]] == 'N') {
                    make_move(deck, moveint);
                }
                if (deck[moveint[1]][moveint[0]] == 'n') {
                    make_move(deck, moveint);
                }
            }
        }
        if ((deck[moveint[1]][moveint[0]] == 'k')
            && (((abs(move[3] - move[1]) == 1) || (abs(move[3] - move[1]) == 0))
                && ((abs(move[3] - move[1]) == 1)
                    || (abs(move[3] - move[1]) == 0)))) {
            make_move(deck, moveint);
        }
        if ((deck[moveint[1]][moveint[0]] == 'K')
            && (((abs(move[3] - move[1]) == 1) || (abs(move[3] - move[1]) == 0))
                && ((abs(move[3] - move[1]) == 1)
                    || (abs(move[3] - move[1]) == 0)))) {
            make_move(deck, moveint);
        }
    }
    //Êîðîëü
    else if (
            ((moveint[0]) > 0) && ((moveint[0]) < 10) && ((moveint[1]) > 0)
            && ((moveint[1]) < 10) && ((moveint[2]) > 0) && ((moveint[2]) < 10)
            && ((moveint[3]) > 0) && ((moveint[3]) < 10)) {
        if (deck[moveint[3]][moveint[2]] != ' ') {
            if (abs(deck[moveint[1]][moveint[0]] - deck[moveint[3]][moveint[2]])
                > 17)
                deck[moveint[3]][moveint[2]] = ' ';
            else
                Counter = 1;
        }
        if (Counter < 1 || Counter > 1) {
            if ((deck[moveint[1]][moveint[0]] == 'k')
                && (((abs(move[3] - move[1]) == 1)
                     || (abs(move[3] - move[1]) == 0))
                    && ((abs(move[3] - move[1]) == 1)
                        || (abs(move[3] - move[1]) == 0)))) {
                make_move(deck, moveint);
            }
            if ((deck[moveint[1]][moveint[0]] == 'K')
                && (((abs(move[3] - move[1]) == 1)
                     || (abs(move[3] - move[1]) == 0))
                    && ((abs(move[3] - move[1]) == 1)
                        || (abs(move[3] - move[1]) == 0)))) {
                make_move(deck, moveint);
            }
        }
        Counter = 0;

        //Êîíü
        if (((deck[moveint[1]][moveint[0]] == 'N')
             || (deck[moveint[1]][moveint[0]] == 'n'))
            && (((abs(move[1] - move[3]) == 1) && (abs(move[0] - move[2]) == 2))
                || ((abs(move[1] - move[3]) == 2)
                    && (abs(move[0] - move[2]) == 1)))) {
            if (deck[moveint[3]][moveint[2]] != ' ') {
                if (abs(deck[moveint[1]][moveint[0]]
                        - deck[moveint[3]][moveint[2]])
                    > 17)
                    deck[moveint[3]][moveint[2]] = ' ';
                else
                    Counter = 1;
            }
            if (Counter < 1 || Counter > 1) {
                if (deck[moveint[1]][moveint[0]] == 'N') {
                    make_move(deck, moveint);
                }
                if (deck[moveint[1]][moveint[0]] == 'n') {
                    make_move(deck, moveint);
                }
            }
        }
        Counter = 0;
        //Ïåøêà

        if ((((deck[moveint[1]][moveint[0]] == 'P') && (move[3] - move[1] == 1))
             || ((deck[moveint[1]][moveint[0]] == 'p')
                 && (move[1] - move[3] == 1)))
            && (abs(move[0] - move[2]))) {
            if (deck[moveint[3]][moveint[2]] != ' ') {
                if (abs(deck[moveint[1]][moveint[0]]
                        - deck[moveint[3]][moveint[2]])
                    > 17)
                    deck[moveint[3]][moveint[2]] = ' ';
                else
                    Counter = 1;
            }

            if (Counter < 1 || Counter > 1) {
                if (deck[moveint[1]][moveint[0]] == 'p') {
                    make_move(deck, moveint);
                }
                if (deck[moveint[1]][moveint[0]] == 'P') {
                    make_move(deck, moveint);
                }
                Counter = 0;
            }
        }
    }
}
