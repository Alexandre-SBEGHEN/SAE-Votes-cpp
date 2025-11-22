/*
    Vote préférentiel : méthode BORDA, avec amélioration au choix
*/
#include <iostream>
#include <vector>
using namespace std;
using mat = vector<vector<size_t>>; //Création de l'alias de la matrice
using mat_ligne = vector<size_t>;

mat generer_matrice(const size_t & lignes, const size_t & colonnes) {
    mat_ligne ligne(colonnes, 0);
    mat matrice(lignes, ligne);
    return matrice;
}

int amelioration_point(const size_t & point) {
    //return point; //Borda classique
    return point * point; //Borda amélioré
}

void calculer_points(mat & matrice) {
    for (size_t i = 0; i < matrice[0].size(); ++i) {
        size_t somme = 0;
        for (size_t j = 0; j < matrice.size() - 1; ++j) {
            size_t point = matrice.size() - 1 - j;
            somme += matrice[j][i] * amelioration_point(point);
        }
        matrice[matrice.size() - 1][i] = somme;
    }
}

int main() {
    mat matrice = {
        {10, 6, 2},
        {5, 10, 8},
        {3, 2, 8},
        {0, 0, 0}
    };

    calculer_points(matrice);




    //afficher la matrice
    for (size_t i = 0; i < matrice.size(); ++i) {
        for (size_t j = 0; j < matrice[i].size(); ++j) {
            cout << matrice[i][j] << ' ';
            if (j >= matrice[0].size() - 1) cout << endl;
        }
    }
    cout << endl;

    return 0;
}