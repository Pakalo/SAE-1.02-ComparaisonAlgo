/**
 * \file fonctions.h
 *
 * D�claration des fonctions fournies.
 */
#pragma once
#include <vector>
#include <string>

 //!\brief Cr�e un tableau al�atoire
std::vector<int> initTabAleat(size_t N);

//!\brief Cr�e un tableau presque tri�
std::vector<int> initTabPresqueTri(size_t N);

//!\brief Cr�e un tableau presque tri� au d�but
std::vector<int> initTabPresqueTriDeb(size_t N);

//!\brief Cr�e un tableau presque tri� � la fin
std::vector<int> initTabPresqueTriFin(size_t N);

//!\brief Cr�e un tableau presque tri� entre le d�but et la fin
std::vector<int> initTabPresqueTriDebFin(size_t N);

//!\brief V�rifie qu'un tableau est correctement tri�
void verifTri(const std::vector<int>& tab, const std::string& algoName = {});


// Tri par selection
size_t triSelection(std::vector<int> tab);