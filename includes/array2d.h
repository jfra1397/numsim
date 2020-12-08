#pragma once

#include <vector>
#include <array>
#include <cassert>

/** This class represents a 2D array of double values.
 *  Internally they are stored consecutively in memory.
 *  The entries can be accessed by two indices i,j.
 */
class Array2D
{
public:
  //constructor
  Array2D(const std::array<int, 2> &size);

  //get the size
  const std::array<int, 2> &size() const;

  //overwrite matrix with new matrix
  void set_data(const Array2D &data);

  //get the whole matrix, declared const, i.e. it is not possible to change the matrix
  const std::vector<double> &operator()() const;

  //access the value at coordinate (i,j), declared not const, i.e. the value can be changed
  //defined in header due to faster execution
  inline double &operator()(int i, int j)
  {
    //calculate position of (i,j) in data array
    const int index = j * size_[0] + i;

//assert that indices are in range, only in debug mode
#ifdef MY_DEBUG
    assert(0 <= i && i < size_[0]);
    assert(0 <= j && j < size_[1]);
    assert(j * size_[0] + i < (int)data_.size());
#endif

    return data_[index];
  };

  //get the value at coordinate (i,j), declared const, i.e. it is not possible to change the value
  //defined in header due to faster execution
  inline double operator()(int i, int j) const
  {
    //calculate position of (i,j) in data array
    const int index = j * size_[0] + i;

//assert that indices are in range,  only in debug mode
#ifdef MY_DEBUG
    assert(0 <= i && i < size_[0]);
    assert(0 <= j && j < size_[1]);
    assert(j * size_[0] + i < (int)data_.size());
#endif

    return data_[index];
  };

  //handels equal sign between two matrices
  void operator=(const Array2D &result);

  // set matrix entries to zero
  void setToZero();

  //used to generate pointer for output_writer
  double *data();

  //get row of a matrix, possible to set stepsize to 2, to get every second entry
  std::vector<double> get_row(int j, int start = 0, int stepsize = 1) const;

  //get column of a matrix, possible to set stepsize to 2, to get every second entry
  std::vector<double> get_column(int i, int start = 0, int stepsize = 1) const;

  //set row of a matrix, possible to set stepsize to 2, to set every second entry
  void set_row(int j, std::vector<double> row, int start = 0, int stepsize = 1);

  //set column of a matrix, possible to set stepsize to 2, to set every second entry
  void set_column(int i, std::vector<double> column, int start = 0, int stepsize = 1);

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