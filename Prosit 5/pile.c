#include <stdio.h>
#include <stdlib.h>

struct pile{
    int valeur;
    struct pile* valeur_precedente;
};
typedef struct pile Pile;

Pile* add_stack(int v, Pile* preced){
    Pile* p = malloc(sizeof(Pile));
    p->valeur = v;
    p->valeur_precedente = preced;
    return p;
}

void afficher_pile(Pile* sommet){
    Pile* actuel = sommet;
    while (actuel != NULL){
        printf("%d \n", actuel->valeur);
        actuel = actuel->valeur_precedente;
    }
}

Pile* depiler(Pile* ma_pile){
    if (ma_pile != NULL){
        Pile* temp = ma_pile;
        ma_pile = ma_pile->valeur_precedente;
        free(temp);
    }
    return ma_pile;
}

void main(){
    Pile* ma_pile = NULL;
    
    ma_pile = add_stack(42, ma_pile);
    ma_pile = add_stack(7, ma_pile);
    ma_pile = add_stack(15, ma_pile);

    printf("Contenu de la pile :\n");
    afficher_pile(ma_pile);
    depiler(ma_pile);
}