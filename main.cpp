#include "tri.h"
#include <iostream>

using namespace std;

// afin de m'entraiener a utiliser les vecteurs, j'ai priviligié leur utilisation aux simple tableau
// de ce fait, j'ai pu utiliser les fonctions inclues dans la librairie vector (size(), push_back(), ...)

int main()
{
    tri t;
    cout << "n = 10" << endl;
    t.Test(10);
    cout << endl;
    cout << "n = 100" << endl;
    t.Test(100);
    cout << endl;
    cout << "n = 1000" << endl;
    t.Test(1000);
    cout << endl;
    cout << "n = 10000" << endl;
    t.Test(10000);
    cout << endl;
    cout << "n = 100000" << endl;
    t.Test(100000);
    cout << endl;
    cout << "n = 1000000" << endl;
    return 0;
}