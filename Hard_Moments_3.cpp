#include <iostream>
#include <string>
#include <utility>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib>

///////////exercise 2

class Matrix {
private:
	int msize;
	std::vector<std::vector <int>> matrix1;
public:
	Matrix() {}
	Matrix(int msize) : msize(msize) {
		for (size_t i = 0; i < msize; i++)
		{
			matrix1.resize(msize);
		}
		for (size_t i = 0; i < msize; i++)
		{
			matrix1[i].resize(msize);
		}
		for (size_t i = 0; i < msize; i++)
		{
			for (size_t j = 0; j < msize; j++)
			{
				matrix1[i][j] = rand() % 20;
			}
		}
	}
	void second_matrix(std::vector<std::vector<int>>& matrix1, std::vector<std::vector<int>> &matrix2, int i, int j, int msize) {
		int ki, kj, di, dj;
		di = 0;
		for (ki = 0; ki < msize -1; ki++)
		{
			if (ki==i)
			{
				di = 1;
			}
			dj = 0;
			for (kj = 0; kj < msize -1; kj++)
			{
				if (kj==j)
				{
					dj = 1;
				}
				matrix2[ki][kj] = matrix1[ki + di][kj + dj];
			}
		}
	}
	int matrix_determinant(std::vector<std::vector<int>> &matrix1, int msize) {
		std::vector<std::vector<int>> matrix2(msize);
		for (size_t i = 0; i < msize; i++)
		{
			matrix2[i].resize(msize);
		}
		int i, j, det, k, sec_size;
		j = 0;
		det = 0;
		k = 1;
		sec_size = msize - 1;
		if (msize <1)
		{
			std::cout << "Can't do that." << std::endl;
		}
		if (msize ==1)
		{
			det = matrix1[0][0];
			return (det);
		}
		if (msize ==2)
		{
			det = matrix1[0][0] * matrix1[1][1] - (matrix1[1][0] * matrix1[0][1]);
			return (det);
		}
		if (msize >2)
		{
			for ( i = 0; i < msize; i++)
			{
				second_matrix(matrix1, matrix2, i, 0, msize);
				det = det + k * matrix1[i][0] * matrix_determinant(matrix2, sec_size);
				k = -k;
			}
		}
		return(det);
	}
	int get_determinant() {
		return matrix_determinant(matrix1, msize);
	}
};

///////////

int main()
{
	/////////// exercise 1
	std::list<double> list1{ 1.25, 2.54 , 5.25, 9.57, 14.88, 59.20 };
	std::list<double>::iterator it1;
	double mid = 0;
	for (it1 = list1.begin(); it1 != list1.end(); it1++)
	{
		mid += *it1;
	}
	mid = mid / list1.size();
	list1.push_back(mid);
	for (it1 = list1.begin(); it1 != list1.end(); it1++)
	{
		std::cout << *it1 << " ";
	}
	std::cout << std::endl;
	/////////////

	/////////// exercise 2

	Matrix matrix(2);
	std::cout << matrix.get_determinant();

	///////////


	system("pause");
	return 0;
}

