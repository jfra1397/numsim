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
  
  //! constructor
  Array2D(std::array<int,2> size);

  //! get the size
  const std::array<int,2> size() const;

  const std::vector<double> operator()() const;

  //! access the value at coordinate (i,j), declared not const, i.e. the value can be changed
  double &operator()(int i, int j);

  //! get the value at coordinate (i,j), declared const, i.e. it is not possible to change the value
  double operator()(int i, int j) const;

  void operator= (const Array2D &data);

  //return maximum of array
  double get_max() const;

  //retunr minimum of array
  double get_min() const;

  void print() const;

protected:
  void resize(const std::array<int,2> size);

private:
  std::vector<double> data_;  //< storage array values, in row-major order
  std::array<int,2> size_;    //< width, height of the domain
};