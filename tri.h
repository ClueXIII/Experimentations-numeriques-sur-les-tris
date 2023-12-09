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
    long int entasser(int *T, int n, int i);
};