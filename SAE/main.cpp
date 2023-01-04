#include "fonctions.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <array>

int main()
{
    // Initialisation de l'aleatoire
    std::srand(std::time(nullptr));
    std::rand();
    std::rand();


    const int nbrCol = 100; //Défini le nombre de colone du tableau

    //Ouverture du fichier 
    std::ofstream out("outputUTF8.csv");
    if (!out.is_open())
        std::cerr << "Problème d'ouverture du fichier \"outputUTF8.csv\".\n";

    typedef std::vector<int>(*function_init_ptr)(size_t N);//Définition du type du pointeur pour les fonction d'init de tab
    std::array<function_init_ptr, 5> FuncInitTab = { initTabAleat, initTabPresqueTri, initTabPresqueTriDeb,initTabPresqueTriDebFin, initTabPresqueTriFin }; //Tableau des fonction d'initialisation

    typedef unsigned int(*function_tri_ptr)(std::vector<int>& tab);//Définition du type du pointeur pour les fonction de tri
    std::array<function_tri_ptr, 4> FuncTriTab = { triSelection, triBulles, triBullesOpti, triPeigne }; //Tableau des fonction de tri

    out << "N"; // Entete N
    for (int i = 0; i < 5; i++) //Boucle d'affichage de l'entete
    {
        out << "; Aleat Sélect.; PresqueTri Sélect.; PresqueTriDeb Sélect.; PresqueTriDebFin Sélect.; PresqueTriFin Sélect;";
    }
    out << "N²; N*ln(N)\n"; //Entete N² 


    for (int i = 2; i <= nbrCol; i++)
    {
        out << i << ";"; //Ecrit l'indice N

        //Parcours les 4 premiers algorithmes de tri
        for (int j = 0; j < 4; j++)
        {
            //Parcours les algorithme de génération de tab, exécute l'algo de trie, et verifie le trie
            for (int k = 0; k < 5; k++) {
                std::vector<int> fit = FuncInitTab[k](i); //Crée un tableau qui contient la génération
                out << FuncTriTab[j](fit) << ";"; // Inscrit et fait le trie
                verifTri(fit); //Verif le tri
            }
            out << ";";
        }
        for (int l = 0; l < 5; l++)
        {
            std::vector<int> FIT = FuncInitTab[l](i);//Crée un tableau qui contient la génération
            out << triRapide(FIT, 0, i - 1)  << ";"; //Fait le tri rapide
            verifTri(FIT); //Verrifi le tri
        }

        out << i * i << ";"; // Ajoute la colone N²
        out << i * log(i) << "\n"; // Ajoute la colone n.ln(n)
    }

}


