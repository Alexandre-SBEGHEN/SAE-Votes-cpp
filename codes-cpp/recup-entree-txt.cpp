#include <iostream>
#include <vector>
using namespace std;

bool est_mot_maj(const string & mot) {
    bool maj = true;
    size_t i = 0;
    while (i < mot.length()) {
        if (!isupper(mot[i])) {
            maj = false;
            break;
        }
        ++i;
    }
    return maj;
}

bool est_commentaire(const string & ligne) {
    return (ligne.length() >= 2 && ligne[0] == '/' && ligne[1] == '/');
}

int main() {
    /*
        liste = {nb_candidats, nb_votants, votes...}
    */
    size_t nb_candidats = 0;
    size_t nb_votants = 0;
    bool candidats_fin_enumeration = false;

    cout << nb_candidats << nb_votants;

    while (cin) {
        string ligne;
        getline(cin, ligne);

        if (est_commentaire(ligne)) continue; //Ignorer les commentaires

        if (!candidats_fin_enumeration) {   //Si les candidats sont en cours d'énumération
            if (est_mot_maj(ligne)) {
                candidats_fin_enumeration = true;
            } else {
                ++nb_candidats;
            }
        } else {                            //Si les votants commencent à être cités
            
        }
    }

    


    return 0;
}