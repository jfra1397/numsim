#pragma once

#include <mpi.h>

#include "settings.h"
#include "array2d.h"
#include "central_differences.h"
#include "donor_cell.h"

class Partitioning
{
public:
    Partitioning();

    //get discretization instance depending on settings
    std::shared_ptr<Discretization> get_discretization(const Settings &settings);
    
    double get_time(double myTime) const;
    
    void set_ghost(Array2D &data, int messageTag) const;
    void set_ghost_fg(Array2D &f, Array2D &g) const;
    void set_ghost_p(Array2D &data, int startPos) const;

    int noRanks() const;
    int ownRankNo() const;

    std::array<int,2> nodeOffset() const;
    bool ownPartitionContainsRightBoundary() const;
    bool ownPartitionContainsTopBoundary() const;

    std::array<int, 2> nCells() const;
    std::array<double, 2> physicalSize() const;
    std::array<int, 2> nCellsGlobal() const;
    std::array<double, 2> physicalSizeGlobal() const; 

    void exchange_uv(FieldVariable &u, FieldVariable &v, const Settings &settings) const;
    void exchange_fg(FieldVariable &f, FieldVariable &g, const FieldVariable &u, const FieldVariable &v) const;
    void exchange_p(FieldVariable &p, int startPos) const;
    
    private:

    int noRanks_;
    int ownRank_;

    std::array<int, 2> nCellsGlobal_;
    std::array<double, 2> physicalSizeGlobal_;

    std::array<int, 2> nCells_;
    std::array<double, 2> physicalSize_;
    
    std::array<int,2> nodeOffset_;
    
    //holds rank of neighbor process if rank equals to nRanks there is no neighbor bc-condition has to be applied
    int leftProcess_;
    int rightProcess_;
    int upProcess_;
    int downProcess_;
};