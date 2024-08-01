#include "s21_matrix.h"

void S21Matrix::PrintMatrix() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      printf("%f ", matrix_[i][j]);
    }
    printf("\n");
  }
}

int S21Matrix::GetRows() const { return rows_; }

int S21Matrix::GetCols() const { return rows_; }

void S21Matrix::SetRows(int rows) { rows_ = rows; }

void S21Matrix::SetCols(int cols) { cols_ = cols; }

double S21Matrix::GetNumber(int row, int col) { return matrix_[row][col]; }

void S21Matrix::SetNumber(int row, int col, double number) {
  matrix_[row][col] = number;
}

S21Matrix::S21Matrix() { rows_ = 0, cols_ = 0, matrix_ = nullptr; }

S21Matrix::~S21Matrix() {
  if (matrix_) {
    // free
    delete[] matrix_;
  }
}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  matrix_ = new double*[rows_];
  for (int row = 0; row < rows; ++row) {
    matrix_[row] = new double[cols_];
    ;
  }
}

S21Matrix::S21Matrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    delete[] matrix_;
    (*this) = S21Matrix(other.rows_, other.cols_);
  }
  for (int row = 0; row < rows_; ++row) {
    memcpy(matrix_[row], other.matrix_[row], other.cols_ * sizeof(double));
  }
}

//объединить однотипные функции с перебором всех элементов и проверять
//корректность входных параметров
void S21Matrix::SumMatrix(const S21Matrix& other) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      this->matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      this->matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

bool S21Matrix::IsValid() {
  if (rows_ >= 0 && cols_ >= 0)
    return true;
  else
    return false;
}

void S21Matrix::MulNumber(const double number) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      this->matrix_[i][j] *= number;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= other.matrix_[i][j];
    }
  }
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(rows_, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix_[i][j] = matrix_[j][i];
    }
  }
  return result;
}

void S21Matrix::MinorMatrix(S21Matrix& A_minor, int scale, int row,
                            int column) {
  int skip_i, skip_j = 0;
  for (int i = 0; i < scale; i++) {
    skip_j = 0;
    if (i == row) {
      skip_i = 1;
      continue;
    }
    for (int j = 0; j < scale; j++) {
      if (j == column) {
        skip_j = 1;
        continue;
      }
      (A_minor).matrix_[i - skip_i][j - skip_j] = matrix_[i][j];
    }
  }
}

S21Matrix S21Matrix::CalcComplements() {
  int code = OK;
  S21Matrix result(rows_, cols_);
  if (IsValid()) {
    perror(ERROR_MATRIX_STR);
  } else if (rows_ != cols_) {
    perror(ERROR_CALC_STR);
  } else {
    int scale = rows_;
    S21Matrix A_minor(scale - 1, scale - 1);
    for (int row = 0; row < scale && code != ERROR_CALC; row++) {
      for (int column = 0; column < scale && code != ERROR_CALC; column++) {
        MinorMatrix(A_minor, scale, row, column);
        double coefficient = ((column + row) % 2 == 0) ? 1 : -1;
        double minor = A_minor.Determinant();
        if (std::isinf(minor) || std::isnan(minor)) {
          code = ERROR_CALC;
          result.~S21Matrix();
        } else {
          result.matrix_[row][column] = coefficient * minor;
        }
      }
    }
    A_minor.~S21Matrix();
  }
  return result;
}

double S21Matrix::Determinant() {
  double result = 0;
  int scale = rows_;
  if (scale == 1) {
    result = matrix_[0][0];
  } else if (scale == 2) {
    result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    S21Matrix A_minor = S21Matrix(scale - 1, scale - 1);
    for (int col = 0; col < scale; col++) {
      MinorMatrix(A_minor, scale, 0, col);
      double coefficient = (col % 2 == 0) ? 1 : -1;
      result += matrix_[0][col] * coefficient * A_minor.Determinant();
    }
    A_minor.~S21Matrix();
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  int code = OK;
  S21Matrix result;
  if (this == NULL || IsValid()) {
    perror(ERROR_MATRIX_STR);
  } else if (rows_ != cols_) {
    perror(ERROR_CALC_STR);
  } else {
    S21Matrix result(rows_, cols_);
    int scale = rows_;
    double determinant = Determinant();
    if (determinant == 0 || std::isinf(determinant) ||
        std::isnan(determinant)) {
      this->~S21Matrix();
      // throw may be
      perror(ERROR_CALC_STR);
    } else if (scale == 1) {
      result.matrix_[0][0] = 1 / matrix_[0][0];
    } else {
      S21Matrix RawMatrix(scale, scale);
      RawMatrix = CalcComplements();
      S21Matrix RawMatrix2(scale, scale);
      if (!code) RawMatrix2 = RawMatrix.Transpose();
      if (!code) RawMatrix2.MulNumber((1.0 / determinant));
      result = RawMatrix2;
      RawMatrix.~S21Matrix();
      RawMatrix2.~S21Matrix();
    }
  }
  return result;
}

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool result = true;
  for (int i = 0; i < other.rows_ && result; i++) {
    for (int j = 0; j < other.cols_ && result; j++) {
      if (fabs(other.matrix_[i][j] - matrix_[i][j]) >= 1e-6) result = false;
    }
  }
  return result;
}

// index operator overload
double S21Matrix::operator()(int row, int col) {
  if (row >= rows_ || col >= cols_) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[row][col];
}

double S21Matrix::operator()(int row, int col) const {
  if (row >= rows_ || col >= cols_) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[row][col];
}

S21Matrix& S21Matrix::operator=(const S21Matrix& o) {
  (*this).~S21Matrix();
  *this = S21Matrix(o);
  return (*this);
}

bool S21Matrix::operator==(const S21Matrix& o) { return EqMatrix(o); }

S21Matrix S21Matrix::operator+(const S21Matrix& o) {
  S21Matrix res(rows_, cols_);
  res.SumMatrix(*this);
  res.SumMatrix(o);
  return res;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& o) {
  // creating result matrix
  SumMatrix(o);
  return *this;
}

S21Matrix S21Matrix::operator-(const S21Matrix& o) {
  // creating result matrix
  S21Matrix res(rows_, cols_);
  res.SubMatrix(*this);
  res.SubMatrix(o);
  return res;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& o) {
  SubMatrix(o);
  return *this;
}

S21Matrix operator*(double num, S21Matrix& matr) {
  S21Matrix res(matr);
  res.MulNumber(num);
  return res;
}

S21Matrix operator*(S21Matrix& matr, double num) {
  S21Matrix res(matr);
  res = matr * num;
  return res;
}

S21Matrix& operator*=(S21Matrix& matr, double num) {
  matr.MulNumber(num);
  return matr;
}

S21Matrix& operator*=(double num, S21Matrix& matr) {
  matr *= num;
  return matr;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& o) {
  MulMatrix(o);
  return *this;
}

S21Matrix S21Matrix::operator*(const S21Matrix& o) {
  // creating result matrix
  S21Matrix res(*this);
  res.MulMatrix(o);
  return res;
}

int main() {
  S21Matrix matr(2, 2);
  S21Matrix matr2(2, 2);
  S21Matrix result(2, 2);
  matr.SetNumber(1, 0, 10);
  matr.PrintMatrix();
  matr2.SetNumber(1, 1, 10);
  matr2.PrintMatrix();
  // S21Matrix matr3 = matr.SubMatrix(matr2);
  matr.SumMatrix(matr2);
  matr.PrintMatrix();
  matr.SetNumber(0, 1, 10);
  double determ = matr.Determinant();
  printf("ok ");
  printf("determinant %f\n", determ);

  matr += matr2;
  matr += matr2;
  matr.PrintMatrix();
  printf("index %f\n", matr(1, 1));
}