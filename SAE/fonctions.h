/**
 * \file fonctions.h
 *
 * Déclaration des fonctions fournies.
 */
#pragma once
#include <vector>
#include <string>

 //!\brief Crée un tableau aléatoire
std::vector<int> initTabAleat(size_t N);

//!\brief Crée un tableau presque trié
std::vector<int> initTabPresqueTri(size_t N);

//!\brief Crée un tableau presque trié au début
std::vector<int> initTabPresqueTriDeb(size_t N);

//!\brief Crée un tableau presque trié à la fin
std::vector<int> initTabPresqueTriFin(size_t N);

//!\brief Crée un tableau presque trié entre le début et la fin
std::vector<int> initTabPresqueTriDebFin(size_t N);

//!\brief Vérifie qu'un tableau est correctement trié
void verifTri(const std::vector<int>& tab, const std::string& algoName = {});



// Tri par selection
unsigned int triSelection(std::vector<int> &tab);

// Tri a bulles
unsigned int triBulles(std::vector<int> &tab);

// Tri a bulles optimise
unsigned int triBullesOpti(std::vector<int> &tab);

// Tri a peigne
unsigned int triPeigne(std::vector<int> &tab);

// Tri rapide
unsigned int partitionner(std::vector<int> &tab, int premier, int dernier, int pivot, unsigned int& cpt);
unsigned int choixPivot(std::vector<int> &tab, int premier, int dernier);
unsigned int triRapide(std::vector<int> &tab, int premier, int dernier);