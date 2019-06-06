
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

private:
  void free();
    
public:
  Matrix(int n);
 ~Matrix(); 
 
  void random(int n = 100);
  void show(int width = 3);
  
  void redim(int n);
  void assign(const Matrix &matrix);
  
  inline
  PMatrixData operator[](int index) {
    return rows[index];
  }
};

#endif

