#include "header.h"

int main() {

	//initialisation :
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE); //plein écran
	std::vector<int> vec_graph(MAX_HIGHT);	//vecteur à trier
	Full_Fill(vec_graph);					//remplissage
	shuffle(vec_graph, SHUFFLE_ID);			//mélange

	//lancement du thread d'affichage :
	std::thread th_Display(Repete_Display, std::ref(vec_graph), TIME_BETWEEN_UPDATES);

	//tris :
	//sort1(vec_graph, 0, vec_graph.size());
	//sort2(vec_graph);
	//sort3(vec_graph);

	//fin du process :
	th_Display.detach();
	display(vec_graph);
}