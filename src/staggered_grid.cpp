#include "../includes/staggered_grid.h"

StaggeredGrid::StaggeredGrid(const std::array<int, 2> &size, const std::array<double, 2> &physicalSize, std::array<edgetype, 4> &edgestype)
    : u_(size, VRIGHT, physicalSize, edgestype), v_(size, VTOP, physicalSize, edgestype),
      p_(size, VCENTRE, physicalSize, edgestype), f_(size, VRIGHT, physicalSize, edgestype),
      g_(size, VTOP, physicalSize, edgestype), rhs_(size, VCENTRE, physicalSize, edgestype)
{
  //pressure uses Neummann boundary conditions
  set_p().set_boundary_type(NEUMANN, NEUMANN, NEUMANN, NEUMANN);
}

//dummy functions for output_writer_text_parallel
int StaggeredGrid::uIBegin() const {}
int StaggeredGrid::uIEnd() const {}
int StaggeredGrid::uJBegin() const {}
int StaggeredGrid::uJEnd() const {}
int StaggeredGrid::vIBegin() const {}
int StaggeredGrid::vIEnd() const {}
int StaggeredGrid::vJBegin() const {}
int StaggeredGrid::vJEnd() const {}
int StaggeredGrid::pIBegin() const {}
int StaggeredGrid::pIEnd() const {}
int StaggeredGrid::pJBegin() const {}
int StaggeredGrid::pJEnd() const {}