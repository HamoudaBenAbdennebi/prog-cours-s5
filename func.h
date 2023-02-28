#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
typedef struct
{
    char nom[20];
    char prenom[20];
    int rdv;
}patient;
typedef struct cellule Cellule;
struct Cellule
{
    patient val;
    struct cellule *suiv
};
typedef Cellule *liste;
void saisir_patient(patient *p);
void afficher_patient(patient p);
liste ajout_patient(liste tete,patient p);
void rendez_vous(liste tete,int *rdv , int *sansrdv);
liste supprime_patient(liste tete);
void consulter_salle_attente(liste tete);


#endif // FONCTION_H_INCLUDED
