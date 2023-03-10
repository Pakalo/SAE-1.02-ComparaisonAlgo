/**
 * \file fonctions.cpp
 *
 * D?finition des fonctions fournies.
 */
#include "fonctions.h"
#include <iostream>

 /**
  * Cr?e un tableau d'entiers dont tous les ?l?ments sont choisis al?atoirement.
  *
  * Un tel tableau peut par exemple ?tre 30968 28073 31177 2882 6140 17999 13828 20039 2310 24865.
  *
  * \param[in] N taille du tableau
  * \return le tableau initialis?
  */
std::vector<int> initTabAleat(size_t N)
{
    std::vector<int> tab(N);
    for (auto& val : tab)
        val = rand();
    return tab;
}

/**
 * Cr?e un tableau d'entiers presque tri?s. Chaque ?l?ment est quasiment ? sa place d?finitive, ?chang? ?ventuellement d'une place.
 *
 * Un tel tableau peut par exemple ?tre 1 3 2 4 6 5 8 7 9 10.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialis?
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
 * Cr?e un tableau d'entiers presque tri?s. Seuls le premier et le deuxi?me ?l?ment sont ?chang?s.
 *
 * Un tel tableau peut par exemple ?tre 2 1 3 4 5 6 7 8 9 10.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialis?
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
 * Cr?e un tableau d'entiers presque tri?s. Seuls le dernier et l'avant dernier ?l?ment sont ?chang?s.
 *
 * Un tel tableau peut par exemple ?tre 1 2 3 4 5 6 7 8 10 9.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialis?
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
 * Cr?e un tableau d'entiers presque tri?s. Seuls le premier et le dernier ?l?ment sont ?chang?s.
 *
 * Un tel tableau peut par exemple ?tre 10 2 3 4 5 6 7 8 9 1.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialis?
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
 * V?rifie qu'un tableau est correctement tri?. Si le tableau est mal tri?, un message d'erreur est
 * affich? sur le flux d'erreur et le programme est termin?.
 *
 * \param[in] tab Le tableau ? v?rifier
 * \param[in] algoName Le nom de l'algorithme de tri qui a ?t? utilis?. Ce param?tre est optionnel.
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
            cpt++; // Compteur pour connaitre le nombre de comparaisons d??l?ments
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
    return cpt; // Renvoie cpt, ce qui correspond au nombre de comparaisons d??l?ments
}


/*
* Tri a bulles
*/

unsigned int triBulles(std::vector<int> &tab)
{
    unsigned int cpt = 0; // initialisation compteur de comparaison

    for (size_t i = 0; i < tab.size() - 1; i++) //Double boucle qui parcours les ?l?ments du tableau
    {
        for (size_t j = 0; j < tab.size() - i - 1; j++)
        {
            cpt++; //Incr?mentation du compteur

            //Echange les l'?l?ment actuel et le plus petit si ce l'?l?ment actuel est plus petit
            if (tab[j + 1] < tab[j])
            {
                std::swap(tab[j + 1], tab[j]);
            }
        }
    }
    return cpt; //Renvoie le nbr de comparaison
}


/*
* Tri a bulles optimis?
*/
unsigned int triBullesOpti(std::vector<int> &tab)
{
    unsigned int cpt = 0;// initialisation compteur de comparaison

    //Boucle qui parcours les ?l?ment de tableau ? l'envers
    for (size_t i = tab.size() - 1; i > 0; i--)
    {
        bool tableau_trie = true; //Bool pour inscrire si le tableau est tri? ou non

        //boucle qui parcours pour comparer les ?l?ments
        for (int j = 0; j < i; j++)
        {
            cpt++; // Incr?mentation du compteur de comparaison


            //Si pr?c?dent plus petit que l'?lem actuel on ?change et on met tableau tri? ? false
            if (tab[j + 1] < tab[j])
            {
                std::swap(tab[j + 1], tab[j]);
                tableau_trie = false;
            }
        }
        //Sort de la boucle si le tableau est tri?
        if (tableau_trie)
        {
            break;
        }
    }
    return cpt; //Renvoie le nbr de comparaison
}



/*
* Tri a bulles optimis?
*/
unsigned int triPeigne(std::vector<int> &tab)
{
    size_t intervalle = tab.size(); // D?fini l'intervale entre les ?l?ments ? comparer
    bool echange; // Contient si il y a eu un ?change durant le dernier parcours
    int cpt = 0; // Initialisation compteur de comparaison


    //Boucle principale
    while (intervalle > 1 || echange == true)
    {
        intervalle = int(intervalle / 1.3); //Calcule l'intervale pour le prochain parcours
        
        // Verrifie si l'intervalle est au moins de 1
        if (intervalle < 1)
            intervalle = 1; 

        int i = 0; //Indice de l'?l?ment en cours
        echange = false; // r?initialise la valeur d'?change


        // parcour le tab et compare les ?l?ment selon l'intervale
        while (i < tab.size() - intervalle)
        {
            cpt++; // Incr?mentation du compteur de comparaison

            //echange l'?l?ment suivant et l'?l?ment en cours si le suivant est plus petit que celui en cours et l'indique gr?ce au bool?en ?change
            if (tab[i] > tab[i + intervalle])
            {
                std::swap(tab[i], tab[i + intervalle]);
                echange = true;
            }
            i = i + 1; //Passage ? l'?l?ment suivant
        }
    }

    return cpt;//Renvoie le nbr de comparaison
}



unsigned int partitionner(std::vector<int> &tab, int premier, int dernier, int pivot, unsigned int& cpt)
{
    //Echange pivot avec le pr?c?dent
    std::swap(tab[pivot], tab[dernier]);
    int j = premier; //indice de pivot

    //Parcours le tableau et partitione en fonction du pivot
    for (size_t i = premier; i <= dernier - 1; i++)
    {
        //Si l'?l?ment est plus petit ou ?gal au pivot on incr?mente l'indice du pivot et on ?change l'?l?ment avec le pivot
        if (tab[i] <= tab[dernier])
        {
            std::swap(tab[i], tab[j]);
            j++;
        }
        cpt++;// Incr?mentation du compteur de comparaison
    }
    std::swap(tab[dernier], tab[j]); // Echange le pivot et l'?l?ment ? sa position finale
    return j; //Retourne le pivot
}


unsigned int choixPivot(std::vector<int> &tab, int premier, int dernier)
{
    //Initialisation de l'al?atoire
    std::srand(std::time(nullptr));
    std::rand(); std::rand();
    //Cette fonction g?n?re un nombre al?atoire entre deux nombres
    return static_cast<unsigned int>(static_cast<double>(dernier - premier + 1) * std::rand() / (RAND_MAX + 1)) + premier;
}


unsigned int triRapide(std::vector<int> &tab, int premier, int dernier)
{
    unsigned int cpt = 0; // Initialisation compteur de comparaison
   
    //Verifie que la taille du tableau est sup?rieur au dernier
    if (premier < dernier)
    {
        //Choisis et partitionne un pivot
        int pivot = choixPivot(tab, premier, dernier);
        pivot = partitionner(tab, premier, dernier, pivot, cpt);
        //Fait le trie rapide de mani?re r?cursive
        cpt += triRapide(tab, premier, pivot - 1);
        cpt += triRapide(tab, pivot + 1, dernier);
    }
    return cpt;//Renvoie le nbr de comparaison
}