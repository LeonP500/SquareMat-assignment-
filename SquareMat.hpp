// leonandsani@gmail.com

#ifndef SQUARE_MAT_HPP
#define SQUARE_MAT_HPP

#include <iostream>
#include <stdexcept>

namespace matlib {

class SquareMat {
private:
  int size;      // matrix size
  double **data; // two-demansion array

  void allocate(int n);
  void copy(const SquareMat &other);
  void free();

public:
  SquareMat(int n);                             // constructor
  SquareMat(const SquareMat &other);            // copy constructor
  SquareMat &operator=(const SquareMat &other);
  ~SquareMat();                                 // destructor

  // operators
  SquareMat operator+(const SquareMat &other) const;
  SquareMat operator-(const SquareMat &other) const;
  SquareMat operator*(const SquareMat &other) const;
  SquareMat operator*(double scalar) const;
  SquareMat operator%(const SquareMat &other) const;
  SquareMat operator%(int scalar) const;
  SquareMat operator/(double scalar) const;
  SquareMat operator^(int power) const;

  SquareMat &operator+=(const SquareMat &other);
  SquareMat &operator-=(const SquareMat &other);
  SquareMat &operator*=(const SquareMat &other);
  SquareMat &operator*=(double scalar);
  SquareMat &operator/=(double scalar);
  SquareMat &operator%=(const SquareMat &other);
  SquareMat &operator%=(int scalar);


  SquareMat operator-() const;
  SquareMat &operator++();     // ++prefix
  SquareMat operator++(int);   // ++postfix
  SquareMat &operator--();     // --prefix
  SquareMat operator--(int);   // --postfix
  SquareMat operator~() const; // transpose

  // comparisons
  bool operator==(const SquareMat &other) const;
  bool operator!=(const SquareMat &other) const;
  bool operator<(const SquareMat &other) const;
  bool operator>(const SquareMat &other) const;
  bool operator<=(const SquareMat &other) const;
  bool operator>=(const SquareMat &other) const;

  // access to matrix fields
  double *operator[](int index);
  const double *operator[](int index) const;

  // determinant
  double operator!() const;

  // output
  friend std::ostream &operator<<(std::ostream &os, const SquareMat &mat);
};

SquareMat operator*(double scalar, const SquareMat &mat); // scalar * matrix

}

#endif