/**
 * \file fonctions.cpp
 *
 * Définition des fonctions fournies.
 */
#include "fonctions.h"
#include <iostream>

 /**
  * Crée un tableau d'entiers dont tous les éléments sont choisis aléatoirement.
  *
  * Un tel tableau peut par exemple être 30968 28073 31177 2882 6140 17999 13828 20039 2310 24865.
  *
  * \param[in] N taille du tableau
  * \return le tableau initialisé
  */
std::vector<int> initTabAleat(size_t N)
{
    std::vector<int> tab(N);
    for (auto& val : tab)
        val = rand();
    return tab;
}

/**
 * Crée un tableau d'entiers presque triés. Chaque élément est quasiment à sa place définitive, échangé éventuellement d'une place.
 *
 * Un tel tableau peut par exemple être 1 3 2 4 6 5 8 7 9 10.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialisé
 */
std::vector<int> initTabPresqueTri(size_t N)
{
    std::vector<int> tab(N);
    for (int i = 0; i < N; i++)
        tab[i] = i;
    for (int i = 0; i < N - 1; i++)
    {
        if (rand() % 2 == 0)
        {
            std::swap(tab[i], tab[i + 1]);
            ++i;
        }
    }
    return tab;
}

/**
 * Crée un tableau d'entiers presque triés. Seuls le premier et le deuxième élément sont échangés.
 *
 * Un tel tableau peut par exemple être 2 1 3 4 5 6 7 8 9 10.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialisé
 */
std::vector<int> initTabPresqueTriDeb(size_t N)
{
    std::vector<int> tab(N);
    for (int i = 0; i < N; i++)
        tab[i] = i;
    std::swap(tab[0], tab[1]);
    return tab;
}

/**
 * Crée un tableau d'entiers presque triés. Seuls le dernier et l'avant dernier élément sont échangés.
 *
 * Un tel tableau peut par exemple être 1 2 3 4 5 6 7 8 10 9.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialisé
 */
std::vector<int> initTabPresqueTriFin(size_t N)
{
    std::vector<int> tab(N);
    for (int i = 0; i < N; i++)
        tab[i] = i;
    std::swap(tab[N - 1], tab[N - 2]);
    return tab;
}

/**
 * Crée un tableau d'entiers presque triés. Seuls le premier et le dernier élément sont échangés.
 *
 * Un tel tableau peut par exemple être 10 2 3 4 5 6 7 8 9 1.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialisé
 */
std::vector<int> initTabPresqueTriDebFin(size_t N)
{
    std::vector<int> tab(N);
    for (int i = 0; i < N; i++)
        tab[i] = i;
    std::swap(tab[N - 1], tab[0]);
    return tab;
}

/**
 * Vérifie qu'un tableau est correctement trié. Si le tableau est mal trié, un message d'erreur est
 * affiché sur le flux d'erreur et le programme est terminé.
 *
 * \param[in] tab Le tableau à vérifier
 * \param[in] algoName Le nom de l'algorithme de tri qui a été utilisé. Ce paramètre est optionnel.
 */
void verifTri(const std::vector<int>& tab, const std::string& algoName)
{
    const size_t taille = tab.size();
    for (size_t i = 1; i < taille; i++)
    {
        if (tab[i - 1] > tab[i])
        {
            std::cerr << "Erreur dans le tri " << algoName << (algoName.empty() ? "!" : " !") << '\n';
            exit(EXIT_FAILURE);
        }
    }
}


/*
* Tri par selection 
* 
* tab : est un tableau d'entier générer de maniére aléatoire
* 
* return -> Un entier correspondant au nombre de comparaison
*/



size_t triSelection(std::vector<int> tab)
{
    //Initialisation des variable
    int n = tab.size();
    unsigned int cpt = 0;
    //Permet parcourir le tableau une premiére fois
    for (int i = 0; i <= n - 2; i++)
    {
        int min = i;
        //Parcours les tableau une deuxiéme fois pour déterminer le plus petit 
        for (int j = i + 1; j <= n - 1; j++)
        {
            //Compare l'élément actuel avec le mininimum actuel si l'élément actuel est plus petit que min il change le min
            if (tab[j] < tab[min])
            {
                min = j;
                cpt++; // compteur de comparaison
            }
            //Si le minimum n'est pas l'élément a l'indice actuel alors on interchange
            if (min != i)
            {
                //Swap des valeurs
                int temp = tab[i];
                tab[i] = tab[min];
                tab[min] = temp;
                cpt++; //compteur de comparaison
            }
        }

    }
    verifTri(tab); //Verifiction de la justesse du trie
    return cpt; //Retourne le nombre de comparaison
}