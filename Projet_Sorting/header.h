#ifndef HEADER_SORT_H
#define HEADER_SORT_H

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <windows.h>

#define MAX_HIGHT 49				//dimension du graphique
#define SHUFFLE_ID 120				//nombre d'int�ration de m�lange
//#define TIME_BETWEEN_UPDATES 30	//Temps en millisecondes qui s'�coule entre chaque �tape de tri.

void Set_TIME_BETWEEN_UPDATES(unsigned int value);

/**
 * Remplis le vecteur avec des entiers de 0 � sa taille.
 *
 * \param vec : vecteur d'entier � remplir
 */
void Full_Fill(std::vector<int>& vec);

/**
 * �change les valeurs de deux indexes du vecteur.
 *
 * \param vec : vecteur cible
 * \param id_1 : index de la premiere valeur � �changer
 * \param id_2 : index de la seconde valeur � �changer
 */
void interchange(std::vector<int>& vec, int id_1, int id_2);

/**
 * �change al�atoirement les valeurs du vecteur un nombre d'it�ration pr�cis.
 *
 * \param vec : vecteur � m�langer
 * \param nbr_shuffle : nombre d'�change � effectuer
 */
void shuffle(std::vector<int>& vec, int nbr_shuffle);

/**
 * Affiche le contenu du vecteur en forme de graphique batons.
 *
 * \param vec : vecteur � afficher
 */
void display(std::vector<int>& vec);

/**
 * Applique une pause dans l'�xecution du programme
 */
void pause();

/**
 * R�p�te l'affichage du vecteur � interval de temps r�gulier.
 *
 * \param vec : vecteur � afficher
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
 * Trie ind�pendament 2 parties du tab sur 2 threads.
 *
 * \param vec : vecteur cible
 */
void sort2(std::vector<int>& vec);

/** Tri dans lequel chaque valeur est compr�e � sa voisine afin de les echanger!.
 *
 * \param vec : vecteur cible
 */
void sort3(std::vector<int>& vec);

/**
 * Trie de droite � gauche le tableau.
 *
 * \param vec : vecteur cible
 */
void TriBulle(std::vector<int>& vec);

/**
 * Fonction appel�e par Quick_sort() qui interchange les valeurs
 *
 * \param vec :		vecteur cible
 * \param debut :	borne inf�rieure
 * \param fin :		borne supp�rieure
 */
int Quick_place(std::vector<int>& vec, int debut, int fin);

/**
 * Trie de tableau tres optimis�
 *
 * \param vec : vecteur cible
 */
void Quick_Sort(std::vector<int>& vec);

#endif