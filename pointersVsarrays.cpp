#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std; 
int main(){
    std::vector<int> a;
    a.reserve(100);
    a.push_back(5);

    for(int i = 0; i < a.size(); i++){
        std::cout << a[i];
    }
    std::cout << "\n";

    //faster, more efficient: directly reads memory
    for(std::vector<int>::iterator i = a.begin(); i != a.end(); ++i){
        std::cout << *i;
    }
    std::cout << "\n";


    std::unordered_map<std::string, int> prices;
    prices["potato"] = 2;
    prices["apple"] = 5;
    prices["mac n cheese"] = 3;

    std::cout << prices["potato"];
    std::cout << "\n";

    //faster, more efficient: directly reads memory
    std::unordered_map<std::string, int>::iterator i = prices.find("potato");
    if(i != prices.end())
        std::cout << (*i).second;
    
    //(first, element)
    
    std::cout << "\n";
    for(const auto &s : prices){
        std::cout << s.first << " " << s.second;
    }

  cout << "---------------"<<endl;

    std::unordered_map<std::string, int> Prices;
    Prices["titla"] = 2;
     Prices["tesla"] = 5;
    Prices["yup"] = 3;

  

    //faster, more efficient: directly reads memory
    std::unordered_map<std::string, int>::iterator j = Prices.find("titla");
    if(j != Prices.end())
        std::cout << (*j).first << " = " <<(*j).second <<endl;

    for (const auto& s:Prices)
        cout <<s.first <<" ---"<<s.second<<endl; 

    char y[12];
    y[0]=2; 

    cout <<'\n'; 
    cout <<int(y[0]); 
 
    
   
}