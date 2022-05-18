#include "functions.h"

#ifdef OS_WINDOWS
#include <windows.h>
#endif

// FONCTIONS POUR LES MOUVEMENTS DU CUBE

void add_solve_mouv(char lettre)
{

    switch(lettre)
    {
    case 'u':
        solution[position] = 'U';
        break;
    case 'r':
        solution[position] = 'R';
        break;
    case 'l':
        solution[position] = 'L';
        break;
    case 'f':
        solution[position] = 'F';
        break;
    case 'b':
        solution[position] = 'B';
        break;
    case 'd':
        solution[position] = 'D';
        break;
    case 'U':
        break;
    case 'A':
        solution[position] = 'A';
        break;
    case 'L':
        break;
    case 'F':
        break;
    case 'B':
        break;
    case 'D':
        break;
    default:
        break;
    }

    position++;

}

void reverse(void (*pf)(int (*)[W]))
{
    for(int i=0;i<2;i++)
    {
        no_mouv = 1;
        pf(cube);
    }
    no_mouv = 0;
    pf(cube);
    position--;
    solution[position] -=  'A' - 'a';
    position++;
}

void mouv_U()
{
    if(no_mouv == 0) add_solve_mouv('u');

    int wait = 0, wait2 = 0;

    if(gamemode == 0)
    {

        //ON TOURNE LA FACE DU HAUT
        wait = cube[0][1];

        cube[0][1] = cube[0][0];
        cube[0][0] = wait;

        wait = cube[1][1];
        cube[1][1] = cube[0][0];
        cube[0][0] = cube[1][0];
        cube[1][0] = wait;

        //ON TOURNE LES COTES
        wait  = cube[4][0];
        wait2 = cube[4][1];
        cube[4][0] = cube[5][0];
        cube[4][1] = cube[5][1];
        cube[5][0] = cube[3][0];
        cube[5][1] = cube[3][1];
        cube[3][0] = wait;
        cube[3][1] = wait2;

        wait  = cube[2][0];
        wait2 = cube[2][1];
        cube[2][0] = cube[5][0];
        cube[2][1] = cube[5][1];
        cube[5][0] = wait;
        cube[5][1] = wait2;

    }
    else if(gamemode == 1)
    {

        //ON TOURNE LA FACE DU HAUT
        wait = cube[0][2];

        cube[0][2] = cube[0][0];
        cube[0][0] = wait;

        wait = cube[2][2];
        cube[2][2] = cube[0][0];
        cube[0][0] = cube[2][0];
        cube[2][0] = wait;

        //ON TOURNE LES COTES
        wait  = cube[5][0];
        wait2 = cube[5][2];
        cube[5][0] = cube[6][0];
        cube[5][2] = cube[6][2];
        cube[6][0] = cube[4][0];
        cube[6][2] = cube[4][2];
        cube[4][0] = wait;
        cube[4][2] = wait2;

        wait  = cube[3][0];
        wait2 = cube[3][2];
        cube[3][0] = cube[6][0];
        cube[3][2] = cube[6][2];
        cube[6][0] = wait;
        cube[6][2] = wait2;

        // ON TOURNE LES AR�TES DU HAUT
        wait = cube[1][2];

        cube[1][2] = cube[0][1];
        cube[0][1] = wait;

        wait = cube[2][1];
        cube[2][1] = cube[0][1];
        cube[0][1] = cube[1][0];
        cube[1][0] = wait;

        // ON TOURNE LES AR�TES SUR LE COTE
        wait = cube[5][1];

        cube[5][1] = cube[6][1];
        cube[6][1] = wait;

        wait = cube[4][1];
        cube[4][1] = cube[6][1];
        cube[6][1] = cube[3][1];
        cube[3][1] = wait;

    }

}


void mouv_D()
{
    if(no_mouv == 0) add_solve_mouv('d');

    int wait = 0, wait2 = 0;

    if(gamemode == 0)
    {

        //ON TOURNE LA FACE DU BAS
        wait = cube[10][1];

        cube[10][1] = cube[10][0];
        cube[10][0] = wait;

        wait = cube[11][1];
        cube[11][1] = cube[10][0];
        cube[10][0] = cube[11][0];
        cube[11][0] = wait;

        //ON TOURNE LES COTES

        for(int i=0;i<3;i++)
        {

            wait  = cube[8][0];
            wait2 = cube[8][1];
            cube[8][0] = cube[9][0];
            cube[8][1] = cube[9][1];
            cube[9][0] = cube[7][0];
            cube[9][1] = cube[7][1];
            cube[7][0] = wait;
            cube[7][1] = wait2;

            wait  = cube[6][0];
            wait2 = cube[6][1];
            cube[6][0] = cube[9][0];
            cube[6][1] = cube[9][1];
            cube[9][0] = wait;
            cube[9][1] = wait2;

        }

    }

    else if(gamemode == 1)
    {

        //ON TOURNE LA FACE DU BAS
        wait = cube[15][2];

        cube[15][2] = cube[15][0];
        cube[15][0] = wait;

        wait = cube[17][2];
        cube[17][2] = cube[15][0];
        cube[15][0] = cube[17][0];
        cube[17][0] = wait;

        //ON TOURNE LES COTES

        for(int i=0;i<3;i++)
        {

            wait  = cube[13][0];
            wait2 = cube[13][2];
            cube[13][0] = cube[14][0];
            cube[13][2] = cube[14][2];
            cube[14][0] = cube[12][0];
            cube[14][2] = cube[12][2];
            cube[12][0] = wait;
            cube[12][2] = wait2;

            wait  = cube[11][0];
            wait2 = cube[11][2];
            cube[11][0] = cube[14][0];
            cube[11][2] = cube[14][2];
            cube[14][0] = wait;
            cube[14][2] = wait2;

        }

        //ON TOURNE LA ARETES VERS LE BAS
        wait = cube[16][2];

        cube[16][2] = cube[15][1];
        cube[15][1] = wait;

        wait = cube[17][1];
        cube[17][1] = cube[15][1];
        cube[15][1] = cube[16][0];
        cube[16][0] = wait;

        //ON TOURNE LES ARETES VERS LE COTE
        wait = cube[13][1];

        cube[13][1] = cube[12][1];
        cube[12][1] = wait;

        wait = cube[14][1];
        cube[14][1] = cube[12][1];
        cube[12][1] = cube[11][1];
        cube[11][1] = wait;

    }


}

void mouv_F()
{
    if(no_mouv == 0) add_solve_mouv('f');

    int wait = 0, wait2 = 0;

    if(gamemode == 0)
    {
        //ON TOURNE LA FACE DU HAUT
        wait = cube[3][1];

        cube[3][1] = cube[3][0];
        cube[3][0] = wait;

        wait = cube[7][1];
        cube[7][1] = cube[3][0];
        cube[3][0] = cube[7][0];
        cube[7][0] = wait;

        //ON TOURNE LES COTES
        wait  = cube[4][0];
        wait2 = cube[8][0];
        cube[4][0] = cube[1][0];
        cube[8][0] = cube[1][1];
        cube[1][0] = cube[10][1];
        cube[1][1] = cube[10][0];
        cube[10][0] = wait2;
        cube[10][1] = wait;

        wait  = cube[2][1];
        wait2 = cube[6][1];
        cube[6][1] = cube[1][0];
        cube[2][1] = cube[1][1];
        cube[1][0] = wait2;
        cube[1][1] = wait;
    }
    else if(gamemode == 1)
    {

        //ON TOURNE LA FACE DU HAUT
        wait = cube[4][2];

        cube[4][2] = cube[4][0];
        cube[4][0] = wait;

        wait = cube[12][2];
        cube[12][2] = cube[4][0];
        cube[4][0] = cube[12][0];
        cube[12][0] = wait;

        //ON TOURNE LES COTES
        wait  = cube[5][0];
        wait2 = cube[13][0];
        cube[5][0] = cube[2][0];
        cube[13][0] = cube[2][2];
        cube[2][0] = cube[15][2];
        cube[2][2] = cube[15][0];
        cube[15][0] = wait2;
        cube[15][2] = wait;

        wait  = cube[3][2];
        wait2 = cube[11][2];
        cube[11][2] = cube[2][0];
        cube[3][2] = cube[2][2];
        cube[2][0] = wait2;
        cube[2][2] = wait;

        //ON TOURNE LES ARETES DU HAUT
        wait = cube[8][2];

        cube[8][2] = cube[4][1];
        cube[4][1] = wait;

        wait = cube[12][1];
        cube[12][1] = cube[4][1];
        cube[4][1] = cube[8][0];
        cube[8][0] = wait;

        //ON TOURNE LES ARETES SUR LE COTE
        wait = cube[9][0];

        cube[9][0] = cube[2][1];
        cube[2][1] = wait;

        wait = cube[15][1];
        cube[15][1] = cube[2][1];
        cube[2][1] = cube[7][2];
        cube[7][2] = wait;



    }

}

void mouv_R()
{
    if(no_mouv == 0) add_solve_mouv('r');

    no_mouv = 1;

    if(gamemode == 0)
    {
        mouv_U();
        for(int i=0;i<3;i++) mouv_D();
        mouv_F();
        for(int i=0;i<3;i++) mouv_U();
        mouv_D();
    }
    else if(gamemode  == 1)
    {
        mouv_U();
        mouv_E();
        for(int i=0;i<3;i++) mouv_D();
        mouv_F();
        for(int i=0;i<3;i++) mouv_U();
        for(int i=0;i<3;i++) mouv_E();
        mouv_D();
    }

    no_mouv = 0;
}

void mouv_L()
{
    if(no_mouv == 0) add_solve_mouv('l');

    no_mouv = 1;

    if(gamemode == 0)
    {
        mouv_D();
        for(int i=0;i<3;i++) mouv_U();
        mouv_F();
        for(int i=0;i<3;i++) mouv_D();
        mouv_U();
    }
    else if(gamemode  == 1)
    {
        mouv_D();
        for(int i=0;i<3;i++) mouv_E();
        for(int i=0;i<3;i++) mouv_U();
        mouv_F();
        for(int i=0;i<3;i++) mouv_D();
        mouv_E();
        mouv_U();
    }

    no_mouv = 0;
}

void mouv_B()
{
    if(no_mouv == 0) add_solve_mouv('b');

    no_mouv = 1;

    if(gamemode == 0)
    {
        for(int i=0;i<2;i++) mouv_U();
        for(int i=0;i<2;i++) mouv_D();
        mouv_F();
        for(int i=0;i<2;i++) mouv_U();
        for(int i=0;i<2;i++) mouv_D();
    }
    else if(gamemode  == 1)
    {
        for(int i=0;i<2;i++) mouv_U();
        for(int i=0;i<2;i++) mouv_E();
        for(int i=0;i<2;i++) mouv_D();
        mouv_F();
        for(int i=0;i<2;i++) mouv_U();
        for(int i=0;i<2;i++) mouv_E();
        for(int i=0;i<2;i++) mouv_D();
    }

    no_mouv = 0;
}

void mouv_E()
{

    if(gamemode == 1)
    {

        int wait = 0;

        if(no_mouv == 0) add_solve_mouv('e');

        for(int i=0;i<3;i++)
        {

            // ON TOURNE LES AR�TES SUR LE COTE
            wait = cube[8][2];

            cube[8][2] = cube[7][2];
            cube[7][2] = wait;

            wait = cube[9][2];
            cube[9][2] = cube[7][2];
            cube[7][2] = cube[10][2];
            cube[10][2] = wait;

            // ON TOURNE LES AR�TES SUR LE COTE
            wait = cube[9][0];

            cube[9][0] = cube[8][0];
            cube[8][0] = wait;

            wait = cube[10][0];
            cube[10][0] = cube[8][0];
            cube[8][0] = cube[7][0];
            cube[7][0] = wait;

            // ON TOURNE LES MILIEUX
            wait = cube[8][1];

            cube[8][1] = cube[7][1];
            cube[7][1] = wait;

            wait = cube[9][1];
            cube[9][1] = cube[7][1];
            cube[7][1] = cube[10][1];
            cube[10][1] = wait;

        }

    }

}

void mouv_M()
{

    if(gamemode == 1)
    {

        int wait = 0;

        if(no_mouv == 0) add_solve_mouv('m');

        for(int i=0;i<3;i++)
        {

            // ON TOURNE LES AR�TES SUR LE COTE
            wait = cube[12][1];

            cube[12][1] = cube[17][1];
            cube[17][1] = wait;

            wait = cube[2][1];
            cube[2][1] = cube[17][1];
            cube[17][1] = cube[6][1];
            cube[6][1] = wait;

            // ON TOURNE LES AR�TES SUR LE COTE
            wait = cube[4][1];

            cube[4][1] = cube[15][1];
            cube[15][1] = wait;

            wait = cube[0][1];
            cube[0][1] = cube[15][1];
            cube[15][1] = cube[14][1];
            cube[14][1] = wait;

            // ON TOURNE LES MILIEUX
            wait = cube[8][1];

            cube[8][1] = cube[16][1];
            cube[16][1] = wait;

            wait = cube[1][1];
            cube[1][1] = cube[16][1];
            cube[16][1] = cube[10][1];
            cube[10][1] = wait;

        }

    }

}

// FORMULES, METHODE FRIDRICH OLL/PLL

void PLL_T()
{
    mouv_R();
    mouv_U();
    reverse(mouv_R);
    reverse(mouv_U);
    reverse(mouv_R);
    mouv_F();
    mouv_R();
    mouv_R();
    reverse(mouv_U);
    reverse(mouv_R);
    reverse(mouv_U);
    mouv_R();
    mouv_U();
    reverse(mouv_R);
    reverse(mouv_F);
    PLL_skip++;
}

void PLL_Y()
{
    mouv_F();
    mouv_R();
    reverse(mouv_U);
    reverse(mouv_R);
    reverse(mouv_U);
    mouv_R();
    mouv_U();
    reverse(mouv_R);
    reverse(mouv_F);
    mouv_R();
    mouv_U();
    reverse(mouv_R);
    reverse(mouv_U);
    reverse(mouv_R);
    mouv_F();
    mouv_R();
    reverse(mouv_F);
    PLL_skip++;
}

void OLL_21()
{
    mouv_R();
    mouv_U();
    mouv_U();
    reverse(mouv_R);
    reverse(mouv_U);
    mouv_R();
    mouv_U();
    reverse(mouv_R);
    reverse(mouv_U);
    mouv_R();
    reverse(mouv_U);
    reverse(mouv_R);
    OLL_skip++;
}

void OLL_22()
{
    mouv_R();
    mouv_U();
    mouv_U();
    mouv_R();
    mouv_R();
    reverse(mouv_U);
    mouv_R();
    mouv_R();
    reverse(mouv_U);
    mouv_R();
    mouv_R();
    mouv_U();
    mouv_U();
    mouv_R();
    OLL_skip++;
}

void OLL_23()
{
    mouv_R();
    mouv_R();
    mouv_D();
    reverse(mouv_R);
    mouv_U();
    mouv_U();
    mouv_R();
    reverse(mouv_D);
    reverse(mouv_R);
    mouv_U();
    mouv_U();
    reverse(mouv_R);
    OLL_skip++;
}

void OLL_24()
{
    mouv_R();
    mouv_U();
    reverse(mouv_R);
    reverse(mouv_U);
    reverse(mouv_L);
    mouv_U();
    mouv_R();
    reverse(mouv_U);
    reverse(mouv_R);
    mouv_L();
    OLL_skip++;
}

void OLL_25()
{
    reverse(mouv_F);
    OLL_24();
    mouv_F();
    OLL_skip++;
}

void OLL_26()
{
    mouv_R();
    mouv_U();
    mouv_U();
    reverse(mouv_R);
    reverse(mouv_U);
    mouv_R();
    reverse(mouv_U);
    reverse(mouv_R);
    OLL_skip++;
}

void OLL_27()
{
    reverse(mouv_L);
    mouv_U();
    mouv_U();
    mouv_L();
    mouv_U();
    reverse(mouv_L);
    mouv_U();
    mouv_L();
    OLL_skip++;
}

void test_faceBas()
{
    int var = 0, var2 = 0;

    if(gamemode == 1) {var=5;var2=1;}

    if (cube[6+var][0] != cube[6+var][1+var2] || cube[8+var][0] != cube[8+var][1+var2])
    {
        printf("puteuh");
    mouv_R();
    mouv_R();
    mouv_L();
    mouv_L();
    }

}

void lancer_PLL()
{

int var = 0;

if(gamemode == 1) var = 1;

    while (cube[2+var][0] != cube[2+var][1+var] || cube[4+var][0] != cube[4+var][1+var])
    {

        if (cube[2+var][0] == cube[2+var][1+var])
        {
            puts("PLL T");
            PLL_T();
        }
        else if (cube[3+var][0] == cube[5+var][1+var] && cube[3+var][1+var] == cube[5+var][0])
        {
            puts("PLL Y");
            PLL_Y();
        }
        else
        {
            mouv_U();
        }

    afficherCube();

    }

}


// AFFICHAGE DU CUBE ET AUTRES FONCTIONS

int nombreAleatoire(int nombreMax)
{
    return (rand() % nombreMax + 1);
}

void affCarre(int couleurcarre)
{
    int colors[] = {VERT, ROSE_FLUO, BLEU, ROUGE, JAUNE_FLUO, BLANC};
    setColor(NOIR, colors[couleurcarre-1]);
    printf("  ");
    setColor(BLANC,NOIR);
}

void afficherCube()
{
    if(difficulty == 0)
    {
        if(gamemode == 0)
        {
            puts("");
            printf("      ");
            affCarre(cube[0][0]);
            affCarre(cube[0][1]);
            printf("\n");

            printf("      ");
            affCarre(cube[1][0]);
            affCarre(cube[1][1]);
            printf("\n");

            printf("  ");
            for(int j=2;j<=5;j++)
                for(int i=0;i<=1;i++)
                    affCarre(cube[j][i]);
            printf("\n");

            printf("  ");
            for(int j=6;j<=9;j++)
                for(int i=0;i<=1;i++)
                    affCarre(cube[j][i]);
            printf("\n");

            printf("      ");
            affCarre(cube[10][0]);
            affCarre(cube[10][1]);
            printf("\n");

            printf("      ");
            affCarre(cube[11][0]);
            affCarre(cube[11][1]);
            printf("\n");
        }
        else if(gamemode == 1)
        {
            puts("");
            printf("        ");
            affCarre(cube[0][0]);
            affCarre(cube[0][1]);
            affCarre(cube[0][2]);
            printf("\n");

            printf("        ");
            affCarre(cube[1][0]);
            affCarre(cube[1][1]);
            affCarre(cube[1][2]);
            printf("\n");

            printf("        ");
            affCarre(cube[2][0]);
            affCarre(cube[2][1]);
            affCarre(cube[2][2]);
            printf("\n");

            printf("  ");
            for(int j=3;j<=6;j++)
                for(int i=0;i<=2;i++)
                    affCarre(cube[j][i]);
            printf("\n");

            printf("  ");
            for(int j=7;j<=10;j++)
                for(int i=0;i<=2;i++)
                    affCarre(cube[j][i]);
            printf("\n");

            printf("  ");
            for(int j=11;j<=14;j++)
                for(int i=0;i<=2;i++)
                    affCarre(cube[j][i]);
            printf("\n");

            printf("        ");
            affCarre(cube[15][0]);
            affCarre(cube[15][1]);
            affCarre(cube[15][2]);
            printf("\n");

            printf("        ");
            affCarre(cube[16][0]);
            affCarre(cube[16][1]);
            affCarre(cube[16][2]);
            printf("\n");

            printf("        ");
            affCarre(cube[17][0]);
            affCarre(cube[17][1]);
            affCarre(cube[17][2]);
            printf("\n");
        }

    }
    else
    {
        printf("      %d %d\n",cube[0][0],cube[0][1]);
        printf("      %d %d\n",cube[1][0],cube[1][1]);
        printf("  %d %d %d %d %d %d %d %d\n",cube[2][0],cube[2][1],cube[3][0],cube[3][1],cube[4][0],cube[4][1],cube[5][0],cube[5][1]);
        printf("  %d %d %d %d %d %d %d %d\n",cube[6][0],cube[6][1],cube[7][0],cube[7][1],cube[8][0],cube[8][1],cube[9][0],cube[9][1]);
        printf("      %d %d\n",cube[10][0],cube[10][1]);
        printf("      %d %d\n",cube[11][0],cube[11][1]);
    }

}

void display_solve()
{
    int var = 0;

    for(int j=0;j<500/20;j++)
    {

        for(int i=var;i<var+20;i++)
        {
            if (solution[i]  >= 'a' &&  solution[i] <= 'z')
            {
                solution[i] -=  'a' - 'A';
                printf("%c' ",solution[i]);
            }
           /* else if((solution[i] == solution[i+1] && solution[i+1] == solution[i+2] && solution[i+2] == solution[i+3]) && i < var+17 && solution[i] != 0)
            {
                printf("X ");
                i += 3;
            }*/
            else if((solution[i] == solution[i+1] && solution[i+1] == solution[i+2]) && i < var+18 && solution[i] != 0)
            {
                printf("%c' ",solution[i]);
                i += 2;
            }
            else if((solution[i] == solution[i+1] && solution[i+1] != solution[i+2]) && i < var+19 && solution[i] != 0)
            {
                printf("%c2 ",solution[i]);
                i += 1;
            }
            else if (solution[i] != '\0')
            {
                printf("%c ",solution[i]);
            }
        }
        var+=20;
        if(solution[var-1] != '\0')
            puts("");
    }

}

void reset_cube()
{

    if(gamemode == 0)
    {

        for(int j=0;j<2;j++)
        {
            for(int i=0;i<2;i++)
            {
                cube[j][i] = 6;
            }
        }

        for(int i=0;i<2;i++)
        {
            cube[2][i] = 2;
            cube[6][i] = 2;
            cube[3][i] = 1;
            cube[7][i] = 1;
            cube[4][i] = 4;
            cube[8][i] = 4;
            cube[5][i] = 3;
            cube[9][i] = 3;
        }

        for(int j=10;j<12;j++)
        {
            for(int i=0;i<2;i++)
            {
                cube[j][i] = 5;
            }
        }

    }
    else if(gamemode == 1)
    {

        for(int j=0;j<3;j++)
        {
            for(int i=0;i<3;i++)
            {
                cube[j][i] = 6;
            }
        }

        for(int i=0;i<3;i++)
        {
            cube[3][i] = 2;
            cube[7][i] = 2;
            cube[11][i] = 2;
            cube[4][i] = 1;
            cube[8][i] = 1;
            cube[12][i] = 1;
            cube[5][i] = 4;
            cube[9][i] = 4;
            cube[13][i] = 4;
            cube[6][i] = 3;
            cube[10][i] = 3;
            cube[14][i] = 3;
        }

        for(int j=15;j<18;j++)
        {
            for(int i=0;i<3;i++)
            {
                cube[j][i] = 5;
            }
        }

    }


    for(int i=0;i<1000;i++)
    {
        solution[i] = 0;
    }

    afficherCube();

}

// CHANGER COULEUR DES PIXELS DE LA CONSOLE
void setColor(int t,int f)
{
    #ifdef OS_WINDOWS
    HANDLE theHandle=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(theHandle,f*16+t);
    #else
    // Linux Code
    if(t == BLANC && f == NOIR) {
        printf("\033[0m");
    }
    else {
        printf("\033[0%dm", t); // t = foreground
        printf("\033[0%dm", f+10); // f = background
    }
    #endif
}
