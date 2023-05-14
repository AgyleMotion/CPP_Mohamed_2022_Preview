#include <iostream> 
#include <utility>
#include <cmath>
using namespace std; 

class Life { 
private: 
    uint32_t rows, cols; 
    double* life; //life is a matrix 
public: 
//constructor initialized
    Life(uint32_t rows, uint32_t cols, double val=0): rows(rows),cols(cols),life(new double [rows*cols]) {
        for (uint32_t i=0;i<rows*cols;i++)
            life[i]=val; 
    }
    ~Life(){
        delete [] life; 
    }

// Move constructor 
 // optional stealing from the dead
 Life (Life && orig ):rows(orig.rows),cols(orig.cols),life(orig.life){
    orig.life = nullptr;
 }

 Life &operator =(Life copy){
    rows=copy.rows; 
    cols=copy.cols;
    swap(life,copy.life);
    return *this; 
 }


 double operator ()(uint32_t r, uint32_t c)const{
    return life[r*cols+c]; 
 }

 double operator ()(uint32_t r, uint32_t c){
    return life[r*cols+c]; 
 }
friend ostream& operator << (ostream &s, const Life & life){
        for (int i=0; i<life.rows; i++){
            for (int j=0; j< life.cols; j++)
                s<<life(i,j)<< '\t'; 
        }
        return s; 
}

friend Life operator+ (const Life & a, const Life & b){

}
};


int main () {

Life m1(3,4);
Life m2(3,4) ;
cout <<m1<<'\n';

m1(1,1)=5.0; 

m1(1,1) = 5.0;
m2(1,2) = 2.2; 


m2(3,2)=9.1; 
l1=l2; 
Life m3(4,5);


}