#include "board.h"
#include "board_read.h"
#include "draw.h"
#include "draw_board.h"
int main()
{
    char deck[8][8];
    draw(deck);
    while (1) {
        printDeck(deck);
        check(deck, 0);
    }
    return 0;
}
