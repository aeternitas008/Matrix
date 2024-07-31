#include "s21_matrix.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
// #include <check.h>

using namespace std;


// создание
TEST(TestCreate, Subtest_1) {
  S21Matrix testMatrix = S21Matrix();
  // char buffer[100];
  // sprintf(buffer, "%p", testMatrix);
  ASSERT_EQ(testMatrix.GetRows(), 0);
  ASSERT_EQ(testMatrix.GetCols(), 0);
}
TEST(TestCreate, Subtest_2) {
  S21Matrix testMatrix = S21Matrix(4, 3);
  ASSERT_EQ(testMatrix.GetRows(), 4);
  ASSERT_EQ(testMatrix.GetCols(), 3);
}
TEST(TestCreate, Subtest_3) {
  ASSERT_TRUE(1 == 1);
};

// удаление
TEST(TestDelete, Subtest_1) {
  ASSERT_TRUE(1 == 1);
}
TEST(TestDelete, Subtest_2) {
  ASSERT_TRUE(1 == 1);
}
TEST(TestDelete, Subtest_3) {
  ASSERT_TRUE(1 == 1);
};

// sum
TEST(TestSum, Subtest_1) {
  ASSERT_TRUE(1 == 1);
}
TEST(TestSum, Subtest_2) {
  ASSERT_TRUE(1 == 1);
}
TEST(TestSum, Subtest_3) {
  ASSERT_TRUE(1 == 1);
};

// sub
TEST(TestSub, Subtest_1) {
  ASSERT_TRUE(1 == 1);
}
TEST(TestSub, Subtest_2) {
  ASSERT_TRUE(1 == 1);
}
TEST(TestSub, Subtest_3) {
  ASSERT_TRUE(1 == 1);
};

// mulNumber
TEST(TestMulNumber, Subtest_1) {
  ASSERT_TRUE(1 == 1);
}
TEST(TestMulNumber, Subtest_2) {
  ASSERT_TRUE(1 == 1);
}
TEST(TestMulNumber, Subtest_3) {
  ASSERT_TRUE(1 == 1);
};

// mulmatrix
TEST(TestMulMatrix, Subtest_1) {
  ASSERT_TRUE(1 == 1);
}
TEST(TestMulMatrix, Subtest_2) {
  ASSERT_TRUE(1 == 1);
}
TEST(TestMulMatrix, Subtest_3) {
  ASSERT_TRUE(1 == 1);
};

// calcAg
TEST(TestcalcAg, Subtest_1) {
  ASSERT_TRUE(1 == 1);
}
TEST(TestcalcAg, Subtest_2) {
  ASSERT_TRUE(1 == 1);
}
TEST(TestcalcAg, Subtest_3) {
  ASSERT_TRUE(1 == 1);
};

// determinant
TEST(TestDeterminant, Subtest_1) {
  ASSERT_TRUE(1 == 1);
}
TEST(TestDeterminant, Subtest_2) {
  ASSERT_TRUE(1 == 1);
}
TEST(TestDeterminant, Subtest_3) {
  ASSERT_TRUE(1 == 1);
};


TEST(TestGroupName, Subtest_2) {
  ASSERT_FALSE('b' == 'b');
  cout << "continue test after failure" << endl;
}
// void print_matrix(S21Matrix array) {
//   for (int i = 0; i < array.rows; i++) {
//     for (int j = 0; j < array.columns; j++) {
//       printf("%.8f", array.matrix[i][j]);
//       if (array.rows != i) {
//         printf(" ");
//       }
//     }
//     printf("\n");
//   }
// }

// void s21_initialize_matrix(S21_MATRIX& A, double num, double num2) {
//   double temp = num;
//   for (int i = 0; i < A->rows; ++i) {
//     for (int j = 0; j < A->columns; ++j) {
//       (*A).matrix[i][j] = temp;
//       temp += num2;
//     }
//   }
// }

// void fill_matrix(S21Matrix& A, double *matrix) {
//   for (int i = 0; i < A->rows; ++i) {
//     for (int j = 0; j < A->columns; ++j) {
//       (*A).matrix[i][j] = matrix[i * A->columns + j];
//     }
//   }
// }

// START_TEST(create_matrix_1) {
//   S21Matrix A;
//   int a = s21_create_matrix(5, 5, &A);
//   ck_assert_int_eq(a, OK);
//   s21_remove_matrix(&A);
// }
// END_TEST

// START_TEST(create_matrix_2) {
//   ck_assert_int_eq(s21_create_matrix(5, 5, NULL), ERROR_MATRIX);
// }
// END_TEST

// START_TEST(create_matrix_3) {
//   S21Matrix A;
//   ck_assert_int_eq(s21_create_matrix(5, 0, &A), ERROR_MATRIX);
// }
// END_TEST

// START_TEST(remove_matrix_1) {
//   S21Matrix A;
//   s21_create_matrix(5, 5, &A);
//   s21_remove_matrix(&A);
//   ck_assert_ptr_null(A.matrix);
// }
// END_TEST

// START_TEST(remove_matrix_2) {
//   s21_remove_matrix(NULL);
//   ck_assert_int_eq(1, 1);
// }
// END_TEST

// START_TEST(remove_matrix_3) {
//   S21Matrix A;
//   s21_create_matrix(3, 3, &A);
//   s21_remove_matrix(&A);
//   ck_assert_int_eq(1, 1);
// }
// END_TEST

// START_TEST(eq_matrix_1) {
//   S21Matrix A;
//   S21Matrix B;
//   s21_create_matrix(5, 5, &A);
//   s21_create_matrix(5, 5, &B);
//   s21_initialize_matrix(&A, 21, 21);
//   s21_initialize_matrix(&B, 21, 21);
//   ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&B);
// }
// END_TEST

// START_TEST(eq_matrix_2) {
//   S21Matrix A;
//   S21Matrix B;
//   s21_create_matrix(5, 5, &A);
//   s21_create_matrix(5, 5, &B);
//   ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&B);
// }
// END_TEST

// START_TEST(eq_matrix_3) {
//   S21Matrix A;
//   S21Matrix B;
//   s21_create_matrix(5, 5, &A);
//   s21_create_matrix(5, 5, &B);
//   s21_initialize_matrix(&A, 1.0, 2e-9);
//   s21_initialize_matrix(&B, 1.0, 1e-9);
//   ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&B);
// }
// END_TEST

// START_TEST(eq_matrix_4) {
//   S21Matrix A;
//   S21Matrix B;
//   s21_create_matrix(5, 5, &A);
//   s21_create_matrix(3, 4, &B);
//   ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&B);
// }
// END_TEST

// START_TEST(eq_matrix_5) {
//   S21Matrix A;
//   S21Matrix B;
//   s21_create_matrix(5, 5, &A);
//   ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
//   s21_remove_matrix(&A);
// }
// END_TEST

// START_TEST(eq_matrix_6) {
//   S21Matrix A;
//   S21Matrix B;
//   s21_create_matrix(5, 5, &A);
//   s21_create_matrix(5, 5, &B);
//   s21_initialize_matrix(&A, 21, 1);
//   s21_initialize_matrix(&B, 42, 1);
//   ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&B);
// }
// END_TEST

// START_TEST(sum_matrix_1) {
//   S21Matrix A;
//   S21Matrix B;
//   ck_assert_int_eq(s21_sum_matrix(&A, &B, NULL), ERROR_MATRIX);
// }
// END_TEST

// START_TEST(sum_matrix_1_2) {
//   S21Matrix B;
//   ck_assert_int_eq(s21_sum_matrix(NULL, &B, NULL), ERROR_MATRIX);
// }
// END_TEST

// START_TEST(sum_matrix_2) {
//   S21Matrix A;
//   S21Matrix B;
//   S21Matrix result;
//   s21_create_matrix(4, 4, &A);
//   s21_create_matrix(5, 5, &B);
//   ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), ERROR_CALC);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&B);
// }
// END_TEST

// START_TEST(sum_matrix_4) {
//   S21Matrix A;
//   S21Matrix B;
//   S21Matrix result;
//   S21Matrix eq_matrix;
//   s21_create_matrix(5, 5, &A);
//   s21_create_matrix(5, 5, &B);
//   s21_create_matrix(5, 5, &eq_matrix);
//   s21_initialize_matrix(&A, 1, 1);
//   s21_initialize_matrix(&B, 1, 1);
//   s21_initialize_matrix(&eq_matrix, 2, 2);
//   ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), OK);
//   ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&B);
//   s21_remove_matrix(&result);
//   s21_remove_matrix(&eq_matrix);
// }
// END_TEST

// START_TEST(sum_matrix_5) {
//   S21Matrix A;
//   S21Matrix B;
//   S21Matrix result;
//   S21Matrix eq_matrix;
//   s21_create_matrix(5, 5, &A);
//   s21_create_matrix(5, 5, &B);
//   s21_create_matrix(5, 5, &eq_matrix);
//   ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), OK);
//   ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&B);
//   s21_remove_matrix(&result);
//   s21_remove_matrix(&eq_matrix);
// }
// END_TEST

// START_TEST(sum_matrix_6) {
//   // sucess with task refence
//   S21Matrix A;
//   S21Matrix B;
//   S21Matrix result;
//   S21Matrix eq_matrix;
//   s21_create_matrix(3, 3, &A);
//   s21_create_matrix(3, 3, &B);
//   s21_create_matrix(3, 3, &eq_matrix);
//   double A_matrix[3][3] = {
//       {1, 2, 3},
//       {0, 4, 5},
//       {0, 0, 6},
//   };
//   double B_matrix[3][3] = {
//       {1, 0, 0},
//       {2, 0, 0},
//       {3, 4, 1},
//   };
//   double result_matrix[3][3] = {
//       {2, 2, 3},
//       {2, 4, 5},
//       {3, 4, 7},
//   };
//   fill_matrix(&A, (double *)&A_matrix);
//   fill_matrix(&B, (double *)&B_matrix);
//   fill_matrix(&eq_matrix, (double *)&result_matrix);
//   ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), OK);
//   ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);

//   // error_calc
//   // double number[6] = {NAN, -NAN, INFINITY, -INFINITY, DBL_MAX, -DBL_MAX};
//   // for (int i = 0; i < 6; i++) {
//   //   A.matrix[0][1] = number[i];
//   //   B.matrix[0][1] = number[i];
//   //   int return_result = s21_sum_matrix(&A, &B, &result);
//   //   ck_assert_int_eq(return_result, ERROR_CALC);
//   // }

//   // s21_remove_matrix(&A);
//   // s21_remove_matrix(&B);
//   // s21_remove_matrix(&result);
//   // s21_remove_matrix(&eq_matrix);
// }
// END_TEST

// START_TEST(sub_matrix_1) {
//   S21Matrix A;
//   S21Matrix B;
//   ck_assert_int_eq(s21_sub_matrix(&A, &B, NULL), ERROR_MATRIX);
// }
// END_TEST

// START_TEST(sub_matrix_2) {
//   S21Matrix A;
//   S21Matrix B;
//   S21Matrix result;
//   s21_create_matrix(4, 4, &A);
//   s21_create_matrix(5, 5, &B);
//   ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), ERROR_CALC);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&B);
// }
// END_TEST

// START_TEST(sub_matrix_4) {
//   S21Matrix A;
//   S21Matrix B;
//   S21Matrix result;
//   S21Matrix eq_matrix;
//   s21_create_matrix(5, 5, &A);
//   s21_create_matrix(5, 5, &B);
//   s21_create_matrix(5, 5, &eq_matrix);
//   s21_initialize_matrix(&A, 1, 1);
//   s21_initialize_matrix(&B, 1, 1);
//   ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
//   ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&B);
//   s21_remove_matrix(&result);
//   s21_remove_matrix(&eq_matrix);
// }
// END_TEST

// START_TEST(sub_matrix_5) {
//   S21Matrix A;
//   S21Matrix B;
//   S21Matrix result;
//   S21Matrix eq_matrix;
//   s21_create_matrix(5, 5, &A);
//   s21_create_matrix(5, 5, &B);
//   s21_create_matrix(5, 5, &eq_matrix);
//   ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
//   ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&B);
//   s21_remove_matrix(&result);
//   s21_remove_matrix(&eq_matrix);
// }
// END_TEST

// START_TEST(sub_matrix_3) {
//   S21Matrix A;
//   S21Matrix B;
//   S21Matrix result;
//   S21Matrix eq_matrix;
//   s21_create_matrix(3, 3, &A);
//   s21_create_matrix(3, 3, &B);
//   s21_create_matrix(3, 3, &eq_matrix);
//   double A_matrix[3][3] = {
//       {1, 2, 3},
//       {0, 4, 5},
//       {0, 0, 6},
//   };
//   double B_matrix[3][3] = {
//       {1, 0, 0},
//       {2, 0, 0},
//       {3, 4, 1},
//   };
//   double result_matrix[3][3] = {
//       {0, 2, 3},
//       {-2, 4, 5},
//       {-3, -4, 5},
//   };
//   fill_matrix(&A, (double *)&A_matrix);
//   fill_matrix(&B, (double *)&B_matrix);
//   fill_matrix(&eq_matrix, (double *)&result_matrix);
//   ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
//   ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);

//   s21_remove_matrix(&A);
//   s21_remove_matrix(&B);
//   s21_remove_matrix(&result);
//   s21_remove_matrix(&eq_matrix);
// }
// END_TEST

// START_TEST(mult_number_1) {
//   S21Matrix A;
//   double number = 3.14;
//   s21_create_matrix(3, 3, &A);
//   s21_initialize_matrix(&A, 1, 1);
//   ck_assert_int_eq(s21_mult_number(&A, number, NULL), ERROR_MATRIX);
//   s21_remove_matrix(&A);
// }
// END_TEST

// START_TEST(mult_number_2) {
//   S21Matrix A;
//   S21Matrix result;
//   double number[6] = {NAN, -NAN, INFINITY, -INFINITY, DBL_MAX, -DBL_MAX};
//   s21_create_matrix(3, 3, &A);
//   s21_initialize_matrix(&A, 1, 1);
//   for (int i = 0; i < 6; i++) {
//     int return_result = s21_mult_number(&A, number[i], &result);
//     ck_assert_int_eq(return_result, 2);
//   }
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&result);
// }
// END_TEST

// START_TEST(mult_number_4) {
//   S21Matrix A;
//   S21Matrix result;
//   S21Matrix eq_matrix;
//   double number = 3;
//   s21_create_matrix(3, 3, &A);
//   s21_create_matrix(3, 3, &eq_matrix);
//   ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
//   ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&result);
//   s21_remove_matrix(&eq_matrix);
// }
// END_TEST

// START_TEST(mult_number_5) {
//   S21Matrix A;
//   S21Matrix result;
//   S21Matrix eq_matrix;
//   double number = 3;
//   s21_create_matrix(3, 3, &A);
//   s21_initialize_matrix(&A, 1, 1);
//   s21_create_matrix(3, 3, &eq_matrix);
//   s21_initialize_matrix(&eq_matrix, 3, 3);
//   ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
//   ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&result);
//   s21_remove_matrix(&eq_matrix);
// }
// END_TEST

// START_TEST(mult_number_3) {
//   S21Matrix A;
//   S21Matrix result;
//   S21Matrix eq_matrix;
//   double number = 2;
//   s21_create_matrix(3, 3, &A);
//   s21_create_matrix(3, 3, &eq_matrix);
//   double A_matrix[3][3] = {
//       {1, 2, 3},
//       {0, 4, 2},
//       {2, 3, 4},
//   };
//   double result_matrix[3][3] = {
//       {2, 4, 6},
//       {0, 8, 4},
//       {4, 6, 8},
//   };
//   fill_matrix(&A, (double *)&A_matrix);
//   fill_matrix(&eq_matrix, (double *)&result_matrix);
//   ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
//   ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&result);
//   s21_remove_matrix(&eq_matrix);
// }
// END_TEST

// START_TEST(mult_matrix_1) {
//   S21Matrix A;
//   s21_create_matrix(3, 3, &A);
//   s21_initialize_matrix(&A, 1, 1);
//   ck_assert_int_eq(s21_mult_matrix(&A, NULL, NULL), ERROR_MATRIX);
//   s21_remove_matrix(&A);
// }
// END_TEST

// // 1_2
// START_TEST(mult_matrix_1_2) {
//   S21Matrix A;
//   S21Matrix B;
//   S21Matrix result;
//   s21_create_matrix(3, 3, &A);
//   s21_initialize_matrix(&A, 1, 1);
//   ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), ERROR_MATRIX);
//   s21_remove_matrix(&A);
// }
// END_TEST

// START_TEST(mult_matrix_2) {
//   S21Matrix A;
//   S21Matrix B;
//   S21Matrix result;
//   S21Matrix eq_matrix;
//   s21_create_matrix(3, 2, &A);
//   s21_create_matrix(2, 3, &B);
//   s21_create_matrix(3, 3, &eq_matrix);
//   double A_matrix[3][2] = {
//       {1, 4},
//       {2, 5},
//       {3, 6},
//   };
//   double B_matrix[2][3] = {
//       {1, -1, 1},
//       {2, 3, 4},
//   };
//   double result_matrix[3][3] = {
//       {9, 11, 17},
//       {12, 13, 22},
//       {15, 15, 27},
//   };
//   fill_matrix(&A, (double *)&A_matrix);
//   fill_matrix(&B, (double *)&B_matrix);
//   fill_matrix(&eq_matrix, (double *)&result_matrix);
//   ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);
//   ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);

//   // error_calc
//   double number[6] = {NAN, -NAN, INFINITY, -INFINITY, DBL_MAX, -DBL_MAX};
//   for (int i = 0; i < 6; i++) {
//     A.matrix[0][1] = number[i];
//     B.matrix[0][1] = number[i];
//     int return_result = s21_mult_matrix(&A, &B, &result);
//     ck_assert_int_eq(return_result, ERROR_CALC);
//   }

//   s21_remove_matrix(&A);
//   s21_remove_matrix(&B);
//   s21_remove_matrix(&result);
//   s21_remove_matrix(&eq_matrix);
// }
// END_TEST

// START_TEST(mult_matrix_3) {
//   S21Matrix A;
//   S21Matrix B;
//   S21Matrix result;
//   s21_create_matrix(3, 2, &A);
//   s21_create_matrix(3, 2, &B);
//   ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), ERROR_CALC);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&B);
// }
// END_TEST

// START_TEST(mult_matrix_4) {
//   S21Matrix A;
//   S21Matrix B;
//   S21Matrix result;
//   S21Matrix eq_matrix;
//   s21_create_matrix(3, 3, &A);
//   s21_create_matrix(3, 3, &B);
//   s21_create_matrix(3, 3, &eq_matrix);
//   ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);
//   ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&B);
//   s21_remove_matrix(&result);
//   s21_remove_matrix(&eq_matrix);
// }
// END_TEST

// START_TEST(mult_matrix_5) {
//   S21Matrix A;
//   S21Matrix B;
//   S21Matrix result;
//   S21Matrix eq_matrix;
//   s21_create_matrix(3, 3, &A);
//   s21_initialize_matrix(&A, 1, 1);
//   s21_create_matrix(3, 3, &B);
//   s21_initialize_matrix(&B, 1, 1);
//   s21_create_matrix(3, 3, &eq_matrix);
//   eq_matrix.matrix[0][0] = 30, eq_matrix.matrix[0][1] = 36,
//   eq_matrix.matrix[0][2] = 42;
//   eq_matrix.matrix[1][0] = 66, eq_matrix.matrix[1][1] = 81,
//   eq_matrix.matrix[1][2] = 96;
//   eq_matrix.matrix[2][0] = 102, eq_matrix.matrix[2][1] = 126,
//   eq_matrix.matrix[2][2] = 150;
//   ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);
//   ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&B);
//   s21_remove_matrix(&result);
//   s21_remove_matrix(&eq_matrix);
// }
// END_TEST

// START_TEST(transpose_1) {
//   S21Matrix A;
//   S21Matrix result;
//   ck_assert_int_eq(s21_transpose(&A, &result), ERROR_MATRIX);
// }
// END_TEST

// START_TEST(transpose_2) {
//   S21Matrix A;
//   S21Matrix result;
//   s21_create_matrix(3, 2, &A);
//   ck_assert_int_eq(s21_transpose(&A, &result), OK);
//   ck_assert_int_eq(result.rows, 2);
//   ck_assert_int_eq(result.columns, 3);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&result);
// }
// END_TEST

// START_TEST(transpose_3) {
//   S21Matrix A;
//   S21Matrix result;
//   s21_create_matrix(2, 3, &A);
//   ck_assert_int_eq(s21_transpose(&A, &result), OK);
//   ck_assert_int_eq(result.rows, 3);
//   ck_assert_int_eq(result.columns, 2);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&result);
// }
// END_TEST

// START_TEST(transpose_4) {
//   S21Matrix A;
//   S21Matrix result;
//   S21Matrix eq_matrix;
//   s21_create_matrix(2, 3, &A);
//   s21_create_matrix(3, 2, &eq_matrix);
//   s21_initialize_matrix(&A, 1, 1);
//   ck_assert_int_eq(s21_transpose(&A, &result), OK);
//   eq_matrix.matrix[0][0] = 1, eq_matrix.matrix[0][1] = 4;
//   eq_matrix.matrix[1][0] = 2, eq_matrix.matrix[1][1] = 5;
//   eq_matrix.matrix[2][0] = 3, eq_matrix.matrix[2][1] = 6;
//   ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
//   ck_assert_int_eq(result.rows, 3);
//   ck_assert_int_eq(result.columns, 2);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&eq_matrix);
//   s21_remove_matrix(&result);
// }
// END_TEST

// START_TEST(transpose_5) {
//   S21Matrix A;
//   S21Matrix result;
//   S21Matrix eq_matrix;
//   s21_create_matrix(3, 2, &A);
//   s21_create_matrix(2, 3, &eq_matrix);
//   A.matrix[0][0] = 1, A.matrix[0][1] = 4;
//   A.matrix[1][0] = 2, A.matrix[1][1] = 5;
//   A.matrix[2][0] = 3, A.matrix[2][1] = 6;
//   ck_assert_int_eq(s21_transpose(&A, &result), OK);
//   eq_matrix.matrix[0][0] = 1, eq_matrix.matrix[0][1] = 2,
//   eq_matrix.matrix[0][2] = 3;
//   eq_matrix.matrix[1][0] = 4, eq_matrix.matrix[1][1] = 5,
//   eq_matrix.matrix[1][2] = 6;
//   ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
//   ck_assert_int_eq(result.rows, 2);
//   ck_assert_int_eq(result.columns, 3);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&eq_matrix);
//   s21_remove_matrix(&result);
// }
// END_TEST

// START_TEST(calc_complements_1) {
//   S21Matrix A;
//   s21_create_matrix(3, 3, &A);
//   ck_assert_int_eq(s21_calc_complements(&A, NULL), ERROR_MATRIX);
//   s21_remove_matrix(&A);
// }
// END_TEST

// START_TEST(calc_complements_2) {
//   S21Matrix A;
//   S21Matrix result;
//   s21_create_matrix(1, 3, &A);
//   s21_initialize_matrix(&A, 1, 3);
//   ck_assert_int_eq(s21_calc_complements(&A, &result), ERROR_CALC);
//   s21_remove_matrix(&A);
// }
// END_TEST

// START_TEST(calc_complements_3) {
//   S21Matrix A;
//   S21Matrix result;
//   S21Matrix eq_matrix;
//   s21_create_matrix(3, 3, &A);
//   s21_create_matrix(3, 3, &eq_matrix);
//   A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
//   A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 2;
//   A.matrix[2][0] = 5, A.matrix[2][1] = 2, A.matrix[2][2] = 1;
//   ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
//   eq_matrix.matrix[0][0] = 0, eq_matrix.matrix[0][1] = 10,
//   eq_matrix.matrix[0][2] = -20;
//   eq_matrix.matrix[1][0] = 4, eq_matrix.matrix[1][1] = -14,
//   eq_matrix.matrix[1][2] = 8;
//   eq_matrix.matrix[2][0] = -8, eq_matrix.matrix[2][1] = -2,
//   eq_matrix.matrix[2][2] = 4;
//   ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);

//   // error_calc
//   double number[6] = {NAN, -NAN, INFINITY, -INFINITY, DBL_MAX, -DBL_MAX};
//   for (int i = 0; i < 6; i++) {
//     A.matrix[0][1] = number[i];
//     int return_result = s21_calc_complements(&A, &result);
//     ck_assert_int_eq(return_result, ERROR_CALC);
//   }

//   s21_remove_matrix(&A);
//   s21_remove_matrix(&result);
//   s21_remove_matrix(&eq_matrix);
// }
// END_TEST

// START_TEST(determinant_1) {
//   S21Matrix A;
//   double det = 0;
//   ck_assert_int_eq(s21_determinant(&A, &det), ERROR_MATRIX);
// }
// END_TEST

// START_TEST(determinant_2) {
//   S21Matrix A;
//   double det = 0;
//   s21_create_matrix(3, 2, &A);
//   s21_initialize_matrix(&A, 1, 1);
//   ck_assert_int_eq(s21_determinant(&A, &det), ERROR_CALC);
//   s21_remove_matrix(&A);
// }
// END_TEST

// START_TEST(determinant_3) {
//   S21Matrix A;
//   double det = 0;
//   s21_create_matrix(3, 3, &A);
//   s21_initialize_matrix(&A, 1, 1);
//   ck_assert_int_eq(s21_determinant(&A, &det), OK);
//   ck_assert_double_eq(det, 0);
//   s21_remove_matrix(&A);
// }
// END_TEST

// START_TEST(determinant_4) {
//   S21Matrix A;
//   double det = 0;
//   s21_create_matrix(2, 2, &A);
//   s21_initialize_matrix(&A, 3, 3);
//   ck_assert_int_eq(s21_determinant(&A, &det), OK);
//   ck_assert_double_eq(det, -18);
//   s21_remove_matrix(&A);
// }
// END_TEST

// START_TEST(determinant_5) {
//   S21Matrix A;
//   double det = 0;
//   s21_create_matrix(1, 1, &A);
//   A.matrix[0][0] = 21;
//   ck_assert_int_eq(s21_determinant(&A, &det), OK);
//   ck_assert_double_eq(det, 21);
//   s21_remove_matrix(&A);
// }
// END_TEST

// START_TEST(inverse_matrix_1) {
//   S21Matrix A;
//   S21Matrix result;
//   ck_assert_int_eq(s21_inverse_matrix(&A, &result), ERROR_MATRIX);
// }
// END_TEST

// START_TEST(inverse_matrix_2) {
//   S21Matrix A;
//   S21Matrix result;
//   s21_create_matrix(3, 3, &A);
//   s21_initialize_matrix(&A, 1, 1);
//   ck_assert_int_eq(s21_inverse_matrix(&A, &result), ERROR_CALC);
//   s21_remove_matrix(&A);
// }
// END_TEST

// START_TEST(inverse_matrix_3) {
//   S21Matrix A;
//   S21Matrix result;
//   s21_create_matrix(5, 3, &A);
//   s21_initialize_matrix(&A, 1, 1);
//   ck_assert_int_eq(s21_inverse_matrix(&A, &result), ERROR_CALC);
//   s21_remove_matrix(&A);
// }
// END_TEST

// START_TEST(inverse_matrix_4) {
//   S21Matrix A;
//   S21Matrix result;
//   S21Matrix eq_matrix;
//   s21_create_matrix(1, 1, &A);
//   s21_create_matrix(1, 1, &eq_matrix);
//   A.matrix[0][0] = 21;
//   eq_matrix.matrix[0][0] = 1.0 / 21.0;
//   ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
//   ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&result);
//   s21_remove_matrix(&eq_matrix);
// }
// END_TEST

// START_TEST(inverse_matrix_5) {
//   S21Matrix A;
//   S21Matrix result;
//   S21Matrix eq_matrix;
//   s21_create_matrix(3, 3, &A);
//   s21_create_matrix(3, 3, &eq_matrix);
//   A.matrix[0][0] = 2, A.matrix[0][1] = 5, A.matrix[0][2] = 7;
//   A.matrix[1][0] = 6, A.matrix[1][1] = 3, A.matrix[1][2] = 4;
//   A.matrix[2][0] = 5, A.matrix[2][1] = -2, A.matrix[2][2] = -3;
//   eq_matrix.matrix[0][0] = 1, eq_matrix.matrix[0][1] = -1,
//   eq_matrix.matrix[0][2] = 1;
//   eq_matrix.matrix[1][0] = -38, eq_matrix.matrix[1][1] = 41,
//   eq_matrix.matrix[1][2] = -34;
//   eq_matrix.matrix[2][0] = 27, eq_matrix.matrix[2][1] = -29,
//   eq_matrix.matrix[2][2] = 24;
//   ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
//   ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&result);
//   s21_remove_matrix(&eq_matrix);
// }
// END_TEST

// Suite *s21_create_matrix_suite(void) {
//   Suite *suite = suite_create("s21_create_matrix");
//   TCase *tc_core = tcase_create("core_of_create_matrix");
//   tcase_add_test(tc_core, create_matrix_1);
//   tcase_add_test(tc_core, create_matrix_2);
//   tcase_add_test(tc_core, create_matrix_3);
//   suite_add_tcase(suite, tc_core);

//   return suite;
// }

// Suite *s21_remove_matrix_suite(void) {
//   Suite *suite = suite_create("s21_remove_matrix");
//   TCase *tc_core = tcase_create("core_of_remove_matrix");
//   tcase_add_test(tc_core, remove_matrix_1);
//   tcase_add_test(tc_core, remove_matrix_2);
//   tcase_add_test(tc_core, remove_matrix_3);
//   suite_add_tcase(suite, tc_core);

//   return suite;
// }

// Suite *s21_eq_matrix_suite(void) {
//   Suite *suite = suite_create("s21_eq_matrix");
//   TCase *tc_core = tcase_create("core_of_eq_matrix");
//   tcase_add_test(tc_core, eq_matrix_1);
//   tcase_add_test(tc_core, eq_matrix_2);
//   tcase_add_test(tc_core, eq_matrix_3);
//   tcase_add_test(tc_core, eq_matrix_4);
//   tcase_add_test(tc_core, eq_matrix_5);
//   tcase_add_test(tc_core, eq_matrix_6);
//   suite_add_tcase(suite, tc_core);

//   return suite;
// }

// Suite *s21_sum_matrix_suite(void) {
//   Suite *suite = suite_create("s21_sum_matrix");
//   TCase *tc_core = tcase_create("core_of_sum_matrix");
//   tcase_add_test(tc_core, sum_matrix_1);
//   tcase_add_test(tc_core, sum_matrix_1_2);
//   tcase_add_test(tc_core, sum_matrix_2);
//   tcase_add_test(tc_core, sum_matrix_4);
//   tcase_add_test(tc_core, sum_matrix_5);
//   tcase_add_test(tc_core, sum_matrix_6);
//   suite_add_tcase(suite, tc_core);

//   return suite;
// }

// Suite *s21_sub_matrix_suite(void) {
//   Suite *suite = suite_create("s21_sub_matrix");
//   TCase *tc_core = tcase_create("core_of_sub_matrix");
//   tcase_add_test(tc_core, sub_matrix_1);
//   tcase_add_test(tc_core, sub_matrix_2);
//   tcase_add_test(tc_core, sub_matrix_4);
//   tcase_add_test(tc_core, sub_matrix_5);
//   tcase_add_test(tc_core, sub_matrix_3);
//   suite_add_tcase(suite, tc_core);

//   return suite;
// }

// Suite *s21_mult_number_suite(void) {
//   Suite *suite = suite_create("s21_mult_number");
//   TCase *tc_core = tcase_create("core_of_mult_number");
//   tcase_add_test(tc_core, mult_number_1);
//   tcase_add_test(tc_core, mult_number_2);
//   tcase_add_test(tc_core, mult_number_3);
//   tcase_add_test(tc_core, mult_number_4);
//   tcase_add_test(tc_core, mult_number_5);
//   suite_add_tcase(suite, tc_core);

//   return suite;
// }

// Suite *s21_mult_matrix_suite(void) {
//   Suite *suite = suite_create("s21_mult_matrix");
//   TCase *tc_core = tcase_create("core_of_mult_matrix");
//   tcase_add_test(tc_core, mult_matrix_1);
//   tcase_add_test(tc_core, mult_matrix_1_2);
//   tcase_add_test(tc_core, mult_matrix_2);
//   tcase_add_test(tc_core, mult_matrix_3);
//   tcase_add_test(tc_core, mult_matrix_4);
//   tcase_add_test(tc_core, mult_matrix_5);
//   suite_add_tcase(suite, tc_core);
//   return suite;
// }

// Suite *s21_transpose_suite(void) {
//   Suite *suite = suite_create("s21_transpose");
//   TCase *tc_core = tcase_create("core_of_transpose");
//   tcase_add_test(tc_core, transpose_1);
//   tcase_add_test(tc_core, transpose_2);
//   tcase_add_test(tc_core, transpose_3);
//   tcase_add_test(tc_core, transpose_4);
//   tcase_add_test(tc_core, transpose_5);
//   suite_add_tcase(suite, tc_core);

//   return suite;
// }

// Suite *s21_calc_complements_suite(void) {
//   Suite *suite = suite_create("s21_calc_complements");
//   TCase *tc_core = tcase_create("core_of_calc_complements");
//   tcase_add_test(tc_core, calc_complements_1);
//   tcase_add_test(tc_core, calc_complements_2);
//   tcase_add_test(tc_core, calc_complements_3);
//   suite_add_tcase(suite, tc_core);

//   return suite;
// }

// Suite *s21_determinant_suite(void) {
//   Suite *suite = suite_create("s21_determinant");
//   TCase *tc_core = tcase_create("core_of_determinant");
//   tcase_add_test(tc_core, determinant_1);
//   tcase_add_test(tc_core, determinant_2);
//   tcase_add_test(tc_core, determinant_3);
//   tcase_add_test(tc_core, determinant_4);
//   tcase_add_test(tc_core, determinant_5);
//   suite_add_tcase(suite, tc_core);

//   return suite;
// }

// Suite *s21_inverse_matrix_suite(void) {
//   Suite *suite = suite_create("s21_inverse_matrix");
//   TCase *tc_core = tcase_create("core_of_inverse_matrix");
//   tcase_add_test(tc_core, inverse_matrix_1);
//   tcase_add_test(tc_core, inverse_matrix_2);
//   tcase_add_test(tc_core, inverse_matrix_3);
//   tcase_add_test(tc_core, inverse_matrix_4);
//   tcase_add_test(tc_core, inverse_matrix_5);
//   suite_add_tcase(suite, tc_core);

//   return suite;
// }

// void s21_suit_execution(Suite *suite, int *failed_count) {
//   SRunner *suite_runner = srunner_create(suite);
//   srunner_run_all(suite_runner, CK_NORMAL);
//   *failed_count = srunner_ntests_failed(suite_runner);
//   srunner_free(suite_runner);
// }

// int main(void) {
//   int failed_count = 0;
//   s21_suit_execution(s21_create_matrix_suite(), &failed_count);
//   s21_suit_execution(s21_remove_matrix_suite(), &failed_count);
//   s21_suit_execution(s21_eq_matrix_suite(), &failed_count);
//   s21_suit_execution(s21_sum_matrix_suite(), &failed_count);
//   s21_suit_execution(s21_sub_matrix_suite(), &failed_count);
//   s21_suit_execution(s21_mult_number_suite(), &failed_count);
//   s21_suit_execution(s21_mult_matrix_suite(), &failed_count);
//   s21_suit_execution(s21_transpose_suite(), &failed_count);
//   s21_suit_execution(s21_calc_complements_suite(), &failed_count);
//   s21_suit_execution(s21_determinant_suite(), &failed_count);
//   s21_suit_execution(s21_inverse_matrix_suite(), &failed_count);

//   return failed_count == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
// }


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}