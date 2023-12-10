#include <vector>

class tri{
    public: 
    // Ces fonctions realisent les tris associes. Chacune devra renvoyer le nombre total d'echanges effectues
    long int TriBulles(int * T, int n);
    long int TriInsertion(int * T, int n);
    long int TriRapide(int * T, int n, int a, int b);
    long int TriTas(int * T, int n, int a, int b);
    void Test(const int n);
    void afficherLigne(int *T, int n);
    void affichertab(int *T, int n);
    long int Reorganiser(int *T, int j, int n); // reorganise le tas a partir de la case j de T de taille n
    long int Suppression(int *T, int n, int & nbEchange); // supprime le premier element du tas de taille n
    bool estTas(int *T, int n); // verifie si le tableau T de taille n est un tas
    bool estTrie(int *T, int n); // verifie si le tableau T de taille n est trie
    ~tri();
};