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

unsigned int triSelection(std::vector<int> &tab)
{
    size_t n = tab.size(); // Initialisation de n en fonction de la taille du tableau
    unsigned int cpt = 0;
    for (int i = 0; i <= n - 2; i++) // 
    {
        int min = i;
        for (int j = i + 1; j <= n-1; j++) 
        {
            cpt++; // Compteur pour connaitre le nombre de comparaisons d��l�ments
            if (tab[j] < tab[min])
            {
                min = j;
            }
        }
            if (min != i)
            {
                std::swap(tab[i], tab[min]);
            }
    }
    return cpt; // Renvoie cpt, ce qui correspond au nombre de comparaisons d��l�ments
}


/*
* Tri a bulles
*/

unsigned int triBulles(std::vector<int> &tab)
{
    unsigned int cpt = 0;
    for (size_t i = 0; i < tab.size() - 1; i++) // Double boucle pour parcourir chaque �l�ment du tableau
    {
        for (size_t j = 0; j < tab.size() - i - 1; j++)
        {
            cpt++;
            if (tab[j + 1] < tab[j])
            {
                std::swap(tab[j + 1], tab[j]);
            }
        }
    }

    verifTri(tab);
    return cpt;
}


/*
* Tri a bulles optimis�
*/
unsigned int triBullesOpti(std::vector<int> &tab)
{
    unsigned int cpt = 0;
    for (size_t i = tab.size() - 1; i > 0; i--)
    {
        bool tableau_trie = true;
        for (int j = 0; j < i; j++)
        {
            cpt++;
            if (tab[j + 1] < tab[j])
            {
                std::swap(tab[j + 1], tab[j]);
                tableau_trie = false;
            }
        }
        if (tableau_trie)
        {
            break;
        }
    }
    return cpt;
}



/*
* Tri a bulles optimis�
*/
unsigned int triPeigne(std::vector<int> &tab)
{
    size_t intervalle = tab.size();
    bool echange;
    int cpt = 0;

    while (intervalle > 1 || echange == true)
    {
        intervalle = int(intervalle / 1.3);
        if (intervalle < 1)
            intervalle = 1;

        int i = 0;
        echange = false;

        while (i < tab.size() - intervalle)
        {
            cpt++;
            if (tab[i] > tab[i + intervalle])
            {
                std::swap(tab[i], tab[i + intervalle]);
                echange = true;
            }
            i = i + 1;
        }
    }

    verifTri(tab);
    return cpt;
}



unsigned int partitionner(std::vector<int> tab, int premier, int dernier, int pivot, unsigned int& cpt)
{
    std::swap(tab[pivot], tab[dernier]);
    int j = premier;
    for (size_t i = premier; i < dernier - 1; i++)
    {
        if (tab[i] <= tab[dernier])
        {
            std::swap(tab[i], tab[j]);
            j++;
        }
        cpt++;
    }
    std::swap(tab[dernier], tab[j]);
    return j;
}


unsigned int choixPivot(std::vector<int> tab, int premier, int dernier)
{
    //Initialisation de l'al�atoire
    std::srand(std::time(nullptr));
    std::rand(); std::rand();
    //Cette fonction g�n�re un nombre al�atoire entre deux nombres
    return static_cast<unsigned int>(static_cast<double>(dernier - premier + 1) * std::rand() / (RAND_MAX + 1)) + premier;
}


unsigned int triRapide(std::vector<int> tab, int premier, int dernier)
{
    unsigned int cpt = 0;
    if (premier < dernier)
    {
        int pivot = choixPivot(tab, premier, dernier);
        pivot = partitionner(tab, premier, dernier, pivot, cpt);
        cpt += triRapide(tab, premier, pivot - 1);
        cpt += triRapide(tab, pivot + 1, dernier);
    }
    return cpt;
}

