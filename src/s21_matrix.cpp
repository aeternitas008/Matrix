class S21Matrix {
    private:
        // Attributes
        int rows_, cols_;         // Rows and columns
        double **matrix_;         // Pointer to the memory where the matrix is allocated

    public:
        S21Matrix();              // Default constructor
        S21Matrix(int rows, int cols);
        S21Matrix(const S21Matrix& other);
        S21Matrix(S21Matrix&& other);
        ~S21Matrix();             // Destructor

        bool EqMatrix(const S21Matrix& other);
        void SumMatrix(const S21Matrix& other);
        void SubMatrix(const S21Matrix& other);
        void MulNumber(const double num);
        void MulMatrix(const S21Matrix& other);
        S21Matrix Transpose();
        S21Matrix CalcComplements();
        double Determinant();
        S21Matrix InverseMatrix();

        int getRows() const;
        int getCols() const;
};

int S21Matrix::getRows() const{
    return this->rows_;
}

int S21Matrix::getCols() {
    return this->rows_;
}

void SumMatrix(const S21Matrix& other) {
    for (int i = 0; i < other.getRows(); i++) {
        for (int j = 0; j < other.getCols(); j++) {
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

// +	Addition of two matrices.	Different matrix dimensions.
// -	Subtraction of one matrix from another.	Different matrix dimensions.
// *	Matrix multiplication and matrix multiplication by a number.	The number of columns of the first matrix does not equal the number of rows of the second matrix.
// ==	Checks for matrices equality (EqMatrix).	
// =	Assignment of values from one matrix to another one.	
// +=	Addition assignment (SumMatrix)	different matrix dimensions.
// -=	Difference assignment (SubMatrix)	different matrix dimensions.
// *=	Multiplication assignment (MulMatrix/MulNumber).	The number of columns of the first matrix does not equal the number of rows of the second matrix.
// (int i, int j)	Indexation by matrix elements (row, column).	Index is outside the matrix.