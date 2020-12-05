#include <cassert>
#include <algorithm>
#include <iostream>
#include <math.h>

#include "../includes/array2d.h"

//constructor
Array2D::Array2D(std::array<int, 2> size) : size_(size)
{
  //allocate data, initialize to 0
  data_.resize(size_[0] * size_[1], 0.0);
}

//get the size
const std::array<int, 2> Array2D::size() const
{
  return size_;
}

//get the whole matrix, declared const, i.e. it is not possible to change the matrix
const std::vector<double> Array2D::operator()() const
{
  return data_;
}

//get the value at coordinate (i,j), declared const, i.e. it is not possible to change the value
void Array2D::operator=(const Array2D &result)
{
  //check if result matrix size corresponds to size of this matrix
  assert(size() == result.size());
  data_ = result();
}

//access the value at coordinate (i,j), declared not const, i.e. the value can be changed
double &Array2D::operator()(int i, int j)
{
  //calculate position of (i,j) in data array
  const int index = j * size_[0] + i;

  //assert that indices are in range
  assert(0 <= i && i < size_[0]);
  assert(0 <= j && j < size_[1]);
  assert(j * size_[0] + i < (int)data_.size());

  return data_[index];
}

//get the value at coordinate (i,j), declared const, i.e. it is not possible to change the value
double Array2D::operator()(int i, int j) const
{
  //calculate position of (i,j) in data array
  const int index = j * size_[0] + i;

  //assert that indices are in range
  assert(0 <= i && i < size_[0]);
  assert(0 <= j && j < size_[1]);
  assert(j * size_[0] + i < (int)data_.size());

  return data_[index];
}

//return maximum of array
double Array2D::get_max() const
{
  return *std::max_element(data_.begin(), data_.end());
}

//return minimum of array
double Array2D::get_min() const
{
  return *std::min_element(data_.begin(), data_.end());
}

//return absolute maximum of array
double Array2D::get_abs_max() const
{
  return std::max(fabs(get_min()), fabs(get_max()));
}

//resize to size and reset matrix on initial values (=0)
void Array2D::resize(const std::array<int, 2> size)
{
  size_ = size;
  // allocate data, initialize to 0
  data_.resize(size_[0] * size_[1], 0.0);
}

//print matrix to console
void Array2D::print() const
{
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
}

//overwrite matrix with new matrix
void Array2D::set_data(const Array2D &result)
{
  //assert that matrix sizes match
  assert(size() == result.size());
  data_ = result();
}


void Array2D::setToZero()
{
  std::fill(std::begin(data_), std::end(data_), 0);
}


double * Array2D::data()
{
  return data_.data();
}