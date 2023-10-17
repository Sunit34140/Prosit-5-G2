#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<unistd.h>

// Constantes
#define const int Nb_Capteurs = x
#define const int Nb_Val = 10

// Variables locales (boucle)
static int ind_moy = 0;
struct Capteurs {
    int Nb_erreur;
};
struct Capteurs Moy_gliss[Nb_Val];

// PROCEDURE LECTURE(POINTEUR_TABLEAU, POINTEUR_ERREURS)
void Lecture(float *Tab_Val, struct Capteurs *Erreurs) {
    float Mesure;
    float Erreur;
    for (int i = 0; i < Nb_Capteurs; i++) {
        Mesure = 0;
        Erreur = Lecture_capteur(&Mesure, i); // Pour le moment, une fonction simule la lecture du capteur avec une valeur aléatoire
        if (Erreur) {
            (Erreurs[i]).Nb_erreur++;
        } else {
            Add_Val(Tab_Val, Mesure);
        }
    }
}

// PROCEDURE ADD_VAL(POINTEUR_TABLEAU, VALEUR)
void Add_Val(float *Tab_Moy, float Val) {
    Tab_Moy[ind_moy] = Val;
    if (ind_moy >= Nb_Val - 1) {
        ind_moy = 0;
    } else {
        ind_moy++;
    }
}