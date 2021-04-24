#include "header.h"

enum Prog {
	Quitter = 0,
	Parametre,

	Gauche_a_droite,
	MultiThread,
	Droite_a_gauche,
	Tri_Bulle,
	Quick_sort,

	NBR_PROG
};

int main() {

	//initialisation :
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE); //plein écran
	std::vector<int> vec_graph(MAX_HIGHT);	//vecteur à trier

	while (true) {
		system("CLS");
		std::cout
			<< "************************************************\n"
			<< "Quel Programme de tri voulez vous observer ?\n\n"

			<< "0 - Quitter\n"
			<< "1 - Parametres\n\n"

			<< "2 - Gauche a droite\n"
			<< "3 - MultiThread\n"
			<< "4 - Droite a gauche\n"
			<< "5 - Tri Bulle\n"
			<< "6 - Quick_Sort\n\n"
			<< "************************************************\n"
			<< "Votre choix : ";

		int nrep;
		std::string rep;
		std::cin >> rep;
		nrep = std::stoi(rep);
		if (nrep == Quitter) {
			exit(0);
		}
		else if (nrep == Parametre) {
			system("CLS");
			std::cout
				<< "************************************\n"
				<< "************** Params **************\n"
				<< "************************************\n"
				<< "Entrez la nouvelle valeur de temps entre etape (milliseconde) :\n";
			std::string inp;
			std::cin >> inp;

			Set_TIME_BETWEEN_UPDATES(std::stoi(inp));
			continue;
		}
		else if (nrep < 0 || nrep >= NBR_PROG) {
			exit(EXIT_FAILURE);
		}

		//intitialisation du tour :
		Full_Fill(vec_graph);					//remplissage
		shuffle(vec_graph, SHUFFLE_ID);			//mélange
		bool EndOfProg = false;					//lien avec le thread d'affichage

		//lancement du thread d'affichage :
		std::thread th_Display(Repete_Display, std::ref(vec_graph), std::ref(EndOfProg));

		switch (nrep)
		{
		case Gauche_a_droite:
			sort1(vec_graph, 0, vec_graph.size());
			break;
		case MultiThread:
			sort2(vec_graph);
			break;
		case Droite_a_gauche:
			sort3(vec_graph);
			break;
		case Tri_Bulle:
			TriBulle(vec_graph);
			break;
		case Quick_sort:
			Quick_Sort(vec_graph);
			break;
		default:
			exit(EXIT_FAILURE);
			break;
		}


		//fin du process :
		EndOfProg = true; //arret de l'affichage
		th_Display.join();

		std::cout << std::endl;
		system("pause");
	}
}