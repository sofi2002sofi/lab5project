#include <iostream>
#include <stdio.h>
class ArrayColumn
{
	friend void sort_Matrix(ArrayColumn matrix[]);
	friend void input_Matrix(ArrayColumn matrix[]);
	friend void output_Matrix(ArrayColumn matrix[]);
	friend void Main_Function(ArrayColumn matrix[]);

private:
	int column[5];

public:
	void merge(int* A, int left, int middle, int right)
	{
		int i = left, j = middle + 1, k = 0;
		int T[right - left + 1];
		while (i <= middle && j <= right)
		{
			if (A[i] < A[j])
			{
				T[k] = A[i];
				i++;
			}
			else
			{
				T[k] = A[j];
				j++;
			}
			k++;
		}
		while (i <= middle)
		{
			T[k] = A[i];
			k++;
			i++;
		}
		while (j <= right)
		{
			T[k] = A[j];
			k++;
			j++;
		}
		for (i = left; i <= right; i++)
			A[i] = T[i - left];
	}
	void sort_merge(int* A, int left, int right)
	{
		/* for (int i = left; i < right; i++)
		std::cout << A[i] << '\t';
	std::cout << std::endl;*/
		int middle = (left + right) / 2;
		if ((right - left) > 0)
		{
			sort_merge(A, left, middle);
			sort_merge(A, middle + 1, right);
		}
		merge(A, left, middle, right);
	}
};
void input_Matrix(ArrayColumn matrix[])
{
	std::cout << "Please enter your matrix" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			std::cout << "a[" << i << "][" << j << "]" << std::endl;
			std::cin >> matrix[i].column[j];
		}
	}
}
void output_Matrix(ArrayColumn matrix[])
{
	std::cout << "Here is the matrix" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			std::cout << matrix[i].column[j] << '\t';
		}
		std::cout << std::endl;
	}
}

void sort_Matrix(ArrayColumn matrix[])
{
	for (int i = 0; i < 5; i++)
	{
		matrix[i].sort_merge(matrix[i].column, 0, 4);
	}
}
void Main_Function(ArrayColumn matrix[])
{
	int min, product = 1;
	for (int j = 0; j < 5; j++)
	{
		min = matrix[0].column[j];
		for (int i = 0; i < 5; i++)
		{
			if ((matrix[i].column[j]) <= min)
			{
				min = matrix[i].column[j];
			}
		}
		product *= min;
		std::cout << "the minimum " << j << "=" << min << std::endl;
	}
	std::cout << "product of minimums =" << product << std::endl;
}
int main()
{
	ArrayColumn matrix[5];
	input_Matrix(matrix);
	output_Matrix(matrix);
	sort_Matrix(matrix);
	output_Matrix(matrix);
	Main_Function(matrix);
	return 0;
}