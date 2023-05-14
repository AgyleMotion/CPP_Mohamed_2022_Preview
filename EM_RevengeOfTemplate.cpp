#include <iostream>
#include <string>
using namespace std;

using namespace std;

/*
Mohamed Eraky
*/
// list of int
template <typename T> 
class dynarray {
private:
  T* data;
  uint32_t len; // still integer
  int capacity;
  // 4 bytes of dead space here..
public:
  dynarray(): data(nullptr), len(0), capacity(0) { // use this. But know NULL and 0    
  }

  ~dynarray() {
    delete [] data;    
  } 

  dynarray (const dynarray& orig ){  //dynarray<T>::dynarray

  }
  dynarray& operator = (const dynarray& orig){

  }

    void grow() {
        // old= 2
        capacity =2*capacity|1;
       // if (capacity == 0)
       //     capacity = 1;
      // else
       //    capacity *= 2;
        const T* old = data;
        data = new T[capacity]; // Calls T::T ()
        for (int i = 0; i < len; i++)
        data[i] = old[i]; // copy all the old memory
        delete [] old;
    }

  void add(const T& val){
    if (len >= capacity)
        grow();
    data[len] = val;
    len++; // now we have len+1 elements

  }
  
  friend ostream& operator <<(ostream& s, const dynarray &a){
    uint32_t i=0; 
    for ( i=0;i<a.len-1;i++){
        s<< a.data[i] <<" ";
    }
    if (a.len == 0) return s; 
   return  s << a.data [i];
  }
  
};

int main() {
  dynarray <string> a;
  a.add("hello");
  a.add("world");
 // for (uint64_t i=0; i <10; i++)
 //  a.add(i);
  cout << a << '\n';

}