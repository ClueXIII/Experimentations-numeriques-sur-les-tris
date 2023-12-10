#include <vector>

class tri{
    public: 
    // Ces fonctions realisent les tris associes. Chacune devra renvoyer le nombre total d'echanges effectues
    long int TriBulles(int * T, int n); // tri a bulles
    long int TriInsertion(int * T, int n); // tri par insertion
    long int TriRapide(int * T, int n, int a, int b); // tri rapide
    long int TriTas(int * T, int n, int a, int b); // tri par tas
    void Test(const int n); // effectue les tris sur un tableau de taille n
    void afficherLigne(int *T, int n); // affiche une ligne contenant les informations sur les tris effectues sur un tableau de taille n
    void affichertab(int *T, int n); // affiche le tableau T de taille n
    long int Reorganiser(int *T, int j, int n); // reorganise le tas a partir de la case j de T de taille n
    long int Suppression(int *T, int n, int & nbEchange); // supprime le premier element du tas de taille n
    bool estTas(int *T, int n); // verifie si le tableau T de taille n est un tas
    bool estTrie(int *T, int n); // verifie si le tableau T de taille n est trie
    ~tri();
};