#include <iostream> 
#include <exception> 
using namespace std; 


int f(){
    int x =5 ; 
    int y=0 ; 

    throw exception(); 
    if (y==0)
        throw "something int or object"; 

    return x/y; 



}

int main() {
try {
    int answer= f(); 
}catch (const char msg[]){
cerr<< msg <<'\n'; 
}


}