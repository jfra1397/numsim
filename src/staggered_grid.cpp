#include "../includes/staggered_grid.h"

//constructor
StaggeredGrid::StaggeredGrid(const std::array<int, 2> size, const std::array<double, 2> physicalSize, const std::array<double, 2> meshWidth, double tInit)
    : Mesh(size, physicalSize),
      u_({size[0] + 1, size[1] + 2}, VRIGHT, physicalSize, meshWidth),
      v_({size[0] + 2, size[1] + 1}, VTOP, physicalSize, meshWidth),
      p_({size[0] + 2, size[1] + 2}, VCENTRE, physicalSize, meshWidth),
      f_({size[0] + 1, size[1] + 2}, VRIGHT, physicalSize, meshWidth),
      g_({size[0] + 2, size[1] + 1}, VTOP, physicalSize, meshWidth),
      rhs_({size[0] + 2, size[1] + 2}, VCENTRE, physicalSize, meshWidth),
      T_({size[0] + 2, size[1] + 2}, VCENTRE, physicalSize, meshWidth, tInit)
{
}

//set boundary values of u and v according to given boundary condition values
void StaggeredGrid::set_boundary_uvfg()
{
    for (int j = 1; j < flag_.size()[1] - 1; j++)
    {
        for (int i = 1; i < flag_.size()[0] - 1; i++)
        {
            switch (flag_(i, j))
            {
            //no boundary to be set in cells of type fluid or empty
            case FLUID:
            case EMPTY:
                break;
            //set boundaries depending on where obstacle cell is
            case OBJLEFT:
                u_(i - 1, j) = 0;
                v_(i, j) = -v_(i - 1, j);
                v_(i, j - 1) = -v_(i - 1, j - 1);
                f_(i - 1, j) = 0;
                g_(i, j) = -v_(i - 1, j);
                g_(i, j - 1) = -v_(i - 1, j - 1);
                break;
            case OBJRIGHT:
                u_(i, j) = 0;
                v_(i, j) = -v_(i + 1, j);
                v_(i, j - 1) = -v_(i + 1, j - 1);
                f_(i, j) = 0;
                g_(i, j) = -v_(i + 1, j);
                g_(i, j - 1) = -v_(i + 1, j - 1);
                break;
            case OBJTOP:
                u_(i, j) = -u_(i, j + 1);
                u_(i - 1, j) = -u_(i - 1, j + 1);
                v_(i, j) = 0;
                f_(i, j) = -u_(i, j + 1);
                f_(i - 1, j) = -u_(i - 1, j + 1);
                g_(i, j) = 0;
                break;
            case OBJBOTTOM:
                u_(i, j) = -u_(i, j - 1);
                u_(i - 1, j) = -u_(i - 1, j - 1);
                v_(i, j - 1) = 0;
                f_(i, j) = -u_(i, j - 1);
                f_(i - 1, j) = -u_(i - 1, j - 1);
                g_(i, j - 1) = 0;
                break;
            case OBJBOTTOMLEFT:
                u_(i, j) = f_(i, j) = -u_(i, j - 1);
                u_(i - 1, j) = f_(i - 1, j) = 0;
                v_(i, j) = g_(i, j) = -v_(i - 1, j);
                v_(i, j - 1) = g_(i, j - 1) = 0;
                break;
            case OBJBOTTOMRIGHT:
                u_(i, j) = f_(i, j) = 0;
                u_(i - 1, j) = f_(i - 1, j) = -u_(i - 1, j - 1);
                v_(i, j) = g_(i, j) = -v_(i + 1, j);
                v_(i, j - 1) = g_(i, j - 1) = 0;
                break;
            case OBJTOPLEFT:
                u_(i, j) = f_(i, j) = -u_(i, j + 1);
                u_(i - 1, j) = f_(i - 1, j) = 0;
                v_(i, j) = g_(i, j) = 0;
                v_(i, j - 1) = g_(i, j - 1) = -v_(i - 1, j - 1);
                break;
            case OBJTOPRIGHT:
                u_(i, j) = f_(i, j) = 0;
                u_(i - 1, j) = f_(i - 1, j) = -u_(i - 1, j + 1);
                v_(i, j) = g_(i, j) = 0;
                v_(i, j - 1) = g_(i, j - 1) = -v_(i + 1, j - 1);
                break;

            default:
                assert(false);
            }
        }
    }
    //set boundary value for u at bottom and top bound
    for (int i = 0; i < u_.size()[0]; i++)
    {
        switch (bottomBoundVelFlag_[i])
        {
        case DIRICHLET:
            u_(i, 0) = f_(i, 0) = 2 * bottomBoundValues_[i][0] - u_(i, 1);
            break;
        case NEUMANN:
            u_(i, 0) = f_(i, 0) = u_(i, 1);
            break;
        default:
            assert(false);
        }

        switch (topBoundVelFlag_[i])
        {
        case DIRICHLET:
            u_(i, u_.size()[1] - 1) = f_(i, u_.size()[1] - 1) = 2 * topBoundValues_[i][0] - u_(i, u_.size()[1] - 2);
            break;
        case NEUMANN:
            u_(i, u_.size()[1] - 1) = f_(i, u_.size()[1] - 1) = u_(i, u_.size()[1] - 2);
            break;
        default:
            assert(false);
        }
    }
    //set boundary value for u at left and right bound
    for (int j = 0; j < u_.size()[1]; j++)
    {
        switch (leftBoundVelFlag_[j])
        {
        case DIRICHLET:
            u_(0, j) = f_(0, j) = leftBoundValues_[j][0];
            break;
        case NEUMANN:
            u_(0, j) = f_(0, j) = u_(1, j);
            break;
        default:
            assert(false);
        }

        switch (rightBoundVelFlag_[j])
        {
        case DIRICHLET:
            u_(u_.size()[0] - 1, j) = f_(u_.size()[0] - 1, j) = rightBoundValues_[j][0];
            break;
        case NEUMANN:
            u_(u_.size()[0] - 1, j) = f_(u_.size()[0] - 1, j) = u_(u_.size()[0] - 2, j);
            break;
        default:
            assert(false);
        }
    }
    //set boundary value for v at bottom and top bound
    for (int i = 0; i < v_.size()[0]; i++)
    {
        switch (bottomBoundVelFlag_[i])
        {
        case DIRICHLET:
            v_(i, 0) = g_(i, 0) = bottomBoundValues_[i][1];
            break;
        case NEUMANN:
            v_(i, 0) = g_(i, 0) = v_(i, 1);
            break;
        default:
            assert(false);
        }

        switch (topBoundVelFlag_[i])
        {
        case DIRICHLET:
            v_(i, v_.size()[1] - 1) = g_(i, v_.size()[1] - 1) = topBoundValues_[i][1];
            break;
        case NEUMANN:
            v_(i, v_.size()[1] - 1) = g_(i, v_.size()[1] - 1) = v_(i, v_.size()[1] - 2);
            break;
        default:
            assert(false);
        }
    }
    //set boundary value for v at left and right bound
    for (int j = 0; j < v_.size()[1]; j++)
    {
        switch (leftBoundVelFlag_[j])
        {
        case DIRICHLET:
            v_(0, j) = g_(0, j) = 2 * leftBoundValues_[j][1] - v_(1, j);
            break;
        case NEUMANN:
            v_(0, j) = g_(0, j) = v_(1, j);
            break;
        default:
            assert(false);
        }

        switch (rightBoundVelFlag_[j])
        {
        case DIRICHLET:
            v_(v_.size()[0] - 1, j) = g_(v_.size()[0] - 1, j) = 2 * rightBoundValues_[j][1] - v_(v_.size()[0] - 2, j);
            break;
        case NEUMANN:
            v_(v_.size()[0] - 1, j) = g_(v_.size()[0] - 1, j) = v_(v_.size()[0] - 2, j);
            break;
        default:
            assert(false);
        }
    }
}

//set boundary values of p according to given boundary condition values
void StaggeredGrid::set_boundary_p(FieldVariable &p) const
{
    for (int j = 1; j < flag_.size()[1] - 1; j++)
    {
        for (int i = 1; i < flag_.size()[0] - 1; i++)
        {
            switch (flag_(i, j))
            {
            //no boundary to be set in cells of type fluid or empty
            case FLUID:
            case EMPTY:
                break;
            //set boundaries depending on where obstacle cell is
            case OBJLEFT:
                p(i, j) = p(i - 1, j);
                break;
            case OBJRIGHT:
                p(i, j) = p(i + 1, j);
                break;
            case OBJTOP:
                p(i, j) = p(i, j + 1);
                break;
            case OBJBOTTOM:
                p(i, j) = p(i, j - 1);
                break;
            case OBJBOTTOMLEFT:
                p(i, j) = (p(i - 1, j) + p(i, j - 1)) / 2;
                break;
            case OBJBOTTOMRIGHT:
                p(i, j) = (p(i + 1, j) + p(i, j - 1)) / 2;
                break;
            case OBJTOPLEFT:
                p(i, j) = (p(i - 1, j) + p(i, j + 1)) / 2;
                break;
            case OBJTOPRIGHT:
                p(i, j) = (p(i + 1, j) + p(i, j + 1)) / 2;
                break;

            default:
                assert(false);
            }
        }
    }
    //set boundary value for p at bottom and top bound
    for (int i = 0; i < p_.size()[0]; i++)
    {
        switch (bottomBoundVelFlag_[i])
        {
        case DIRICHLET:
            p(i, 0) = p(i, 1);
            break;
        case NEUMANN:
            p(i, 0) = 2 * bottomBoundValues_[i][2] - p(i, 1);
            break;
        default:
            assert(false);
        }

        switch (topBoundVelFlag_[i])
        {
        case DIRICHLET:
            p(i, p.size()[1] - 1) = p(i, p.size()[1] - 2);
            break;
        case NEUMANN:
            p(i, p.size()[1] - 1) = 2 * topBoundValues_[i][2] - p(i, p.size()[1] - 2);
            break;
        default:
            assert(false);
        }
    }
    //set boundary value for u at left and right bound
    for (int j = 0; j < p.size()[1]; j++)
    {
        switch (leftBoundVelFlag_[j])
        {
        case DIRICHLET:
            p(0, j) = p(1, j);
            break;
        case NEUMANN:
            p(0, j) = 2 * leftBoundValues_[j][2] - p(1, j);
            break;
        default:
            assert(false);
        }

        switch (rightBoundVelFlag_[j])
        {
        case DIRICHLET:
            p(p.size()[0] - 1, j) = p(p.size()[0] - 2, j);
            break;
        case NEUMANN:
            p(p.size()[0] - 1, j) = 2 * rightBoundValues_[j][2] - p(p.size()[0] - 2, j);
            break;
        default:
            assert(false);
        }
    }
}

//set boundary values of T according to given boundary condition values
void StaggeredGrid::set_boundary_T(FieldVariable &T) const
{
    for (int j = 1; j < flag_.size()[1] - 1; j++)
    {
        for (int i = 1; i < flag_.size()[0] - 1; i++)
        {

            switch (flag_(i, j))
            {
            //no boundary to be set in cells of type fluid or empty
            case FLUID:
            case EMPTY:
                break;
            //set boundaries depending on where obstacle cell is
            case OBJLEFT:
                if (objTemperatureFlag_(i, j) == NEUMANN)
                    T(i, j) = T(i - 1, j);
                else if (objTemperatureFlag_(i, j) == DIRICHLET)
                    T(i, j) = 2 * objTemperatureValues_(i, j) - T(i - 1, j);
                break;
            case OBJRIGHT:
                if (objTemperatureFlag_(i, j) == NEUMANN)
                    T(i, j) = T(i + 1, j);
                else if (objTemperatureFlag_(i, j) == DIRICHLET)
                    T(i, j) = 2 * objTemperatureValues_(i, j) - T(i + 1, j);
                break;
            case OBJTOP:
                if (objTemperatureFlag_(i, j) == NEUMANN)
                    T(i, j) = T(i, j + 1);
                else if (objTemperatureFlag_(i, j) == DIRICHLET)
                    T(i, j) = 2 * objTemperatureValues_(i, j) - T(i, j + 1);
                break;
            case OBJBOTTOM:
                if (objTemperatureFlag_(i, j) == NEUMANN)
                    T(i, j) = T(i, j - 1);
                else if (objTemperatureFlag_(i, j) == DIRICHLET)
                    T(i, j) = 2 * objTemperatureValues_(i, j) - T(i, j - 1);
                break;
            case OBJBOTTOMLEFT:
                if (objTemperatureFlag_(i, j) == NEUMANN)
                    T(i, j) = (T(i - 1, j) + T(i, j - 1)) / 2;
                else if (objTemperatureFlag_(i, j) == DIRICHLET)
                    T(i, j) = 2 * objTemperatureValues_(i, j) - (T(i, j - 1) + T(i - 1, j)) / 2;
                break;
            case OBJBOTTOMRIGHT:
                if (objTemperatureFlag_(i, j) == NEUMANN)
                    T(i, j) = (T(i + 1, j) + T(i, j - 1)) / 2;
                else if (objTemperatureFlag_(i, j) == DIRICHLET)
                    T(i, j) = 2 * objTemperatureValues_(i, j) - (T(i, j - 1) + T(i + 1, j)) / 2;
                break;
            case OBJTOPLEFT:
                if (objTemperatureFlag_(i, j) == NEUMANN)
                    T(i, j) = (T(i - 1, j) + T(i, j + 1)) / 2;
                else if (objTemperatureFlag_(i, j) == DIRICHLET)
                    T(i, j) = 2 * objTemperatureValues_(i, j) - (T(i, j + 1) + T(i - 1, j)) / 2;
                break;
            case OBJTOPRIGHT:
                if (objTemperatureFlag_(i, j) == NEUMANN)
                    T(i, j) = (T(i + 1, j) + T(i, j + 1)) / 2;
                else if (objTemperatureFlag_(i, j) == DIRICHLET)
                    T(i, j) = 2 * objTemperatureValues_(i, j) - (T(i, j + 1) + T(i + 1, j)) / 2;
                break;

            default:
                assert(false);
            }
        }
    }
    //set boundary value for T at bottom and top bound
    for (int i = 0; i < T_.size()[0]; i++)
    {
        switch (bottomBoundTempFlag_[i])
        {

        case DIRICHLET:
            T(i, 0) = 2 * bottomBoundValues_[i][3] - T(i, 1);
            break;
        case NEUMANN:
            T(i, 0) = T(i, 1);
            break;
        default:
            assert(false);
        }

        switch (topBoundTempFlag_[i])
        {
        case DIRICHLET:
            T(i, T_.size()[1] - 1) = 2 * topBoundValues_[i][3] - T(i, T_.size()[1] - 2);
            break;
        case NEUMANN:
            T(i, T_.size()[1] - 1) = T(i, T_.size()[1] - 2);
            break;
        default:
            assert(false);
        }
    }
    //set boundary value for T at left and right bound
    for (int j = 0; j < T_.size()[1]; j++)
    {
        switch (leftBoundTempFlag_[j])
        {
        case DIRICHLET:
            T(0, j) = 2 * leftBoundValues_[j][3] - T(1, j);
            break;
        case NEUMANN:
            T(0, j) = T(1, j);
            break;
        default:
            assert(false);
        }

        switch (rightBoundTempFlag_[j])
        {
        case DIRICHLET:
            T(T_.size()[0] - 1, j) = 2 * rightBoundValues_[j][3] - T(T.size()[0] - 2, j);
            break;
        case NEUMANN:
            T(T.size()[0] - 1, j) = T(T.size()[0] - 2, j);
            break;
        default:
            assert(false);
        }
    }
}
//get the whole field variable, declared const, i.e. it is not possible to change it
const FieldVariable &StaggeredGrid::u() const { return u_; }
const FieldVariable &StaggeredGrid::v() const { return v_; }
const FieldVariable &StaggeredGrid::p() const { return p_; }
const FieldVariable &StaggeredGrid::f() const { return f_; }
const FieldVariable &StaggeredGrid::g() const { return g_; }
const FieldVariable &StaggeredGrid::rhs() const { return rhs_; }
const FieldVariable &StaggeredGrid::T() const { return T_; }

//get the value at coordinate (i,j), declared const, i.e. it is not possible to change the value
double StaggeredGrid::u(int i, int j) const { return u_(i, j); }
double StaggeredGrid::v(int i, int j) const { return v_(i, j); }
double StaggeredGrid::p(int i, int j) const { return p_(i, j); }
double StaggeredGrid::f(int i, int j) const { return f_(i, j); }
double StaggeredGrid::g(int i, int j) const { return g_(i, j); }
double StaggeredGrid::rhs(int i, int j) const { return rhs_(i, j); }
double StaggeredGrid::T(int i, int j) const { return T_(i, j); }
CELLTYPE StaggeredGrid::flag(int i, int j) const { return flag_(i, j); }

//access the field variable, declared not const, i.e. the values can be changed
FieldVariable &StaggeredGrid::set_u() { return u_; }
FieldVariable &StaggeredGrid::set_v() { return v_; }
FieldVariable &StaggeredGrid::set_p() { return p_; }
FieldVariable &StaggeredGrid::set_f() { return f_; }
FieldVariable &StaggeredGrid::set_g() { return g_; }
FieldVariable &StaggeredGrid::set_rhs() { return rhs_; }
FieldVariable &StaggeredGrid::set_T() { return T_; }

//access the value at coordinate (i,j), declared not const, i.e. the value can be changed
double &StaggeredGrid::set_u(int i, int j) { return u_(i, j); }
double &StaggeredGrid::set_v(int i, int j) { return v_(i, j); }
double &StaggeredGrid::set_p(int i, int j) { return p_(i, j); }
double &StaggeredGrid::set_f(int i, int j) { return f_(i, j); }
double &StaggeredGrid::set_g(int i, int j) { return g_(i, j); }
double &StaggeredGrid::set_rhs(int i, int j) { return rhs_(i, j); }
double &StaggeredGrid::set_T(int i, int j) { return T_(i, j); }