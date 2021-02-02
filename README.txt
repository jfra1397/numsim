README

This program is a fluid solver for laminar flow.
It is possible to use arbitrary geometries und to model heat flow.

How to run the program?
create a build folder and execute the following from within it:
cmake ..
make
./numsim ../cases/parameters.txt

An example parameters.txt is already given in the cases folder. It only differs slightly from the original file. Changes are shown in the following:

The Prandtl number pr, internal heat q, beta (volume expansion coefficient) and gamma are added according to the lecture.
tInit describes the initial temperature of the domain.

The boundary conditions need to be determined differently, this is a commented example:
{
    Type = Bottombound             #location boundary, alternatives: Topbound, Bottombound, Leftbound, Rightbound
    Velocity= Dirichlet; 0; 0      #boundary type and values (u;v) for velocity, alternatives: Dirichlet , Neumann
    Pressure= Neumann; 0           #boundary type and value for pressure, alternatives: Dirichlet , Neumann
    Temperature = Neumann; 0       #boundary type and value for temperature, alternatives: Dirichlet , Neumann
    Position = 0; 1                #physical starting and end value where the boundary conditions and values should be applied
}
!!Velocity and pressure need to be of a different boundary type!!
Obstacles are determined similarly, possible shapes are rectangle, triangle and ellipse:
{
    Shape = Rectangle              
    Position= 0.4;0.4;0.6;0.6      #bottomleft (x_1,y_1) and topright (x_2,y_2) corner as x_1;y_1;x_2;y_2
    Temperature= Dirichlet; 1      #boundary type and value for temperature, alternatives: Dirichlet , Neumann
}
{
    Shape = Triangle              
    Position= 0.4;0.4;0.5;0.6;0.6;0.4      #first(x_1,y_1),second (x_2,y_2) and third (x_3,y_3) corner as x_1;y_1;x_2;y_2;x_3,y_3
    Temperature= Dirichlet; 1              #boundary type and value for temperature, alternatives: Dirichlet , Neumann
}
{
    Shape = Ellipse             
    Position= 0.4;0.4;0.6;0.8      #center (x,y) and half-axes (a,b) of ellipse as x;y;a;b
    Temperature= Dirichlet; 1      #boundary type and value for temperature, alternatives: Dirichlet , Neumann
}
It is possible to change the obstacle its type to fluid, by adding
Type= Fluid. This can be used when "cutting out" parts of an obstacle.
For example, check the last obstacle in standardForms.txt A rectangle is partly overlaid by a fluid ellipse.
!!NOSLIP boundary conditions are always applied for obstacles!!

The following flags can be added when running the file (./numsim ../cases/parameters.txt):
-m (only create mesh)
-o (output direction)
-r (remove files in output folder)
-tf (print time feedback)
-h (help)
For further information run ./numsim ../cases/parameters.txt -h.

Resulting vts-files are stored in the given out-folder (-o, default: build/out).