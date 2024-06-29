#include <iostream>

class S21Matrix {
    private:
        // Attributes
        int rows_, cols_;         // Rows and columns
        double **matrix_;         // Pointer to the memory where the matrix is allocated

    public:
        S21Matrix();              // Default constructor
        S21Matrix(int rows, int cols);
        // S21Matrix(const S21Matrix& other);
        // S21Matrix(S21Matrix&& other);
        ~S21Matrix();             // Destructor

        bool EqMatrix(const S21Matrix& other);
        void SumMatrix(const S21Matrix& other);
        // void SubMatrix(const S21Matrix& other);
        // void MulNumber(const double num);
        // void MulMatrix(const S21Matrix& other);
        // S21Matrix Transpose();
        // S21Matrix CalcComplements();
        // double Determinant();
        // S21Matrix InverseMatrix();

        int GetRows() const;
        int GetCols() const;
};

int S21Matrix::GetRows() const{
    return this->rows_;
}

int S21Matrix::GetCols() const{
    return this->rows_;
}

S21Matrix::S21Matrix(int rows, int cols) {
    this->rows_ = rows;
    this->cols_ = cols;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
    for (int i = 0; i < other.GetRows(); i++) {
        for (int j = 0; j < other.GetCols(); j++) {
            this->matrix_[i][j] += other.matrix_[i][j];
        }
    }
}

bool S21Matrix::EqMatrix(const S21Matrix& other) {
    bool result = true;
    for (int i = 0; i < other.rows_ && result; i++) {
        for (int j = 0; j < other.cols_ && result; j++) {
            if (other.matrix_[i][j] != this->matrix_[i][j]) result = false;
        }
    }
    return result;
}

int main() {
    S21Matrix matr(2, 2);
    printf("%d", matr.GetCols());
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