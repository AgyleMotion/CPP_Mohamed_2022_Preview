#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

// class is abstract if it contains at least one virtual function
class Shape
{
protected:
    double x;
    double y;
    double rr;
    double g;
    double b;

public:
    Shape(double x, double y, double rr, double g, double b) : x(x), y(y), rr(rr), g(g), b(b) {}

    virtual double area() const = 0; // pure virtual function
    virtual void print(ostream &s) const = 0;
};

//**************************
class Circle : public Shape
{ // inherit from shape

private:
    double r;

public:
    Circle(double x, double y, double r, double rr, double g, double b) : Shape(x, y, rr, g, b), r(r)
    {
    }

    // void print(ostream&os)const override{};
    double area() const override
    {
        return M_PI * r * r;
    }

    void print(ostream &s) const override
    {
        s << this->rr << " " << this->g << " " << this->b << " "
          << "setrgbcolor"
          << " " << this->x << " " << this->y << " " << this->r << " " << 0 << " " << 360 << " "
          << "arc"
          << " "
          << "fill";
    }

    friend ostream &operator<<(ostream &os, const Circle c)
    {
        return os << c.rr << " " << c.g << " " << c.b << " "
                  << "setrgbcolor"
                  << " " << c.x << " " << c.y << " " << c.r << " " << 0 << " " << 360 << " "
                  << "arc"
                  << " "
                  << "fill";
    }
};

int main()
{

    vector<Shape *> shapes;

    // Circle c1(200, 100, 50.0, 1.0, 1.0, 0.0);
    // c1.print(cout);

    ofstream f("circle5.ps");
    // c1.print(f);
    //  cout<<c1;
    //  f<<c1;
    shapes.push_back(new Circle(200, 100, 50.0, 1.0, 0.0, 0.0)); // new Circle (100,200,50,1.0,0,0);
    for (auto s : shapes)
    {
        cout << " area = " << s->area() << endl;

        s->print(f);
    }

    for (auto s : shapes)
    {
        delete s; // free the memory used by each shape after we are done
    }
    
    // cout << c1 << endl;
    //    s->print(cout);
    // question what if I want to add s-> print(); polymorphism
}
