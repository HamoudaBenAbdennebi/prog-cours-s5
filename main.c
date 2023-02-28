#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
int main()
{
    char chemin[20];
    patient p;
    liste tete =NULL;
    saisir_patient(&p,tete);
    afficher_patient(p,tete);
    l=ajout_patient(l,p);
    supprime_patient(tete);
    consulter_salle_attente(tete);
    sauvegarder_patient(tete,"chemin.txt");
    return 0;
}
