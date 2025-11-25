#include <iostream>
#include <vector>
using namespace std;
using ligne = vector<size_t>;

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

size_t indice_maximum(const ligne & tab) {
    if (tab.size() == 0) return 0;
    size_t maxi = 0;
    for (size_t i = 1; i < tab.size(); ++i) {
        if (tab[i] > tab[maxi]) maxi = i;
    }
    return maxi;
}

size_t indice_minimum(const ligne & tab) {
    if (tab.size() == 0) return 0;
    size_t mini = 0;
    for (size_t i = 1; i < tab.size(); ++i) {
        if (tab[i] < tab[mini]) mini = i;
    }
    return mini;
}

bool test_majorite_absolue(const ligne & tab) {
    size_t max = indice_maximum(tab);
    size_t somme = 0;
    for (size_t i: tab) somme += i;
    return tab[max] > somme/2;
}

template <typename T>
void supprimer_de_tab(T & tab, const size_t & indice) {
    tab.erase(tab.begin() + indice);
}

bool str_est_dans_tab(const vector<string> & tab, const string & elt) {
    bool est = false;
    size_t i = 0;
    while (i < tab.size()) {
        if (tab[i] == elt) {
            est = true;
            break;
        }
        ++i;
    }
    return est;
}

struct participant {
    string nom;
    string prenom;
    ligne choixGlacePref;
};

bool est_majuscule(const string & mot) {
    bool est = true;
    size_t i = 0;
    while (i < mot.length()) {
        if (isalpha(mot[i]) && !isupper(mot[i])) {
            est = false;
            break;
        }
        ++i;
    }
    return est;
}

int main() {
    //Enregistrer la dernière/prochaine donnée lue
    string donnee_lue = "";

    //Lire la liste des candidats
    int nb_candidats = 0;
    vector<string> liste_candidats;

    //Lire les candidats jusqu'à tomber sur une ligne en majuscule (= nom de famille)
    while (cin) {
        liste_candidats.push_back((donnee_lue == "") ? litUneString() : donnee_lue); //Mettre en valeur de fin la dernière donnée lue
        ++nb_candidats;

        donnee_lue = litUneString();
        //Si la donnée prochaine est tout en majuscule, c'est un nom de famille, donc on a fini d'énumérer les candidats
        if (est_majuscule(donnee_lue)) break;
    }

    //Votes
    ligne votes_ligne(nb_candidats, 0);
    vector<participant> participants;

    //Saisie des votes
    while (cin) {
        //Récupérer nom, prenom, glace pref, et si on peut pas récupérer les trois, alors on sort de l'entrée donc on quitte la boucle pour éviter un débordement
        //Récupérer le nom de famille stocké dans la dernière donnée lue, si c'est déjà fait on vide la donnée lue et on lit une ligne
        string nom = (donnee_lue == "") ? litUneString() : donnee_lue;
        donnee_lue = "";
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
    }

    //Tours
    ligne votes(nb_candidats, 0); //Initialiser les votes de tous les candidats à 0
    size_t tour = 0; //0 correspond au premier tour, 1 au second, etc
    while (true) { // Tant qu'il n'y a pas de majorité absolue on ajoute aux candidats les choix d'indice 'tour'
        //cout << "---------------" << endl << "Tour " << tour + 1 << endl;
        if (tour+1 > nb_candidats) return 1;
        
        for (participant part: participants) {
            if (tour == 0 || str_est_dans_tab(liste_candidats, liste_candidats[part.choixGlacePref[tour] - 1])) votes[part.choixGlacePref[tour] - 1] += 1;
        }

        //str_est_dans_tab(liste_candidats, liste_candidats[part.choixGlacePref[tour] - 1])

        //###
        // cout << "Votes : ";
        // for (size_t i: votes) cout << i << ' ';
        // cout << endl;
        //###

        //S'arrêter s'il y a majorité absolue
        if (test_majorite_absolue(votes)) break;

        //Si on continue, c'est qu'il n'y a pas majorité absolue
        size_t plus_faible_choix = indice_minimum(votes);
        supprimer_de_tab(votes, plus_faible_choix);
        supprimer_de_tab(liste_candidats, plus_faible_choix);

        ++tour;
    }

    //cout << endl << "Il y a majorité absolue !" << endl;

    //Trouver la glace gagnante
    size_t indice_gagnant = indice_maximum(votes);
    string gagnant = liste_candidats[indice_gagnant];

    cout << "c'est la glace " << gagnant << " qui a gagne" << endl;

    



    /*#################### DEBUG
    for (participant part: participants) {
        cout << "----------" << endl;
        cout << "Nom :\t\t" << part.nom << endl;
        cout << "Prénom :\t" << part.prenom << endl;
        cout << "Choix :\t\t";
        for (size_t ch: part.choixGlacePref) cout << ch << ' ';
        cout << endl;
    }
    //##################*/


    

    return 0;
}