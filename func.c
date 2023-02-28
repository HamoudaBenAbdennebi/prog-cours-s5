#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
void saisir_patient(patient *p)
{
    printf("donner le nom\n");
    scanf("%s",p->nom);
    printf("donner le prenom\n");
    scanf("%s",p->prenom);
    do{
    printf("donner le rendez-vous\n");
    scanf("%d",&(p)->rdv);
    }while((p->rdv!=0) || (p->rdv!=1));
}
void afficher_patient(patient p)
{
    printf("le nom %s",p.nom);
    printf("\n");
    printf("le prenom %s",p.prenom);
    printf("\n");
    if(p.rdv==0)
    {
    printf("patient sans rdv\n");
    }
    else
    {
    printf("patient avec rdv\n");
    }
}
liste ajout_patient(liste tete,patient p)
{

struct Cellule *nouv,*parc;
nouv=(struct Cellule*)malloc(sizeof(struct Cellule));
nouv->val=p;
nouv->suiv=NULL;
if(tete==NULL)
{
    tete=nouv;
}
else
{
    while(parc->suiv !=NULL)
        parc=parc->suiv;
        parc->suiv=nouv;
}
return(tete);
}
void rendez_vous(liste tete,int *rdv , int *sansrdv)
{
    (*rdv)=0;
    (*sansrdv)=0;
    struct Cellule *tmp;
    tmp=tete;
        while(tmp!=NULL)
        {
            if(tmp->val.rdv==0)
                (*sansrdv)++;
            else
                (*rdv)++;
            tmp=tmp->suiv;
        }

}
liste supprime_patient(liste tete)
{
    liste p,q;
    int *rdv,*sansrdv;
    if(tete!=NULL)
    {
        rendez_vous(tete,&rdv,&sansrdv);
        if(rdv==0)
        {
            p=tete;
            tete=tete->suiv;
            free(p);
        }
        else
        {
            p=tete;
            q=tete;
            while(p->suiv!=NULL && p->val.rdv!=1)
            {
                q=p;
                p=p->suiv;
            }
            if(p==tete)
            {
                tete=tete->suiv;
                free(p);
            }
            else
            {
                q->suiv=p->suiv;
                free(p);
            }

        }
        return tete;
    }

}
void consulter_salle_attente(liste tete)
{
    liste p;
    if(tete==NULL)
    {
        printf("liste vide\n");
    }
    else{
        p=tete;
        while(p!=NULL)
        {
            if(p->val.rdv==1)
            {
                printf("%s %s",p->val.nom,p->val.prenom);

            }
             p=p->suiv;
        }
        p=tete;
        while(p!=Null)
        {
            if(p->val.rdv==0)
            {
                prinntf("%s %s",p->val.nom,p->val.prenom);
            }
            p=p->suiv;
        }

    }

}
void sauvegarder_patient(liste tete, char *chemin)
{
    liste p;
    FILE *f=NULL;
    f=fopen("chemin.txt","a");
    if(f!=NULL)
    {
        if(tete==NULL)
            printf("liste vide\n");
        else{
            p=tete;
            while(p!=NULL){
        fprintf("%s %s %d",p->val.nom,p->val.prenom,p->val.rdv);
        p=p->suiv;}
        }
        fclose(f);
    }
    else
    {
        printf("impossible d'ouvrir le fichier\n");
    }

}
