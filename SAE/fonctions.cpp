/**
 * \file fonctions.cpp
 *
 * D�finition des fonctions fournies.
 */
#include "fonctions.h"
#include <iostream>

 /**
  * Cr�e un tableau d'entiers dont tous les �l�ments sont choisis al�atoirement.
  *
  * Un tel tableau peut par exemple �tre 30968 28073 31177 2882 6140 17999 13828 20039 2310 24865.
  *
  * \param[in] N taille du tableau
  * \return le tableau initialis�
  */
std::vector<int> initTabAleat(size_t N)
{
    std::vector<int> tab(N);
    for (auto& val : tab)
        val = rand();
    return tab;
}

/**
 * Cr�e un tableau d'entiers presque tri�s. Chaque �l�ment est quasiment � sa place d�finitive, �chang� �ventuellement d'une place.
 *
 * Un tel tableau peut par exemple �tre 1 3 2 4 6 5 8 7 9 10.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialis�
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
 * Cr�e un tableau d'entiers presque tri�s. Seuls le premier et le deuxi�me �l�ment sont �chang�s.
 *
 * Un tel tableau peut par exemple �tre 2 1 3 4 5 6 7 8 9 10.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialis�
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
 * Cr�e un tableau d'entiers presque tri�s. Seuls le dernier et l'avant dernier �l�ment sont �chang�s.
 *
 * Un tel tableau peut par exemple �tre 1 2 3 4 5 6 7 8 10 9.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialis�
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
 * Cr�e un tableau d'entiers presque tri�s. Seuls le premier et le dernier �l�ment sont �chang�s.
 *
 * Un tel tableau peut par exemple �tre 10 2 3 4 5 6 7 8 9 1.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialis�
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
 * V�rifie qu'un tableau est correctement tri�. Si le tableau est mal tri�, un message d'erreur est
 * affich� sur le flux d'erreur et le programme est termin�.
 *
 * \param[in] tab Le tableau � v�rifier
 * \param[in] algoName Le nom de l'algorithme de tri qui a �t� utilis�. Ce param�tre est optionnel.
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
*/



size_t triSelection(std::vector<int> tab)
{
    int n = tab.size();
    unsigned int cpt = 0;
    for (int i = 0; i <= n - 2; i++)
    {
        int min = i;
        for (int j = i + 1; j <= n - 1; j++)
        {
            if (tab[j] < tab[min])
            {
                min = j;
                cpt++;
            }

            if (min != i)
            {
                int temp = tab[i];
                tab[i] = tab[min];
                tab[min] = temp;
                cpt++;
            }
        }

    }
    verifTri(tab);
    return cpt;
}