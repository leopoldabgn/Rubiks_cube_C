#include <time.h>
#include <string.h>

#include "functions.h"

#ifdef OS_WINDOWS
#include <conio.h>
#include <windows.h>
#else
#include "getch.h"
#endif

int cube[H][W] = {        {6,6},
                          {6,6},
                    {2,2},{1,1},{4,4},{3,3},
                    {2,2},{1,1},{4,4},{3,3},
                          {5,5},
                          {5,5}};

int difficulty = 0, position = 0, PLL_skip = 0, OLL_skip = 0, gamemode = 0;
int no_mouv;

char solution[1000], empty_file[1000], rep[100];

int main()
{
    srand(time(NULL)); //IMPORTANT POUR LES NOMBRES ALEATOIRES

    puts("(Press 'q' to stop the program)");
    
    while(gamemode != 38 && gamemode != '1' && gamemode != 130 &&
          gamemode != 195 && gamemode != '2')    // Correspond aux touches 1 et 2, lorsque MAJ n'est pas enfonce
    {
        clear();
        printf("\nBienvenue dans notre simulateur de Rubik's Cube !\n\nChoisissez le cube que vous voulez utiliser :\n\n1. 2x2x2\n2. 3x3x3\n");
        gamemode = get_char();
    }
    clear();
    if(gamemode == 38 || gamemode == '1')
    {
        printf("\n| RUBIK'S CUBE 2X2X2 |\n");
        gamemode = 0;
    }
    else
    {
        printf("\n| RUBIK'S CUBE 3X3X3 |\n");
        gamemode = 1;
    }

    printf("Voulez-vous rentrer la configuration de votre cube ? (y/n)\n");
    char c;
    while((c = get_char()) != 'y' && c != 'n')
        ;
    if(c == 'y')
    {
        reset_cube(0);
        ask_scramble();
    }
    else 
    {
        reset_cube(1);
        printf("\nMelanger le rubiks cube ? o/n\n");
        if (get_char() == 'o')
            scramble(20);
        else
        {
            setColor(BLANC,NOIR);
            clear();
            afficherCube();
        }
    }
    /*
        do
        {
            printf("\nDIFFICULTY ? ");
            scanf("%d",&difficulty);
            if(difficulty != 0 && difficulty != 1) printf("\nMerci de saisir une valeur en 0 et 1 !! \n");

        }while(difficulty != 0 && difficulty != 1);

        setColor(ROUGE,NOIR);
        clear();

        afficherCube();
    */

    /*
        do
        {
            PLL_skip = 0;
            OLL_skip = 0;
            scramble(20);
            IA();
        }while(PLL_skip != 1);

        display_solve();

    */

    lancer_jeu();

    return 0;
}


void lancer_jeu()
{
    int jeu = 0;

    float temps;
    clock_t t1, t2;

    while(jeu == 0)
    {

        switch (get_char())
        {
        case 's':
            scramble(20);
            break;
        case 'd':
            mouv_D();
            afficherCube();
            printf("D");
            break;
        case 'u':
            mouv_U();
            afficherCube();
            printf("U");
            break;
        case 'f':
            mouv_F();
            afficherCube();
            printf("F");
            break;
        case 'r':
            mouv_R();
            afficherCube();
            printf("R");
            break;
        case 'l':
            mouv_L();
            afficherCube();
            printf("L");
            break;
        case 'b':
            mouv_B();
            afficherCube();
            printf("B");
            break;
        case 'e':
            mouv_E();
            afficherCube();
            printf("E");
            break;
        case 'm':
            mouv_M();
            afficherCube();
            printf("M");
            break;
        case 'D':
            mouv_D();
            mouv_D();
            mouv_D();
            afficherCube();
            printf("D'");
            break;
        case 'U':
            mouv_U();
            mouv_U();
            mouv_U();
            afficherCube();
            printf("U'");
            break;
        case 'F':
            mouv_F();
            mouv_F();
            mouv_F();
            afficherCube();
            printf("F'");
            break;
        case 'R':
            mouv_R();
            mouv_R();
            mouv_R();
            afficherCube();
            printf("R'");
            break;
        case 'L':
            mouv_L();
            mouv_L();
            mouv_L();
            afficherCube();
            printf("L'");
            break;
        case 'B':
            mouv_B();
            mouv_B();
            mouv_B();
            afficherCube();
            printf("B'");
            break;
        case 'E':
            mouv_E();
            mouv_E();
            mouv_E();
            afficherCube();
            printf("E'");
            break;
        case 'M':
            mouv_M();
            mouv_M();
            mouv_M();
            afficherCube();
            printf("M'");
            break;
        case 'i':
            for(int i=0;i<1000;i++)
                solution[i] = 0;
            t1 = clock();
            IA();
            t2 = clock();
            temps = (float)(t2-t1)/CLOCKS_PER_SEC;
            printf("temps = %f\n", temps);
            display_solve();
            break;
        case 't':
            PLL_T();
            afficherCube();
            break;
        case 'a':
            reset_cube(1);
            break;
        case 'p':
            for(int i=0;i<1000;i++)
                solution[i] = 0;
            break;
        }

        sleep(100);
    }

}

void sleep(int time)
{
    #ifdef OS_WINDOWS
    Sleep(time);
    #else
    // TODO
    #endif
}

void clear()
{
    #ifdef OS_WINDOWS
    system("cls");
    #else
    // TODO
    #endif 
}

int get_char()
{
    int value;
    #ifdef OS_WINDOWS
    value = getch();
    #else
    value = getch();
    // clear_buffer();
    #endif

    // On quitte le prgm si q est presse
    if(value == 'q')
        exit(EXIT_SUCCESS);

    return value;
}

void clear_buffer()
{
    while ( getchar() != '\n' )
        ;
}

void scramble(int nombreMax)
{

    int alea = 0;
    char choix[1] = {0};
    char melange[nombreMax];

    reset_cube(1);

    for(int i=0;i<nombreMax;i++)
    {
        alea = nombreAleatoire(6);
        switch(alea)
        {
            case 1:
                mouv_F();
                choix[0] = 'F';
                puts("F");
                afficherCube();
                break;
            case 2:
                mouv_U();
                choix[0] = 'U';
                puts("U");
                afficherCube();
                break;
            case 3:
                mouv_R();
                choix[0] = 'R';
                puts("R");
                afficherCube();
                break;
            case 4:
                mouv_L();
                choix[0] = 'L';
                puts("L");
                afficherCube();
                break;
            case 5:
                mouv_D();
                choix[0] = 'D';
                puts("D");
                afficherCube();
                break;
            case 6:
                mouv_B();
                choix[0] = 'B';
                puts("B");
                afficherCube();
                break;
        }
        melange[i] = choix[0];
    }

    for(int i=0;i<1000;i++)
        solution[i] = 0;

    position = 0;

    printf("\nScramble : ");
    for(int i = 0;i<nombreMax;i++)
        printf("%c",melange[i]);
    puts("");
    afficherCube();
}

void ask_scramble() 
{
    clear();
    afficherCube();

    char c;

    int col = 2, line = 12;
    if(gamemode == 1) {
        col = 3;
        line = 18;
    }

    for(int j=0;j<line;j++)
    {
        for(int i=0;i<col;i++)
        {
            printf("Appuyez pour colorier la prochaine case\n\nrouge (r), vert (g), orange (o) : violet\nbleu (b), blanc (w), jaune (y)\n");
            c = 0;
            while(c != 'r' && c != 'g' && c != 'o' && c != 'b' && c != 'w' && c != 'y')
                c = get_char();
            puts("");
            cube[j][i] = getColor(c);
            clear();
            afficherCube();
            clear();
        }
    }

}
