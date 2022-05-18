#include "functions.h"

void IA()
{

if(gamemode == 0)
{

    while(cube[10][0] != 6 || cube[10][1] != 6 || cube[11][0] != 6 || cube[11][1] != 6)
    {

            test_if_2W(); // Test si il y a 2 blocks de blanc quelque part
            test_2W_bottom();

            if (cube[10][0] != 6 && cube[10][1] != 6 && cube[11][0] != 6 && cube[11][1] != 6)
            {
                if(cube[2][0] == 6 || cube[6][0] == 6) mouv_B();
                else if (cube[4][1] == 6 || cube[8][1] == 6) reverse(mouv_B);
                else if (cube[7][0] == 6) mouv_L();
                else if (cube[7][1] == 6) reverse(mouv_R);
                else if (cube[5][0] == 6) mouv_R();
                else if (cube[5][1] == 6) reverse(mouv_L);
                else if (cube[2][1] == 6 || cube[6][1] == 6) reverse(mouv_F);
                else if (cube[4][0] == 6 || cube[8][1] == 6) mouv_F();
                else if (cube[9][0] == 6) mouv_R();
                else if (cube[9][1] == 6) reverse(mouv_L);
                else if (cube[3][0] == 6) mouv_L();
                else if (cube[3][1] == 6) reverse(mouv_R);
                else if (cube[0][0] == 6 || cube[0][1] == 6) {mouv_B();mouv_B();}
                else if (cube[1][0] == 6) {mouv_L();mouv_L();}
                else if (cube[1][1] == 6) {mouv_R();mouv_R();}
            }

        if(test_2W_bottom() == 0)
        {
            while(cube[10][0] != 6)
            {
                mouv_D();
            }
        }

        afficherCube();

    while(cube[10][0] != 6 || cube[10][1] != 6 || cube[11][0] != 6 || cube[11][1] != 6)
    {

        while(test_topLeft() == 1 || test_topRight() == 1)
        {

            if(test_topLeft() == 1)
            {

                while(cube[2][1] != 6)
                {
                    mouv_U();
                    afficherCube();
                }

                if(cube[1][0] == cube[7][0])
                {
                    printf("case de devant");
                    mouv_R();
                    reverse(mouv_U);
                    afficherCube();
                    reverse(mouv_R);
                }
                else if(cube[3][0] == cube[6][1])
                {
                    printf("case de derriere");
                    mouv_U();
                    mouv_U();
                    mouv_L();
                    reverse(mouv_U);
                    reverse(mouv_L);
                }
                else
                {
                    printf("case en diagonal...");
                    reverse(mouv_U);
                    mouv_B();
                    afficherCube();
                    reverse(mouv_U);
                    reverse(mouv_B);
                }

            }

            afficherCube();

            if(test_topRight() == 1)
            {

                while(cube[5][0] != 6)
                {
                    mouv_U();
                    afficherCube();
                }

                if(cube[4][1] == cube[7][0])
                {
                    printf("case de devant");
                    reverse(mouv_F);
                    mouv_U();
                    afficherCube();
                    mouv_F();
                }
                else if(cube[0][1] == cube[6][1])
                {
                    printf("case de derriere");
                    mouv_U();
                    mouv_U();
                    reverse(mouv_B);
                    afficherCube();
                    mouv_U();
                    mouv_B();
                }
                else
                {
                    printf("case en diagonal !");
                    reverse(mouv_U);
                    reverse(mouv_R);
                    afficherCube();
                    mouv_U();
                    mouv_R();
                }

            }

            afficherCube();

        }

        if(test_bottomLeft() == 1)
        {
            int mouv = 0;
            while(cube[6][1] != 6)
            {
                mouv_D();
                mouv++;
                afficherCube();
                printf("D");
            }

            reverse(mouv_L);
            printf("L'");
            afficherCube();
            reverse(mouv_U);
            printf("U'");
            afficherCube();
            mouv_L();
            printf("L");
            afficherCube();

            switch(mouv)
            {
            case 1:
                reverse(mouv_D);
                printf("D'");
                break;
            case 2:
                mouv_D();
                printf("D");
                mouv_D();
                printf("D");
                break;
            case 3:
                mouv_D();
                printf("D");
                break;
            }
        afficherCube();
        }

        if(test_bottomRight() == 1)
        {
            int mouv = 0;
            while(cube[8][0] != 6)
            {
                mouv_D();
                mouv++;
                afficherCube();
            }

            mouv_R();
            mouv_U();
            reverse(mouv_R);

            switch(mouv)
            {
            case 1:
                reverse(mouv_D);
                break;
            case 2:
                mouv_D();
                mouv_D();
                break;
            case 3:
                mouv_D();
                break;
            }
            afficherCube();
        }

        afficherCube();



            if(test_top() == 1)
            {

                while(cube[1][1] != 6)
                {
                    mouv_U();
                    afficherCube();
                }

                if(cube[4][0] == cube[7][0])
                {
                    printf("case de devant");
                    mouv_R();
                    mouv_U();
                    mouv_U();
                    reverse(mouv_R);
                    afficherCube();
                    reverse(mouv_U);
                    mouv_F();
                    reverse(mouv_R);
                    afficherCube();
                    reverse(mouv_F);
                    mouv_R();
                }
                else if(cube[3][1] == cube[6][1])
                {
                    printf("case de derriere");
                    mouv_U();
                    mouv_U();
                    mouv_L();
                    reverse(mouv_U);
                    afficherCube();
                    reverse(mouv_L);
                    reverse(mouv_B);
                    afficherCube();
                    mouv_U();
                    mouv_U();
                    mouv_B();
                }
                else
                {
                    printf("case en diagonal...");
                    reverse(mouv_U);
                    reverse(mouv_R);
                    afficherCube();
                    mouv_U();
                    mouv_R();
                    reverse(mouv_U);
                    mouv_B();
                    afficherCube();
                    reverse(mouv_U);
                    reverse(mouv_B);

                }

            }

            afficherCube();

    }

    }

    afficherCube();


    //TANT QUE LA FACE DU HAUT N EST PAS TERMINER

    while(cube[0][0] != 5 || cube[0][1] != 5 || cube[1][0] != 5 || cube[1][1] != 5)
    {

        if (cube[0][0] == 5 && cube[1][0] == 5)
        {

            if (cube[3][1] == 5)
            {
                mouv_U();
                afficherCube();
                mouv_U();
                afficherCube();
                puts("OLL 24");
                OLL_24();
            }
            else
            {
                mouv_U();
                afficherCube();
                puts("OLL 23");
                OLL_23();
            }

        }
        else if(cube[0][1] == 5 && cube[1][0] == 5)
        {
            mouv_U();
            mouv_U();
            puts("OLL 25");
            OLL_25();
        }
        else if(cube[0][0] == 5 && cube[2][1] == 5 && cube[3][1] == 5)
        {
            puts("OLL 27");
            OLL_27();
        }
        else if(cube[0][1] == 5 && cube[3][0] == 5 && cube[4][0] == 5)
        {
            puts("OLL 26");
            OLL_26();
        }
        else if(cube[3][0] == 5 && cube[3][1] == 5 && cube[5][0] == 5)
        {
            puts("OLL 21");
            OLL_21();

        }
        else if(cube[2][0] == 5 && cube[2][1] == 5 && cube[3][1] == 5 )
        {
            puts("OLL 22");
            OLL_22();
        }
        else
        {
            mouv_U();
        }

    afficherCube();

    }

        // PLL

    lancer_PLL();
    test_faceBas();
    lancer_PLL();

    while(cube[3][0] != cube[7][0])
    {
        puts("A.U.F");
        mouv_U();
        afficherCube();
    }

}
else if (gamemode == 1)
{

    while(cube[15][0] != 6 || cube[15][2] != 6 || cube[17][0] != 6 || cube[17][2] != 6)
    {

            test_if_2W(); // Test si il y a 2 blocks de blanc quelque part
            test_2W_bottom();

            if (cube[15][0] != 6 && cube[15][2] != 6 && cube[17][0] != 6 && cube[17][2] != 6)
            {
                if(cube[3][0] == 6 || cube[11][0] == 6) mouv_B(); // A REFAIRE !
                else if (cube[5][2] == 6 || cube[13][2] == 6) reverse(mouv_B);
                else if (cube[12][0] == 6) mouv_L();
                else if (cube[12][2] == 6) reverse(mouv_R);
                else if (cube[6][0] == 6) mouv_R();
                else if (cube[6][2] == 6) reverse(mouv_L);
                else if (cube[3][2] == 6 || cube[11][2] == 6) reverse(mouv_F);
                else if (cube[5][0] == 6 || cube[13][0] == 6) mouv_F();
                else if (cube[14][0] == 6) mouv_R();
                else if (cube[14][2] == 6) reverse(mouv_L);
                else if (cube[4][0] == 6) mouv_L();
                else if (cube[4][2] == 6) reverse(mouv_R);
                else if (cube[0][0] == 6 || cube[0][2] == 6) {mouv_B();mouv_B();}
                else if (cube[2][0] == 6) {mouv_L();mouv_L();}
                else if (cube[2][2] == 6) {mouv_R();mouv_R();}
            }

        afficherCube();

        if(test_2W_bottom() == 0)
        {
            while(cube[15][0] != 6)
            {
                mouv_D();
            }
        }

        afficherCube();

    while(cube[15][0] != 6 || cube[15][2] != 6 || cube[17][0] != 6 || cube[17][2] != 6)
    {

        while(test_topLeft() == 1 || test_topRight() == 1)
        {

            if(test_topLeft() == 1)
            {

                while(cube[3][2] != 6)
                {
                    mouv_U();
                    afficherCube();
                }

                if(cube[2][0] == cube[12][0])
                {
                    printf("case de devant");
                    mouv_R();
                    reverse(mouv_U);
                    afficherCube();
                    reverse(mouv_R);
                }
                else if(cube[4][0] == cube[11][2])
                {
                    printf("case de derriere");
                    mouv_U();
                    mouv_U();
                    mouv_L();
                    reverse(mouv_U);
                    reverse(mouv_L);
                }
                else
                {
                    printf("case en diagonal...");
                    reverse(mouv_U);
                    mouv_B();
                    afficherCube();
                    reverse(mouv_U);
                    reverse(mouv_B);
                }

            }

            afficherCube();

            if(test_topRight() == 1)
            {

                while(cube[6][0] != 6)
                {
                    mouv_U();
                    afficherCube();
                }

                if(cube[5][2] == cube[12][0])
                {
                    printf("case de devant");
                    reverse(mouv_F);
                    mouv_U();
                    afficherCube();
                    mouv_F();
                }
                else if(cube[0][2] == cube[11][2])
                {
                    printf("case de derriere");
                    mouv_U();
                    mouv_U();
                    reverse(mouv_B);
                    afficherCube();
                    mouv_U();
                    mouv_B();
                }
                else
                {
                    printf("case en diagonal !");
                    reverse(mouv_U);
                    reverse(mouv_R);
                    afficherCube();
                    mouv_U();
                    mouv_R();
                }

            }

            afficherCube();

        }

        if(test_bottomLeft() == 1)
        {
            int mouv = 0;

            while(cube[11][2] != 6)
            {
                mouv_D();
                mouv++;
                afficherCube();
                printf("D");
            }

            reverse(mouv_L);
            printf("L'");
            afficherCube();
            reverse(mouv_U);
            printf("U'");
            afficherCube();
            mouv_L();
            printf("L");
            afficherCube();

            switch(mouv)
            {
            case 1:
                reverse(mouv_D);
                printf("D'");
                break;
            case 2:
                mouv_D();
                printf("D");
                mouv_D();
                printf("D");
                break;
            case 3:
                mouv_D();
                printf("D");
                break;
            }
        afficherCube();
        }

        if(test_bottomRight() == 1)
        {
            int mouv = 0;
            while(cube[13][0] != 6)
            {
                mouv_D();
                mouv++;
                afficherCube();
            }

            mouv_R();
            mouv_U();
            reverse(mouv_R);

            switch(mouv)
            {
            case 1:
                reverse(mouv_D);
                break;
            case 2:
                mouv_D();
                mouv_D();
                break;
            case 3:
                mouv_D();
                break;
            }
            afficherCube();
        }

        afficherCube();



            if(test_top() == 1)
            {

                while(cube[2][2] != 6)
                {
                    mouv_U();
                    afficherCube();
                }

                if(cube[5][0] == cube[12][0])
                {
                    printf("case de devant");
                    mouv_R();
                    mouv_U();
                    mouv_U();
                    reverse(mouv_R);
                    afficherCube();
                    reverse(mouv_U);
                    mouv_F();
                    reverse(mouv_R);
                    afficherCube();
                    reverse(mouv_F);
                    mouv_R();
                }
                else if(cube[4][2] == cube[11][2])
                {
                    printf("case de derriere");
                    mouv_U();
                    mouv_U();
                    mouv_L();
                    reverse(mouv_U);
                    afficherCube();
                    reverse(mouv_L);
                    reverse(mouv_B);
                    afficherCube();
                    mouv_U();
                    mouv_U();
                    mouv_B();
                }
                else
                {
                    printf("case en diagonal...");
                    reverse(mouv_U);
                    reverse(mouv_R);
                    afficherCube();
                    mouv_U();
                    mouv_R();
                    reverse(mouv_U);
                    mouv_B();
                    afficherCube();
                    reverse(mouv_U);
                    reverse(mouv_B);

                }

            }

            afficherCube();

    }

    }

    afficherCube();

    //TANT QUE LA FACE DU HAUT N EST PAS TERMINER

    while(cube[0][0] != 5 || cube[0][2] != 5 || cube[2][0] != 5 || cube[2][2] != 5)
    {


        if (cube[0][0] == 5 && cube[2][0] == 5)
        {

            if (cube[4][2] == 5)
            {
                mouv_U();
                afficherCube();
                mouv_U();
                afficherCube();
                puts("OLL 24");
                OLL_24();
            }
            else
            {
                mouv_U();
                afficherCube();
                puts("OLL 23");
                OLL_23();
            }

        }
        else if(cube[0][2] == 5 && cube[2][0] == 5)
        {
            mouv_U();
            mouv_U();
            puts("OLL 25");
            OLL_25();
        }
        else if(cube[0][0] == 5 && cube[3][2] == 5 && cube[4][2] == 5)
        {
            puts("OLL 27");
            OLL_27();
        }
        else if(cube[0][2] == 5 && cube[4][0] == 5 && cube[5][0] == 5)
        {
            puts("OLL 26");
            OLL_26();
        }
        else if(cube[4][0] == 5 && cube[4][2] == 5 && cube[6][0] == 5)
        {
            puts("OLL 21");
            OLL_21();

        }
        else if(cube[3][0] == 5 && cube[3][2] == 5 && cube[4][2] == 5 )
        {
            puts("OLL 22");
            OLL_22();
        }
        else
        {
            mouv_U();
        }

    afficherCube();

    }

        // PLL

    lancer_PLL();
    test_faceBas();
    lancer_PLL();

    /*

    while(cube[4][0] != cube[12][0])
    {
       // puts("A.U.F");
        mouv_U();
        afficherCube();
    }

    */

    // TANT QUE LA FACE DU BAS N EST PAS TERMINE

   /* while(cube[15][1] != cube[16][0] && cube[16][0] != cube[16][2] && cube[16][2] != cube[17][1] && cube[16][1] != cube[17][1])
    {

    }*/

}


}


void test_if_2W()
{

    if(gamemode == 0)
    {

        if((cube[0][0] == 6 && cube[0][1] == 6) && (cube[5][0] == cube[5][1]))
        {
            mouv_B();
            mouv_B();
        }
        else if((cube[1][0] == 6 && cube[1][1] == 6) && (cube[3][0] == cube[3][1]))
        {
            mouv_F();
            mouv_F();
        }
        else if((cube[0][0] == 6 && cube[1][0] == 6) && (cube[2][0] == cube[2][1]))
        {
            mouv_L();
            mouv_L();
        }
        else if((cube[0][1] == 6 && cube[1][1] == 6) && (cube[4][0] == cube[4][1]))
        {
            mouv_R();
            mouv_R();
        }


        if((cube[2][0] == 6 && cube[2][1] == 6) && (cube[0][0] == cube[1][0]))
        {
            reverse(mouv_L);
            mouv_B();
        }
        else if((cube[2][1] == 6 && cube[6][1] == 6) && (cube[3][0] == cube[7][0]))
        {
            reverse(mouv_F);
        }
        else if((cube[6][0] == 6 && cube[6][1] == 6) && (cube[10][0] == cube[11][0]))
        {
           mouv_L();
           mouv_B();
        }
        else if((cube[6][0] == 6 && cube[2][0] == 6) && (cube[5][1] == cube[9][1]))
        {
            mouv_B();
        }


        if((cube[3][0] == 6 && cube[3][1] == 6) && (cube[1][0] == cube[1][1]))
        {
            reverse(mouv_F);
            mouv_L();
        }
        else if((cube[3][1] == 6 && cube[7][1] == 6) && (cube[4][0] == cube[8][0]))
        {
            reverse(mouv_R);
        }
        else if((cube[7][0] == 6 && cube[7][1] == 6) && (cube[10][0] == cube[10][1]))
        {
            reverse(mouv_R);
            mouv_L();
        }
        else if((cube[3][0] == 6 && cube[7][0] == 6) && (cube[2][1] == cube[6][1]))
        {
            mouv_L();
        }


        if((cube[4][0] == 6 && cube[4][1] == 6) && (cube[0][1] == cube[1][1]))
        {
            mouv_R();
            reverse(mouv_B);
        }
        else if((cube[4][1] == 6 && cube[8][1] == 6) && (cube[5][0] == cube[9][0]))
        {
            reverse(mouv_B);
        }
        else if((cube[8][0] == 6 && cube[8][1] == 6) && (cube[10][1] == cube[11][1]))
        {
            reverse(mouv_R);
            reverse(mouv_B);
        }
        else if((cube[4][0] == 6 && cube[8][0] == 6) && (cube[3][1] == cube[7][1]))
        {
            mouv_F();
        }


        if((cube[5][0] == 6 && cube[5][1] == 6) && (cube[0][0] == cube[0][1]))
        {
            reverse(mouv_L);
            mouv_R();
        }
        else if((cube[5][1] == 6 && cube[9][1] == 6) && (cube[2][0] == cube[6][0]))
        {
            reverse(mouv_L);
        }
        else if((cube[9][0] == 6 && cube[9][1] == 6) && (cube[11][0] == cube[11][1]))
        {
            reverse(mouv_B);
            reverse(mouv_L);
        }
        else if((cube[5][0] == 6 && cube[9][0] == 6) && (cube[4][1] == cube[8][1]))
        {
            mouv_R();
        }

    }
    else if(gamemode == 1)
    {

        if((cube[0][0] == 6 && cube[0][2] == 6) && (cube[6][0] == cube[6][2]))
        {
            mouv_B();
            mouv_B();
        }
        else if((cube[2][0] == 6 && cube[2][2] == 6) && (cube[4][0] == cube[4][2]))
        {
            mouv_F();
            mouv_F();
        }
        else if((cube[0][0] == 6 && cube[2][0] == 6) && (cube[3][0] == cube[3][2]))
        {
            mouv_L();
            mouv_L();
        }
        else if((cube[0][2] == 6 && cube[2][2] == 6) && (cube[5][0] == cube[5][2]))
        {
            mouv_R();
            mouv_R();
        }


        if((cube[3][0] == 6 && cube[3][2] == 6) && (cube[0][0] == cube[2][0]))
        {
            reverse(mouv_L);
            mouv_B();
        }
        else if((cube[3][2] == 6 && cube[11][2] == 6) && (cube[4][0] == cube[12][0]))
        {
            reverse(mouv_F);
        }
        else if((cube[11][0] == 6 && cube[11][2] == 6) && (cube[15][0] == cube[17][0]))
        {
           mouv_L();
           mouv_B();
        }
        else if((cube[11][0] == 6 && cube[3][0] == 6) && (cube[6][2] == cube[14][2]))
        {
            mouv_B();
        }


        if((cube[4][0] == 6 && cube[4][2] == 6) && (cube[2][0] == cube[2][2]))
        {
            reverse(mouv_F);
            mouv_L();
        }
        else if((cube[4][2] == 6 && cube[12][2] == 6) && (cube[5][0] == cube[13][0]))
        {
            reverse(mouv_R);
        }
        else if((cube[12][0] == 6 && cube[12][2] == 6) && (cube[15][0] == cube[15][2]))
        {
            reverse(mouv_R);
            mouv_L();
        }
        else if((cube[4][0] == 6 && cube[12][0] == 6) && (cube[3][2] == cube[11][2]))
        {
            mouv_L();
        }


        if((cube[5][0] == 6 && cube[5][2] == 6) && (cube[0][2] == cube[2][2]))
        {
            mouv_R();
            reverse(mouv_B);
        }
        else if((cube[5][2] == 6 && cube[13][2] == 6) && (cube[6][0] == cube[14][0]))
        {
            reverse(mouv_B);
        }
        else if((cube[13][0] == 6 && cube[13][2] == 6) && (cube[15][2] == cube[17][2]))
        {
            reverse(mouv_R);
            reverse(mouv_B);
        }
        else if((cube[5][0] == 6 && cube[13][0] == 6) && (cube[4][2] == cube[12][2]))
        {
            mouv_F();
        }


        if((cube[6][0] == 6 && cube[6][2] == 6) && (cube[0][0] == cube[0][2]))
        {
            reverse(mouv_L);
            mouv_R();
        }
        else if((cube[6][2] == 6 && cube[14][2] == 6) && (cube[3][0] == cube[11][0]))
        {
            reverse(mouv_L);
        }
        else if((cube[14][0] == 6 && cube[14][2] == 6) && (cube[17][0] == cube[17][2]))
        {
            reverse(mouv_B);
            reverse(mouv_L);
        }
        else if((cube[6][0] == 6 && cube[14][0] == 6) && (cube[5][2] == cube[13][2]))
        {
            mouv_R();
        }

    }

}

int test_2W_bottom()
{

    if(gamemode == 0)
    {

            if((cube[10][0] == 6 && cube[11][0] == 6) && cube[6][0] == cube[6][1])
            {
                return 1;
            }
            else if((cube[10][0] == 6 && cube[10][1] == 6) && cube[7][0] == cube[7][1])
            {
                mouv_D();
                mouv_D();
                mouv_D();
                return 1;
            }
            else if((cube[10][1] == 6 && cube[11][1] == 6) && cube[8][0] == cube[8][1])
            {
                mouv_D();
                mouv_D();
                return 1;
            }
            else if((cube[11][0] == 6 && cube[11][1] == 6) && cube[9][0] == cube[9][1])
            {
                mouv_D();
                return 1;
            }
            else
            {
                return 0;
            }

    }
    else if(gamemode == 1)
    {

            if((cube[15][0] == 6 && cube[17][0] == 6) && cube[11][0] == cube[11][2])
            {
                return 1;
            }
            else if((cube[15][0] == 6 && cube[15][2] == 6) && cube[12][0] == cube[12][2])
            {
                mouv_D();
                mouv_D();
                mouv_D();
                return 1;
            }
            else if((cube[15][2] == 6 && cube[17][2] == 6) && cube[13][0] == cube[13][2])
            {
                mouv_D();
                mouv_D();
                return 1;
            }
            else if((cube[17][0] == 6 && cube[17][2] == 6) && cube[14][0] == cube[14][2])
            {
                mouv_D();
                return 1;
            }
            else
            {
                return 0;
            }

    }

return -1;

}

int test_top()
{

int var = 0;

if(gamemode == 1) var = 1;

    for(int i=0;i<4;i++)
    {

        if(cube[1+var][1+var] == 6)
        {
            switch(i)
            {
            case 1:
                no_mouv = 1;
                mouv_U();
                mouv_U();
                mouv_U();
                no_mouv = 0;
                break;
            case 2:
                no_mouv = 1;
                mouv_U();
                mouv_U();
                no_mouv = 0;
                break;
            case 3:
                no_mouv = 1;
                mouv_U();
                no_mouv = 0;
                break;
            }

            return 1;

        }

        no_mouv = 1;
        mouv_U();
        no_mouv = 0;

    }

return 0;

}

int test_topLeft()
{

int var = 0;

if(gamemode == 1) var = 1;

    for(int i=0;i<4;i++)
    {

        if(cube[2+var][1+var] == 6)
        {

            switch(i)
            {
            case 1:
                no_mouv = 1;
                mouv_U();
                mouv_U();
                mouv_U();
                no_mouv = 0;
                break;
            case 2:
                no_mouv = 1;
                mouv_U();
                mouv_U();
                no_mouv = 0;
                break;
            case 3:
                no_mouv = 1;
                mouv_U();
                no_mouv = 0;
                break;
            }

            return 1;

        }

        no_mouv = 1;
        mouv_U();
        no_mouv = 0;

    }

    return 0;
}

int test_topRight()
{

    int var = 0;

    if(gamemode == 1) var = 1;

    for(int i=0;i<4;i++)
    {

        if(cube[4+var][0] == 6)
        {

            switch(i)
            {
            case 1:
                no_mouv = 1;
                mouv_U();
                mouv_U();
                mouv_U();
                no_mouv = 0;
                break;
            case 2:
                no_mouv = 1;
                mouv_U();
                mouv_U();
                no_mouv = 0;
                break;
            case 3:
                no_mouv = 1;
                mouv_U();
                no_mouv = 0;
                break;
            }

            return 1;

        }

        no_mouv = 1;
        mouv_U();
        no_mouv = 0;

    }

    return 0;
}

int test_bottomLeft()
{

int var = 0, var2 = 0;

if(gamemode == 1){ var = 5; var2 = 1;}


    for(int i=0;i<4;i++)
    {

        if(cube[7+var][1+var2] == 6)
        {

            switch(i)
            {
            case 1:
                no_mouv = 1;
                mouv_D();
                mouv_D();
                mouv_D();
                no_mouv = 0;
                break;
            case 2:
                no_mouv = 1;
                mouv_D();
                mouv_D();
                no_mouv = 0;
                break;
            case 3:
                no_mouv = 1;
                mouv_D();
                no_mouv = 0;
                break;
            }

            return 1;

        }

        no_mouv = 1;
        mouv_D();
        no_mouv = 0;

    }

    return 0;
}

int test_bottomRight()
{

int var = 0;

if(gamemode == 1) var = 5;

    for(int i=0;i<4;i++)
    {

        if(cube[8+var][0] == 6)
        {

            switch(i)
            {
            case 1:
                no_mouv = 1;
                mouv_D();
                mouv_D();
                mouv_D();
                no_mouv = 0;
                break;
            case 2:
                no_mouv = 1;
                mouv_D();
                mouv_D();
                no_mouv = 0;
                break;
            case 3:
                no_mouv = 1;
                mouv_D();
                no_mouv = 0;
                break;
            }

            return 1;

        }

        no_mouv = 1;
        mouv_D();
        no_mouv = 0;

    }

    return 0;
}


