#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main() {
    liste tete = NULL;
    int choix;
    char chemin[100];
    int rdv = 0, sansRdv = 0;

    do {
        choix = afficherMenu();

        switch (choix) {
            case 1:
                printf("\nAjouter un patient :\n");
                Patient p;
                saisirPatient(&p);
                tete = AjoutPatient(tete, p);
                break;
            case 2:
                printf("\nListe des patients :\n");
                afficherListe(tete);
                break;
            case 3:
                printf("\nAjouter un rendez-vous :\n");
                ajouterRendezVous(tete);
                break;
            case 4:
                printf("\nSupprimer un patient :\n");
                tete = SupprimePatient(tete);
                break;
            case 5:
                printf("\nConsulter la salle d'attente :\n");
                ConsulterSalleAttente(tete);
                RendezVous(tete, &rdv, &sansRdv);
                printf("\nNombre de patients avec rendez-vous : %d\n", rdv);
                printf("Nombre de patients sans rendez-vous : %d\n", sansRdv);
                break;
            case 6:
                printf("\nSauvegarder la liste des patients :\n");
                printf("Entrez le chemin du fichier : ");
                scanf("%s", chemin);
                sauvegarderPatients(tete, chemin);
                break;
            case 7:
                printf("\nCharger la liste des patients :\n");
                printf("Entrez le chemin du fichier : ");
                scanf("%s", chemin);
                tete = recupererListePatients(tete, chemin);
                break;
            case 0:
                printf("\nAu revoir !\n");
                break;
        }
    } while (choix != 0);

    return 0;
}