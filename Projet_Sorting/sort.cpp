#include "header.h"

int Nbr_Iter = 0;

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

void Repete_Display(std::vector<int>& vec, int Time_Between_Display) {
	for (;;) {
		std::this_thread::sleep_for(std::chrono::milliseconds(Time_Between_Display));
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
		interchange(vec, i, min_id);
		pause();
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
		}
		pause();
	}
}

void sort3(std::vector<int>& vec) {
	for (int nbr_iter = 1; nbr_iter <= vec.size(); ++nbr_iter) {
		for (int i = 0; i < vec.size() - nbr_iter; ++i) {
			if (vec[i + 1] < vec[i])
				interchange(vec, i, i + 1);
			pause();
		}
	}
}
