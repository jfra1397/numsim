#pragma once

#include <mpi.h>

#include "settings.h"
#include "array2d.h"
#include "central_differences.h"
#include "donor_cell.h"

/** This  class enables multiprocessing by providing functions like
 * exchanging edges of field variables between different processes.
 **/
class Partitioning
{
public:
    //constructor
    Partitioning();

    //get discretization instance depending on settings
    std::shared_ptr<Discretization> get_discretization(const Settings &settings);

    //get calculated timestep of each process and return minimum
    double get_time(double myTime) const;

    //set values at ghost edges or apply boundary condition
    void set_ghost_uv(Array2D &u, Array2D &v) const;
    void set_ghost_fg(Array2D &f, Array2D &g) const;
    void set_ghost_p(Array2D &p, int startPos) const;

    //returns amount of acting processes
    int noRanks() const { return noRanks_; };

    //returns rank of own process
    int ownRankNo() const { return ownRank_; };

    //returns node offset depending on position of own rank's partition
    const std::array<int, 2> &nodeOffset() const { return nodeOffset_; };

    //return if own partition is at right or top boundary
    bool ownPartitionContainsRightBoundary() const { return (rightProcess_ == noRanks_); };
    bool ownPartitionContainsTopBoundary() const { return (topProcess_ == noRanks_); };

    //return size of own partition and of global area
    const std::array<int, 2> &nCells() const { return nCells_; };
    const std::array<double, 2> &physicalSize() const { return physicalSize_; } ;
    const std::array<int, 2> &nCellsGlobal() const  { return nCellsGlobal_; };
    const std::array<double, 2> &physicalSizeGlobal() const { return physicalSizeGlobal_; };

    //set boundary condition or exchange values of the edges of all field variables
    void exchange_uv(FieldVariable &u, FieldVariable &v, const Settings &settings) const;
    void exchange_fg(FieldVariable &f, FieldVariable &g, const FieldVariable &u, const FieldVariable &v) const;
    void exchange_p(FieldVariable &p, int startPos) const;

private:
    //amount of acting processes
    int noRanks_;

    //rank of own process
    int ownRank_;

    //size of own partition and of global area
    std::array<int, 2> nCellsGlobal_;
    std::array<double, 2> physicalSizeGlobal_;
    std::array<int, 2> nCells_;
    std::array<double, 2> physicalSize_;

    //node offset depending on position of own rank's partition
    std::array<int, 2> nodeOffset_;

    //holds rank of neighbor process
    //if rank equals to nRanks, no neighboring boundary condition has to be applied
    int leftProcess_;
    int rightProcess_;
    int topProcess_;
    int bottomProcess_;
};