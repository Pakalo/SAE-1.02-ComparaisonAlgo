#include "fonctions.h"
#include <iostream>
#include <fstream>
#include <cmath>


int main()
{


	// Initialisation de l'aleatoire
	std::srand(std::time(nullptr));
	std::rand();
	std::rand();


	/*std::cout << triSelection(initTabAleat(6844));*/
	


	std::ofstream out("outputUTF8.csv");
	if (!out.is_open())
		std::cerr << "Problème d'ouverture du fichier \"outputUTF8.csv\".\n";


    {
        for (int i = 0; i<3;i++)
        {
            out << "N; Aleat Sélect.; PresqueTri Sélect.; PresqueTriDeb Sélect.; PresqueTriDebFin Sélect.; PresqueTriFin Sélect;";
        }
        out << "N²; N*ln(N)\n";
        
        for (int i = 3; i < 100; i += 2)
        {
            std::vector<int> tabAleat = initTabAleat(i);
            std::vector<int> tabPt = initTabPresqueTri(i);
            std::vector<int> tabPtd = initTabPresqueTriDeb(i);
            std::vector<int> tabPtdf = initTabPresqueTriDebFin(i);
            std::vector<int> tabPtf = initTabPresqueTriFin(i);
            out << i << ";";
            out << triSelection(tabAleat) << ";";
            out << triSelection(tabPt) << ";";
            out << triSelection(tabPtd) << ";";
            out << triSelection(tabPtdf) << ";";
            out << triSelection(tabPtf) << ";";
            verifTri(tabAleat);
            verifTri(tabPt);
            verifTri(tabPtd);
            verifTri(tabPtdf);
            verifTri(tabPtf);

            tabAleat = initTabAleat(i);
            tabPt = initTabPresqueTri(i);
            tabPtd = initTabPresqueTriDeb(i);
            tabPtdf = initTabPresqueTriDebFin(i);
            tabPtf = initTabPresqueTriFin(i);
            out << i << ";";
            out << triBulles(tabAleat) << ";";
            out << triBulles(tabPt) << ";";
            out << triBulles(tabPtd) << ";";
            out << triBulles(tabPtdf) << ";";
            out << triBulles(tabPtf) << ";";
            verifTri(tabAleat);
            verifTri(tabPt);
            verifTri(tabPtd);
            verifTri(tabPtdf);
            verifTri(tabPtf);

            tabAleat = initTabAleat(i);
            tabPt = initTabPresqueTri(i);
            tabPtd = initTabPresqueTriDeb(i);
            tabPtdf = initTabPresqueTriDebFin(i);
            tabPtf = initTabPresqueTriFin(i);
            out << i << ";";
            out << triBullesOpti(tabAleat) << ";";
            out << triBullesOpti(tabPt) << ";";
            out << triBullesOpti(tabPtd) << ";";
            out << triBullesOpti(tabPtdf) << ";";
            out << triBullesOpti(tabPtf) << ";";
            verifTri(tabAleat);
            verifTri(tabPt);
            verifTri(tabPtd);
            verifTri(tabPtdf);
            verifTri(tabPtf);
        

            out << i * i << ";";
            out << i * log(i) << "\n";
        }
    }

}