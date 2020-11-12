#include <cassert>
#include <algorithm>
#include <iostream>

#include "../includes/array2d.h"



Array2D::Array2D(std::array<int,2> size) :
  size_(size)
{
  // allocate data, initialize to 0
  data_.resize(size_[0]*size_[1], 0.0);
}

//! get the size
const std::array<int,2> Array2D::size() const
{
  return size_;
}

const std::vector<double> Array2D::operator()() const
{
  return data_;
}

void Array2D::operator= (const Array2D &result)
{
  assert(size() == result.size());
  data_ = result();

}

double &Array2D::operator()(int i, int j)

{
  const int index = j*size_[0] + i;

  // assert that indices are in range
  assert(0 <= i && i < size_[0]);
  assert(0 <= j && j < size_[1]);
  assert(j*size_[0] + i < (int)data_.size());

  return data_[index];
}

double Array2D::operator()(int i, int j) const
{
  const int index = j*size_[0] + i;

  // assert that indices are in range
  assert(0 <= i && i < size_[0]);
  assert(0 <= j && j < size_[1]);
  assert(j*size_[0] + i < (int)data_.size());

  return data_[index];
}

double Array2D::get_max() const
{
    double max = *std::max_element(data_.begin(), data_.end());

    return max;
}

double Array2D::get_min() const
{
    double min = *std::min_element(data_.begin(), data_.end());

    return min;
}

void Array2D::resize(const std::array<int,2> size)
{
  size_=size;
  // allocate data, initialize to 0
  data_.resize(size_[0]*size_[1], 0.0);
}

void Array2D::print() const
{
    for(int j = size()[1] - 1; j>= 0 ;j--)
    {
        for (int i=0; i<size()[0]; i++)
        {
            std::cout << (*this)(i,j) << "  ";
        }
        std::cout << std::endl;
    }
}