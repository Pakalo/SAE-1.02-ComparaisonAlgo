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
    std::array<function_init_ptr, 5> FuncInitTab = { initTabAleat, initTabPresqueTri, initTabPresqueTriDeb, initTabPresqueTriDebFin, initTabPresqueTriFin }; //Tableau des fonction d'initialisation

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
        out << i << ";";
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 5; k++) {
                std::vector<int> FIT = FuncInitTab[k](i);
                out << FuncTriTab[j](FIT) << ";";
                verifTri(FIT);
            }
            out << ";";
        }
        for (int l = 0; l < 5; l++)
        {
            std::vector<int> FIT = FuncInitTab[l](i);
            out << triRapide(FIT, 0, FIT.size() - 1) << ";";
            
        }

        out << i * i << ";";
        out << i * log(i) << "\n";
    }

}



    /*std::vector<int> tab = { '5', '7', '6', '2', '9', '1', '3' };

    std::cout << choix_pivot(tab, 0, tab.size()-1);/



    std::cout << tri_rapide(initTabAleat(25),0,25-1);*/

