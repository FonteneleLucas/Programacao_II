
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

Matrix::Matrix(int n)
{
  dim  = n;
  data = new MatrixData[dim * dim];
  rows = new PMatrixData[dim];
  
  for(int i=0;i < dim;i++)
    rows[i] = data + i*dim;
}

Matrix::~Matrix()
{
  delete[] rows;
  delete[] data;
}

void Matrix::random(int n)
{
  for(int i=0;i < dim*dim;i++)
    data[i] = rand() % n;
}


