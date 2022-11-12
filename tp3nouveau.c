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

void remplirMatrice(matrice_creuse* m, int N, int M) {
    //initialisation des attributs de m
    m->Ncolonnes=M;
    m->Nlignes=N;
    m->tab_lignes=malloc(N*sizeof(liste_ligne));
    int k1;

    //initialisation des pointeurs d'éléments
    element *elementactif=NULL;
    element *elementk=NULL;

    //initialisation des pointeurs sur les lignes
    for (int i=0;i<N;i++){
        m->tab_lignes[i]=NULL;
    }

    for (int i=0;i<N;i++) { //parcourt les lignes
        elementactif = m->tab_lignes[i];//on se place sur la première ligne
        for (int j=0;j<M;j++){ //parcourt les colonnes
            printf("\nEntrez un chiffre positif, négatif ou nul : ");
            scanf("%d", &k1);

            //printf("\n%d - %d\n",i,j);
            if(k1!=0){//si le chiffre entré est différent de zéro
                elementk = creerElement(j,k1);//création d'un nouvel élément

                if (m->tab_lignes[i]==NULL){//si c'est le premier élément non nul de la ligne
                    m->tab_lignes[i]=elementk;//on l'insère au début de la ligne
                } else {
                    elementactif->suivant=elementk;//sinon on l'insère après le dernier élément inséré de la ligne
                }
                elementactif = elementk;//element actif pointe sur le nouvel élément dernièrement inséré
            }
        }
    }
}




void afficherMatrice(matrice_creuse m){
    element *elementactif;

    for (int i=0;i<m.Nlignes;i++) { //parcourt les lignes
        elementactif = m.tab_lignes[i]; //on se place sur la première ligne

        for (int j=0;j<m.Ncolonnes;j++){ //parcourt les colonnes
            if (elementactif!=NULL){ //si le pointeur elementactif est non nul
                if (elementactif->col == j) { //si la colonne d'elementactif est égale à la colonne j
                    printf("%d  ", elementactif->val); //alors on affiche la valeur de l'élément
                    elementactif = elementactif->suivant; //on passe à l'élément suivant
                } else {
                    printf("0  "); //sinon on affiche 0
                }
            } else {
                printf("0  "); //sinon on affiche 0
            }
        }
        printf("\n");
    }
    printf("\n");
}


void afficherMatriceListes(matrice_creuse m) {
    element *elementactif;

    for (int i=0;i<m.Nlignes;i++) { //parcourt les lignes
        elementactif = m.tab_lignes[i];
        //printf("\n");
        if (elementactif==NULL){
            printf("NULL\n");
        } else {
            while (elementactif!=NULL){
                printf("(%d ; %d) -> ",elementactif->col, elementactif->val);
                elementactif=elementactif->suivant;
            }
            printf("NULL\n");
        }

    }
}

int rechercherValeur(matrice_creuse m, int i, int j) {

    element *elementactif; //on crée un pointeur sur un élément
    elementactif=m.tab_lignes[i]; //on le positionne sur la ligne demandée

    while (elementactif!=NULL) { //tant qu'elementactif est non nul
        if (elementactif->col==j){ //on se trouve sur la cible
            return elementactif->val; //on retourne la valeur de la cible
        } else if (elementactif->col>j) { //l'élément à la ligne i et la colonne j n'existe pas, donc la valeur est nulle
            return 0; //on retourne 0
        }
        elementactif=elementactif->suivant; //on passe à l'élément suivant
    }
    return 0;
}


void affecterValeur(matrice_creuse m, int i, int j, int val) {

    if (i<0 || j<0 || i>m.Nlignes-1 || j>m.Ncolonnes-1) { //si les valeurs de i et j données par l'utilisateur ne sont pas bonnes
        return;//on sort du programme
    }

    if (m.tab_lignes[i]==NULL) {//si la ligne est remplie de 0
        if (val==0) { //si on insère une valeur nulle, on ne fait rien
            return;
        } else {
            m.tab_lignes[i]= creerElement(j,val);//on crée l'élément et on met son adresse dans m.tab_lignes[i]
            return;
        }
    }

    element *elementactif=m.tab_lignes[i];//on se place au début de la ligne donnée par l'utilisateur

    if (j<m.tab_lignes[i]->col) { //on se trouve après la cible
        if(val==0){ //si on insère une valeur nulle, on ne fait rien
            return;
        } else { //dans ce cas, il faut insérer entre m.tab_lignes[i] et elementactif
            m.tab_lignes[i]= creerElement(j,val);
            m.tab_lignes[i]->suivant=elementactif;
        }
    } else if (j==m.tab_lignes[i]->col) { //dans ce cas, on se trouve sur la cible
        if(val==0){ //dans ce cas, il faut supprimer le premier élément de la ligne
            elementactif=m.tab_lignes[i];
            m.tab_lignes[i]=m.tab_lignes[i]->suivant;
            free(elementactif);
            return;
        } else { //dans ce cas, il faut changer la valeur du premier élément de la ligne
            m.tab_lignes[i]->val=val;
            return;
        }
    }

    element *elementp=m.tab_lignes[i];
    element *nouvelelement=NULL;
    elementactif=elementp->suivant;

    while (elementactif!=NULL) {
        if (elementactif->col==j) { //on se trouve sur la cible, donc l'élément existe déjà
            if (val==0) { //si on insère une valeur nulle, il faut supprimer l'élément
                elementp->suivant = elementactif->suivant;
                free(elementactif);
                return;
            } else { //sinon on met à jour la valeur de l'élément
                elementactif->val=val;
                return;
            }
        } else if (elementactif->col>j) { //on se trouve après la cible
            if (val==0){ //si on insère une valeur nulle, on ne fait rien
                return;
            } else {//on crée un nouvel élément qu'on insère entre élément p et élément actif
                    nouvelelement = creerElement(j, val);
                    nouvelelement->suivant = elementactif;
                    elementp->suivant = nouvelelement;
                    return;
            }
        }

        //déplacements des deux pointeurs
        elementp=elementactif; //elementp pointe sur elementactif
        elementactif=elementactif->suivant; //elementactif pointe sur le suivant
    }
}

int testPointeur(element* elementp, element* elementactif) {
    if (elementp==NULL && elementactif==NULL) {
        return 0; //ligne vide
    }

    if (elementp==NULL && elementactif!=NULL) {
        return 1; //on se trouve en début de ligne
    }

    if (elementp!=NULL && elementactif!=NULL) {
        return 2; //on se trouve en milieu de ligne
    }

    if (elementp!=NULL && elementactif==NULL) {
        return 3; //on se trouve en fin de ligne
    }
    return -1; //erreur
}

void additionerMatrices(matrice_creuse m1, matrice_creuse m2) {

    if (m1.Ncolonnes!=m2.Ncolonnes || m1.Nlignes!=m2.Nlignes) {
        //printf("Erreur : indices non compatibles\n");
        return;
    }

    int l=0;
    element* elementactif1;
    element* elementactif2;
    element *elementp1;
    element *elementp2;
    int situationm1;
    int situationm2;
    int compteur;


    while (l<m1.Nlignes) {
        elementactif1 = m1.tab_lignes[l];
        elementactif2 = m2.tab_lignes[l];
        elementp1=NULL;
        elementp2=NULL;
        //printf("LIGNE %d\n",l);
        compteur=0;

        do {
            //printf("Compteur : %d\n",compteur);
            situationm1=testPointeur(elementp1,elementactif1);
            situationm2=testPointeur(elementp2,elementactif2);

            if(situationm2==0){ //on a une ligne vide à additionner
                //printf("Rien.\n");
                elementactif1=NULL;//pour assurer la sortie de la boucle
            }

            if(situationm1==0 && situationm2==1){ //on se trouve sur une ligne vide de m1 et en début de ligne de m2
                //printf("0 et 1 ou plus\n");
                m1.tab_lignes[l]=elementactif2;
                m2.tab_lignes[l]=NULL;
                elementactif2=NULL;
            }

            if(situationm1==1 && situationm2==1) { //on se trouve en début de lignes sur les 2 matrices
                //printf("1 et 1\n");
                if (elementactif1->col == elementactif2->col){
                    //printf("même colonne\n");
                    if (elementactif1->val + elementactif2->val != 0) { //la somme est non nulle
                        //printf("\nOn additionne les valeurs des colonnes de même rang.\n");
                        elementactif1->val = elementactif1->val + elementactif2->val; //addition dans m1

                        //on supprime l'elementactif2
                        m2.tab_lignes[l] = elementactif2->suivant;
                        free(elementactif2);
                        elementactif2 = m2.tab_lignes[l];

                        elementp1 = elementactif1;
                        elementactif1 = elementactif1->suivant;
                    } else { //la somme est nulle
                        m1.tab_lignes[l] = elementactif1->suivant;
                        free(elementactif1);
                        elementactif1 = m1.tab_lignes[l];

                        m2.tab_lignes[l] = elementactif2->suivant;
                        free(elementactif2);
                        elementactif2 = m2.tab_lignes[l];

                    }
                } else if (elementactif1->col < elementactif2->col) {//On passe à l'élément suivant dans m1.
                    //printf("colonne1<colonne2\n");
                    elementp1=elementactif1;
                    elementactif1=elementactif1->suivant;
                } else if (elementactif1->col > elementactif2->col) { //On insère elementactif2 entre m1.tab_lignes et elementactif1
                    m1.tab_lignes[l]=elementactif2;
                    m2.tab_lignes[l]=elementactif2->suivant;
                    elementactif2->suivant = elementactif1;
                    elementactif2=m2.tab_lignes[l];
                    elementp1=m1.tab_lignes[l];
                    //printf("colonne1>colonne2\n");
                }
            }

            if(situationm1==2 && situationm2==1) { //on se trouve en début de ligne de m2 et en milieu de ligne de m1
                //printf("2 et 1\n");
                if (elementactif2->col == elementactif1->col){
                    if (elementactif1->val + elementactif2->val != 0) { //la somme est non nulle
                        //printf("\nOn additionne les valeurs des colonnes de même rang.\n");
                        elementactif1->val = elementactif1->val + elementactif2->val; //addition dans m1

                        //on supprime l'elementp2
                        m2.tab_lignes[l]=elementactif2->suivant;
                        free(elementactif2);
                        elementactif2=m2.tab_lignes[l];
                        //on passe à l'élément suivant dans m1
                        elementp1 = elementactif1;
                        elementactif1 = elementactif1->suivant;
                    } else { //la somme est nulle
                        elementp1->suivant=elementactif1->suivant;
                        free(elementactif1);
                        elementactif1=elementp1->suivant;

                        m2.tab_lignes[l]=elementactif2->suivant;
                        free(elementactif2);
                        elementactif2=m2.tab_lignes[l];
                    }
                } else if (elementactif2->col < elementactif1->col) { //On insère elementactif2 entre elementp1 et elementactif1
                    m2.tab_lignes[l]=elementactif2->suivant;

                    elementp1->suivant=elementactif2;
                    elementp1=elementactif2;

                    elementp1->suivant=elementactif1;
                    elementactif2= m2.tab_lignes[l];

                } else if (elementactif2->col > elementactif1->col) { //On passe à l'élément suivant dans m1.
                    elementp1=elementactif1;
                    elementactif1=elementactif1->suivant;
                }
            }

            if(situationm1==3 && situationm2==1) { //si on se trouve en fin de ligne de m1 et en début de ligne de m2
                elementp1->suivant=elementactif2;
                m2.tab_lignes[l]=NULL;
                elementactif2=NULL;
                elementactif1=NULL;
                elementp1=NULL;
            }

            compteur++;
            //if (compteur>20){printf("\nboucle infinie\n"); }

        } while ((elementactif2!=NULL || elementactif1!=NULL) && compteur<(m1.Nlignes*m1.Ncolonnes));

        l++;
    }

}


int nombreOctetsGagnes(matrice_creuse m) {
    int compteur_elements=0;//compteur du nb d'éléments non nuls dans une matrice

    element *elementactif=NULL;

    for (int i=0;i<m.Nlignes;i++) { //parcourt les lignes
        elementactif=m.tab_lignes[i];

        while(elementactif!=NULL){
            compteur_elements++;
            elementactif=elementactif->suivant;
        }
    }

    int taille_tableau = m.Nlignes*m.Ncolonnes*sizeof(int);
    int taille_matrice_creuse = (m.Nlignes)*sizeof(liste_ligne *); //N lignes de tab[i] + le pointeur sur le tab[i]
    taille_matrice_creuse+=compteur_elements*sizeof(element); //ajout du nb éléments non vides * taille(element)
    //printf("Taille tableau : %d\n",taille_tableau);
    //printf("Taille matrice creuse : %d\n",taille_matrice_creuse);
    return taille_tableau-taille_matrice_creuse;
}

void libererMatrice(matrice_creuse *m){
    element *elementactif=NULL;
    element *elementp=NULL;

    for (int i=0;i<m->Nlignes;i++){
        elementactif=m->tab_lignes[i];
        while(elementactif!=NULL){
            elementp=elementactif;
            elementactif=elementactif->suivant;
            free(elementp);
        }
    }
    free(m->tab_lignes);
    free(m);
}

