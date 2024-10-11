#include <iostream>
#include <string>

int main(){
    const double x{5.2};
    std::cout << x << std::endl;

    const int y{4};
    // y = 5; COMPILE FAIL

    const std::string my_string{"Hello!"};
    std::cout << my_string << std::endl;
}