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
    for (int i = 0; i < nbvotant; i++)
    {
        int vote;
        int voteblanc = 0;
        cout << "Vote du n°" << (i + 1);
        cin >> vote;
        if (vote >= 1 && vote <= nbcandidat)
        {
            resultatcandidat[vote - 1] += 1;
            cout << "Vote pour le candidat n°" << vote << endl;
        }
        else
        {
            cout << "Vote blanc" << endl;
            voteblanc += 1;
        }
    }
}
