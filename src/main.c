#include "../include/main.h"

int main(void)
{
    // Create random seed from computer time
    srand(time(NULL));

    // Sets locale for printing unicode chars/strings
    setlocale(LC_ALL, "");

    // Applies predefined ncurses attributes
    startcurses();

    // Create 52 unique cards and a placholder
    card cardobjs[52];
    initcards(cardobjs);

    // Randomize card arrangement
    shufflecards(cardobjs);

    // Initialize array of type Array with the discard, foundation, and tableau
    Array * board = (Array *) malloc(12 * sizeof(Array));
    initarray(board, cardobjs);
    debugarray(board);
    refresh();

    getinput();

    // Free pointers and end ncurses window
    endwin();
    freearray(board);

    return 0;
}

void debugarray(Array * a)
{
    for(int i = DS; i <= T7; i++)
    {
        int n = 0;
        for(int j = 0; j < a[i].used; j++)
        {
            mvprintw(i, n + 0, "%i", a[i].array[j]->s); // Suit val
#ifndef _MSVC_TRADITIONAL
            mvprintw(i, n + 1, "%s", suit_ch[a[i].array[j]->s]); // Suit symbol
#else
            mvaddwstr(i, n + 1, suit_ch[a[i].array[j]->s]); // Suit symbol
#endif
            mvprintw(i, n + 2, "%x", a[i].array[j]->v); // Number val
            mvprintw(i, n + 3, "%i", a[i].array[j]->r); // Reveal state
            mvprintw(i, n + 4, "%i|", Card_color(a[i].array[j])); // Card color
            n += 6;
        }
        printw("\n");
    }
}

void freearray(Array * a)
{
    for(int i = DS; i <= T7; i++)
    {
        Array_deallocate(&a[i]);
    }
    free(a);
}

char getinput()
{
    char input;
    do
    {
        input = getch();
    } while(input == ERR);

    return input;
}

void initarray(Array * a, card * deck)
{
    int count = 0;

    for(int i = DS; i <= T7; i++)
    {
        Array_init(&a[i], 1);
    }

    for(int i = T1; i <= T7; i++)
    {
        for(int j = 0; j <= i - T1; j++)
        {
            Array_append(&a[i], &deck[count++]);
        }
        Card_reveal(Array_last(&a[i]));
    }

    while(count < 52)
    {
        Array_append(&a[DS], &deck[count++]);
    }
}

void initcards(card * deck)
{
    for(int s = Spade, i = 0; s <= Heart; s++)
    {
        for(int v = Ace; v <= King; v++, i++)
        {
            Card_init(&deck[i], false, s, v);
        }
    }
}

void shufflecards(card * deck)
{
    for(int i = 0; i < 52; i++)
    {
        int rand_1 = rand() % 52;
        int rand_2 = rand() % 52;

        card temp = deck[rand_1];
        deck[rand_1] = deck[rand_2];
        deck[rand_2] = temp;
    }
}

void startcurses(void)
{
    // Initialize curses terminal attributes
    initscr();
    if(has_colors() == FALSE)
    {    
        endwin();
        printf("Your terminal doesn't support color!");
        exit(1);
    }
    start_color();
    
    // Initializes color pairs
    init_pair(1, COLOR_WHITE, COLOR_BLACK); // Default white text on black background

    // Apply default color mode and apply ncurses window attributes
    attron(COLOR_PAIR(1));
    raw();
    keypad(stdscr, true);
    noecho();
    halfdelay(1);
}
