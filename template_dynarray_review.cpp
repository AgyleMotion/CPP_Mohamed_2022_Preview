#include <iostream> 

using namespace std; 

template <typename T> 

class dynarray{
    private: 
    T*  data; 
    uint32_t len; 

    public: 
    dynarray():data(nullptr),len(0){

    }

    void add(const T& val){

    }  //since you don't know what is T use reference 

friend ostream& operator<< (ostream& s, const dynarray& list){

    for (int i=0)
}

}; 

int main(){
     dynarray <int> a;
     a.add(3);
     a.add(1); 

     for (int i=0; i< 1000000;i++) {
        a.add(i);}
        std::cout <<a<<'\n';
     dynarray<int> b=a; 
     dynarray<int> c=a; 

     dynarray<Elephant> elephants; 
     Elephants.add(Elephant)("Eve")

}