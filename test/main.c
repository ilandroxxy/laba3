#define CTEST_MAIN
#include <board.h>
#include <draw.h>
#include <draw_board.h>
#include <board_read.h>
#include <ctest.h>

char deck[8][8];

CTEST(Syntax, Correct)
{
    int result = input_check("a2a8");
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(Syntax, Incorrect)
{
    int result = input_check("a2a9");
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}
CTEST(Pawn, Correct)
{
    draw(deck);
    char move[4] = "a2a4";
    int moveint[4];
    input(move, moveint);
    int result = pawn(deck, moveint);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(Pawn, Incorrect)
{
    draw(deck);
    char move[4] = "a2a5";
    int moveint[4];
    input(move, moveint);
    int result = pawn(deck, moveint);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(Check_Figure, Correct)
{
    draw(deck);
    char move[4] = "a2a5";
    int moveint[4];
    input(move, moveint);
    int result = check_figure(deck, moveint);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}
CTEST(Check_Figure, Incorrect)
{
    draw(deck);
    char move[4] = "a5a6";
    int moveint[4];
    input(move, moveint);
    int result = check_figure(deck, moveint);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}
CTEST(PAWN, Correct)
{
    draw(deck);
    char move[4] = "a7a5";
    int moveint[4];
    input(move, moveint);
    int result = PAWN(deck, moveint);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(PAWN, Incorrect)
{
    draw(deck);
    char move[4] = "a7a3";
    int moveint[4];
    input(move, moveint);
    int result = PAWN(deck, moveint);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}
int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}
