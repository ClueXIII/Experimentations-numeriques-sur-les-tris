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

    for (int i = 0; i < n-1; ++i) {
        for (int j = n-1; j > i; --j) {
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

    // Construction du tas (à partir de l'indice 0)
    for (int k = n / 2 - 1; k >= 0; k--) {
        nbEchange += Reorganiser(T, k, n);
    }

    // Extraction des éléments du tas
    for (int k = n - 1; k > 0; k--) {
        // Suppression du min
        swap(T[0], T[k]);
        nbEchange++;
        nbEchange += Reorganiser(T, 0, k);
    }

    return nbEchange;
}

long int tri::Reorganiser(int *T, int j, int n)
{
    int i = j;
    int m = 0;
    long int nbEchange = 0;

    while (2 * i + 1 < n) {
        m = 2 * i + 1; // Fils gauche

        if (2 * i + 2 < n && T[2 * i + 2] > T[2 * i + 1]) {
            m = 2 * i + 2; // Fils droit
        }

        if (T[i] < T[m]) {
            swap(T[i], T[m]);
            nbEchange++;
            i = m;
        } else {
            break;
        }
    }
    return nbEchange;
}


long int tri::Suppression(int *T, int n,int & nbEchange)
{
    int min = T[0];
    T[0] = T[n];
    n--;
    nbEchange+= Reorganiser(T, 0, n);
    return min;
}

bool tri::estTas(int *T, int n)
{
    bool estTas = true;
    for (int i = 0; i < n; ++i) {
        if (2 * i + 1 < n && T[i] > T[2 * i + 1]) {
            estTas = false;
        }
        if (2 * i + 2 < n && T[i] > T[2 * i + 2]) {
            estTas = false;
        }
    }
    return estTas;
}

bool tri::estTrie(int *T, int n)
{
    bool estTrie = true;
    for (int i = 0; i < n-1; ++i) {
        if (T[i] > T[i+1]) {
            estTrie = false;
        }
    }
    return estTrie;
}

tri::~tri()
{
    cout << "Destruction de l'objet tri" << endl;
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
    

    cout << "|" << setw(5) << "n" << "|"
         << setw(20) << "Nom du Tri" << "|"
         << setw(20) << "Nombre d'echanges" << "|"
         << setw(20) << "Temps d'execution" << "|"
         << setw(10) << "est trié ?" << "|" << endl;

    cout << string(81, '-') << endl;

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
    cout << "|" << setw(5) << n << "|" << setw(20) << "Tri à bulles" << " |" << setw(20) << TriBulles(temp.data(), n) << "|" << setw(20) <<  difftime(time(NULL), startTime) <<  "|" << setw(10) << estTrie(temp.data(), n) << "|" << endl;
    temp.assign(T, T + n); // remet le tableau dans le meme désordre qu'au départ
   
    startTime = time(NULL);
    cout << "|" << setw(5) << n << "|" << setw(20) << "Tri par insertion" << "|" << setw(20) << TriInsertion(temp.data(), n) << "|" << setw(20) <<  difftime(time(NULL), startTime) <<  "|" << setw(10) << estTrie(temp.data(), n) << "|"<< endl;
    temp.assign(T, T + n); // remet le tableau dans le meme désordre qu'au départ

    startTime = time(NULL);
    cout << "|" << setw(5) << n << "|" << setw(20) << "Tri rapide" << "|" << setw(20) << TriRapide(temp.data(), n, 0, n-1) << "|" << setw(20) <<  difftime(time(NULL), startTime) <<  "|" << setw(10) << estTrie(temp.data(), n) << "|" << endl;
    temp.assign(T, T + n); // remet le tableau dans le meme désordre qu'au départ

    startTime = time(NULL);
    cout << "|" << setw(5) << n << "|" << setw(20) << "Tri par tas" << "|" << setw(20) << TriTas(temp.data(), n, 0, n-1) << "|" << setw(20) <<  difftime(time(NULL), startTime) <<  "|" << setw(10) << estTas(temp.data(), n) << "|"<< endl;
    cout << string(81, '-') << endl;
}

void tri::affichertab(int *T, int n)
{
    for (int i = 0; i < n; ++i) {
        cout << T[i] << "[" << i << "]" << " ";
    }
    cout << endl;
}