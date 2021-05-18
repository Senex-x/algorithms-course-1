#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <random>       
#include <chrono> 

using namespace std;

int main() {
	int n = 10;
	int div = 100;
	ofstream fout;
	fout.open("D:\\Projects\\Cpp\\tests\\seq.txt", ios_base::app);

	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	default_random_engine randomizer(seed);
	srand((unsigned int)time(NULL));

	vector<vector<int>> matrix(div, vector<int>(div, 0));
	
	for (int k = 1; k <= n; k++) {
		int size = div * k;
		int oldSize = matrix.size();
		for (int i = oldSize; i < size; i++) {
			matrix.push_back(vector<int>(size, 0));
		}
		for (int i = 0; i < oldSize; i++) {
			matrix[i].resize(size);
		}
		for (int i = 0; i < matrix.size(); i++) {
			
			for (int j = 0; j < matrix.size(); j++) {
				if (i >= j) {
					matrix[i][j] = 0;
				}
				else {
					matrix[i][j] = rand() % 2;
				}
			}
		}

		shuffle(matrix.begin(), matrix.end(), randomizer);

		fout << size << endl;
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix.size(); j++) {
				fout << matrix[i][j] << " ";
			}
			fout << endl;
		}
	}

}







