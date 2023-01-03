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

	for (int i = 3; i <= 200; i++)
	{
		
		out << i << ";";
		out << triSelection(initTabAleat(i)) << ";";
		out << triSelection(initTabPresqueTri(i)) << ";";
		out << triSelection(initTabPresqueTriDeb(i)) << ";";
		out << triSelection(initTabPresqueTriDebFin(i)) << ";";
		out << triSelection(initTabPresqueTriFin(i)) << "\n";
	}
	

	out << "\n\n\n\nN²; Aleat Sélect.; PresqueTri Sélect.; PresqueTriDeb Sélect.; PresqueTriDebFin Sélect.; PresqueTriFin Sélect\n";

	for (int i = 3; i <= 200; i++)
	{

		out << i*i << ";";
		out << triSelection(initTabAleat(i-i)) << ";";
		out << triSelection(initTabPresqueTri(i*i)) << ";";
		out << triSelection(initTabPresqueTriDeb(i*i)) << ";";
		out << triSelection(initTabPresqueTriDebFin(i*i)) << ";";
		out << triSelection(initTabPresqueTriFin(i*i)) << "\n";
	}
	


}