#include <iostream>
#include <string>
#include <vector>


#define MAX_HIGHT 30
#define SHUFFLE_ID 100


void Full_Fill(std::vector<int>& vec) {
	for (int i = 0; i < MAX_HIGHT; ++i) {
		vec[i] = i;
	}
}

void shuffle(std::vector<int>& vec) {
	for (int i = 0; i < SHUFFLE_ID; ++i) {
		int temp;

		int v1 = rand() % MAX_HIGHT;
		int v2 = rand() % MAX_HIGHT;
		while(v1 == v2)
			v2 = rand() % MAX_HIGHT;

		temp = vec[v1];
		vec[v1] = vec[v2];
		vec[v2] = temp;
	}
}

void display(std::vector<int>& vec) {
	for (int i = 0; i < MAX_HIGHT; ++i) {
		for (auto value : vec) {
			if (value >= MAX_HIGHT - i)
				std::cout << '|';
			else
				std::cout << ' ';
		}
		std::cout << std::endl;
	}
}

int main() {

	std::vector<int> vec_graph(MAX_HIGHT);
	Full_Fill(vec_graph);
	shuffle(vec_graph);
	display(vec_graph);
}