#include <iostream> 
#include <vector> 
#include <unordered_map> 
using namespace std; 
int main (){
std::vector<int> a;
a.reserve(100); 
a.push_back(5); 

for (std::vector <int>:: iterator i=a.begin();i!= a.end();++i){
    std::cout <<*i; 
}
int *c =new int[100]; 
delete [] c; 

std::unordered_map<std::string,int> prices; 
prices["potato"]=2; 

std::cout<<prices["potato"]<<std::endl; 



int *b = (int*) malloc(100*sizeof(int));
free(b);
}