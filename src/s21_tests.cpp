#include <gtest/gtest.h>

#include "s21_matrix.hpp"

// Тест FillMatrix
TEST(S21MatrixTest, FillMatrix) {
  S21Matrix mat(2, 2);
  double data[] = {1.0, 2.0, 3.0, 4.0};
  mat.FillMatrix(data, 2, 2);

  EXPECT_DOUBLE_EQ(mat.GetNumber(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(mat.GetNumber(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(mat.GetNumber(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(mat.GetNumber(1, 1), 4.0);
  EXPECT_DOUBLE_EQ(mat(1, 0), 3.0);
  // EXPECT_THROW( mat(3, 2), std::out_of_range);

  const S21Matrix mat3(mat);
  EXPECT_DOUBLE_EQ(mat3(1, 0), 3.0);
  // EXPECT_THROW(mat3(3, 2), std::out_of_range);
}

// Тест инициализации матрицы

TEST(S21MatrixTest, MatrixInitialization) {
  S21Matrix mat(3, 3);
  EXPECT_EQ(mat.GetRows(), 3);
  EXPECT_EQ(mat.GetCols(), 3);
}

TEST(S21MatrixTest, MatrixInitialization2) {
  S21Matrix mat(2, 2);
  double data[] = {1.0, 2.0, 3.0, 4.0};
  mat.FillMatrix(data, 2, 2);
  S21Matrix mat2(mat);
  EXPECT_EQ(mat2.GetRows(), 2);
  EXPECT_EQ(mat2.GetCols(), 2);
  EXPECT_DOUBLE_EQ(mat2.GetNumber(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(mat2.GetNumber(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(mat2.GetNumber(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(mat2.GetNumber(1, 1), 4.0);
}

// Тест перемешения
TEST(S21MatrixTest, MoveConstructorAndAssignment) {
  // Создание и заполнение первой матрицы
  S21Matrix mat1(2, 2);
  double data1[] = {1.0, 2.0, 3.0, 4.0};
  mat1.FillMatrix(data1, 2, 2);

  // Перемещение матрицы
  S21Matrix mat2(std::move(mat1));

  // Проверка матрицы mat2
  EXPECT_DOUBLE_EQ(mat2.GetNumber(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(mat2.GetNumber(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(mat2.GetNumber(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(mat2.GetNumber(1, 1), 4.0);

// Проверка исходной матрицы mat1
    EXPECT_EQ(mat1.GetRows(), 0);  // Проверка, что размеры матрицы после перемещения равны 0
    EXPECT_EQ(mat1.GetCols(), 0);
}

// Тест установки размеров
TEST(S21MatrixTest, MatrixSetRowsCols) {
  S21Matrix mat(3, 3);
  mat.SetRows(2);
  mat.SetCols(2);
  EXPECT_EQ(mat.GetRows(), 2);
  EXPECT_EQ(mat.GetCols(), 2);
}

// Тест на проверку корректности матрицы
TEST(S21MatrixTest, InvalidMatrixSize) {
  EXPECT_THROW({ S21Matrix mat(-1, 2); }, std::out_of_range);
}

// Тест EqMatrix
TEST(S21MatrixTest, EqMatrix) {
  S21Matrix mat1(2, 2);
  double data1[] = {1.0, 2.0, 3.0, 4.0};
  mat1.FillMatrix(data1, 2, 2);

  S21Matrix mat2(2, 2);
  double data2[] = {1.0, 2.0, 3.0, 4.0};
  mat2.FillMatrix(data2, 2, 2);

  EXPECT_TRUE(mat1.EqMatrix(mat2));
}

TEST(S21MatrixTest, EqMatrix2) {
  S21Matrix mat1(1, 2);
  double data1[] = {1.0, 2.0};
  mat1.FillMatrix(data1, 1, 2);

  S21Matrix mat2(2, 2);
  double data2[] = {1.0, 2.0, 3.0, 4.0};
  mat2.FillMatrix(data2, 2, 2);

  EXPECT_THROW({
    mat1.EqMatrix(mat2);
  }, std::out_of_range);
}

TEST(S21MatrixTest, EqMatrix3) {
  S21Matrix mat1(2, 2);
  double data1[] = {1.0, 2.0, 3.0, 4.0};
  mat1.FillMatrix(data1, 2, 2);

  S21Matrix mat2(2, 2);
  double data2[] = {1.0, 2.0, 3.0, 4.0};
  mat2.FillMatrix(data2, 2, 2);

  EXPECT_TRUE(mat1 == mat2);
}

// Тест SumMatrix
TEST(S21MatrixTest, SumMatrix) {
  S21Matrix mat1(2, 2);
  double data1[] = {1.0, 2.0, 3.0, 4.0};
  mat1.FillMatrix(data1, 2, 2);

  S21Matrix mat2(2, 2);
  double data2[] = {1.0, 2.0, 3.0, 4.0};
  mat2.FillMatrix(data2, 2, 2);

  mat1.SumMatrix(mat2);

  EXPECT_DOUBLE_EQ(mat1.GetNumber(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(mat1.GetNumber(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(mat1.GetNumber(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(mat1.GetNumber(1, 1), 8.0);
}

TEST(S21MatrixTest, SumMatrix2) {
  S21Matrix mat1(2, 2);
  double data1[] = {1.0, 2.0, 3.0, 4.0};
  mat1.FillMatrix(data1, 2, 2);

  S21Matrix mat2(2, 2);
  double data2[] = {1.0, 2.0, 3.0, 4.0};
  mat2.FillMatrix(data2, 2, 2);

  S21Matrix res = mat1 + mat2;

  EXPECT_DOUBLE_EQ(res.GetNumber(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(res.GetNumber(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(res.GetNumber(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(res.GetNumber(1, 1), 8.0);
}

TEST(S21MatrixTest, SumMatrix3) {
  S21Matrix mat1(2, 2);
  double data1[] = {1.0, 2.0, 3.0, 4.0};
  mat1.FillMatrix(data1, 2, 2);

  S21Matrix mat2(2, 2);
  double data2[] = {1.0, 2.0, 3.0, 4.0};
  mat2.FillMatrix(data2, 2, 2);

  mat1 += mat2;

  EXPECT_DOUBLE_EQ(mat1.GetNumber(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(mat1.GetNumber(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(mat1.GetNumber(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(mat1.GetNumber(1, 1), 8.0);
}

TEST(S21MatrixTest, SumMatrix4) {
  S21Matrix mat1(1, 2);
  double data1[] = {1.0, 2.0};
  mat1.FillMatrix(data1, 1, 2);

  S21Matrix mat2(2, 2);
  double data2[] = {1.0, 2.0, 3.0, 4.0};
  mat2.FillMatrix(data2, 2, 2);

  EXPECT_THROW({
    mat1.SumMatrix(mat2);
  }, std::out_of_range);
}

// Тест SubMatrix
TEST(S21MatrixTest, SubMatrix) {
  S21Matrix mat1(2, 2);
  double data1[] = {2.0, 3.0, 4.0, 5.0};
  mat1.FillMatrix(data1, 2, 2);

  S21Matrix mat2(2, 2);
  double data2[] = {1.0, 1.0, 1.0, 1.0};
  mat2.FillMatrix(data2, 2, 2);

  mat1.SubMatrix(mat2);

  EXPECT_DOUBLE_EQ(mat1.GetNumber(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(mat1.GetNumber(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(mat1.GetNumber(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(mat1.GetNumber(1, 1), 4.0);
}

TEST(S21MatrixTest, SubMatrix2) {
  S21Matrix mat1(2, 2);
  double data1[] = {2.0, 3.0, 4.0, 5.0};
  mat1.FillMatrix(data1, 2, 2);

  S21Matrix mat2(2, 2);
  double data2[] = {1.0, 1.0, 1.0, 1.0};
  mat2.FillMatrix(data2, 2, 2);

  S21Matrix res = mat1 - mat2;

  EXPECT_DOUBLE_EQ(res.GetNumber(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(res.GetNumber(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(res.GetNumber(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(res.GetNumber(1, 1), 4.0);
}

TEST(S21MatrixTest, SubMatrix3) {
  S21Matrix mat1(2, 2);
  double data1[] = {2.0, 3.0, 4.0, 5.0};
  mat1.FillMatrix(data1, 2, 2);

  S21Matrix mat2(2, 2);
  double data2[] = {1.0, 1.0, 1.0, 1.0};
  mat2.FillMatrix(data2, 2, 2);

  mat1-=mat2;

  EXPECT_DOUBLE_EQ(mat1.GetNumber(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(mat1.GetNumber(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(mat1.GetNumber(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(mat1.GetNumber(1, 1), 4.0);
}

TEST(S21MatrixTest, SubMatrix4) {
  S21Matrix mat1(1, 2);
  double data1[] = {2.0, 3.0};
  mat1.FillMatrix(data1, 1, 2);

  S21Matrix mat2(2, 2);
  double data2[] = {1.0, 1.0, 1.0, 1.0};
  mat2.FillMatrix(data2, 2, 2);

  EXPECT_THROW({
    mat1-=mat2;
  }, std::out_of_range);
}

// Тест MulNumber
TEST(S21MatrixTest, MulNumber) {
  S21Matrix mat(2, 2);
  double data[] = {1.0, 2.0, 3.0, 4.0};
  mat.FillMatrix(data, 2, 2);

  mat.MulNumber(2.0);

  EXPECT_DOUBLE_EQ(mat.GetNumber(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(mat.GetNumber(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(mat.GetNumber(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(mat.GetNumber(1, 1), 8.0);
}

TEST(S21MatrixTest, MulNumber2) {
  S21Matrix mat(2, 2);
  double data[] = {1.0, 2.0, 3.0, 4.0};
  mat.FillMatrix(data, 2, 2);

  S21Matrix res = mat * 2.0;

  EXPECT_DOUBLE_EQ(res.GetNumber(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(res.GetNumber(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(res.GetNumber(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(res.GetNumber(1, 1), 8.0);
}

TEST(S21MatrixTest, MulNumber3) {
  S21Matrix mat(2, 2);
  double data[] = {1.0, 2.0, 3.0, 4.0};
  mat.FillMatrix(data, 2, 2);

  mat*=2.0;

  EXPECT_DOUBLE_EQ(mat.GetNumber(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(mat.GetNumber(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(mat.GetNumber(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(mat.GetNumber(1, 1), 8.0);
}

TEST(S21MatrixTest, MulNumber4) {
  S21Matrix mat(2, 2);
  double data[] = {1.0, 2.0, 3.0, 4.0};
  mat.FillMatrix(data, 2, 2);

  S21Matrix res = 2.0 * mat;

  EXPECT_DOUBLE_EQ(res.GetNumber(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(res.GetNumber(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(res.GetNumber(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(res.GetNumber(1, 1), 8.0);
}

TEST(S21MatrixTest, MulNumber5) {
  S21Matrix mat1;

  EXPECT_THROW({
    mat1 *= 2.0;
  }, std::out_of_range);
}

// Тест MulMatrix
TEST(S21MatrixTest, MulMatrix) {
  S21Matrix mat1(2, 2);
  double data1[] = {1.0, 2.0, 3.0, 4.0};
  mat1.FillMatrix(data1, 2, 2);

  S21Matrix mat2(2, 2);
  double data2[] = {1.0, 0.0, 0.0, 1.0};
  mat2.FillMatrix(data2, 2, 2);

  mat1.MulMatrix(mat2);

  EXPECT_DOUBLE_EQ(mat1.GetNumber(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(mat1.GetNumber(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(mat1.GetNumber(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(mat1.GetNumber(1, 1), 4.0);
}

TEST(S21MatrixTest, MulMatrix2) {
  S21Matrix mat1(2, 2);
  double data1[] = {1.0, 2.0, 3.0, 4.0};
  mat1.FillMatrix(data1, 2, 2);

  S21Matrix mat2(2, 2);
  double data2[] = {1.0, 0.0, 0.0, 1.0};
  mat2.FillMatrix(data2, 2, 2);

  S21Matrix res = mat1 * mat2;

  EXPECT_DOUBLE_EQ(res.GetNumber(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(res.GetNumber(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(res.GetNumber(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(res.GetNumber(1, 1), 4.0);
}

TEST(S21MatrixTest, MulMatrix3) {
  S21Matrix mat1(2, 2);
  double data1[] = {1.0, 2.0, 3.0, 4.0};
  mat1.FillMatrix(data1, 2, 2);

  S21Matrix mat2(2, 2);
  double data2[] = {1.0, 0.0, 0.0, 1.0};
  mat2.FillMatrix(data2, 2, 2);

  mat1*=mat2;

  EXPECT_DOUBLE_EQ(mat1.GetNumber(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(mat1.GetNumber(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(mat1.GetNumber(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(mat1.GetNumber(1, 1), 4.0);
}

TEST(S21MatrixTest, MulMatrix4) {
  S21Matrix mat1(2, 1);
  double data1[] = {2.0, 3.0};
  mat1.FillMatrix(data1, 1, 2);

  S21Matrix mat2(2, 2);
  double data2[] = {1.0, 1.0, 1.0, 1.0};
  mat2.FillMatrix(data2, 2, 2);

  EXPECT_THROW({
    mat1 *= mat2;
  }, std::out_of_range);
}

// Тест Transpose
TEST(S21MatrixTest, Transpose) {
  S21Matrix mat(2, 2);
  double data[] = {1.0, 2.0, 3.0, 4.0};
  mat.FillMatrix(data, 2, 2);

  S21Matrix transposed = mat.Transpose();

  EXPECT_DOUBLE_EQ(transposed.GetNumber(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(transposed.GetNumber(0, 1), 3.0);
  EXPECT_DOUBLE_EQ(transposed.GetNumber(1, 0), 2.0);
  EXPECT_DOUBLE_EQ(transposed.GetNumber(1, 1), 4.0);
}

// Тест CalcComplements
TEST(S21MatrixTest, CalcComplements) {
  S21Matrix mat(3, 3);
  double data[] = {1.0, 2.0, 3.0, 0.0, 1.0, 4.0, 5.0, 6.0, 0.0};
  mat.FillMatrix(data, 3, 3);

  S21Matrix complements = mat.CalcComplements();

  EXPECT_DOUBLE_EQ(complements.GetNumber(0, 0), -24.0);
  EXPECT_DOUBLE_EQ(complements.GetNumber(1, 0), 18.0);
  EXPECT_DOUBLE_EQ(complements.GetNumber(2, 0), 5.0);
  EXPECT_DOUBLE_EQ(complements.GetNumber(0, 1), 20.0);
  EXPECT_DOUBLE_EQ(complements.GetNumber(1, 1), -15.0);
  EXPECT_DOUBLE_EQ(complements.GetNumber(2, 1), -4.0);
  EXPECT_DOUBLE_EQ(complements.GetNumber(0, 2), -5.0);
  EXPECT_DOUBLE_EQ(complements.GetNumber(1, 2), 4.0);
  EXPECT_DOUBLE_EQ(complements.GetNumber(2, 2), 1.0);
}

// Тест исключение CalcComplements для неквадратной матрицы
TEST(S21MatrixTest, CalcComplementsNonSquareMatrix) {
  S21Matrix mat(2, 3);
  double data[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  mat.FillMatrix(data, 2, 3);

  EXPECT_THROW({ mat.CalcComplements(); }, std::out_of_range);
}

// Тест Determinant
TEST(S21MatrixTest, Determinant) {
  S21Matrix mat(3, 3);
  double data[] = {1.0, 2.0, 3.0, 0.0, 1.0, 4.0, 5.0, 6.0, 0.0};
  mat.FillMatrix(data, 3, 3);

  double det = mat.Determinant();

  EXPECT_DOUBLE_EQ(det, 1.0);
}

// Тест InverseMatrix
TEST(S21MatrixTest, InverseMatrix) {
  S21Matrix mat(3, 3);
  double data[] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
  mat.FillMatrix(data, 3, 3);

  S21Matrix inverse = mat.InverseMatrix();

  EXPECT_NEAR(inverse.GetNumber(0, 0), 1.0, 1e-6);
  EXPECT_NEAR(inverse.GetNumber(0, 1), -1.0, 1e-6);
  EXPECT_NEAR(inverse.GetNumber(0, 2), 1.0, 1e-6);
  EXPECT_NEAR(inverse.GetNumber(1, 0), -38.0, 1e-6);
  EXPECT_NEAR(inverse.GetNumber(1, 1), 41.0, 1e-6);
  EXPECT_NEAR(inverse.GetNumber(1, 2), -34.0, 1e-6);
  EXPECT_NEAR(inverse.GetNumber(2, 0), 27.0, 1e-6);
  EXPECT_NEAR(inverse.GetNumber(2, 1), -29.0, 1e-6);
  EXPECT_NEAR(inverse.GetNumber(2, 2), 24.0, 1e-6);
}

TEST(S21MatrixTest, InverseMatrix2) {
    // Создание матрицы, детерминант которой равен 0
    S21Matrix mat(2, 2);
    double data[] = {1.0, 2.0, 2.0, 4.0};
    mat.FillMatrix(data, 2, 2);

    // Проверка, что исключение
    EXPECT_THROW(mat.InverseMatrix(), std::out_of_range);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}