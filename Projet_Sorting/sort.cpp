#include "header.h"

int Nbr_Iter = 0;
int TIME_BETWEEN_UPDATES = 10;

void Set_TIME_BETWEEN_UPDATES(unsigned int value) {
	TIME_BETWEEN_UPDATES = value;
}

void Full_Fill(std::vector<int>& vec) {
	for (int i = 0; i < vec.size(); ++i) {
		vec[i] = i;
	}
}

void interchange(std::vector<int>& vec, int id_1, int id_2) {
	Nbr_Iter++;
	int temp = vec[id_1];
	vec[id_1] = vec[id_2];
	vec[id_2] = temp;
}

void shuffle(std::vector<int>& vec, int nbr_shuffle) {
	int size = vec.size();
	for (int i = 0; i < nbr_shuffle; ++i) {
		int temp;
		int v1 = rand() % size;
		int v2 = rand() % size;
		while (v1 == v2)
			v2 = rand() % size;

		interchange(vec, v1, v2);
	}
	Nbr_Iter = 0;
}

void display(std::vector<int>& vec) {
	std::string str_disp = "";
	for (int i = 0; i < vec.size(); ++i) {
		for (auto value : vec) {
			if (value >= vec.size() - i)
				str_disp += '|';
			else
				str_disp += ' ';
		}
		str_disp += "\n";
	}
	std::cout << "\t\r" << std::flush << str_disp << "\nNombre d'echange : " << Nbr_Iter;
}

void pause() {
	std::this_thread::sleep_for(std::chrono::milliseconds(TIME_BETWEEN_UPDATES));
}

void Repete_Display(std::vector<int>& vec, bool& End) {
	for (;;) {
		if (End)
			return;
		std::this_thread::sleep_for(std::chrono::milliseconds(TIME_BETWEEN_UPDATES));
		display(vec);
	}
}

void sort1(std::vector<int>& vec, int from, int to) {
	for (int i = from; i < to; ++i) { //pour chaque emplacement
		int min = 999999999;
		int min_id = 0;
		for (int j = i; j < to; ++j) {
			if (vec[j] < min) {
				min = vec[j];
				min_id = j;
			}
		}
		if (i != min_id) {
			interchange(vec, i, min_id);
			pause();
		}
	}
}

void sort2(std::vector<int>& vec) {
	int size = vec.size();
	int second_thread = size / 2;

	std::thread t1(sort1, std::ref(vec), 0, second_thread);
	std::thread t2(sort1, std::ref(vec), second_thread, size);
	t1.join();
	t2.join();
	//seconde partie
	int id_second = second_thread;
	for (int i = 0; i < second_thread; i++) {
		if (vec[i] > vec[id_second]) {
			interchange(vec, i, id_second);
			id_second++;
			pause();
		}
	}
}

void sort3(std::vector<int>& vec) {
	for (int nbr_iter = 1; nbr_iter <= vec.size(); ++nbr_iter) {
		for (int i = 0; i < vec.size() - nbr_iter; ++i) {
			if (vec[i + 1] < vec[i]) {
				interchange(vec, i, i + 1);
				pause();
			}
		}
	}
}

void TriBulle(std::vector<int>& vec) {
	bool stop = false;
	int tmp, j = 0;

	while (!stop) {
		stop = true;

		for (int i = vec.size() - 1; i > j; --i) {
			if (vec[i] < vec[i - 1]) {
				interchange(vec, i, i - 1);
				stop = false;
				pause();
			}
		}
		j++;
	}
}

int Quick_place(std::vector<int>& vec, int debut, int fin) {
	int pivot = vec[debut];
	int gauche = debut + 1;
	int droite = fin;
	int tmp;

	while (gauche <= droite) {
		while (gauche <= droite && (vec[gauche] <= pivot))
			gauche++;
		while (gauche <= droite && (vec[droite] > pivot))
			droite--;
		if (gauche < droite) {
			interchange(vec, droite, gauche);
			gauche++;
			droite--;
			pause();
		}
	}
	//mettre le pivot à sa place :
	vec[debut] = vec[droite];
	vec[droite] = pivot;
	Nbr_Iter++;
	pause();
	return droite;
}

void Quick_Sort(std::vector<int>& vec) {
	int deb, fin, j;
	bool fini = false;

	//création pile :
	int* pile = new int[2 * vec.size()];
	int sommet_pile = -1; deb = 0; fin = vec.size() - 1;

	//boucle principale :

	while (!fini) {
		while (deb < fin) {
			j = Quick_place(vec, deb, fin);
			if (deb < j - 1) {
				//empile partie gauche :
				pile[sommet_pile + 1] = deb;
				pile[sommet_pile + 2] = j - 1;
				sommet_pile = sommet_pile + 2;
			}
			//traite partie droite :
			deb = j + 1;
		}
		if (sommet_pile > 0) { //pile non vide, on dépile :
			fin = pile[sommet_pile];
			deb = pile[sommet_pile - 1];
			sommet_pile = sommet_pile - 2;
		}
		else {
			fini = true;
		}
	}
	delete[] pile;
}