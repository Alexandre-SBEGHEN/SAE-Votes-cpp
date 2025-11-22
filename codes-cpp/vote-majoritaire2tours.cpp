#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int nbcandidat, nbvotant;
    cout << "Nombre de candidats : ";
    cin >> nbcandidat;
    cout << "Nombre de votants : ";
    cin >> nbvotant;
    vector<int> resultatcandidat(nbcandidat, 0);
    int vote;
    int voteblanc = 0;
    int maxvote1 = 0;
    int maxvote2 = 0;
    for (int i = 0; i < nbvotant; i++)
    {
        cout << "Vote du n°" << (i + 1) << ": ";
        cin >> vote;
        if (vote >= 1 && vote <= nbcandidat)
        {
            resultatcandidat[vote - 1] += 1;
            cout << "Vote pour le candidat n° : " << vote  << endl;
        }
        else
        {
            cout << "Vote blanc" << endl;
            voteblanc += 1;
        }
        if (maxvote2 < resultatcandidat[vote - 1])
        {
            maxvote2 = resultatcandidat[vote - 1];
        }
        if (maxvote1<maxvote2)
        {
            maxvote1 = maxvote2;
        }
    }
    for (int i = 0; i < nbcandidat; i++)
    {
        cout << "Resultat pour le candididat n°" << i + 1 << ": " << resultatcandidat [i] << endl;
    }
    cout << "Nombre de vote blanc : " << voteblanc << endl;
    cout << maxvote2 << endl;
    cout << maxvote1 << endl;
}
