#include <termios.h>
#include <stdio.h>

#include "getch.h"

// Code from :
// https://stackoverflow.com/questions/7469139/what-is-the-equivalent-to-getch-getche-in-linux

static struct termios old, new;

/* Initialize new terminal i/o settings */
static void initTermios(int echo)
{
    tcgetattr(0, &old); //grab old terminal i/o settings
    new = old; //make new settings same as old settings
    new.c_lflag &= ~ICANON; //disable buffered i/o
    new.c_lflag &= echo ? ECHO : ~ECHO; //set echo mode
    tcsetattr(0, TCSANOW, &new); //apply terminal io settings
}

/* Restore old terminal i/o settings */
static void resetTermios(void)
{
    tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
static int getch_(int echo)
{
    int ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}

/* 
Read 1 character without echo 
getch() function definition.
*/
int getch(void)
{
    return getch_(0);
}

/* 
Read 1 character with echo 
getche() function definition.
*/
int getche(void)
{
    return getch_(1);
}