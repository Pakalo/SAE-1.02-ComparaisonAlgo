#include "fonctions.h"
#include <iostream>
#include <fstream>


int main()
{


	// Initialisation de l'aleatoire
	std::srand(std::time(nullptr));
	std::rand();
	std::rand();


	/*std::cout << triSelection(initTabAleat(6844));*/
	


	std::ofstream out("outputUTF8.csv");
	if (!out.is_open())
		std::cerr << "Probl�me d'ouverture du fichier \"outputUTF8.csv\".\n";


    {
        out << "N; Aleat S�lect.; PresqueTri S�lect.; PresqueTriDeb S�lect.; PresqueTriDebFin S�lect.; PresqueTriFin S�lect\n";

        for (int i = 3; i <= 20; i++)
        {

            out << i << ";";
            out << triSelection(initTabAleat(i)) << ";";
            out << triSelection(initTabPresqueTri(i)) << ";";
            out << triSelection(initTabPresqueTriDeb(i)) << ";";
            out << triSelection(initTabPresqueTriDebFin(i)) << ";";
            out << triSelection(initTabPresqueTriFin(i)) << "\n";
        }
    }



    out << "\n\n\nN; Aleat S�lect.; PresqueTri S�lect.; PresqueTriDeb S�lect.; PresqueTriDebFin S�lect.; PresqueTriFin S�lect\n";

    for (int i = 3; i <= 20; i++)
    {

        out << i << ";";
        out << triBulles(initTabAleat(i)) << ";";
        out << triBulles(initTabPresqueTri(i)) << ";";
        out << triBulles(initTabPresqueTriDeb(i)) << ";";
        out << triBulles(initTabPresqueTriDebFin(i)) << ";";
        out << triBulles(initTabPresqueTriFin(i)) << "\n";
    }

}