#ifndef PATIENT_H_INCLUDED
#define PATIENT_H_INCLUDED

typedef struct patient {
    char nom[20];
    char prenom[20];
    int rdv; // 0 si pas de rendez-vous, 1 si rendez-vous
} Patient;

typedef struct cellule {
    Patient p;
    struct cellule *suivant;
} Cellule;

typedef Cellule* liste;

void saisirPatient(Patient *p);
void afficherPatient(Patient p);
liste AjoutPatient(liste tete, Patient P);
void RendezVous(liste tete, int *rdv, int *sansRdv);
liste SupprimePatient(liste tete);
void ConsulterSalleAttente(liste tete);
void sauvegarderPatients(liste tete, char *chemin);
liste recupererListePatients(char *chemin);
int afficherMenu();

#endif // PATIENT_H_INCLUDED
