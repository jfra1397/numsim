#include <cassert>
#include <algorithm>
#include <iostream>
#include <math.h>

#include "../includes/array2d.h"

//constructor
template<>
Array2D<double>::Array2D(std::array<int, 2> size) : size_(size)
{
  //allocate data, initialize to 0
  data_.resize(size_[0] * size_[1], 0.0);
}
template<>
Array2D<CELLTYPE>::Array2D(std::array<int, 2> size) : size_(size)
{
  //allocate data, initialize to 0
  data_.resize(size_[0] * size_[1], FLUID);
}
template<>
Array2D<OBJECTTEMPTYPE>::Array2D(std::array<int, 2> size) : size_(size)
{
  //allocate data, initialize to 0
  data_.resize(size_[0] * size_[1], NOOBJECT);
}

// //get the size
// template <typename T>
// const std::array<int, 2> Array2D<T>::size() const
// {
//   return size_;
// }

// //get the whole matrix, declared const, i.e. it is not possible to change the matrix
// template <typename T>
// const std::vector<T> Array2D<T>::operator()() const
// {
//   return data_;
// }

// //get the value at coordinate (i,j), declared const, i.e. it is not possible to change the value
// template <typename T>
// void Array2D<T>::operator=(const Array2D &result)
// {
//   //check if result matrix size corresponds to size of this matrix
//   assert(size() == result.size());
//   data_ = result();
// }

// //access the value at coordinate (i,j), declared not const, i.e. the value can be changed
// template <typename T>
// T &Array2D<T>::operator()(int i, int j)
// {
//   //calculate position of (i,j) in data array
//   const int index = j * size_[0] + i;

//   //assert that indices are in range
//   assert(0 <= i && i < size_[0]);
//   assert(0 <= j && j < size_[1]);
//   assert(j * size_[0] + i < (int)data_.size());

//   return data_[index];
// }

// //get the value at coordinate (i,j), declared const, i.e. it is not possible to change the value
// template <typename T>
// T Array2D<T>::operator()(int i, int j) const
// {
//   //calculate position of (i,j) in data array
//   const int index = j * size_[0] + i;

//   //assert that indices are in range
//   assert(0 <= i && i < size_[0]);
//   assert(0 <= j && j < size_[1]);
//   assert(j * size_[0] + i < (int)data_.size());

//   return data_[index];
// }

// //return maximum of array
// template <typename T>
// T Array2D<T>::get_max() const
// {
//   return *std::max_element(data_.begin(), data_.end());
// }

// //return minimum of array
// template <typename T>
// T Array2D<T>::get_min() const
// {
//   return *std::min_element(data_.begin(), data_.end());
// }

// //return absolute maximum of array
// template <typename T>
// T Array2D<T>::get_abs_max() const
// {
//   return std::max(fabs(get_min()), fabs(get_max()));
// }

// //resize to size and reset matrix on initial values (=0)
// template <typename T>
// void Array2D<T>::resize(const std::array<int, 2> size)
// {
//   size_ = size;
//   // allocate data, initialize to 0
//   data_.resize(size_[0] * size_[1], 0.0);
// }

// //print matrix to console
// template <typename T>
// void Array2D<T>::print() const
// {
//   //start iteration on the top for correct dsplaying (indexing start at bottom left corner)
//   for (int j = size()[1] - 1; j >= 0; j--)
//   {
//     //start iteration on the left for correct dsplaying (indexing start at bottom left corner)
//     for (int i = 0; i < size()[0]; i++)
//     {
//       std::cout << (*this)(i, j) << "  ";
//     }
//     std::cout << std::endl;
//   }
// }

// //overwrite matrix with new matrix
// template <typename T>
// void Array2D<T>::set_data(const Array2D &result)
// {
//   //assert that matrix sizes match
//   assert(size() == result.size());
//   data_ = result();
// }