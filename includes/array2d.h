#pragma once

#include <vector>
#include <array>

/** This class represents a 2D array of double values.
 *  Internally they are stored consecutively in memory.
 *  The entries can be accessed by two indices i,j.
 */
class Array2D
{
public:
  //constructor
  Array2D(std::array<int, 2> size);

  //get the size
  const std::array<int, 2> size() const;

  //overwrite matrix with new matrix
  void set_data(const Array2D &data);

  //get the whole matrix, declared const, i.e. it is not possible to change the matrix
  const std::vector<double> operator()() const;

  //access the value at coordinate (i,j), declared not const, i.e. the value can be changed
  double &operator()(int i, int j);

  //get the value at coordinate (i,j), declared const, i.e. it is not possible to change the value
  double operator()(int i, int j) const;

  void operator=(const Array2D &result);

  void setToZero();

  double * data();

  std::vector<double> get_row(int j) const
  {
    std::vector<double> row(size_[0]);
    for (int i = 0; i < size_[0]; i++) row[i] = (*this)(i,j);
    return row; 
  };
  std::vector<double> get_column(int i) const
  {
    std::vector<double> column(size_[1]);
    for (int j = 0; j < size_[1]; j++) column[j] = (*this)(i,j);
    return column; 
  };
  void set_row(int j, std::vector<double> row)
  {
    for (int i = 0; i < size_[0]; i++) (*this)(i,j) = row[i];
  };
  void set_column(int i, std::vector<double> column)
  {
    for (int j = 0; j < size_[1]; j++) (*this)(i,j)  = column[j];
  };
  //return maximum of array
  double get_max() const;

  //return minimum of array
  double get_min() const;

  //return absolute maximum of array
  double get_abs_max() const;

  //print matrix to console
  void print() const;

protected:
  //resize to size and reset matrix on initial values (=0)
  void resize(const std::array<int, 2> size);

private:
  //storage array values, in row-major order
  std::vector<double> data_;

  //width, height of the domain
  std::array<int, 2> size_;
};