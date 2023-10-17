#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<unistd.h>



int generateRandomNumber(int multiple) {
    int randomNumber = (rand() % 100 + 1)*multiple;

    if (rand() % 100 < 20) {
        randomNumber = 0;
    }

    return randomNumber;
}


void affichage_tableau(int *tableau, int taille, int multiple) {
    for (int i = 0; i < taille; i++) {
        float val = (float)tableau[i]/multiple;
        if (val - (int)val == 0.0) {
            printf("%d ", (int)val);
        } 
        else {
            printf("%.2f ", val);
        }
    }
    printf("\n");
}


void moyenne_mobile(int *moyenne, int *tab_capteurs, int nb_cap, int taille){
    int somme_tab = 0;
    int compteur_zero = 0;
    for (int i = 0; i < taille; i++) {
        if (tab_capteurs[i] != 0){
            somme_tab += tab_capteurs[i];
        }
        else{
            compteur_zero += 1;
        }
    }
    if (taille != compteur_zero){
        *moyenne = (int)somme_tab/(taille-compteur_zero);
    }
    else{
        *moyenne = 0;
    }
}


void decalage(int *tableau, int valeur, int taille, int *erreur, int multiple) {
    for (int i = 0; i < taille - 1; i++) {
        tableau[i] = tableau[i + 1];
    }
    tableau[taille - 1] = valeur;
    if (valeur == 0){
        *erreur = 1*multiple;
    }
    else{
        *erreur = 0;
    }
}   


void main() {
    const int multiple = 100;
    const int nb_val = 15;
    const int nb_capteur = 3;

    int tab_moyenne_mobile[nb_capteur];
    int tab_erreur[nb_capteur];
    for (int i = 0; i < nb_capteur; i++) {
        tab_erreur[i] = 0;
        tab_moyenne_mobile[i] = 0;
    }

    int val_cap1[nb_val];
    int val_cap2[nb_val];
    int val_cap3[nb_val];
    for (int i = 0; i < nb_val; i++) {
        val_cap1[i] = 0;
        val_cap2[i] = 0;
        val_cap3[i] = 0;
    }
    int *all_capteurs[] = {val_cap1, val_cap2, val_cap3};

    srand(time(NULL));

    for (int i=0; i<15;i++){
        for (int j=0; j<nb_capteur; j++){
            printf("Valeur du capteur %d: ", j+1);
            decalage(all_capteurs[j], generateRandomNumber(multiple), nb_val, &tab_erreur[j], multiple);
            affichage_tableau(all_capteurs[j], nb_val, multiple);
            moyenne_mobile(&tab_moyenne_mobile[j], all_capteurs[j], nb_capteur, nb_val);
        }

        printf("Tableau erreur : ");
        affichage_tableau(&tab_erreur,nb_capteur,multiple);

        printf("Moyenne mobile: ");
        affichage_tableau(&tab_moyenne_mobile,nb_capteur,multiple);

        printf("\n");
        sleep(1);
    }
}

