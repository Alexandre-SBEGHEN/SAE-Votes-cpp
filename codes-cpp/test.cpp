#include <iostream>
using namespace std;

int main() {
    while (cin) {
        string ligne;
        getline(cin, ligne);

        if (ligne[0] == '#') continue;

        cout << ligne << endl;
    }

    return 0;
}