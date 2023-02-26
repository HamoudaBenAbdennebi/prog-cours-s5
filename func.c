#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

void saisirPatient(Patient *p) {
    printf("Saisir le nom du patient : ");
    scanf("%s", p->nom);
    printf("Saisir le prenom du patient : ");
    scanf("%s", p->prenom);
    printf("Le patient a-t-il un rendez-vous ? (0: non, 1: oui) ");
    scanf("%d", &p->rdv);
}

void afficherPatient(Patient p) {
    printf("%s %s", p.nom, p.prenom);
    if (p.rdv == 1) {
        printf(" (avec rendez-vous)\n");
    } else {
        printf(" (sans rendez-vous)\n");
    }
}

liste AjoutPatient(liste tete, Patient P) {
    Cellule *new_cell = (Cellule*) malloc(sizeof(Cellule));
    new_cell->p = P;
    new_cell->suivant = NULL;

    if (tete == NULL) {
        tete = new_cell;
    } else {
        Cellule *courant = tete;
        while (courant->suivant != NULL) {
            courant = courant->suivant;
        }
        courant->suivant = new_cell;
    }

    return tete;
}

void RendezVous(liste tete, int *rdv, int *sansRdv) {
    *rdv = 0;
    *sansRdv = 0;

    Cellule *courant = tete;
    while (courant != NULL) {
        if (courant->p.rdv == 1) {
            (*rdv)++;
        } else {
            (*sansRdv)++;
        }
        courant = courant->suivant;
    }
}
//p2
liste SupprimePatient(liste tete) {
    // Vérifier si la liste est vide
    if (tete == NULL) {
        printf("La liste est vide.\n");
        return tete;
    }

    // Chercher le premier patient avec rendez-vous
    Cellule* prec = NULL;
    Cellule* cour = tete;
    while (cour != NULL && cour->patient.rdv == 0) {
        prec = cour;
        cour = cour->suivant;
    }

    // Si aucun patient n'a de rendez-vous, supprimer le premier patient de la liste
    if (cour == NULL) {
        Cellule* temp = tete;
        tete = tete->suivant;
        free(temp);
    } else {  // Sinon, supprimer le premier patient avec rendez-vous
        if (prec == NULL) {
            tete = cour->suivant;
        } else {
            prec->suivant = cour->suivant;
        }
        free(cour);
    }

    return tete;
}
void ConsulterSalleAttente(liste tete) {
    if (tete == NULL) {
        printf("La salle d'attente est vide.\n");
        return;
    }

    int i = 1;
    printf("Patients avec rendez-vous :\n");
    Cellule *p = tete;
    while (p != NULL) {
        if (p->patient.rdv == 1) {
            printf("%d - ", i);
            afficherPatient(p->patient);
            i++;
        }
        p = p->suivant;
    }

    i = 1;
    printf("Patients sans rendez-vous :\n");
    p = tete;
    while (p != NULL) {
        if (p->patient.rdv == 0) {
            printf("%d - ", i);
            afficherPatient(p->patient);
            i++;
        }
        p = p->suivant;
    }
}
void sauvegarderPatients(liste tete, char *chemin) {
    FILE *fichier = fopen(chemin, "w");
    if (fichier == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier %s.\n", chemin);
        return;
    }

    Cellule *courant = tete;
    while (courant != NULL) {
        fprintf(fichier, "%s %s %d\n", courant->patient.nom, courant->patient.prenom, courant->patient.rdv);
        courant = courant->suivant;
    }

    fclose(fichier);
}
liste recupererListePatients(liste tete, char* chemin) {
    FILE* fichier = fopen(chemin, "r");
    if (fichier == NULL) {
        fprintf(stderr, "Erreur : impossible d'ouvrir le fichier %s\n", chemin);
        return tete;
    }

    Patient p;
    while (fscanf(fichier, "%s %s %d", p.nom, p.prenom, &p.rdv) == 3) {
        tete = AjoutPatient(tete, p);
    }

    fclose(fichier);
    return tete;
}
int afficherMenu() {
    int choix;
    printf("=== Cabinet Medical ===\n");
    printf("1. Ajouter un patient\n");
    printf("2. Afficher les patients\n");
    printf("3. Ajouter un rendez-vous\n");
    printf("4. Supprimer un patient\n");
    printf("5. Consulter la salle d'attente\n");
    printf("6. Sauvegarder la liste des patients\n");
    printf("7. Charger la liste des patients\n");
    printf("0. Quitter\n");

    do {
        printf("\nEntrez votre choix : ");
        scanf("%d", &choix);
    } while (choix < 0 || choix > 7);

    return choix;
}
