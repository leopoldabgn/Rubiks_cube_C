#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#if defined(_WIN64) || defined(_WIN32)
#define OS_WINDOWS
#endif

#include <stdlib.h>
#include <stdio.h>

#define H 18
#define W 3

extern int cube[H][W], difficulty, position, no_mouv, PLL_skip, OLL_skip, gamemode;
extern char solution[1000], empty_file[1000], rep[100];

void sleep();
void clear();
int get_char();
void clear_buffer();

void display_solve();

// MAIN

void scramble(int nombreMax);
void lancer_jeu();

//FONCTION IA

void IA();
void test_if_2W();
int test_2W_bottom();
int test_top();
int test_topLeft();
int test_topRight();
int test_bottomRight();
int test_bottomLeft();
void add_solve_mouv(char lettre);

// FONCTIONS MOUVEMENTS CUBE

void reverse(void (*pf)(int (*)[W]));
void mouv_F();
void mouv_D();
void mouv_U();
void mouv_L();
void mouv_B();
void mouv_R();
void mouv_E();
void mouv_M();

//FONCTIONS FORMULES OLL/PLL

void PLL_T();
void PLL_Y();
void OLL_21();
void OLL_22();
void OLL_23();
void OLL_24();
void OLL_25();
void OLL_26();
void OLL_27();
void test_faceBas();
void lancer_PLL();

//FONCTIONS AFFICHAGE CUBE ET AUTRES FONCTIONS

void afficherCube();
void affCarre(int couleurcarre);
int nombreAleatoire(int nombreMax);
void reset_cube(int with_colors);
void ask_scramble();

//FONCTIONS CHANGER COULEUR CONSOLE
#ifdef OS_WINDOWS

#define NOIR 0
#define BLEU_FONCE 1
#define VERT 2
#define BLEU_GRIS 3
#define MARRON 4
#define POURPRE 5
#define KAKI 6
#define GRIS_CLAIR 7
#define GRIS 8
#define BLEU 9
#define VERT_FLUO 10
#define TURQUOISE 11
#define ROUGE 12
#define ROSE_FLUO 13
#define JAUNE_FLUO 14
#define BLANC 15

#else

#define NOIR 30
#define ROUGE 31
#define VERT 32
#define JAUNE_FLUO 33
#define BLEU 34
#define ROSE_FLUO 35
#define CYAN 36
#define BLANC 37

#endif

void setColor(int t,int f);
int getColor(char c);

#endif // FUNCTIONS_H_INCLUDED
