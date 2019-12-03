#include <iostream>
#include <stdio.h>

const int matrix_size = 5;
class ArrayColumn
{
	friend void sort_matrix(ArrayColumn matrix[]);
	friend void input_matrix(ArrayColumn matrix[]);
	friend void output_matrix(ArrayColumn matrix[]);
	friend void main_function(ArrayColumn matrix[]);

private:
	int column[matrix_size];

public:
	void merge(int* array, int first_element, int middle_element, int last_element)
	{
		int begin_of_left_part = first_element, begin_of_right_part = middle_element + 1, index_of_extra_array = 0;
		int extra_array[last_element - first_element + 1];
		while (begin_of_left_part <= middle_element && begin_of_right_part <= last_element)
		{
			if (array[begin_of_left_part] < array[begin_of_right_part])
			{
				extra_array[index_of_extra_array] = array[begin_of_left_part];
				begin_of_left_part++;
			}
			else
			{
				extra_array[index_of_extra_array] = array[begin_of_right_part];
				begin_of_right_part++;
			}
			index_of_extra_array++;
		}
		while (begin_of_left_part <= middle_element)
		{
			extra_array[index_of_extra_array] = array[begin_of_left_part];
			index_of_extra_array++;
			begin_of_left_part++;
		}
		while (begin_of_right_part <= last_element)
		{
			extra_array[index_of_extra_array] = array[begin_of_right_part];
			index_of_extra_array++;
			begin_of_right_part++;
		}
		for (begin_of_left_part = first_element; begin_of_left_part <= last_element; begin_of_left_part++)
			array[index_of_matrix_value] = extra_array[index_of_matrix_value - first_element];
	}
	void sort_merge_in_rows_increase(int* array, int first_element, int last_element)
	{
		int middle_element = (first_element + last_element) / 2;
		if ((last_element - first_element) > 0)
		{
			sort_merge(array, first_element, middle_element);
			sort_merge(array, middle_element + 1, last_element);
		}
		merge_in_rows_increase(array, first_element, middle_element, last_element);
	}
};
void input_matrix(ArrayColumn matrix[])
{
	std::cout << "Please enter your matrix" << std::endl;
	for (int row_position = 0; row_position < matrix_size; row_position++)
	{
		for (int column_position = 0; column_position < matrix_size; column_position++)
		{
			std::cout << "a[" << row_position << "][" << column_position << "]" << std::endl;
			std::cin >> matrix[row_position].column[column_position];
		}
	}
}
void output_matrix(ArrayColumn matrix[])
{
	std::cout << "Here is the matrix" << std::endl;
	for (int row_position = 0; row_position < matrix_size; row_position++)
	{
		for (int column_position = 0; column_position < matrix_size; column_position++)
		{
			std::cout << matrix[row_position].column[column_position] << '\t';
		}
		std::cout << std::endl;
	}
}

void sort_matrix(ArrayColumn matrix[])
{
	for (int row_position = 0; row_position < matrix_size; row_position++)
	{
		matrix[row_position].sort_merge(matrix[row_position].column, 0, matrix_size - 1);
	}
}
void main_function(ArrayColumn matrix[])
{
	int minimum_value_in_column, product_of_minimum_value_in_column = 1;
	for (int column_position = 0; column_position < matrix_size; column_position++)
	{
		minimum_value_in_column = matrix[0].column[column_position];
		for (int row_position = 0; row_position < matrix_size; row_position++)
		{
			if ((matrix[row_position].column[column_position]) <= minimum_value_in_column)
			{
				minimum_value_in_column = matrix[row_position].column[column_position];
			}
		}
		product_of_minimum_value_in_column *= minimum_value_in_column;
		std::cout << "the minimum " << column_position << "=" << minimum_value_in_column << std::endl;
	}
	std::cout << "product of minimums of each column =" << product_of_minimum_value_in_column << std::endl;
}
int main()
{
	ArrayColumn matrix[matrix_size];
	input_matrix(matrix);
	output_matrix(matrix);
	sort_matrix(matrix);
	output_matrix(matrix);
	main_function(matrix);
	return 0;
}