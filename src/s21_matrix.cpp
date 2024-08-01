#include "s21_matrix.hpp"

// helper functions

void S21Matrix::FillMatrix(const double* array, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix_[i][j] = array[i * cols + j];
    }
  }
}

bool S21Matrix::IsSquareMatrix() const { return (rows_ == cols_); }

bool S21Matrix::IsCorrectMatrix() const {
  return (rows_ > 0 && cols_ > 0 && matrix_ != nullptr);
}

bool S21Matrix::IsEqualSize(const S21Matrix& o) const {
  return (rows_ == o.rows_ && cols_ == o.cols_);
}

int S21Matrix::GetRows() const { return rows_; }

int S21Matrix::GetCols() const { return cols_; }

void S21Matrix::SetRows(int rows) {
  if (rows <= 0) throw std::length_error("Array size can't be zero");
  S21Matrix tmp(rows, cols_);
  for (int i = 0; i < (rows_ < rows ? rows_ : rows); ++i)
    for (int j = 0; j < cols_; ++j) tmp.matrix_[i][j] = (*this).matrix_[i][j];
  *this = std::move(tmp);
}

void S21Matrix::SetCols(int cols) {
  if (cols <= 0) throw std::length_error("Array size can't be zero");
  S21Matrix tmp(rows_, cols);
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < (cols_ < cols ? cols_ : cols); ++j)
      tmp.matrix_[i][j] = (*this).matrix_[i][j];
  *this = std::move(tmp);
}

double S21Matrix::GetNumber(int row, int col) { return matrix_[row][col]; }

S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::~S21Matrix() {
  if (matrix_) {
    delete[] matrix_;
  }
}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows_ <= 0 || cols_ <= 0) {
    throw std::out_of_range("Incorrect matrix or not square matrix");
  }
  matrix_ = new double*[rows_];
  for (int row = 0; row < rows; ++row) {
    matrix_[row] = new double[cols_];
  }
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  matrix_ = nullptr;
  matrix_ = new double*[rows_];
  for (int row = 0; row < rows_; ++row) {
    matrix_[row] = new double[cols_];
  }
  if (rows_ > 0 && cols_ > 0) {
    for (int row = 0; row < rows_; ++row) {
      memcpy(matrix_[row], other.matrix_[row], other.cols_ * sizeof(double));
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
    other.rows_ = 0;
    other.cols_ = 0;
    other.matrix_ = nullptr;
}

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  if (!IsCorrectMatrix() || !other.IsCorrectMatrix() || !IsEqualSize(other)) {
    throw std::out_of_range("Incorrect matrix or different size matrix");
  }
  bool result = true;
  for (int i = 0; i < other.rows_ && result; i++) {
    for (int j = 0; j < other.cols_ && result; j++) {
      if (fabs(other.matrix_[i][j] - matrix_[i][j]) >= 1e-6) result = false;
    }
  }
  return result;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (!IsCorrectMatrix() || !other.IsCorrectMatrix() || !IsEqualSize(other)) {
    throw std::out_of_range("Incorrect matrix or different size matrix");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      this->matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (!IsCorrectMatrix() || !other.IsCorrectMatrix() || !IsEqualSize(other)) {
    throw std::out_of_range("Incorrect matrix or different size matrix");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      this->matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double number) {
  if (!IsCorrectMatrix()) {
    throw std::out_of_range("Incorrect matrix");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      this->matrix_[i][j] *= number;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (!IsCorrectMatrix() || !other.IsCorrectMatrix() ||
      (cols_ != other.rows_)) {
    throw std::out_of_range("Incorrect matrix or incorrect size matrix");
  }
  S21Matrix res(rows_, other.cols_);
  for (int row = 0; row < rows_; row++) {
    for (int col = 0; col < other.cols_; col++) {
      for (int k = 0; k < cols_; k++) {
        res.matrix_[row][col] += matrix_[row][k] * other.matrix_[k][col];
      }
    }
  }
  *this = res;
}

S21Matrix S21Matrix::Transpose() {
  if (!IsCorrectMatrix()) {
    throw std::out_of_range("Incorrect matrix");
  }
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix_[i][j] = matrix_[j][i];
    }
  }
  return result;
}

void S21Matrix::MinorMatrix(S21Matrix& A_minor, int scale, int row,
                            int column) {
  int minor_row = 0, minor_col = 0;  // Счетчики для индексов A_minor
  for (int i = 0; i < scale; i++) {
    if (i == row) {
      continue;  // Пропускаем строку, которую нужно удалить
    }
    minor_col = 0;
    for (int j = 0; j < scale; j++) {
      if (j == column) {
        continue;  // Пропускаем столбец, который нужно удалить
      }
      A_minor.matrix_[minor_row][minor_col] = matrix_[i][j];
      minor_col++;
    }
    minor_row++;
  }
}

S21Matrix S21Matrix::CalcComplements() {
  if (!IsCorrectMatrix() || !IsSquareMatrix()) {
    throw std::out_of_range("Incorrect matrix or not square matrix");
  }
  S21Matrix result(rows_, cols_);
  int scale = rows_;
  S21Matrix A_minor(scale - 1, scale - 1);
  for (int row = 0; row < scale; row++) {
    for (int column = 0; column < scale; column++) {
      MinorMatrix(A_minor, scale, row, column);
      double coefficient = ((column + row) % 2 == 0) ? 1 : -1;
      double minor = A_minor.Determinant();
      result.matrix_[row][column] = coefficient * minor;
    }
  }
  return result;
}

double S21Matrix::Determinant() {
  if (!IsCorrectMatrix() || !IsSquareMatrix()) {
    throw std::out_of_range("Incorrect matrix or not square matrix");
  }
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
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  double determinant = Determinant();
  S21Matrix result;
  int scale = rows_;
  if (determinant == 0 || std::isinf(determinant) || std::isnan(determinant)) {
    throw std::out_of_range("Determinant is 0 or is incorrect");
  } else if (scale == 1) {
    result.matrix_[0][0] = 1 / matrix_[0][0];
  } else {
    S21Matrix RawMatrix = CalcComplements();
    S21Matrix RawMatrix2 = RawMatrix.Transpose();
    RawMatrix2.MulNumber((1.0 / determinant));
    result = RawMatrix2;
  }
  return result;
}

double S21Matrix::operator()(int row, int col) {
  if (row >= rows_ || col >= cols_ || row <0 || col < 0) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[row][col];
}

double S21Matrix::operator()(int row, int col) const {
  if (row >= rows_ || col >= cols_ || row <0 || col < 0) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[row][col];
}

S21Matrix& S21Matrix::operator=(const S21Matrix& o) {
  if (this == &o) {
    return *this;
  }
  if (rows_ != o.rows_ || cols_ != o.cols_) {
    delete[] matrix_;
    rows_ = o.rows_;
    cols_ = o.cols_;
    matrix_ = new double*[rows_];
    for (int i = 0; i < rows_; ++i) {
      matrix_[i] = new double[cols_];
    }
  }
  for (int row = 0; row < rows_; ++row) {
    memcpy(matrix_[row], o.matrix_[row], o.cols_ * sizeof(double));
  }
  return *this;
}

bool S21Matrix::operator==(const S21Matrix& o) { return EqMatrix(o); }

S21Matrix S21Matrix::operator+(const S21Matrix& o) {
  S21Matrix res(*this);
  res.SumMatrix(o);
  return res;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& o) {
  SumMatrix(o);
  return *this;
}

S21Matrix S21Matrix::operator-(const S21Matrix& o) {
  S21Matrix res(*this);
  res.SubMatrix(o);
  return res;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& o) {
  SubMatrix(o);
  return *this;
}

S21Matrix operator*(const S21Matrix& matr, double num) {
  S21Matrix res(matr);
  res.MulNumber(num);
  return res;
}

S21Matrix operator*(double num, const S21Matrix& matr) { return matr * num; }

S21Matrix& operator*=(S21Matrix& matr, double num) {
  matr.MulNumber(num);
  return matr;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& o) {
  MulMatrix(o);
  return *this;
}

S21Matrix S21Matrix::operator*(const S21Matrix& o) {
  S21Matrix res(*this);
  res.MulMatrix(o);
  return res;
}

// int main() {
//   S21Matrix matr(2, 2);
//   S21Matrix matr2(2, 2);
//   matr.SetNumber(1, 0, 10);
//   matr.PrintMatrix();
//   matr2.SetNumber(1, 1, 10);
//   matr2.PrintMatrix();
//   printf("equal %d\n", matr.EqMatrix(matr2));
//   matr.SumMatrix(matr2);
//   matr.PrintMatrix();
//   matr.SubMatrix(matr2);
//   matr.PrintMatrix();
//   matr2.SetNumber(0, 1, 10);
//   matr.SumMatrix(matr2);
//   S21Matrix result = matr.CalcComplements();
//   result.PrintMatrix();
//   printf("base matrix \n");
//   matr.PrintMatrix();
//   S21Matrix result2 = matr.InverseMatrix();
//   printf("inverse matrix \n");
//   result2.PrintMatrix();
//   matr.SetNumber(0, 1, 10);
//   double determ = matr.Determinant();
//   printf("determinant %f\n", determ);
//   matr += matr2;
//   matr.PrintMatrix();
//   printf("index %f\n", matr(1, 1));
// }