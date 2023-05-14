#include <iostream> 
#include <cmath>

using namespace std; 

// class is abstract if it contains at least one virtual function
class Shape {

protected:
double x;
double y;

public:
Shape(double x, double y):x(x),y(y){}

virtual double area()const=0;  // pure virtual function 
virtual double perimeter()const=0; 
};

//**************************
class Circle :public Shape{ // inherit from shape

private: 
double r; 

public:
Circle(double x, double y, double r): Shape(x,y),r(r){}

double area()const{
return M_PI*r*r;}


friend ostream &operator <<(ostream& os, Circle& c){
return os<<"x=" << c.x<<", y="<<c.y<<", r="<<c.r<<endl;
}

double perimeter()const{
return 2*M_PI*r;
}
};

// ***********************
class Rect:public Shape{
private: 

double w; // width and height in meters
double h;

public: 

Rect(double x, double y, double w, double h): Shape(x,y),w(w),h(h){
// initializers list 
}
double area()const{
return w*h;}

double area(Rect &r)const{
return w*h;
}
double perimeter()const{
return 2*(x+y);
}

friend ostream &operator <<(ostream &s,const Rect &r){
return s <<"x=" <<r.x <<"y="<<r.y <<"w=" <<r.w << " h="<<r.h;
} 

// friend  double area2 (Circle c); //didn't work

};


int main(){
   // Shape s; // illegal as Shape is abstract class
const Rect r1(10.0,15.0,3.0,4.0); // x=10, y=15, w=3, h=4; 
const Rect r2 (4.0,5.2,4.6,2.0); 

cout <<  "Area of Rect 1 = " <<r1.area()<<'\n'; // area (&r1) -- points method/ or member function
cout << "Area of Rect  2 = " <<r2.area()<<'\n'; 

//cout <<area(r2) <<'\n';
// g++ -std=c++20 how to compile. 

Circle c1(50.0,62.5,4.0);
cout << "Area of Circle 1 = " <<c1.area()<<"\n"; 
cout << "Parameters of Circle are : " <<c1 << "\n"; 
//cout << area2 (c1)<<endl;
const int size = 3; 
Circle circles[3]={Circle(2,5,3.5), Circle(4,5,6),Circle(2,4.5,1)};


for ( auto& c: circles) { // more efficient
   
cout <<" Area of Circle" <<"= " <<c.area()<<endl;

}

/*
for (int i=0; i<size ;i++){
    cout <<circles[i].area() <<"\n"<<endl; 
    
}
*/

}


