
#ifndef __matrix_h
#define __matrix_h

typedef int   MatrixData, 
             *PMatrixData;

class Matrix
{
private:
  int          dim;
  MatrixData  *data;
  PMatrixData *rows;  
  
public:
  Matrix(int n);
 ~Matrix(); 
 
  void random(int n = 100);
  void show();
};

#endif

