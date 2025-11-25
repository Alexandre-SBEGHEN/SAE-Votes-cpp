#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string litUneString (){
    string uneChaine;
    while (true){
        getline (cin, uneChaine);
        if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
    }
    return uneChaine;
}

int litUnEntier () {
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
    int glacePref;
};

int main() {
    size_t nombre_candidats = 4;

    //Lire les participants et les stocker dans une liste
    vector<string> liste_candidats;
    for (size_t i = 0; i < nombre_candidats; ++i) {
        liste_candidats.push_back(litUneString());
    }

    //Lire les voies
    vector<participant> liste_participants;
    vector<size_t> liste_votes(nombre_candidats, 0);

    while (cin) {
        string nom = litUneString();
        if (!cin) break;
        string prenom = litUneString();
        if (!cin) break;
        //string vote_string = ().substr(0, 1)litUneString;
        int vote = litUnEntier();
        if (!cin) break;


        cout << nom << endl << prenom << endl << vote << endl;

        

        participant part;
        part.nom = nom;
        part.prenom = prenom;
        part.glacePref = 0;

        liste_participants.push_back(part);
        liste_votes[vote - 1] += 1;

        
    }

    for (size_t i: liste_votes) cout << i << endl;

    return 0;
}