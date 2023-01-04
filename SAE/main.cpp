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
		std::cerr << "Problème d'ouverture du fichier \"outputUTF8.csv\".\n";


    out << "N; Aleat Sélect.; PresqueTri Sélect.; PresqueTriDeb Sélect.; PresqueTriDebFin Sélect.; PresqueTriFin Sélect\n";

    for (int i = 3; i <= 20; i++)
    {

        out << i << ";";
        out << triSelection(initTabAleat(i)) << ";";
        out << triSelection(initTabPresqueTri(i)) << ";";
        out << triSelection(initTabPresqueTriDeb(i)) << ";";
        out << triSelection(initTabPresqueTriDebFin(i)) << ";";
        out << triSelection(initTabPresqueTriFin(i)) << "\n";
    }


    out << "\n\n\n\nN²; Aleat Sélect.; PresqueTri Sélect 2; PresqueTriDeb Sélect2; PresqueTriDebFin Sélect2; PresqueTriFin Sélect2\n";

    for (int i = 3; i <= 20; i++)
    {

        out << i * i << ";";
        out << triSelection(initTabAleat(i * i)) << ";";
        out << triSelection(initTabPresqueTri(i * i)) << ";";
        out << triSelection(initTabPresqueTriDeb(i * i)) << ";";
        out << triSelection(initTabPresqueTriDebFin(i * i)) << ";";
        out << triSelection(initTabPresqueTriFin(i * i)) << "\n";
    }


    out << "\n\n\n\nN*ln(N); Aleat Sélect3; PresqueTri Sélect3; PresqueTriDeb Sélect3; PresqueTriDebFin Sélect3; PresqueTriFin Sélect3\n";

    for (int i = 3; i <= 20; i++)
    {

        out << i * log(i) << ";";
        out << triSelection(initTabAleat(i * log(i))) << ";";
        out << triSelection(initTabPresqueTri(i * log(i))) << ";";
        out << triSelection(initTabPresqueTriDeb(i * log(i))) << ";";
        out << triSelection(initTabPresqueTriDebFin(i * log(i))) << ";";
        out << triSelection(initTabPresqueTriFin(i * log(i))) << "\n";
    }


}