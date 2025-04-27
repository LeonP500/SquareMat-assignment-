// leonandsani@gmail.com

#include "SquareMat.hpp"
#include <cmath>

namespace matlib {

void SquareMat::allocate(int n) {
  data = new double *[n];
  for (int i = 0; i < n; ++i)
    data[i] = new double[n]{};
}

void SquareMat::copy(const SquareMat &other) {
  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j)
      data[i][j] = other.data[i][j];
}

void SquareMat::free() {
  if (data) {
    for (int i = 0; i < size; ++i)
      delete[] data[i];
    delete[] data;
    data = nullptr;
  }
}

// constructor
SquareMat::SquareMat(int n) : size(n), data(nullptr) {
  if (n <= 0)
    throw std::invalid_argument("Matrix size must be positive.");
  allocate(n);
}

// copy constructor
SquareMat::SquareMat(const SquareMat &other) : size(other.size) {
  allocate(size);
  copy(other);
}

// oprtator =
SquareMat &SquareMat::operator=(const SquareMat &other) {
  if (this != &other) {
    free();
    size = other.size;
    allocate(size);
    copy(other);
  }
  return *this;
}

// destructor
SquareMat::~SquareMat() { free(); }


// operators

SquareMat SquareMat::operator+(const SquareMat &other) const {
  if (size != other.size)
    throw std::invalid_argument("Matrix sizes must match.");
  SquareMat res(size);
  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j)
      res.data[i][j] = data[i][j] + other.data[i][j];
  return res;
}

SquareMat SquareMat::operator-(const SquareMat &other) const {
  if (size != other.size)
    throw std::invalid_argument("Matrix sizes must match.");
  SquareMat res(size);
  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j)
      res.data[i][j] = data[i][j] - other.data[i][j];
  return res;
}

SquareMat SquareMat::operator*(const SquareMat &other) const {
  if (size != other.size)
    throw std::invalid_argument("Matrix sizes must match.");
  SquareMat res(size);
  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j)
      for (int k = 0; k < size; ++k)
        res.data[i][j] += data[i][k] * other.data[k][j];
  return res;
}

SquareMat SquareMat::operator*(double scalar) const {
  SquareMat res(size);
  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j)
      res.data[i][j] = data[i][j] * scalar;
  return res;
}

SquareMat SquareMat::operator%(const SquareMat &other) const {
  if (size != other.size)
    throw std::invalid_argument("Matrix sizes must match.");
  SquareMat res(size);
  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j)
      res.data[i][j] = data[i][j] * other.data[i][j];
  return res;
}

SquareMat SquareMat::operator%(int scalar) const {
  if (scalar == 0)
    throw std::invalid_argument("Modulo by zero.");
  SquareMat res(size);
  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j)
      res.data[i][j] = std::fmod(data[i][j], scalar);
  return res;
}

SquareMat SquareMat::operator/(double scalar) const {
  if (scalar == 0)
    throw std::invalid_argument("Division by zero.");
  SquareMat res(size);
  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j)
      res.data[i][j] = data[i][j] / scalar;
  return res;
}

SquareMat SquareMat::operator^(int power) const {
  if (power < 0)
    throw std::invalid_argument("Negative powers not supported.");
  SquareMat res(size);
  for (int i = 0; i < size; ++i)
    res.data[i][i] = 1;

  SquareMat base(*this);
  while (power > 0) {
    if (power % 2 == 1)
      res = res * base;
    base = base * base;
    power /= 2;
  }
  return res;
}


SquareMat &SquareMat::operator+=(const SquareMat &other) {
  *this = *this + other;
  return *this;
}

SquareMat &SquareMat::operator-=(const SquareMat &other) {
  *this = *this - other;
  return *this;
}

SquareMat &SquareMat::operator*=(const SquareMat &other) {
  *this = *this * other;
  return *this;
}

SquareMat &SquareMat::operator*=(double scalar) {
  *this = *this * scalar;
  return *this;
}

SquareMat &SquareMat::operator/=(double scalar) {
  *this = *this / scalar;
  return *this;
}

SquareMat &SquareMat::operator%=(const SquareMat &other) {
  *this = *this % other;
  return *this;
}

SquareMat &SquareMat::operator%=(int scalar) {
  *this = *this % scalar;
  return *this;
}

SquareMat SquareMat::operator-() const {
  SquareMat res(size);
  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j)
      res.data[i][j] = -data[i][j];
  return res;
}

SquareMat &SquareMat::operator++() {
  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j)
      ++data[i][j];
  return *this;
}

SquareMat SquareMat::operator++(int) {
  SquareMat temp(*this);
  ++(*this);
  return temp;
}

SquareMat &SquareMat::operator--() {
  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j)
      --data[i][j];
  return *this;
}

SquareMat SquareMat::operator--(int) {
  SquareMat temp(*this);
  --(*this);
  return temp;
}

SquareMat SquareMat::operator~() const {
  SquareMat res(size);
  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j)
      res.data[i][j] = data[j][i];
  return res;
}

// comparisons operatrs

bool SquareMat::operator==(const SquareMat &other) const {
  double sum1 = 0, sum2 = 0;
  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j) {
      sum1 += data[i][j];
      sum2 += other.data[i][j];
    }
  return sum1 == sum2;
}

bool SquareMat::operator!=(const SquareMat &other) const {
  return !(*this == other);
}

bool SquareMat::operator<(const SquareMat &other) const {
  double sum1 = 0, sum2 = 0;
  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j) {
      sum1 += data[i][j];
      sum2 += other.data[i][j];
    }
  return sum1 < sum2;
}

bool SquareMat::operator>(const SquareMat &other) const {
  return other < *this;
}

bool SquareMat::operator<=(const SquareMat &other) const {
  return !(*this > other);
}

bool SquareMat::operator>=(const SquareMat &other) const {
  return !(*this < other);
}

// access to fileds of matrix

double *SquareMat::operator[](int index) {
  if (index < 0 || index >= size)
    throw std::out_of_range("Index out of bounds.");
  return data[index];
}

const double *SquareMat::operator[](int index) const {
  if (index < 0 || index >= size)
    throw std::out_of_range("Index out of bounds.");
  return data[index];
}

// determinant

static double calcDeterminant(double **mat, int n) {
  if (n == 1)
    return mat[0][0];
  if (n == 2)
    return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];

  double det = 0;
  for (int p = 0; p < n; p++) {
    double **temp = new double *[n - 1];
    for (int i = 0; i < n - 1; i++)
      temp[i] = new double[n - 1];

    for (int i = 1; i < n; i++) {
      int col = 0;
      for (int j = 0; j < n; j++) {
        if (j == p)
          continue;
        temp[i - 1][col++] = mat[i][j];
      }
    }

    det += (p % 2 == 0 ? 1 : -1) * mat[0][p] * calcDeterminant(temp, n - 1);

    for (int i = 0; i < n - 1; i++)
      delete[] temp[i];
    delete[] temp;
  }
  return det;
}

double SquareMat::operator!() const { return calcDeterminant(data, size); }

// output

std::ostream &operator<<(std::ostream &os, const SquareMat &mat) {
  for (int i = 0; i < mat.size; ++i) {
    for (int j = 0; j < mat.size; ++j)
      os << mat.data[i][j] << " ";
    os << "\n";
  }
  return os;
}

// scalar * matrix

SquareMat operator*(double scalar, const SquareMat &mat) {
  return mat * scalar;
}

}