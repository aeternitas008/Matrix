#include <iostream>
#include <stdlib.h>
#include <cmath>

#define OK 0
#define ERROR_MATRIX 1
#define ERROR_MEMORY 1
#define ERROR_CALC 2

class S21Matrix {
    private:
        // Attributes
        int rows_, cols_;         // Rows and columns
        double **matrix_;         // Pointer to the memory where the matrix is allocated

    public:
        S21Matrix();              // Default constructor
        S21Matrix(int rows, int cols);
        S21Matrix(const S21Matrix& other);
        ~S21Matrix();             // Destructor

        // bool IsValid();

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
        void SetNumber(int row, int col, double number);

        void PrintMatrix();
        void MinorMatrix(S21Matrix& A_minor, int scale, int row,
                       int column);
};

void S21Matrix::PrintMatrix(){
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            printf("%f ", matrix_[i][j]);
        }
            printf("\n");
    }
}

int S21Matrix::GetRows() const{
    return rows_;
}

int S21Matrix::GetCols() const{
    return rows_;
}

void S21Matrix::SetRows(int rows){
    rows_ = rows;
}

void S21Matrix::SetCols(int cols){
    cols_ = cols;
}

double S21Matrix::GetNumber(int row, int col) {
    return matrix_[row][col];
}

void S21Matrix::SetNumber(int row, int col, double number) {
    matrix_[row][col] = number;
}

S21Matrix::S21Matrix() {
    rows_ = 0, cols_ = 0, matrix_ = nullptr;
}

S21Matrix::~S21Matrix() {
    for (int row = 0; row < rows_; ++row) {
      free(matrix_[row]);
      matrix_[row] = NULL;
    }
    free(matrix_);
    matrix_ = NULL;
}

S21Matrix::S21Matrix(int rows, int cols) {
    rows_ = rows;
    cols_ = cols;
    matrix_ = (double**)calloc(rows, sizeof(double *));
    for (int row = 0; row < rows; ++row) {
      matrix_[row] = (double *)calloc(cols, sizeof(double));
    }
}

S21Matrix::S21Matrix(const S21Matrix& other) {
    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = (double**)calloc(rows_, sizeof(double *));
    for (int row = 0; row < rows_; ++row) {
      matrix_[row] = (double *)calloc(cols_, sizeof(double));
      for(int col = 0; col < cols_; col++) {
        matrix_[row][col] = other.matrix_[row][col];
      }
    }
}

//объединить однотипные функции с перебором всех элементов и проверять корректность входных параметров
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

// bool S21Matrix::IsValid() {
//     if ((*this).row >= 0 && this. >= 0) return true; else return false;
// }

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

// void S21Matrix::CalcComplements() {
//     for (int i = 0; i < (*this).GetRows(); i++) {
//         for (int j = 0; j < (*this).GetCols(); j++) {
//             this->matrix_[i][j] *= other.matrix_[i][j];
//         }
//     }
// }


// void S21Matrix::SubMatrix(const S21Matrix& B) {
//   int code = OK;
//   if (result == NULL || invalid_matrix(A) || invalid_matrix(B)) {
//     return ERROR_MATRIX;
//   } else if (is_not_equal_rows_columns(A, B)) {
//     return ERROR_CALC;
//   } else if ((code = s21_create_matrix(A->rows, A->columns, result)) == OK) {
//     for (int i = 0; i < A->rows; i++) {
//       for (int j = 0; j < A->columns; j++) {
//         result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
//       }
//     }
//   }
//   return code;
// }

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
  if (invalid_matrix(this)) {
    return ERROR_MATRIX;
  } else if (rows_ != cols_) {
    return ERROR_CALC;
  } else {
    int scale = rows_;
    S21Matrix A_minor(scale - 1, scale - 1);
    for (int row = 0; row < scale && code != ERROR_CALC; row++) {
      for (int column = 0; column < scale && code != ERROR_CALC; column++) {
        MinorMatrix(A_minor, scale, row, column);
        double coefficient = ((column + row) % 2 == 0) ? 1 : -1;
        double minor = A_minor.Determinant();
        if (isinf(minor) || isnan(minor)) {
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
      MinorMatrix(&A_minor, scale, 0, col);
      double coefficient = (col % 2 == 0) ? 1 : -1;
      result += matrix_[0][col] * coefficient * get_determinant(A_minor);
    }
    s21_remove_matrix(&A_minor);
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  int code = OK;
  if (result == NULL || invalid_matrix(A)) {
    return ERROR_MATRIX;
  } else if ((*A).rows != (*A).columns) {
    return ERROR_CALC;
  } else if ((code = s21_create_matrix(A->rows, A->rows, result)) == OK) {
    int scale = A->rows;
    double determinant = get_determinant(*A);
    if (determinant == 0 || isinf(determinant) || isnan(determinant)) {
      this->~S21Matrix();
      code = ERROR_CALC;
    } else if (scale == 1) {
      result->matrix[0][0] = 1 / A->matrix[0][0];
    } else {
      S21Matrix RawMatrix(scale, scale);
      code = s21_calc_complements(A, &RawMatrix);
      S21Matrix RawMatrix2(scale, scale);
      if (!code) code = RawMatrix.Transpose(&RawMatrix2);
      if (!code)
        code = RawMatrix2.MulNumber((1.0 / determinant));
      RawMatrix.~S21Matrix();
      RawMatrix2.~S21Matrix();
    }
  }
  return code;
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

int main() {
    S21Matrix matr(2, 2);
    S21Matrix matr2(2, 2);
    S21Matrix result(2, 2);
    matr.SetNumber(1,0, 10);
    matr.PrintMatrix();
    matr2.SetNumber(1,1, 10);
    matr2.PrintMatrix();
    // S21Matrix matr3 = matr.SubMatrix(matr2);
    matr.SumMatrix(matr2);
    matr.PrintMatrix();
    printf("ok");
}

// +	Addition of two matrices.	Different matrix dimensions.
// -	Subtraction of one matrix from another.	Different matrix dimensions.
// *	Matrix multiplication and matrix multiplication by a number.	The number of columns of the first matrix does not equal the number of rows of the second matrix.
// ==	Checks for matrices equality (EqMatrix).	
// =	Assignment of values from one matrix to another one.	
// +=	Addition assignment (SumMatrix)	different matrix dimensions.
// -=	Difference assignment (SubMatrix)	different matrix dimensions.
// *=	Multiplication assignment (MulMatrix/MulNumber).	The number of columns of the first matrix does not equal the number of rows of the second matrix.
// (int i, int j)	Indexation by matrix elements (row, column).	Index is outside the matrix.

// int invalid_matrix(S21Matrix& A) {
//   int code = OK;
//   if (A == NULL || A->matrix == NULL || (*A).rows < 1 || (*A).columns < 1) {
//     code = ERROR_MATRIX;
//   } else {
//     for (int row = 0; row < A->rows && code != ERROR_MATRIX; row++) {
//       if (!A->matrix[row]) code = ERROR_MATRIX;
//     }
//   }
//   return code;
// }

// int is_not_equal_rows_columns(S21Matrix& A, S21Matrix& B) {
//   return (A->rows != B->rows || A->columns != B->columns);
// }

// int s21_create_matrix(int rows, int columns, S21Matrix& result) {
//   int code = OK;
//   if ((result == NULL) || rows < 1 || columns < 1) {
//     code = ERROR_MATRIX;
//   } else {
//     result->rows = rows;
//     result->columns = columns;
//     result->matrix = (double **)calloc(rows, sizeof(double *));
//     for (int row = 0; row < rows; ++row) {
//       result->matrix[row] = (double *)calloc(columns, sizeof(double));
//     }
//   }
//   return code;
// }

// void s21_remove_matrix(S21Matrix& A) {
//   if (A != NULL && A->matrix != NULL) {
//     for (int i = 0; i < A->rows; i++) {
//       if (A->matrix[i] != NULL) {
//         free(A->matrix[i]);
//         A->matrix[i] = NULL;
//       }
//     }
//     free(A->matrix);
//     A->matrix = NULL;
//   }
// }

// int s21_eq_matrix(S21Matrix& A, S21Matrix& B) {
//   int code = SUCCESS;
//   if (is_not_equal_rows_columns(A, B)) {
//     code = FAILURE;
//   } else {
//     double different = 0;
//     for (int i = 0; i < (A->rows * A->columns) && code != 0; i++) {
//       different = (*A).matrix[i / A->columns][i % A->columns] -
//                   (*B).matrix[i / B->columns][i % B->columns];
//       if (fabs(different) >= 1e-7) {
//         code = FAILURE;
//       }
//     }
//   }
//   return code;
// }

// int s21_sum_matrix(S21Matrix& A, S21Matrix& B, S21Matrix& result) {
//   int code = OK;
//   if (invalid_matrix(A) || invalid_matrix(B)) {
//     code = ERROR_MATRIX;
//   } else if (is_not_equal_rows_columns(A, B)) {
//     code = ERROR_CALC;
//   } else if ((code = s21_create_matrix(A->rows, A->columns, result)) == OK) {
//     for (int i = 0; i < A->rows; i++) {
//       for (int j = 0; j < A->columns; j++) {
//         result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
//       }
//     }
//   }
//   return code;
// }


// int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
//   int code = OK;
//   if (result == NULL || invalid_matrix(A)) {
//     code = ERROR_MATRIX;
//   } else if ((code = s21_create_matrix(A->rows, A->columns, result)) == OK) {
//     for (int i = 0; i < A->rows && code != ERROR_CALC; i++) {
//       for (int j = 0; j < A->columns && code != ERROR_CALC; j++) {
//         result->matrix[i][j] = A->matrix[i][j] * number;
//         if (isinf(result->matrix[i][j]) || isnan(result->matrix[i][j]))
//           code = ERROR_CALC;
//       }
//     }
//   }
//   return code;
// }

// int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
//   int code = OK;
//   if (result == NULL || invalid_matrix(A) || invalid_matrix(B)) {
//     return ERROR_MATRIX;
//   } else if ((*A).columns != (*B).rows) {
//     return ERROR_CALC;
//   } else if ((code = s21_create_matrix(A->rows, B->columns, result)) == OK) {
//     for (int row = 0; row < A->rows && code != ERROR_CALC; row++) {
//       for (int column = 0; column < B->columns && code != ERROR_CALC;
//            column++) {
//         for (int k = 0; k < A->columns; k++) {
//           result->matrix[row][column] +=
//               A->matrix[row][k] * B->matrix[k][column];
//         }
//         if (isinf(result->matrix[row][column]) ||
//             isnan(result->matrix[row][column]))
//           code = ERROR_CALC;
//       }
//     }
//   }
//   return code;
// }

// int s21_transpose(matrix_t *A, matrix_t *result) {
//   int code = OK;
//   if (invalid_matrix(A)) {
//     return ERROR_MATRIX;
//   } else if ((code = s21_create_matrix(A->columns, A->rows, result)) == OK) {
//     for (int row = 0; row < result->rows; row++) {
//       for (int column = 0; column < result->columns; column++) {
//         result->matrix[row][column] = A->matrix[column][row];
//       }
//     }
//   }
//   return code;
// }




// int s21_determinant(matrix_t *A, double *result) {
//   int code = OK;
//   if (result == NULL || invalid_matrix(A)) {
//     code = ERROR_MATRIX;
//   } else if ((*A).rows != (*A).columns) {
//     code = ERROR_CALC;
//   } else {
//     *result = get_determinant(*A);
//   }
//   return code;
// }

// int s21_calc_complements(matrix_t *A, matrix_t *result) {
//   int code = OK;
//   if (result == NULL || invalid_matrix(A)) {
//     return ERROR_MATRIX;
//   } else if ((*A).rows != (*A).columns) {
//     return ERROR_CALC;
//   } else if ((code = s21_create_matrix(A->rows, A->columns, result)) == OK) {
//     int scale = A->rows;
//     matrix_t A_minor = {0};
//     s21_create_matrix(scale - 1, scale - 1, &A_minor);
//     for (int row = 0; row < scale && code != ERROR_CALC; row++) {
//       for (int column = 0; column < scale && code != ERROR_CALC; column++) {
//         fill_minor_matrix(*A, &A_minor, scale, row, column);
//         double coefficient = ((column + row) % 2 == 0) ? 1 : -1;
//         double minor = get_determinant(A_minor);
//         if (isinf(minor) || isnan(minor)) {
//           code = ERROR_CALC;
//           s21_remove_matrix(result);
//         } else {
//           (*result).matrix[row][column] = coefficient * minor;
//         }
//       }
//     }
//     s21_remove_matrix(&A_minor);
//   }
//   return code;
// }

// int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
//   int code = OK;
//   if (result == NULL || invalid_matrix(A)) {
//     return ERROR_MATRIX;
//   } else if ((*A).rows != (*A).columns) {
//     return ERROR_CALC;
//   } else if ((code = s21_create_matrix(A->rows, A->rows, result)) == OK) {
//     int scale = A->rows;
//     double determinant = get_determinant(*A);
//     if (determinant == 0 || isinf(determinant) || isnan(determinant)) {
//       s21_remove_matrix(result);
//       code = ERROR_CALC;
//     } else if (scale == 1) {
//       result->matrix[0][0] = 1 / A->matrix[0][0];
//     } else {
//       matrix_t raw_matrix = {0};
//       s21_create_matrix(scale, scale, &raw_matrix);
//       code = s21_calc_complements(A, &raw_matrix);
//       matrix_t raw_matrix_2 = {0};
//       s21_create_matrix(scale, scale, &raw_matrix_2);
//       if (!code) code = s21_transpose(&raw_matrix, &raw_matrix_2);
//       if (!code)
//         code = s21_mult_number(&raw_matrix_2, (1.0 / determinant), result);
//       s21_remove_matrix(&raw_matrix);
//       s21_remove_matrix(&raw_matrix_2);
//     }
//   }
//   return code;
// }