#include <iostream> 
#include <cmath>
using namespace std; 


int main() {
uint32_t _ndiv = pow(2,12); 
double vin = 15; 

double pot_deg = 330; 
double volt_div = vin/pot_deg; 
double n_deg = 50;  // range of elastic actuator. 
double res =5.0/_ndiv; 
double vin_range = n_deg *volt_div;
double degResolution = vin_range/ n_deg ;
cout << "Vin range for pot for 50 deg " << vin_range <<endl; 
cout << "Vin range for pot for 50 deg " << 0.00122/0.0454 <<endl; 
cout << "degResolution = " << degResolution << " volt/Deg"<<'\n'; 
cout << "pot res = " << res  << " volt "<<'\n'; 
cout << "min_deg = " << res/degResolution << " deg "<<'\n'; 
}