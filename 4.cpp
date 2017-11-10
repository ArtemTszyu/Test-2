    #include <iostream>
	#include <cstdlib>
	#include <utility>
	#include <sstream>

	using namespace std;
	
	bool read(int & rows, int & columns) {
		bool succ = false;
	

		string stroka;
		getline(cin, stroka);
		istringstream stream(stroka);
	

		char symb;
		if (stream >> rows && rows > 0 &&
			stream >> symb && symb == ',' &&
			stream >> columns && columns > 0) {
			succ = true;
		}
	

		return succ;
	}
	

	bool read_replace(int & replace) {
		bool succ = false;
	

		string stroka;
		getline(cin, stroka);
		istringstream stream(stroka);
	

		char symb;
		if (stream >> replace && replace > -1) {
			succ = true;
		}
	

		return succ;
	}
	

	bool create(int ** & matrix, int & rows, int & columns) {
		bool succ = true;
	

		matrix = new int *[rows];
		for (int i = 0; i < rows; i++) {
			matrix[i] = new int[columns];
			
			string stroka;
			getline(cin, stroka);
			istringstream stream(stroka);
			
			for (int j = 0; j < columns; j++) {
				if (!(stream >> matrix[i][j])) {
					succ = false;
				}
			}
		}
		return succ;
	}
	
	void swap1(int * mass, int n, int replace) {
	for (int i = 0; i < (n - replace) / 2; i++) {
		swap(mass[i], mass[n - replace - 1 - i]);
	}
	for (int i = n - replace, j = 0; i < n - (replace / 2); i++, j++) {
		swap(mass[i], mass[n - 1 - j]);
	}
	for (int i = 0; i < n / 2; i++) {
		swap(mass[i], mass[n - 1 - i]);
	}
}

	void change(int ** matrix, int rows, int columns, int replace) {
		int *mass = new int[2 * (rows + columns) - 4];
		int k = 0;
		
		for (int j = 0, i = 0; j < columns; j++) {
			mass[k] = matrix[i][j];
			k++;
		}
		for (int i = 1, j = columns - 1; i < rows - 1; i++) {
			mass[k] = matrix[i][j];
			k++;
		}
		for (int j = columns - 1, i = rows - 1; j > -1; j--) {
			mass[k] = matrix[i][j];
			k++;
		}
		for (int i = rows - 2, j = 0; i > 0; i--) {
			mass[k] = matrix[i][j];
			k++;
		}
	

		swap1(mass, k, replace);
		k--;
	

		for (int i = 1, j = 0; i < rows - 1; i++) {
			matrix[i][j] = mass[k];
			k--;
		}
		for (int j = 0, i = rows - 1; j < columns; j++) {
			matrix[i][j] = mass[k];
			k--;
		}
		for (int i = rows - 2, j = columns - 1; i > 0; i--) {
			matrix[i][j] = mass[k];
			k--;
		}
		for (int j = columns - 1, i = 0; j > -1; j--) {
			matrix[i][j] = mass[k];
			k--;
		}
	}	

	void write(int ** matrix, int rows, int columns) {
		cout << '\n';
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				cout << matrix[i][j];
				if (j != columns - 1) {
					cout << ' ';
				}
				else {
					cout << '\n';
				}
			}
		}
	}
	
	void delete1(int ** & matrix, int rows) {
		for (int i = 0; i < rows; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
	}
	
	int main()
	{
		int ** matrix = nullptr;
		int rows = 0, columns = 0, replace = 0;
	

		if (read(rows, columns)) {
			if (create(matrix, rows, columns)) {
				if (read_replace(replace)) {
					if (replace <= 2 * (rows + columns) - 4) {
						change(matrix, rows, columns, replace);
						write(matrix, rows, columns);
						delete1(matrix, rows);
					}
					else {
						cout << "An error has occured while reading input data.";
					}
				}
				else {
					cout << "An error has occured while reading input data.";
				}
			}
			else {
				cout << "An error has occured while reading input data.";
			}
		}
		else {
			cout << "An error has occured while reading input data.";
		}
		
		system("pause");
		return 0;
	}
