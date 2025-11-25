/*
    Vote préférentiel : méthode BORDA, avec amélioration au choix
*/
#include <iostream>
#include <vector>
using namespace std;
using mat_ligne = vector<size_t>; //Création de l'alias ligne de la matrice
using mat = vector<mat_ligne>; //Création de l'alias de la matrice

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

void saisir_points();

int main() {
    //Déclarer la matrice candidats/votes
    mat matrice_candidats_votes;

    //Laisser l'utilisateur choisir le nombre de candidats et de votants, puis générer la matrice
    size_t nb_candidats, nb_votants;
    cout << "Combien y a-t-il de candidats ? ";
    cin >> nb_candidats;
    cout << "Combien y a-t-il de votants ? ";
    cin >> nb_votants;
    matrice_candidats_votes = generer_matrice(nb_candidats + 1, nb_candidats);

    //Saisie des différents choix des votants
    for (size_t num_votant = 0; num_votant < nb_votants; ++num_votant) {
        cout << "########## Votant numéro " << num_votant + 1 << " ##########" << endl;  
        for (size_t num_choix = 0; num_choix < nb_candidats; ++num_choix) {
            //cout << "Votant " << num_votant+1 << ", choix " << num_choix+1 << endl;

            size_t choix;
            cout << "Quel est le choix " << num_choix + 1 << " du votant " << num_votant + 1<< " ? ";
            cin >> choix;

            matrice_candidats_votes[num_choix][choix - 1] += 1;
        }
    }

    calculer_points(matrice_candidats_votes);
    
    //Afficher la matrice
    for (size_t i = 0; i < matrice_candidats_votes.size(); ++i) {
        for (size_t j = 0; j < matrice_candidats_votes[i].size(); ++j) {
            cout << matrice_candidats_votes[i][j] << ' ';
            if (j >= matrice_candidats_votes[0].size() - 1) cout << endl;
        }
    }
    cout << endl;

    return 0;
}