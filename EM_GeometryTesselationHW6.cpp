/*
Name: Mohamed Eraky
HW-6: 
This code output the stl files for cube and cylinder.
Note: Cylinder can be refined by changing n, higher -> finer mesh. 
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

class shape
{
private:
  double x, y, z; //  position
public:
  shape() : x(0), y(0), z(0) {}
  virtual void print(ostream &os) const = 0;
};

class cylinder : public shape
{
private:
  double r, h;
  uint64_t n;

public:
  cylinder(double rad, double height, int n) : r(rad), h(height), n(n) {}
  void print(ostream &os) const override
  {
    // top surface
    double ntop[] = {0, 0, 1};
    double nbot[] = {0, 0, -1};
    double top_c[] = {0, 0, h}; // top center
    double bot_c[] = {0, 0, 0}; // bottom center

    double dtheta = 2.0 * M_PI / n;
    os << "solid "
       << " "
       << "cylinder"
       << "\n";
    for (uint16_t i = 0; i < n; i++)
    {
      os << "facet normal"
         << " " << ntop[0] << " " << ntop[1] << " " << ntop[2] << "\n";
      os << "outer loop\n";
      os << "vertex"
         << " " << top_c[0] << " " << top_c[1] << " " << top_c[2] << "\n";
      os << "vertex"
         << " " << r * cos(i * dtheta) << " " << r * sin(i * dtheta) << " " << h << "\n";
      os << "vertex"
         << " " << r * cos((i + 1) * dtheta) << " " << r * sin((i + 1) * dtheta) << " " << h << "\n";
      os << "endloop\n";
      os << "endfacet\n";
    }
    // bottom surface loop
    for (uint16_t i = 0; i < n; i++)
    {
      os << "facet normal"
         << " " << nbot[0] << " " << nbot[1] << " " << nbot[2] << "\n";
      os << "outer loop\n";
      os << "vertex"
         << " " << bot_c[0] << " " << bot_c[1] << " " << bot_c[2] << "\n";
      os << "vertex"
         << " " << r * cos(i * dtheta) << " " << r * sin(i * dtheta) << " " << 0 << "\n";
      os << "vertex"
         << " " << r * cos((i + 1) * dtheta) << " " << r * sin((i + 1) * dtheta) << " " << 0 << "\n";
      os << "endloop\n";
      os << "endfacet\n";
    }
    // circumference-1
    for (uint16_t i = 0; i < n; i++)
    {
      double x1 = r * cos(i * dtheta);
      double y1 = r * sin(i * dtheta);
      double z1 = h;

      double x2 = r * cos((i + 1) * dtheta);
      double y2 = r * sin((i + 1) * dtheta);
      double z2 = h;

      double x3 = r * cos(i * dtheta);
      double y3 = r * sin(i * dtheta);
      double z3 = 0;

      double Ax = x2 - x1;
      double Ay = y2 - y1;
      double Az = z2 - z1;
      double Bx = x3 - x1;
      double By = y3 - y1;
      double Bz = z3 - z1;
      double nx = Ay * Bz - Az * By;
      double ny = Az * Bx - Ax * Bz;
      double nz = Ax * Bz - Ay * Bx;

      os << "facet normal"
         << " " << nx << " " << ny << " " << nz << "\n";
      os << "outer loop\n";
      os << "vertex"
         << " " << x1 << " " << y1 << " " << z1 << "\n";
      os << "vertex"
         << " " << x2 << " " << y2 << " " << z2 << "\n";
      os << "vertex"
         << " " << x3 << " " << y3 << " " << z3 << "\n";
      os << "endloop\n";
      os << "endfacet\n";
    }
    // circumference 2
    for (uint16_t i = 0; i < n; i++)
    {
      double x1 = r * cos(i * dtheta);
      double y1 = r * sin(i * dtheta);
      double z1 = 0;

      double x2 = r * cos((i + 1) * dtheta);
      double y2 = r * sin((i + 1) * dtheta);
      double z2 = 0;

      double x3 = x2;
      double y3 = y2;
      double z3 = h;

      double Ax = x2 - x1;
      double Ay = y2 - y1;
      double Az = z2 - z1;
      double Bx = x3 - x1;
      double By = y3 - y1;
      double Bz = z3 - z1;
      double nx = Ay * Bz - Az * By;
      double ny = Az * Bx - Ax * Bz;
      double nz = Ax * Bz - Ay * Bx;

      os << "facet normal"
         << " " << nx << " " << ny << " " << nz << "\n";
      os << "outer loop\n";
      os << "vertex"
         << " " << x1 << " " << y1 << " " << z1 << "\n";
      os << "vertex"
         << " " << x2 << " " << y2 << " " << z2 << "\n";
      os << "vertex"
         << " " << x3 << " " << y3 << " " << z3 << "\n";
      os << "endloop\n";
      os << "endfacet\n";
    }
    os << "endsolid"
       << " "
       << "cylinder"
       << "\n";
  }
  friend ostream &operator<<(ostream &os, const cylinder cyl)
  {
    return os << "radius= " << cyl.r << "\t\theight= " << cyl.h << endl;
  }
};
class cube : public shape
{
private:
  double lx, wy, hz;

public:
  cube()
  {
    lx = wy = hz = 0;
  }
  cube(double length, double width, double height) : lx(length), wy(width), hz(height) {}
  void print(ostream &os) const override
  {
    // facet normals
    double nx[] = {0.0, 0.0, -1.0, -1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0};
    double ny[] = {0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, -1.0, -1.0, 0.0, 0.0};
    double nz[] = {-1.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0};
    // coords
    double x1[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, lx, lx, 0.0, 0.0, 0.0, 0.0};
    double x2[] = {lx, 0.0, 0.0, 0.0, lx, 0.0, lx, lx, lx, lx, lx, lx};
    double x3[] = {lx, lx, 0.0, 0.0, lx, lx, lx, lx, lx, 0.0, lx, 0.0};

    double y1[] = {0.0, 0.0, 0.0, 0, wy, wy, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    double y2[] = {wy, wy, wy, 0, wy, wy, wy, wy, 0.0, 0.0, 0.0, wy};
    double y3[] = {0.0, wy, wy, wy, wy, wy, wy, 0.0, 0.0, 0.0, wy, wy};

    double z1[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, hz, hz};
    double z2[] = {0.0, 0.0, hz, hz, hz, hz, 0.0, hz, 0.0, hz, hz, hz};
    double z3[] = {0.0, 0.0, 0.0, hz, 0.0, hz, hz, hz, hz, hz, hz, hz};
    for (int i = 0; i < sizeof(x1) / sizeof(x1[0]); i++)
    {
      if (i == 0)
        os << "solid "
           << " "
           << "mysolid"
           << "\n";
      os << "facet normal"
         << " " << nx[i] << " " << ny[i] << " " << nz[i] << "\n";
      os << "outer loop\n";
      os << "vertex"
         << " " << x1[i] << " " << y1[i] << " " << z1[i] << "\n";
      os << "vertex"
         << " " << x2[i] << " " << y2[i] << " " << z2[i] << "\n";
      os << "vertex"
         << " " << x3[i] << " " << y3[i] << " " << z3[i] << "\n";
      os << "endloop\n";
      os << "endfacet\n";
      if (i == (sizeof(x1) / sizeof(x1[0]) - 1))
        os << "endsolid"
           << " "
           << "mysolid"
           << "\n";
    }
  }
  friend ostream &operator<<(ostream &os, const cube &c)
  {
    return os << "<" << c.lx << "," << c.wy << "," << c.hz << ">";
  }
};

class model
{
private:
  vector<shape *> shapes;
  ofstream file_cube;
  ofstream file_cylinder;

public:
  model(const char filename_cube[], const char filename_cyl[]) : file_cube(filename_cube), file_cylinder(filename_cyl)
  {
    //    file.open(filename);
  }
  // clean up when we're done

  void add(shape *s)
  {
    shapes.push_back(s);
  }
  void print()
  {
    // for (auto s : shapes)
    //  s->print(file);
    shape *cube = shapes[0];
    shape *cylinder = shapes[1];
    cube->print(file_cube);
    cylinder->print(file_cylinder);
   
    cube->print(file_cube);
    cylinder->print(file_cylinder);
  }
};

int main()
{
  // cube c1(1, 1, 1);
  // cout << c1;
  // cylinder c2(10, 30,20);
  // cout << c2;

  model m("Cube_test.stl","cylinder_test.stl");
  // Don't do this: m.add(&c1);
  m.add(new cube(20, 1, 6));
  m.add(new cylinder(4, 6, 20)); // radius, height, number of triangles (resolution)

  m.print();
}