#include <iostream> 
#include <vector> 
#include <list> 
#include <unordered_map>
using namespace std; 

int main()
{
vector <int>a; 

a.reserve (10); 

for (int i=0; i<10;i++)
    a.push_back(i);

for (vector <int>::iterator i=a.begin();i!=a.end();++i ){
*i=1; 
cout <<" -- "<<*i+*i<<endl;
}

list <int>b; 

 
for (int i=0; i<10;i++)
    b.push_back(i);

for (list <int>:: iterator i=b.begin();i!=b.end();++i)
    cout << *i; 

for (const auto &x:a){
        cout <<x; 
    }

unordered_map<std::string, int> prices; 

prices ["potato"]=2; 
prices["mango"] =3; 
prices ["mac n cheese"] =5; 

cout << prices ["potato"]<<endl; 
cout << "\n"; 
unordered_map<std::string, int> ::iterator i=prices.find("potato");
if(i!=prices.end())
cout <<(*i).second;

for (const auto &s:prices ){
    cout <<s.first <<", "<<s.second<<endl; 
}


}

