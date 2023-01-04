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


    out << "\n\n\n\nN�; Aleat S�lect.; PresqueTri S�lect 2; PresqueTriDeb S�lect2; PresqueTriDebFin S�lect2; PresqueTriFin S�lect2\n";

    for (int i = 3; i <= 20; i++)
    {

        out << i * i << ";";
        out << triSelection(initTabAleat(i * i)) << ";";
        out << triSelection(initTabPresqueTri(i * i)) << ";";
        out << triSelection(initTabPresqueTriDeb(i * i)) << ";";
        out << triSelection(initTabPresqueTriDebFin(i * i)) << ";";
        out << triSelection(initTabPresqueTriFin(i * i)) << "\n";
    }


    out << "\n\n\n\nN*ln(N); Aleat S�lect3; PresqueTri S�lect3; PresqueTriDeb S�lect3; PresqueTriDebFin S�lect3; PresqueTriFin S�lect3\n";

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