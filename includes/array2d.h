#pragma once

#include <cassert>
#include <algorithm>
#include <iostream>
#include <math.h>

#include <vector>
#include <array>

#include "values.h"



/** This class represents a 2D array as template values.
 *  Internally they are stored consecutively in memory.
 *  The entries can be accessed by two indices i,j.
 */
template <typename T>
class Array2D
{
public:
  //constructor
  Array2D(std::array<int, 2> size);

  //get the size
  const std::array<int, 2> size() const {return size_ ;};

  //overwrite matrix with new matrix
  void set_data(const Array2D &result){
  //assert that matrix sizes match
  assert(size() == result.size());
  data_ = result();
};

  //get the whole matrix, declared const, i.e. it is not possible to change the matrix
  const std::vector<T> operator()() const{
  return data_;
};

  //access the value at coordinate (i,j), declared not const, i.e. the value can be changed
  T &operator()(int i, int j){
  //calculate position of (i,j) in data array
  const int index = j * size_[0] + i;

  //assert that indices are in range
  assert(0 <= i && i < size_[0]);
  assert(0 <= j && j < size_[1]);
  assert(j * size_[0] + i < (int)data_.size());

  return data_[index];
};

  //get the value at coordinate (i,j), declared const, i.e. it is not possible to change the value
  T operator()(int i, int j) const{
  //calculate position of (i,j) in data array
  const int index = j * size_[0] + i;

  //assert that indices are in range
  assert(0 <= i && i < size_[0]);
  assert(0 <= j && j < size_[1]);
  assert(j * size_[0] + i < (int)data_.size());

  return data_[index];
};

  void operator=(const Array2D &result){
  //check if result matrix size corresponds to size of this matrix
  assert(size() == result.size());
  data_ = result();
};

  //return maximum of array
  T get_max() const{
  return *std::max_element(data_.begin(), data_.end());
};

  //return minimum of array
  T get_min() const{
  return *std::min_element(data_.begin(), data_.end());
};

  //return absolute maximum of array
  T get_abs_max() const{
  return std::max(fabs(get_min()), fabs(get_max()));
};

  //print matrix to console
  void print() const{
  //start iteration on the top for correct dsplaying (indexing start at bottom left corner)
  for (int j = size()[1] - 1; j >= 0; j--)
  {
    //start iteration on the left for correct dsplaying (indexing start at bottom left corner)
    for (int i = 0; i < size()[0]; i++)
    {
      std::cout << (*this)(i, j) << "  ";
    }
    std::cout << std::endl;
  }
};

protected:
  //resize to size and reset matrix on initial values (=0)
  void resize(const std::array<int, 2> size){
  size_ = size;
  // allocate data, initialize to 0
  data_.resize(size_[0] * size_[1], 0.0);
};

private:
  //storage array values, in row-major order
  std::vector<T> data_;

  //width, height of the domain
  std::array<int, 2> size_;
};