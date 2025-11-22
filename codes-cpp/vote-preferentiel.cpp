/*
    Vote préférentiel : méthode BORDA, avec amélioration au choix
*/
#include <iostream>
#include <vector>
using namespace std;
using mat = vector<vector<size_t>>; //Création de l'alias de la matrice
using mat_ligne = vector<size_t>;

int amelioration_point(const size_t & point) {
    return point * point;
}

mat generer_matrice(const size_t & lignes, const size_t & colonnes) {
    mat_ligne ligne(colonnes, 0);
    mat matrice(lignes, ligne);
    return matrice;
}

int main() {
    mat matrice = generer_matrice(3, 3);
    for (size_t i = 0; i < matrice.size(); ++i) {
        for (size_t j = 0; j < matrice.size(); ++j) {
            matrice[i][j] = i + j * matrice.size();
        }
    }

    for (mat_ligne i: matrice) {
        for (size_t j: i) {
            cout << j << ' ';
        }
    }
    cout << endl;

    return 0;
}