#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"


// Fonction qui permet de cr�er un �lement d'une liste cha�n�e
// Params : indice de colonne (int), valeur de l'�lement (int)
// Return : pointeur vers le nouvele �lement cr��
element *creerElement(int colonne, int valeur) {
    element *nouvelElement = malloc(sizeof(element));
    nouvelElement->col = colonne;
    nouvelElement->val = valeur;
    nouvelElement->suivant = NULL;
    return nouvelElement;
}

int remplirInstance(int i, int j){
    if(i==0) {
        return 1;
    } else if (i==1) {
        if (j%2==0){
            return 0;
        } else {
            return 2;
        }
    } else if (i==2) {
        return 0;
    } else {
        return rand()%10;
    }
}



void remplirMatrice(matrice_creuse* m, int N, int M) {

    m->Ncolonnes=M;
    m->Nlignes=N;
    m->tab_lignes=malloc(N*sizeof(liste_ligne));

    int k1;
    element *elementactif=NULL;
    element *elementk=NULL;
    int bool=0; //faux

    for (int i=0;i<N;i++){
        m->tab_lignes[i]=NULL;
    }

    for (int i=0;i<N;i++) { //parcourt les lignes
        elementactif = m->tab_lignes[i];
        for (int j=0;j<M;j++){ //parcourt les colonnes
            printf("Entrez un chiffre positif, négatif ou nul : \n");
            if (bool==1){
                scanf("%d", &k1);
            } else {
                k1=remplirInstance(i,j);
            }
            printf("\n%d - %d\n",i,j);
            if(k1!=0){
                elementk = creerElement(j,k1);
                if (m->tab_lignes[i]==NULL){
                    m->tab_lignes[i]=elementk;
                } else {
                    elementactif->suivant=elementk;
                }
                elementactif = elementk;
            }
        }
    }
    printf("\n\nfin remplir matrice\n\n");
}




void afficherMatrice(matrice_creuse m){
    element *elementactif;

    for (int i=0;i<m.Nlignes;i++) { //parcourt les lignes
        elementactif = m.tab_lignes[i];

        for (int j=0;j<m.Ncolonnes;j++){ //parcourt les colonnes
            if (elementactif!=NULL){
                if ((*elementactif).col == j) {
                    printf("%d  ", (*elementactif).val);
                    elementactif = elementactif->suivant;
                } else {
                    printf("0  ");
                }
            } else {
                printf("0  ");
            }
        }
        printf("\n");
    }
}


void afficherMatriceListes(matrice_creuse m) {
    element *elementactif;

    printf("{");
    for (int i=0;i<m.Nlignes;i++) { //parcourt les lignes
        elementactif = m.tab_lignes[i];

        printf("(");

        for (int j=0;j<m.Ncolonnes;j++){ //parcourt les colonnes
            if (elementactif!=NULL){
                if ((*elementactif).col == j) {
                    printf("%d", (*elementactif).val);
                    elementactif = elementactif->suivant;
                } else {
                    printf("0");
                }
            } else {
                printf("0");
            }
            if (j!=m.Ncolonnes-1) { printf(","); }
        }
        printf(")");
        if (i!=m.Nlignes-1){ printf(","); }
    }
    printf("}");
}

void rechercher(matrice_creuse m) {
    int i,j;
    printf("\nEntrez un numéro de ligne : ");
    scanf("%d",&i);
    printf("\nEntrez un numéro de colonne : ");
    scanf("%d",&j);

    if(i>m.Nlignes || i<0){
        printf("Erreur : indice de ligne non compatible\n");
    } else if (j>m.Ncolonnes || j<0) {
        printf("Erreur : indice de colonne non compatible\n");
    } else {
        int p=rechercherValeur(m,i,j);
        printf("Valeur : %d",p);
    }
}

int rechercherValeur(matrice_creuse m, int i, int j) {

    element *elementactif;
    elementactif=m.tab_lignes[i];

    while (elementactif!=NULL) {
        if (elementactif->col==j){ //sur la cible
            return elementactif->val;
        } else if (elementactif->col>j) { //avant la cible
            return 0;
        }
        elementactif=elementactif->suivant;
    }
    return 0;
}


void affecterValeur(matrice_creuse m, int i, int j, int val) {

    /*Ecrire ici le code de cette fonction*/

}


void additionerMatrices(matrice_creuse m1, matrice_creuse m2) {

    /*Ecrire ici le code de cette fonction*/

}


//int nombreOctetsGagnes(matrice_creuse m) {

    /*Ecrire ici le code de cette fonction*/

//}


