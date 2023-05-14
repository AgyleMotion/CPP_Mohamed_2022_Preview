#include <iostream> 
#include <exception>
#include <fstream> 
using namespace std; 


int f(){
int x=3; 
int y=0; 

 //int *p=new int[10000000000000000];
  if(y==0)
    throw exception();
  
  return x/y  ;


}

int * F() {
int a=20; 
int x[10]; 
int *p =&a; 
//cout <<p<<endl; 
return p;  
}

int main() {

 int answer; 
 try { 

 answer =f(); 

cout <<answer<<endl; 
 }catch (const char msg[]){
    cerr<< "cannot be done "<<endl; 
 }catch (const exception&e){
    cerr<<"yes "; 
    }catch (...){
        cerr<<"something happened"<<endl; 
    }

    int a=3; 
    int &r =a;
    cout <<r<<endl; 
    cout <<&r<<endl; 
    cout <<&a<<endl; 
    int *p= &a; 
   
    p[0]=5; 
    cout <<p[0]<<"---" << a << endl; 
//for (int i=0;i<1000;i++)
 //   cout <<F()<<endl; 
    int x[10] ={ 1, 2, 4, 5 ,7 }; 
    char * m=(char*)x; 
    cout <<m[0]<<m[1]<<m[2]<<endl; 
     int z[1000]={1,257}; 
     ofstream f("test.dat"); 
     f.write((char*)z,1000*sizeof(int));
 }

