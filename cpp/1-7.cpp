#include <iostream>

void printMatrix(int matrix[][5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

// 0 the values in the row and column in which a 0 is found in the matrix
// Obviously intent is not to 0 out more rows/columns after they are found
// so I just keep track of the columns and rows that need to be zero'd out
void matrixCancel(int matrix[][5]) {
	bool clearRows[5], clearCols[5];

	for (int i = 0; i < 5; i++) {
		clearRows[i] = false;
		clearCols[i] = false;
	}

	for (int j = 0; j < 5; j++) {
		for (int k = 0; k < 5; k++) {
			if (matrix[j][k] == 0) {
				clearRows[j] = true;
				clearCols[k] = true;
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (clearRows[i] == true || clearCols[j] == true) {
				matrix[i][j] = 0;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	std::cout << "Original matrix: " << std::endl;

	int matrix[5][5] = {
		{11, 13, 14, 0, 2},
		{3, 2, -1, 5, 0},
		{0, 10, 5, 2000, 6},
		{1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1}
	};

	printMatrix(matrix);

	matrixCancel(matrix);

	printMatrix(matrix);

	return 0;
}


