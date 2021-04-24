#ifndef HEADER_SORT_H
#define HEADER_SORT_H

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <windows.h>

#define MAX_HIGHT 49				//dimension du graphique
#define SHUFFLE_ID 120				//nombre d'intération de mélange
//#define TIME_BETWEEN_UPDATES 30	//Temps en millisecondes qui s'écoule entre chaque étape de tri.

void Set_TIME_BETWEEN_UPDATES(unsigned int value);

/**
 * Remplis le vecteur avec des entiers de 0 à sa taille.
 *
 * \param vec : vecteur d'entier à remplir
 */
void Full_Fill(std::vector<int>& vec);

/**
 * échange les valeurs de deux indexes du vecteur.
 *
 * \param vec : vecteur cible
 * \param id_1 : index de la premiere valeur à échanger
 * \param id_2 : index de la seconde valeur à échanger
 */
void interchange(std::vector<int>& vec, int id_1, int id_2);

/**
 * échange aléatoirement les valeurs du vecteur un nombre d'itération précis.
 *
 * \param vec : vecteur à mélanger
 * \param nbr_shuffle : nombre d'échange à effectuer
 */
void shuffle(std::vector<int>& vec, int nbr_shuffle);

/**
 * Affiche le contenu du vecteur en forme de graphique batons.
 *
 * \param vec : vecteur à afficher
 */
void display(std::vector<int>& vec);

/**
 * Applique une pause dans l'éxecution du programme
 */
void pause();

/**
 * Répète l'affichage du vecteur à interval de temps régulier.
 *
 * \param vec : vecteur à afficher
 */
void Repete_Display(std::vector<int>& vec, bool& End);

/**
 * Trie le tableau en prenant chaque emplacement un par un et
 * en y affectant le minimum restant dans le tableau.
 *
 * \param vec : vecteur cible
 */
void sort1(std::vector<int>& vec, int from, int to);

/**
 * Trie indépendament 2 parties du tab sur 2 threads.
 *
 * \param vec : vecteur cible
 */
void sort2(std::vector<int>& vec);

/** Tri dans lequel chaque valeur est comprée à sa voisine afin de les echanger!.
 *
 * \param vec : vecteur cible
 */
void sort3(std::vector<int>& vec);

/**
 * Trie de droite à gauche le tableau.
 *
 * \param vec : vecteur cible
 */
void TriBulle(std::vector<int>& vec);

/**
 * Fonction appelée par Quick_sort() qui interchange les valeurs
 *
 * \param vec :		vecteur cible
 * \param debut :	borne inférieure
 * \param fin :		borne suppérieure
 */
int Quick_place(std::vector<int>& vec, int debut, int fin);

/**
 * Trie de tableau tres optimisé
 *
 * \param vec : vecteur cible
 */
void Quick_Sort(std::vector<int>& vec);

#endif