#include <cassert>
#include <algorithm>
#include <iostream>
#include <math.h>

#include "../includes/array2d.h"

//constructor for data type double
template <>
Array2D<double>::Array2D(std::array<int, 2> size, double value) : size_(size)
{
  //allocate data, initialize to 0
  data_.resize(size_[0] * size_[1], value);
}
//constructor for data type CELLTYPE
template <>
Array2D<CELLTYPE>::Array2D(std::array<int, 2> size, CELLTYPE value) : size_(size)
{
  //allocate data, initialize to FLUID
  data_.resize(size_[0] * size_[1], value);
}
//constructor for data type btype
template <>
Array2D<btype>::Array2D(std::array<int, 2> size, btype value) : size_(size)
{
  //allocate data, initialize to NOTHING
  data_.resize(size_[0] * size_[1], value);
}