#include "draw_board.h"
#include "board.h"
#include "board_read.h"
#include "draw.h"
#include <stdio.h>
void printDeck(char deck[8][8])
{
    for (int n = 1; n < 9; ++n) {
        printf("%d", n);
        printf("|");
        for (int s = 1; s < 9; ++s) {
            printf("%c|", deck[n][s]);
        }
        printf("\n");
    }
    printf(" +---------------+\n");
    printf("  a b c d e f g h");
    printf("\n\n");
}
