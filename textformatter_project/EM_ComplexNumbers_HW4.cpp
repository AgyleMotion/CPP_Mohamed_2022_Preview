#include <iostream>
#include <cmath>

using namespace std;

double pi = M_PI;

class Complex
{

private:
   double real;
   double img;

public:
   Complex() : real(0), img(0)
   {
   }

   Complex(double x) : real(x), img(0)
   {
   }

   Complex(double x, double y) : real(x), img(y)
   {
   }

   friend Complex operator+(const Complex &c1, const Complex &c2)
   {
      Complex ans(c1.real + c2.real, c1.img + c2.img);
      return ans;
   }

   friend ostream &operator<<(ostream &s, const Complex c)
   {
      return s << c.real << "+" << c.img << "i" << endl;
   }
};

class Circle {
private:
  double xx, yy, rr; // coordinates of the circle center and radii

public:
  Circle(double x, double y, double r) : xx(x), yy(y), rr(r) {
  }

   bool contains(double x, double y) const {
      return rr >= sqrt((xx - x) * (xx - x) + (yy - y) * (yy - y));
   }

   friend ostream &operator<<(ostream &s, const Circle &c)
   {
      return s << c.xx << "," << c.yy << endl;
   }
};

string is_inside(bool inside)
{
   if (inside)
      return "yes, it's Inside circle";
   else
      return "No, it's Outside circle";
}

int main()
{
   Complex c1;
   Complex c2(1.0, 2.5);
   Complex c3 = 2.5;
   Complex c4 = c2 + c3;
   cout << c4 << "\n";

   double x = 50, y = 62.5, r = 10;

   Circle c(x, y, r);

   cout << is_inside(c.contains(x + 8, y)) << "\n";
   cout << is_inside(c.contains(x + 10, y)) << '\n';
   cout << is_inside(c.contains(x + 10, y + 3)) << '\n';
   cout << is_inside(c.contains(x, y + 10)) << '\n';

   double dx = r * cos(45 * pi / 180);
   double dy = r * sin(45 * pi / 180);

   cout << is_inside(c.contains(x + dx, y + dy)) << '\n';
}