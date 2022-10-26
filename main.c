#include <stdio.h>
#include "tp3.h"



int main() {
    matrice_creuse* m;
    remplirMatrice(m,6,5);
    afficherMatrice(*m);
    afficherMatriceListes(*m);
    rechercher(*m);
    return 0;
}
