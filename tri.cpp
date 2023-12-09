#include "tri.h"
#include <iostream> // cout, cin, endl
#include <vector> // vector
#include <cstdlib> // srand, rand
#include <ctime> // time
#include <iomanip> // setw (taille de champ pour bel affichage)

using namespace std;

long int tri::TriBulles(int *T, int n)
{
    long int nbEchange = 0;

    for (int i = 1; i < n-1; ++i) {
        for (int j = n; j > i+1; --j) {
            if (T[j] < T[j-1]) {
                swap(T[j], T[j-1]);
                nbEchange++;
            }
        }
    }
    
    return nbEchange;
}

long int tri::TriInsertion(int *T, int n)
{
    long int nbEchange = 0;
    for (int i = 1; i < n; ++i) {
        int j = i;
        while (j > 0 && T[j-1] > T[j]){
            swap(T[j], T[j-1]);
            nbEchange++;
            j--;
        }
    }
    return nbEchange;
}

long int tri::TriRapide(int *T, int n, int a, int b) // compte le nombre d'échange
{
    long int nbEchange = 0;
    if (a < b) {
        int pivot = T[a];
        int i = a;
        int j = b;
        while (i < j) {
            while (T[i] <= pivot && i < b) {
                i++;
            }
            while (T[j] > pivot) {
                j--;
            }
            if (i < j) {
                swap(T[i], T[j]);
                nbEchange++;
            }
        }
        swap(T[a], T[j]);
        nbEchange++;
        nbEchange += TriRapide(T, n, a, j-1);
        nbEchange += TriRapide(T, n, j+1, b);
    }
    return nbEchange;
}



long int tri::TriTas(int *T, int n, int a, int b)
{
    long int nbEchange = 0;
    for (int i = (n)/2; i >= 1; --i) {
        nbEchange += entasser(T, n, i);
    }
    for (int i = b; i >= 2; --i) {
        swap(T[a], T[i]);
        nbEchange++;
        n--;
        nbEchange+=entasser(T, n, a);
    }
    return nbEchange;
}

long int tri::entasser(int *T, int n, int i)
{
    long int nbEchange = 0;
    int l = 2*i;
    int r = 2*i+1;
    int max = i;
    if (l <= n && T[l] > T[i]) {
        max = l;
    }
    if (r <= n && T[r] > T[i]) {
        max = r;
    }
    if (max != i) {
        swap(T[i], T[max]);
        nbEchange++;
        nbEchange += entasser(T, n, max);
    }
    return nbEchange;
}

void tri::Test(const int n)
{

//génére aléatoirement 5 tableaux T de taille n composé d'entiers entre 100 et 2000 compris
    srand(time(0));
    vector<int> T1, T2, T3, T4, T5;
    volatile vector<int> temp;
    

    for (int i = 0; i < n; ++i) {
        T1.push_back(rand() % 1901 + 100);
        T2.push_back(rand() % 1901 + 100);
        T3.push_back(rand() % 1901 + 100);
        T4.push_back(rand() % 1901 + 100);
        T5.push_back(rand() % 1901 + 100);
    }

// execute sur chaque tableau généré les 4 tris
    

    cout << setw(5) << "n" << "|"
         << setw(20) << "Nom du Tri" << "|"
         << setw(20) << "Nombre d'echanges" << "|"
         << setw(20) << "Temps d'execution" << "|" << endl;

    cout << string(69, '-') << endl;

    afficherLigne(T1.data(), n);
    afficherLigne(T2.data(), n);
    afficherLigne(T3.data(), n);
    afficherLigne(T4.data(), n);
    afficherLigne(T5.data(), n);

}

void tri::afficherLigne(int *T, int n)
{
    vector<int> temp(T, T + n);   // copie du tableau pour le remettre dans le meme désordre apres chaque tri 
    
    time_t startTime = time(NULL);
    cout << setw(5) << n << "|" << setw(20) << "Tri à bulles" << " |" << setw(20) << TriBulles(temp.data(), n) << "|" << setw(20) <<  difftime(time(NULL), startTime) << endl;
    temp.assign(T, T + n); // remet le tableau dans le meme désordre qu'au départ
    
    startTime = time(NULL);
    cout << setw(5) << n << "|" << setw(20) << "Tri par insertion" << "|" << setw(20) << TriInsertion(temp.data(), n) << "|" << setw(20) <<  difftime(time(NULL), startTime) << endl;
    temp.assign(T, T + n); // remet le tableau dans le meme désordre qu'au départ
    
    startTime = time(NULL);
    cout << setw(5) << n << "|" << setw(20) << "Tri rapide" << "|" << setw(20) << TriRapide(temp.data(), n, 0, n-1) << "|" << setw(20) <<  difftime(time(NULL), startTime) << endl;
    affichertab(temp.data(), n);
    temp.assign(T, T + n); // remet le tableau dans le meme désordre qu'au départ
    
    startTime = time(NULL);
    cout << setw(5) << n << "|" << setw(20) << "Tri par tas" << "|" << setw(20) << TriTas(temp.data(), n, 0, n-1) << "|" << setw(20) <<  difftime(time(NULL), startTime) << endl;
    temp.assign(T, T + n); // remet le tableau dans le meme désordre qu'au départ

    cout << string(69, '-') << endl;
}

void tri::affichertab(int *T, int n)
{
    for (int i = 0; i < n; ++i) {
        cout << T[i] << " ";
    }
    cout << endl;
}