#include <iostream>
#include <vector>
#include <algorithm>
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

struct participant {
    string nom;
    string prenom;
    int glacePref;
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
    ligne votes(nb_candidats, 0);
    vector<participant> participants;

    //Saisie des votes
    while (cin) {
        //Récupérer nom, prenom, glace pref, et si on peut pas récupérer les trois, alors on sort de l'entrée donc on quitte la boucle pour éviter un débordement
        //Récupérer le nom de famille stocké dans la dernière donnée lue, si c'est déjà fait on vide la donnée lue et on lit une ligne
        string nom = (donnee_lue == "") ? litUneString() : donnee_lue;
        donnee_lue = "";
        if (!cin || nom.substr(0, 1) == "#") break;
        string prenom = litUneString();
        if (!cin) break;
        int glacePref = litUnEntier();

        //Si on continue, c'est qu'un nouveau votant a été détécté

        //Ajouter le participant à la liste des participants
        participant part = {nom, prenom, glacePref};
        participants.push_back(part);
    }

    //Premier tour
    for (participant part: participants) {
        votes[part.glacePref - 1] += 1;
    }

    //Tester la majorité absolue
    if (!test_majorite_absolue(votes)) {
        vector<string> liste_candidats_second;
        for (string i: liste_candidats) liste_candidats_second.push_back(i);
        while (votes.size() > 2) {
            //Garder les 2 meilleurs
            size_t plus_faible = indice_minimum(votes);
            supprimer_de_tab(votes, plus_faible);
            supprimer_de_tab(liste_candidats_second, plus_faible);
        }
        //Reset les votes
        votes = {0, 0, 0, 0};
        participants.resize(0);

        //Nouvelle saisie des votes
        while (cin) {
            //Récupérer nom, prenom, glace pref, et si on peut pas récupérer les trois, alors on sort de l'entrée donc on quitte la boucle pour éviter un débordement
            //Récupérer le nom de famille stocké dans la dernière donnée lue, si c'est déjà fait on vide la donnée lue et on lit une ligne
            string nom = (donnee_lue == "") ? litUneString() : donnee_lue;
            donnee_lue = "";
            if (!cin) break;
            string prenom = litUneString();
            if (!cin) break;
            int glacePref = litUnEntier();

            //Si on continue, c'est qu'un nouveau votant a été détécté

            //Ajouter le participant à la liste des participants si le vote fait partie des 2 meilleurs
            if (find(liste_candidats_second.begin(), liste_candidats_second.end(), liste_candidats[glacePref - 1]) != liste_candidats.end()) {
                participant part = {nom, prenom, glacePref};
                participants.push_back(part);
            }
        }

        for (participant part: participants) {
            votes[part.glacePref - 1] += 1;
        }
    }

    //Trouver la glace gagnante
    size_t indice_gagnant = indice_maximum(votes);
    string gagnant = liste_candidats[indice_gagnant];
    cout << "c'est la glace " << gagnant << " qui a gagne" << endl;



    return 0;
}
