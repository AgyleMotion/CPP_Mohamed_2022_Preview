#include <iostream> 

using namespace std; 
class dynarray {
private: 
int* data; 
uint32_t len; 


public: 
dynarray ():data(nullptr),len(0){

} 


void add( int val){
    const int* old=data; 
    data=new int[len+1]; 

    for (int i=0;i<len;i++){
        data[i]=old[i]; 
        
    }
    data[len]=val; 
    cout<<data[0]<<endl; 
    cout<<this->data[0]<<endl; 
    len++; 
    delete [] old; 
}





}; 
int main(){
uint64_t *a =new uint64_t[10]; 
delete [] a; 
uint64_t *p=a; 

cout <<a<<endl;
uint64_t *c= a++; 
cout<<p<<endl; 

dynarray d; 
d.add(5); 
 















}