#include "Matrix.h"
#include <assert.h>
#include <sstream>

Matrix::Matrix() {}

Matrix::Matrix(int height, int width)
{
	this->height = height;
	this->width = width;
	this->array = std::vector<std::vector<double> >(height, std::vector<double>(width));
}

Matrix::Matrix(std::vector<std::vector<double> > const &array)
{
	assert(array.size() != 0);
	this->height = array.size();
	this->width = array[0].size();
	this->array = array;
}

Matrix Matrix::multiply(double const &value)
{
	Matrix result(height, width);
	int i, j;

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			result.array[i][j] = array[i][j] * value;
		}
	}

	return result;
}

Matrix Matrix::add(Matrix const &m) const
{
	assert(height == m.height && width == m.width);

	Matrix result(height, width);
	int i, j;

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			result.array[i][j] = array[i][j] + m.array[i][j];
		}
	}

	return result;
}

Matrix Matrix::subtract(Matrix const &m) const
{
	assert(height == m.height && width == m.width);

	Matrix result(height, width);
	int i, j;

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			result.array[i][j] = array[i][j] - m.array[i][j];
		}
	}

	return result;
}

Matrix Matrix::multiply(Matrix const &m) const
{
	assert(height == m.height && width == m.width);

	Matrix result(height, width);
	int i, j;

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			result.array[i][j] = array[i][j] * m.array[i][j];
		}
	}
	return result;
}

Matrix Matrix::dot(Matrix const &m) const
{
	assert(width == m.height);

	int i, j, h, mwidth = m.width;
	double w = 0;

	Matrix result(height, mwidth);

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < mwidth; j++)
		{
			for (h = 0; h < width; h++)
			{
				w += array[i][h] * m.array[h][j];
			}
			result.array[i][j] = w;
			w = 0;
		}
	}

	return result;
}

Matrix Matrix::transpose() const // ij element becomes ji element
{
	Matrix result(width, height);
	int i, j;

	for (i = 0; i < width; i++) {
		for (j = 0; j < height; j++) {
			result.array[i][j] = array[j][i];
		}
	}
	return result;
}

Matrix Matrix::applyFunction(double(*function)(double)) const // takes as parameter a function which prototype looks like : double function(double x)
{
	Matrix result(height, width);
	int i, j;

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++) {
			result.array[i][j] = (*function)(array[i][j]);
		}
	}

	return result;
}
