
/*
***********************
Author : Mohamed Eraky
HW-3
***********************
*/
#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

// fn to print an array 
void print(const uint64_t a[], uint32_t len) {
    for ( uint32_t i =0; i < len ;i++)
        cout << a[i] << " "; 
        cout<<endl;
   
}

void cubeit(uint64_t a[], uint32_t len){
for ( uint32_t i =0; i < len ;i++)
        cout << a[i]*a[i]*a[i] << " "; 
        cout<<endl;
   
}

// fn to return the sum of squares
uint64_t sumsq(const uint64_t a, const uint64_t b ){
   uint64_t sum =0;
    for (uint64_t i =a ; i<=b;i++ ){
        sum+=i*i;
    } 
    return sum; 
     
}

// fn to compute the angle of 90 deg triangle  

inline double angle(double x=1, double y=1){
     return atan2(x,y); 
}
   
void polar2rect(double r, double ang ,double &x, double &y)
{
       
     x=r*cos(ang*M_PI/180.0);
     y=r*sin(ang*M_PI/180.0);

} 

void multtable(int n){
    for ( int j= 1; j<=n;j++){
         for (int i =1; i<=n;i++){
        cout << setw(4) <<j*i ;
    }
    cout <<"\n";
    }
   
}
   
int main() {

    // array 
	uint64_t a[] = {1, 3, 5, 9};
	uint32_t len = sizeof(a)/sizeof(a[0]); 
	print(a,len);

   // write a function that computes the sum of squares
	uint64_t s = sumsq(1, 5); // 1*1 + 2*2 + 3*3 + 4*4 + 5*5
    cout <<"s = " << s <<endl; 

   // look up the floating point library in the notes use atan2
   
	/*
        ang
       /|
      / |
     /  | 4
    /   |
    -----
      3
	 */ 

	double ang = angle(4, 3); // calculate the angle for 3-4-5 right triangle
	cout << "angle in radian = " <<ang << '\n'; // in radians
    
    double deg = 0; //  convert to degrees
    deg= ang *180.0/M_PI; 
    cout << "angle in degrees = " << deg<< '\n'; // in radians 
    double r = 5;
    double x,y;  
         
    polar2rect(r,deg,x,y);
	cout << "x=" << x << " y=" << y << '\n';

    	/*
    1  2  3  4  5
    2  4  6  8  10
    3  6  9  12 15
    4  8  12 16 20
    5  10 15 20 25
	*/
	multtable(5); 
    cubeit(a, 4); // 1*1*1   3*3*3   5*5*5   9*9*9
   
}
