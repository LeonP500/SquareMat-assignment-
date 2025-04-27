// leonandsani@gmail.com

#include "SquareMat.hpp"
#include <iostream>

using namespace matlib;

int main() { // Main file for demonstration
  try {
    // create 2 matrices
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

    std::cout << "Matrix A:" << std::endl;
    std::cout << A << std::endl;

    std::cout << "Matrix B:" << std::endl;
    std::cout << B << std::endl;

    // addition
    SquareMat C = A + B;
    std::cout << "A + B:" << std::endl;
    std::cout << C << std::endl;

    // subtraction
    C = A - B;
    std::cout << "A - B:" << std::endl;
    std::cout << C << std::endl;

    // matrix mul
    C = A * B;
    std::cout << "A * B:" << std::endl;
    std::cout << C << std::endl;

    // scalar mul
    C = A * 2;
    std::cout << "A * 2:" << std::endl;
    std::cout << C << std::endl;

    // modulu with scalar
    C = A % 3;
    std::cout << "A % 3:" << std::endl;
    std::cout << C << std::endl;

    // element wise mul
    C = A % B;
    std::cout << "A element-wise * B:" << std::endl;
    std::cout << C << std::endl;

    // square
    C = A ^ 2;
    std::cout << "A squared:" << std::endl;
    std::cout << C << std::endl;

    // transpose
    C = ~A;
    std::cout << "Transpose of A:" << std::endl;
    std::cout << C << std::endl;

    // increment
    ++A;
    std::cout << "++A:" << std::endl;
    std::cout << A << std::endl;

    // decrement
    A--;
    std::cout << "A--:" << std::endl;
    std::cout << A << std::endl;

    // determinant
    double detA = !A;
    std::cout << "Determinant of A: " << detA << std::endl;

    // comparison
    std::cout << "A == B? " << (A == B ? "Yes" : "No") << std::endl;
    std::cout << "A > B? " << (A > B ? "Yes" : "No") << std::endl;

  } catch (const std::exception &ex) {
    std::cerr << "Error: " << ex.what() << std::endl;
  }
}