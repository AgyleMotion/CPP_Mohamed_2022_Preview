#include <iostream>

//class template
template <typename T>
class Tuple{
    private:
        T a, b;
    public:
        Tuple(T a, T b) : a(a), b(b) {}
        //try writing the other constructors yourself!

        friend std::ostream &operator<<(std::ostream &os, Tuple t){
            os << "<" << t.a << ", " << t.b << ">";
            return os;
        }

        T geta(){
            return a;
        }
        T getb(){
            return b;
        }
};

//function template
template <typename T>
T add(Tuple<T> t){
    return t.geta() + t.getb();
}


int main(){
    Tuple<int> tuple(1,2);
    Tuple<std::string> tuple2("abc","def");
    Tuple<double> tuple3(2.5,3.2);
    std::cout << tuple << "\n";
    std::cout << add(tuple) << "\n";
    std::cout << add(tuple2) << "\n";
    std::cout << add(tuple3) << "\n";
}