#include "board.h"
#include "draw.h"
#include "draw_board.h"
#include "board_read.h"
int main()
{
    char deck[8][8];
    board_print(deck);
    while (1) {
        printDeck(deck);
        check(deck, 0);
    }
    return 0;
}
