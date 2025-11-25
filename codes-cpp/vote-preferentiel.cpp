#include <iostream>
#include <vector>
using namespace std;
using ligne = vector<size_t>;
using mat = vector<ligne>;

string litUneString (){
    string uneChaine;
    while (true){
        getline (cin, uneChaine);
        if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
    }
    return uneChaine;
}

int litUnEntier (){
    string uneChaine;
    while (true){
        getline (cin, uneChaine);
        if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
    }
    return stoi(uneChaine);
}

struct participant {
    string nom;
    string prenom;
    ligne choixGlacePref;
};

size_t indice_maximum(const ligne & tab) {
    if (tab.size() == 0) return 0;
    size_t maxi = 0;
    for (size_t i = 1; i < tab.size(); ++i) {
        if (tab[i] > tab[maxi]) maxi = i;
    }
    return maxi;
}

int main() {
    //Lire la liste des candidats
    int nb_candidats = litUnEntier();
    vector<string> liste_candidats;

    for (int i = 0; i < nb_candidats; ++i) {
        liste_candidats.push_back(litUneString());
    }

    //Votes
    ligne votes_ligne(nb_candidats, 0);
    mat votes(nb_candidats, votes_ligne); //Chaque ligne de la matrice est un candidat, chaque colonne est le nombre de voies en choix numéro 'colonne'
    vector<participant> participants;

    //Saisie des votes
    while (cin) {
        //Récupérer nom, prenom, glace pref, et si on peut pas récupérer les trois, alors on sort de l'entrée donc on quitte la boucle pour éviter un débordement
        string nom = litUneString();
        if (!cin) break;
        string prenom = litUneString();
        if (!cin) break;
        ligne choixGlacePref;
        for (size_t i = 0; i < nb_candidats; ++i) {
            choixGlacePref.push_back(litUnEntier());
            if (!cin) break;
        }

        //Si on continue, c'est qu'un nouveau votant a été détécté
        
        //Ajouter le participant à la liste des participants
        participant part = {nom, prenom, choixGlacePref};
        participants.push_back(part);

        //Ajouter les choix dans la matrice
        for (size_t i = 0; i < choixGlacePref.size(); ++i) votes[choixGlacePref[i] - 1][i] += 1; //-1 car le premier indice est zéro mais quand on fait les choix on commence par 1
    }

    //alculer les scores dans une dernière colonne
    for (size_t i = 0; i < votes.size(); ++i) {
        size_t somme = 0;
        for (size_t j = 0; j < nb_candidats; ++j) {
            size_t point = nb_candidats - j; //Les points sont {nb_candidats, nb_candidats - 1, nb_candidats - 2 ..., 3, 2, 1}

            somme += votes[i][j] * point * point; //On multiplie 2 fois par point pour avoir l'amélioration de Borda (les points au carré)
        }
        votes[i].push_back(somme);
    }

    //Trouver la glace gagnante
    ligne resultat;
    for (ligne i: votes) resultat.push_back(i[i.size() - 1]);
    size_t indice_gagnant = indice_maximum(resultat);
    string gagnant = liste_candidats[indice_gagnant];

    cout << "c'est la glace " << gagnant << " qui a gagne" << endl;
    
    /*#################### DEBUG
    //Afficher le nombre de candidats
    // cout << "Nombre candidats : " << nb_candidats << endl;
    // for (string i: liste_candidats) cout << i << ", " << endl;
    // cout << "Participants :" << endl;
    // for (participant i: participants) cout << i.prenom << ", ";
    // cout << endl;

    //Mettre des valeurs prédéfinies
    // votes = {
    //     {10, 5, 3, 0},
    //     {6, 10, 2, 0},
    //     {2, 8, 8, 0},
    // };

    //Afficher la matrice
    for (size_t i = 0; i < votes.size(); ++i) {
        for (size_t j = 0; j < votes[i].size(); ++j) {
            cout << votes[i][j] << '\t';
            if (j >= votes[i].size() - 1) cout << endl;
        }
    }
    //##################*/

    return 0;
}