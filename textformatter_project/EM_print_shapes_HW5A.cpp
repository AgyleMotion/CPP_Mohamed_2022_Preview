#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// class is abstract if it contains at least one virtual function
class Shape
{
protected:
    double x; // x- coordinate center of circle, or bottom low corner for rect, or vertex of traingle.
    double y; // y- coordinate center of circle, or bottom low corner for rect, or vertex of traingle.
    double rr;
    double g;
    double b;

public:
    Shape(double x, double y, double rr, double g, double b) : x(x), y(y), rr(rr), g(g), b(b) {}
    virtual void print(ostream &s) const = 0;
    virtual ~Shape()
    {
        cout << "Destructing shape\n";
    }
};

class Circle : public Shape
{ // inherit from shape

private:
    double r;

public:
    Circle(double x, double y, double r, double rr, double g, double b) : Shape(x, y, rr, g, b), r(r)
    {
    }

    void print(ostream &s) const override
    {
        s << this->rr << " " << this->g << " " << this->b << " "
          << "setrgbcolor"
          << " " << this->x << " " << this->y << " " << this->r << " " << 0 << " " << 360 << " "
          << "arc"
          << " "
          << "fill"
          << "\n";
    }
};

class Rect : public Shape
{ // inherit from shape

private:
    double w;
    double h;

public:
    Rect(double x, double y, double w, double h, double rr, double g, double b) : Shape(x, y, rr, g, b), w(w), h(h)
    {
    }

    void print(ostream &s) const override
    {
        s << this->rr << " " << this->g << " " << this->b << " "
          << "setrgbcolor"
          << " "
          << this->x << " " << this->y << " "
          << "moveto"
          << " "
          << this->x + this->w << " " << this->y << " "
          << "lineto"
          << " "
          << this->x + this->w << " " << this->y + this->h << " "
          << "lineto"
          << " "
          << this->x << " " << this->y + this->h << " "
          << "lineto"
          << " "
          << "closepath"
          << " "
          << "fill"
          << "\n";
    }
};

class Triangle : public Shape
{ // inherit from shape

private:
    double x2;
    double y2;
    double x3;
    double y3;

public:
    Triangle(double x, double y, double x2, double y2, double x3, double y3, double rr, double g, double b) : Shape(x, y, rr, g, b), x2(x2), y2(y2), x3(x3), y3(y3)
    {
    }

    void print(ostream &s) const override
    {
        s << this->rr << " " << this->g << " " << this->b << " "
          << "setrgbcolor"
          << " "
          << this->x << " " << this->y << " "
          << "moveto"
          << " "
          << this->x2 << " " << this->y2 << " "
          << "lineto"
          << " "
          << this->x3 << " " << this->y3 << " "
          << "lineto"
          << " "
          << "closepath"
          << " "
          << "fill"
          << "\n";
    }
};

int main()
{

    vector<Shape *> shapes;

    ofstream f("out.ps");

    shapes.push_back(new Circle(200, 100, 50.0, 1.0, 0.0, 0.0));           // new Circle (100,200,50,1.0,0,0);
    shapes.push_back(new Rect(200, 300, 50, 40, 0, 1, 0));                 // bright green rect
    shapes.push_back(new Triangle(100, 500, 300, 600, 400, 500, 0, 0, 1)); // bright blue triangle

    // circle has to print r g b setrgbcolor x y r 0 360 arc fill
    //    1 0 0 setrgbcolor 100 200 50 0 360 arc fill

    // rect
    // r g b setrgbcolor x y moveto x+w y lineto x+w y+h lineto x y+h lineto closepath fill

    // triangle
    // r g b setrgbcolor x y moveto x2 y2 lineto x3 y3 lineto closepath fill
    for (auto s : shapes)
    {
        s->print(f);
    }

    for (auto s : shapes)
    {
        delete s; // free the memory used by each shape after we are done
    }

}
