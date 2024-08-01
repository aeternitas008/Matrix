#include <gtest/gtest.h>

#include "s21_matrix.hpp"

// Тест для функции FillMatrix
TEST(S21MatrixTest, FillMatrix) {
  S21Matrix mat(2, 2);
  double data[] = {1.0, 2.0, 3.0, 4.0};
  mat.FillMatrix(data, 2, 2);

  EXPECT_DOUBLE_EQ(mat.GetNumber(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(mat.GetNumber(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(mat.GetNumber(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(mat.GetNumber(1, 1), 4.0);
}

// Тест для функции EqMatrix
TEST(S21MatrixTest, EqMatrix) {
  S21Matrix mat1(2, 2);
  double data1[] = {1.0, 2.0, 3.0, 4.0};
  mat1.FillMatrix(data1, 2, 2);

  S21Matrix mat2(2, 2);
  double data2[] = {1.0, 2.0, 3.0, 4.0};
  mat2.FillMatrix(data2, 2, 2);

  EXPECT_TRUE(mat1.EqMatrix(mat2));
}

// Тест для функции SumMatrix
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

// Тест для функции SubMatrix
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

// Тест для функции MulNumber
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

// Тест для функции MulMatrix
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

// Тест для функции Transpose
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

// Тест для функции CalcComplements
TEST(S21MatrixTest, CalcComplements) {
  S21Matrix mat(3, 3);
  double data[] = {1.0, 2.0, 3.0, 0.0, 1.0, 4.0, 5.0, 6.0, 0.0};
  mat.FillMatrix(data, 3, 3);

  S21Matrix complements = mat.CalcComplements();

  EXPECT_DOUBLE_EQ(complements.GetNumber(0, 0), -24.0);
  EXPECT_DOUBLE_EQ(complements.GetNumber(0, 1), 18.0);
  EXPECT_DOUBLE_EQ(complements.GetNumber(0, 2), 5.0);
  EXPECT_DOUBLE_EQ(complements.GetNumber(1, 0), 20.0);
  EXPECT_DOUBLE_EQ(complements.GetNumber(1, 1), -15.0);
  EXPECT_DOUBLE_EQ(complements.GetNumber(1, 2), -4.0);
  EXPECT_DOUBLE_EQ(complements.GetNumber(2, 0), -5.0);
  EXPECT_DOUBLE_EQ(complements.GetNumber(2, 1), 4.0);
  EXPECT_DOUBLE_EQ(complements.GetNumber(2, 2), 1.0);
}

// Тест для функции Determinant
TEST(S21MatrixTest, Determinant) {
  S21Matrix mat(3, 3);
  double data[] = {1.0, 2.0, 3.0, 0.0, 1.0, 4.0, 5.0, 6.0, 0.0};
  mat.FillMatrix(data, 3, 3);

  double det = mat.Determinant();

  EXPECT_DOUBLE_EQ(det, 1.0);
}

// Тест для функции InverseMatrix
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

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}