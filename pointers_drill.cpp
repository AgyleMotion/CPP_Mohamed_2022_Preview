#include <iostream> 

using namespace std; 
class gravbody {
    bool ismoon:1; 
    bool isplanet:1; 
    bool isgravity:1; 
    int x:4;
   // uint64_t numberofmoons:8; 
  
};
class A{
char c; 
double x; 
uint32_t d; 
uint64_t e:8; 
};
int main(){

    int* p=new int[10]; 

    p[0]=5;
    p[1]=19;
    p[2]=3; 
    int* q=p+2; 
   // cout <<q<<endl; 
   // cout <<p[0]<<endl; 
    // cout <<q[0]<<endl; 
     char*x=(char*)q-1; 
     cout<<x<<endl; 


   int zz[10]={256,65657,1001};
   char* qq =(char*)zz ;

    cout <<(int)qq[0]<<(int)qq[1]<<(int)qq[2]<<(int)qq[3]<<(int)qq[4]<<endl;
    cout <<sizeof(gravbody) <<endl; 
    uint32_t dummy=5; 
    cout<<sizeof(x);
}

