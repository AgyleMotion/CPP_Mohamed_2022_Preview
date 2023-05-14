#include <iostream>
using namespace std;

/*
Mohamed Eraky
*/
// list of int
class dynarray {
private:
  int* data;
  uint32_t len;
  uint32_t capacity;
  // 4 bytes of dead space here..
public:
  dynarray(): data(nullptr), len(0), capacity(0) { // use this. But know NULL and 0    
  }

  ~dynarray() {
    delete [] data;    
  }

  
    void grow() {
        // old= 2
        capacity =2*capacity|1;
       // if (capacity == 0)
      //     capacity = 1;
      // else
      //    capacity *= 2;

        const int* old = data;
        data = new int[capacity]; // _2_, _3_, _v_
        for (int i = 0; i < len; i++)
        data[i] = old[i]; // copy all the old memory
        delete [] old;
    }

  void add(int val){
    
    if (len >= capacity)
        grow();
    data[len] = val;
    len++; // now we have len+1 elements

  }
  
  friend ostream& operator <<(ostream& s, const dynarray &a){
    
    for ( int i=0;i<a.len;i++){
        s<< a.data[i] <<" ";
    }
   return  s ;
  }
  
};

int main() {
  dynarray a;
  a.add(3);
  a.add(1);
  for (uint64_t i=0; i <10; i++)
  a.add(i);
  cout << a << '\n';
  // dynarray b = a;


  double* aa = new double[1000000];
  //double* p = aa;
  
  aa++; // a points to a[1]
 cout << aa<<endl; 
 delete [] ++aa; // this will crash
 cout <<sizeof (aa)<<endl ;
  
  //delete [] p;

}