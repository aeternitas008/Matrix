#ifndef S21_MATRIX_HPP
#define S21_MATRIX_HPP

#include <math.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

#include <cstring>
#include <iostream>

class S21Matrix {
 private:
  int rows_, cols_;  // Rows and columns
  double** matrix_;  // Pointer to the memory where the matrix is allocated

 public:
  S21Matrix();  // Default constructor
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  ~S21Matrix();  // Destructor

  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  int GetRows() const;
  int GetCols() const;
  void SetRows(int rows);
  void SetCols(int cols);

  double GetNumber(int row, int col);
  void FillMatrix(const double* array, int rows, int cols);
  void MinorMatrix(S21Matrix& A_minor, int scale, int row, int column);

  // some operators overloads
  S21Matrix& operator=(const S21Matrix& o);  // assignment operator overload
  bool operator==(const S21Matrix& o);
  double operator()(int row, int col);  // index operator overload
  double operator()(int row, int col) const;
  S21Matrix& operator+=(const S21Matrix& o);
  S21Matrix operator+(const S21Matrix& o);
  S21Matrix& operator-=(const S21Matrix& o);
  S21Matrix operator-(const S21Matrix& o);
  S21Matrix& operator*=(const S21Matrix& o);
  S21Matrix operator*(const S21Matrix& o);

  friend S21Matrix operator*(double, const S21Matrix&);
  friend S21Matrix operator*(const S21Matrix&, double);
  friend S21Matrix& operator*=(S21Matrix&, double);

  bool IsSquareMatrix() const;
  bool IsCorrectMatrix() const;
  bool IsEqualSize(const S21Matrix& o) const;
};

#endif  // S21_MATRIX_HPP