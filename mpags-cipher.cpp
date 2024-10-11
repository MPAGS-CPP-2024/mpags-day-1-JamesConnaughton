#include <iostream>
#include <string>

int main(){
    const int a{5};
    const double b{4.3};
    std::cout << a * b << std::endl;

    std::cout << a / b << std::endl;

    const int c{2};
    std::cout << a / c << std::endl;

    std::string my_string{"Hey!"};
    char l = my_string[2];
    std::cout << l << std::endl;
}