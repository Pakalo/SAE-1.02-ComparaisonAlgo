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


    const int nbrCol = 100; //D�fini le nombre de colone du tableau

    //Ouverture du fichier 
    std::ofstream out("outputUTF8.csv");
    if (!out.is_open())
        std::cerr << "Probl�me d'ouverture du fichier \"outputUTF8.csv\".\n";

    typedef std::vector<int>(*function_init_ptr)(size_t N);//D�finition du type du pointeur pour les fonction d'init de tab
    std::array<function_init_ptr, 5> FuncInitTab = { initTabAleat, initTabPresqueTri, initTabPresqueTriDeb,initTabPresqueTriDebFin, initTabPresqueTriFin }; //Tableau des fonction d'initialisation

    typedef unsigned int(*function_tri_ptr)(std::vector<int>& tab);//D�finition du type du pointeur pour les fonction de tri
    std::array<function_tri_ptr, 4> FuncTriTab = { triSelection, triBulles, triBullesOpti, triPeigne }; //Tableau des fonction de tri

    out << "N"; // Entete N
    for (int i = 0; i < 5; i++) //Boucle d'affichage de l'entete
    {
        out << "; Aleat S�lect.; PresqueTri S�lect.; PresqueTriDeb S�lect.; PresqueTriDebFin S�lect.; PresqueTriFin S�lect;";
    }
    out << "N�; N*ln(N)\n"; //Entete N� 


    for (int i = 2; i <= nbrCol; i++)
    {
        out << i << ";"; //Ecrit l'indice N

        //Parcours les 4 premiers algorithmes de tri
        for (int j = 0; j < 4; j++)
        {
            //Parcours les algorithme de g�n�ration de tab, ex�cute l'algo de trie, et verifie le trie
            for (int k = 0; k < 5; k++) {
                std::vector<int> fit = FuncInitTab[k](i); //Cr�e un tableau qui contient la g�n�ration
                out << FuncTriTab[j](fit) << ";"; // Inscrit et fait le trie
                verifTri(fit); //Verif le tri
            }
            out << ";";
        }
        for (int l = 0; l < 5; l++)
        {
            std::vector<int> FIT = FuncInitTab[l](i);//Cr�e un tableau qui contient la g�n�ration
            out << triRapide(FIT, 0, i - 1)  << ";"; //Fait le tri rapide
            verifTri(FIT); //Verrifi le tri
        }

        out << i * i << ";"; // Ajoute la colone N�
        out << i * log(i) << "\n"; // Ajoute la colone n.ln(n)
    }

}


