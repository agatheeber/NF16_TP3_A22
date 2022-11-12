#include <stdio.h>
#include <stdlib.h>
#include "tp3.h"



int main() {
    int continu=1; //booléen pour revenir au menu si on ne sélectionne pas 8.
    char* listemat[4];  //initialisation de la liste des matrices créées
    for (int i=0;i<4;i++){
        listemat[i]=NULL;
    }
//attribution mémoire des matrices
    matrice_creuse* m0= malloc(sizeof(matrice_creuse));
    matrice_creuse* m1=malloc(sizeof(matrice_creuse));
    matrice_creuse* m2=malloc(sizeof(matrice_creuse));
    matrice_creuse* m3=malloc(sizeof(matrice_creuse));

    while (continu==1){  //affichage menu
        printf("\n1. Remplir une matrice creuse");
        printf("\n2. Afficher une matrice creuse sous forme de tableau");
        printf("\n3. Afficher une matrice creuse sous forme de listes");
        printf("\n4. Donner la valeur d’un élément d’une matrice creuse");
        printf("\n5. Affecter une valeur à un élément d’une matrice creuse");
        printf("\n6. Additionner deux matrices creuses");
        printf("\n7. Calculer le gain en espace en utilisant cette représentation pour une matrice donnée");
        printf("\n8. Quitter");
        printf("\nSaisir une option : ");
        int x;
        scanf("%d",&x); //sélection du menu
        
        switch(x){
            case 1:
                printf(" saisir un nombre de lignes : ");
                int N;
                scanf("%d",&N);
                printf(" saisir un nombre de colonnes : ");
                int M;
                scanf("%d",&M);

                if (listemat[0]==NULL){
                    listemat[0]="m0";

                    remplirMatrice(m0,N,M);
                    printf("la matrice disponible créées est %s", listemat[0]);
                    break;
                }
                if (listemat[0]!=NULL && listemat[1]==NULL){ 
                    listemat[1]="m1";
                    remplirMatrice(m1,N,M);
                    printf("les matrices créées sont %s %s ", listemat[0], listemat[1]);
                    break;
                }
                if (listemat[0]!=NULL && listemat[1]!=NULL && listemat[2]==NULL){
                    listemat[2]="m2";
                    remplirMatrice(m2,N,M);
                    printf("les matrices créées sont %s %s %s", listemat[0], listemat[1],listemat[2]);
                    break;
                }
                if (listemat[0]!=NULL && listemat[1]!=NULL && listemat[2]!=NULL && listemat[3]==NULL){
                    listemat[3]="m3";
                    remplirMatrice(m3,N,M);
                    printf("les matrices créées sont %s %s %s %s", listemat[0], listemat[1],listemat[2], listemat[3]);
                    break;
                }
                break;

            case 2:
                printf("saisir le numéro de la matrice à afficher (les matrices disponibles sont %s %s %s %s)", listemat[0], listemat[1],listemat[2], listemat[3]);
                int a;
                scanf("%d",&a);
                switch(a){ //choix de la matrice à afficher
                    case 0: afficherMatrice(*m0);break;
                    case 1: afficherMatrice(*m1);break;
                    case 2: afficherMatrice(*m2);break;
                    case 3: afficherMatrice(*m3);break;
                    default:
                        printf("saisie incorrecte");
                        break;
                }
                break;

            case 3:
                printf("Saisir le numéro de la matrice à afficher (les matrices disponibles sont %s %s %s %s)", listemat[0], listemat[1],listemat[2], listemat[3]);
                int b;
                scanf("%d",&b);
                switch(b){
                    case 0: afficherMatriceListes(*m0);break;
                    case 1: afficherMatriceListes(*m1);break;
                    case 2: afficherMatriceListes(*m2);break;
                    case 3: afficherMatriceListes(*m3);break;
                    default:
                        printf("saisie incorrecte");
                        break;
                }
                break;

            case 4:
                printf("saisir le numéro de la matrice dont on souhaite afficher la valeur d'un coefficient(les matrices disponibles sont %s %s %s %s)", listemat[0], listemat[1],listemat[2], listemat[3]);
                int c;
                scanf("%d",&c);
                int i;
                int j;
                printf("Saisir le numéro de la ligne du coefficient à afficher");
                scanf("%d",&i);
                printf("Saisir le numéro de la colonne du coefficient à afficher");
                scanf("%d",&j);
                switch(c){
                    case 0 : printf("La valeur du coefficient %d-%d est %d",i,j,rechercherValeur(*m0,i,j));break;
                    case 1 : printf("La valeur du coefficient %d-%d est %d",i,j,rechercherValeur(*m0,i,j));break;
                    case 2 :printf("La valeur du coefficient %d-%d est %d",i,j,rechercherValeur(*m0,i,j));break;
                    case 3 :printf("La valeur du coefficient %d-%d est %d",i,j,rechercherValeur(*m0,i,j));break;
                    default:printf("Saisie incorrecte");break;
                }
                break;

            case 5:
                printf("Saisir le numéro de la matrice à laquelle on souhaite affecter la valeur d'un coefficient(les matrices disponibles sont %s %s %s %s)", listemat[0], listemat[1],listemat[2], listemat[3]);
                int d;
                scanf("%d",&d);
                int k;
                int l;
                int val;
                printf("Saisir la valeur que l'on souhaite affecter");
                scanf("%d",&val);
                printf("Saisir le numéro de la ligne du coefficient à modifier");
                scanf("%d",&k);
                printf("Saisir le numéro de la colonne du coefficient à modifier");
                scanf("%d",&l);
                switch(d){ //un cas pour une matrice
                    case 0 :
                        affecterValeur(*m0,k,l,val);
                        printf("La valeur du coefficient %d-%d est désormais %d",k,l,val);
                        break;

                    case 1 :
                        affecterValeur(*m1,k,l,val);
                        printf("La valeur du coefficient %d-%d est désormais %d",k,l,val);
                        break;

                    case 2 :
                        affecterValeur(*m2,k,l,val);
                        printf("La valeur du coefficient %d-%d est désormais %d",k,l,val);
                        break;

                    case 3 :
                        affecterValeur(*m3,k,l,val);
                        printf("La valeur du coefficient %d-%d est désormais %d",k,l,val);
                        break;

                    default:
                        printf("Saisie incorrecte");
                        break;
                }
                break;

            case 6 :
                printf("Saisir le numéro de la première matrice à additionner(les matrices disponibles sont %s %s %s %s)", listemat[0], listemat[1],listemat[2], listemat[3]);
                int c1; //choix de la matrice 1
                int c2; //choix de la matrice 2
                scanf("%d",&c1);

                printf("Saisir le numéro de deuxième matrice à additionner(les matrices disponibles sont %s %s %s %s)", listemat[0], listemat[1],listemat[2], listemat[3]);
                scanf("%d",&c2);
                switch(c1){ //matrice 1
                    case 0 :
                        switch (c2){ //matrice 2
                            case 0 : additionerMatrices(*m0,*m0);
                                break;
                            case 1 : additionerMatrices(*m0,*m1);
                                break;
                            case 2 : additionerMatrices(*m0,*m2);
                                break;
                            case 3 : additionerMatrices(*m0,*m3);
                                break;

                        }
                    case 1 :
                        switch (c2){
                            case 0 : additionerMatrices(*m1,*m0);
                                break;
                            case 1 : additionerMatrices(*m1,*m1);
                                break;
                            case 2 : additionerMatrices(*m1,*m2);
                                break;
                            case 3 : additionerMatrices(*m1,*m3);
                                break;

                        }
                    case 2 :
                        switch (c2){
                            case 0 : additionerMatrices(*m2,*m0);
                                break;
                            case 1 : additionerMatrices(*m2,*m1);
                                break;
                            case 2 : additionerMatrices(*m2,*m2);
                                break;
                            case 3 : additionerMatrices(*m2,*m3);
                                break;

                        }
                    case 3 :
                        switch (c2){
                            case 0 : additionerMatrices(*m0,*m0);
                                break;
                            case 1 : additionerMatrices(*m1,*m1);
                                break;
                            case 2 : additionerMatrices(*m2,*m2);
                                break;
                            case 3 : additionerMatrices(*m3,*m3);
                                break;

                        }

                }
                break;

            case 7 :
                printf("saisir le numéro de la matrice dont on souhaite afficher le nombre d'octets gagnés (les matrices disponibles sont %s %s %s %s)", listemat[0], listemat[1],listemat[2], listemat[3]);
                int e;
                scanf("%d",&e);
                switch(e){
                    case 0: printf("le nombre d'octets gagnés est %d",nombreOctetsGagnes(*m0));break;
                    case 1: printf("le nombre d'octets gagnés est %d",nombreOctetsGagnes(*m1));break;
                    case 2: printf("le nombre d'octets gagnés est %d",nombreOctetsGagnes(*m2));break;
                    case 3: printf("le nombre d'octets gagnés est %d",nombreOctetsGagnes(*m3));break;
                    default:
                        printf("saisie incorrecte");
                        break;
                }
                break;

            case 8: continu = 0; //sortie du menu puis libération de l'espace mémoire
                if (listemat[0]!=NULL && listemat[1]==NULL){ 
                    libererMatrice(m0);
                }
                if (listemat[0]!=NULL && listemat[1]!=NULL && listemat[2]==NULL){
                    libererMatrice(m0);
                    libererMatrice(m1);
                }
                if (listemat[0]!=NULL && listemat[1]!=NULL && listemat[2]!=NULL && listemat[3]==NULL){
                    libererMatrice(m0);
                    libererMatrice(m1);
                    libererMatrice(m2);
                }
                if (listemat[0]!=NULL && listemat[1]!=NULL && listemat[2]!=NULL && listemat[3]!=NULL){
                    libererMatrice(m0);
                    libererMatrice(m1);
                    libererMatrice(m2);
                    libererMatrice(m3);
                }
                break;

            default:
                printf("Votre entrée n'est pas valide. [1-8]\n");
                break;

        }
    }
    return 0;
}
