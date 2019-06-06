
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

using namespace std;

Matrix::Matrix(int n)
{
  dim  = 0;
  data = NULL;
  rows = NULL;
  
  redim(n);
}

Matrix::~Matrix()
{
  free();
}

void Matrix::free()
{
  if(dim > 0) {
    delete[] data;
    delete[] rows;
  }
  dim  = 0;
  data = NULL;
  rows = NULL;
}

void Matrix::redim(int n)
{
  if(dim != n)
    free();
  
  dim  = n;
  data = new MatrixData[dim * dim];
  rows = new PMatrixData[dim];
  
  for(int i=0;i < dim;i++)
    rows[i] = data + i*dim;
}

void Matrix::random(int n)
{
  for(int i=0;i < dim*dim;i++)
    data[i] = rand() % n;
}

void Matrix::show(int width)
{
  for(int i=0;i < dim;i++) {
    cout << '|';
    for(int j=0;j < dim;j++)
      cout << setw(width) << rows[i][j];
    cout << '|' << endl;
  }
}

void Matrix::assign(const Matrix &matrix)
{
  // a.assign(b)
  if(dim != matrix.dim) 
    redim(matrix.dim);
  memcpy(data,matrix.data,dim*dim*sizeof(*data));
}

