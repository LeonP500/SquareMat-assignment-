// leonandsani@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "SquareMat.hpp"
#include "doctest.h"

using namespace matlib;

TEST_CASE("Basic matrix operations") {
  SquareMat A(2);
  A[0][0] = 1;
  A[0][1] = 2;
  A[1][0] = 3;
  A[1][1] = 4;

  SquareMat B(2);
  B[0][0] = 5;
  B[0][1] = 6;
  B[1][0] = 7;
  B[1][1] = 8;

  SUBCASE("Addition") {
    SquareMat C = A + B;
    CHECK(C[0][0] == 6);
    CHECK(C[0][1] == 8);
    CHECK(C[1][0] == 10);
    CHECK(C[1][1] == 12);
  }

  SUBCASE("Subtraction") {
    SquareMat C = A - B;
    CHECK(C[0][0] == -4);
    CHECK(C[0][1] == -4);
    CHECK(C[1][0] == -4);
    CHECK(C[1][1] == -4);
  }

  SUBCASE("Matrix Multiplication") {
    SquareMat C = A * B;
    CHECK(C[0][0] == 19);
    CHECK(C[0][1] == 22);
    CHECK(C[1][0] == 43);
    CHECK(C[1][1] == 50);
  }

  SUBCASE("Scalar Multiplication") {
    SquareMat C = A * 2;
    CHECK(C[0][0] == 2);
    CHECK(C[0][1] == 4);
    CHECK(C[1][0] == 6);
    CHECK(C[1][1] == 8);
  }

  SUBCASE("Element-wise Multiplication") {
    SquareMat C = A % B;
    CHECK(C[0][0] == 5);
    CHECK(C[0][1] == 12);
    CHECK(C[1][0] == 21);
    CHECK(C[1][1] == 32);
  }

  SUBCASE("Modulo with scalar") {
    SquareMat C = A % 2;
    CHECK(C[0][0] == 1);
    CHECK(C[0][1] == 0);
    CHECK(C[1][0] == 1);
    CHECK(C[1][1] == 0);
  }

  SUBCASE("Matrix division by scalar") {
    SquareMat C = A / 2;
    CHECK(C[0][0] == doctest::Approx(0.5));
    CHECK(C[0][1] == doctest::Approx(1.0));
    CHECK(C[1][0] == doctest::Approx(1.5));
    CHECK(C[1][1] == doctest::Approx(2.0));
  }
}

TEST_CASE("Other matrix operations") {
  SquareMat A(2);
  A[0][0] = 1;
  A[0][1] = 2;
  A[1][0] = 3;
  A[1][1] = 4;

  SUBCASE("Unary minus") {
    SquareMat C = -A;
    CHECK(C[0][0] == -1);
    CHECK(C[0][1] == -2);
    CHECK(C[1][0] == -3);
    CHECK(C[1][1] == -4);
  }

  SUBCASE("Transpose") {
    SquareMat C = ~A;
    CHECK(C[0][0] == 1);
    CHECK(C[0][1] == 3);
    CHECK(C[1][0] == 2);
    CHECK(C[1][1] == 4);
  }

  SUBCASE("Increment and Decrement") {
    ++A;
    CHECK(A[0][0] == 2);
    CHECK(A[0][1] == 3);
    CHECK(A[1][0] == 4);
    CHECK(A[1][1] == 5);

    A--;
    CHECK(A[0][0] == 1);
    CHECK(A[0][1] == 2);
    CHECK(A[1][0] == 3);
    CHECK(A[1][1] == 4);
  }

  SUBCASE("Power") {
    SquareMat C = A ^ 2;
    CHECK(C[0][0] == 7);
    CHECK(C[0][1] == 10);
    CHECK(C[1][0] == 15);
    CHECK(C[1][1] == 22);
  }

  SUBCASE("Determinant") {
    double det = !A;
    CHECK(det == doctest::Approx(-2.0));
  }
}

TEST_CASE("Comparisons") {
  SquareMat A(2);
  A[0][0] = 1;
  A[0][1] = 1;
  A[1][0] = 1;
  A[1][1] = 1;

  SquareMat B(2);
  B[0][0] = 2;
  B[0][1] = 2;
  B[1][0] = 2;
  B[1][1] = 2;

  SUBCASE("Equality and Inequality") {
    CHECK_FALSE(A == B);
    CHECK(A != B);
  }

  SUBCASE("Relational Operators") {
    CHECK(A < B);
    CHECK(B > A);
    CHECK(A <= B);
    CHECK(B >= A);
  }
}

TEST_CASE("Errors and exceptions") {
  SquareMat A(2);
  SquareMat B(3);

  SUBCASE("Size mismatch throws") {
    CHECK_THROWS_AS(A + B, std::invalid_argument);
    CHECK_THROWS_AS(A - B, std::invalid_argument);
    CHECK_THROWS_AS(A * B, std::invalid_argument);
    CHECK_THROWS_AS(A % B, std::invalid_argument);
  }

  SUBCASE("Division by zero throws") {
    CHECK_THROWS_AS(A / 0, std::invalid_argument);
  }

  SUBCASE("Modulo by zero throws") {
    CHECK_THROWS_AS(A % 0, std::invalid_argument);
  }

  SUBCASE("Negative power throws") {
    CHECK_THROWS_AS(A ^ -2, std::invalid_argument);
  }
}