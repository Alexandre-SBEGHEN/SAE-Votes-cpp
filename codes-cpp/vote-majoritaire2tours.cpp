#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief litUneString
 * @return la chaine lue sauf si :
 * (1) on une boulette sur l'entrée
 * (2) on trouve un commentaire sur l'entrée
 * le commentaire est matérialisé par la chaine "//"
 */

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
    int glacePref;
};

bool compare2part (const participant & p1, const participant & p2){
    return p1.prenom < p2.prenom;
}

void affichVectString (const vector<string> & v){
    for (const string & val : v)
        cout << val << '\t';
    cout << endl;
}

void affichVectParticipants (const vector<participant> & vPart){
    for (const participant & part : vPart){
        cout << part.nom << endl;
        cout << part.prenom << endl;
        cout << part.glacePref << endl;
    }
}

int main() {
    cout << "-- SCRUTIN MAJORITAIRE A 2 TOURS --" << endl;
    cout << "Saisissez les 4 parfums en compétition :" << endl;

    vector<string> tabGlacePref;
    for (int i = 1; i <= 4; ++i) {
        cout << "Parfum " << i << " : ";
        tabGlacePref.push_back(litUneString());
    }

    cout << endl << "Il y aura combien de votants ? ";
    int nbVotants = litUnEntier();
    vector<participant> tabParticipant;

    cout << endl << "SAISIE DES VOTES DU 1er TOUR :" << endl;
    for (int i = 0; i < nbVotants; ++i) {
        cout << "Votant " << (i + 1) << ": " << "Nom: ";
        string nom = litUneString();
        cout << "Prénom: ";
        string prenom = litUneString();
        int choix;
        do {
            cout << "  Votre glace préférée (1 à 4) : ";
            choix = litUnEntier();
        } while (choix < 1 || choix > 4);
        tabParticipant.push_back({ nom, prenom, choix });
    }

    vector<int> tabVotesPremierTour(5, 0); // Indices 1 à 4 utilisés

    for (const auto& part : tabParticipant)
        tabVotesPremierTour[part.glacePref]++;

    cout << endl << "Résultats du 1er tour :" << endl;
    for (int i = 1; i <= 4; ++i)
        cout << "  " << i << " : " << tabGlacePref[i - 1] << " = " << tabVotesPremierTour[i] << " voix" << endl;

    int maxVotes = 0, gagnant = 1;
    for (int i = 1; i <= 4; ++i) {
        if (tabVotesPremierTour[i] > maxVotes) {
            maxVotes = tabVotesPremierTour[i];
            gagnant = i;
        }
    }

    if (maxVotes > nbVotants / 2) {
        cout << endl << "Victoire dès le 1er tour pour " << tabGlacePref[gagnant - 1] << " avec " << maxVotes << " voix." << endl;
        return 0;
    }

    // Chercher les deux meilleurs pour le second tour
    int premier = 0, second = 0;
    for (int i = 1; i <= 4; ++i) {
        if (premier == 0 || tabVotesPremierTour[i] > tabVotesPremierTour[premier]) {
            second = premier;
            premier = i;
        }
        else if (second == 0 || tabVotesPremierTour[i] > tabVotesPremierTour[second]) {
            second = i;
        }
    }

    cout << endl << "Second tour entre :" << endl;
    cout << "  1 : " << tabGlacePref[premier - 1] << endl;
    cout << "  2 : " << tabGlacePref[second - 1] << endl;

    int votesA = 0, votesB = 0;
    for (int i = 0; i < nbVotants; ++i) {
        cout << tabParticipant[i].prenom << " " << tabParticipant[i].nom << ", votez (1 ou 2) : ";
        int choix2;
        do {
            cin >> choix2;
        } while (choix2 != 1 && choix2 != 2);
        if (choix2 == 1)
            votesA++;
        else
            votesB++;
    }

    cout << endl << "Résultats du second tour :" << endl;
    cout << tabGlacePref[premier - 1] << " : " << votesA << " voix, " << tabGlacePref[second - 1] << " : " << votesB << " voix" << endl;

    if (votesA > votesB)
        cout << "Gagnant : " << tabGlacePref[premier - 1] << endl;
    else if (votesB > votesA)
        cout << "Gagnant : " << tabGlacePref[second - 1] << endl;
    else
        cout << "Egalité parfaite au second tour !" << endl;

    return 0;
}
